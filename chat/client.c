#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "client.h"
#include "protocol.h"

uint g_uiId = 0;
static void handleChat(PDU *pdu)
{
	if(NULL == pdu)
	{
		return;
	}
	printf("%u says:\n",pdu->uiFrom);
	write(STDOUT_FILENO,pdu->caMsg,pdu->uiMsgLen);
}
void *handleServer(void *arg)
{
	int sockfd = (int)arg;
	PDU *pdu = NULL;
	while(1)
	{
		pdu = recvPDU(sockfd);
		if(NULL == pdu)
		{
			printf("和服务器已断开\n");
			exit(0);
		}
		switch(pdu->uiMsgType)
		{
			case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
			case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
				handleChat(pdu);
				break;
			default:
				break;
		}
		free(pdu);
	}
}
int loginOrRegistFace()
{
	printf("  欢迎\n");
	printf("1、登录\n");
	printf("2、注册\n");
	printf("0、退出\n");
	printf("请输入选项：\n");
	int num = 0;
	scanf("%d",&num);
	return num;
}
static int login(int sockfd)
{
	int id = 0;
	PDU *pdu = makePDU(PWD_LEN);
	printf("请输入id:\n");
	scanf("%u",&pdu->uiFrom);
	id = pdu->uiFrom;
	printf("请输入密码:\n");
	scanf("%s",pdu->caMsg);
	pdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_REQUEST;
	sendPDU(sockfd,pdu);
	free(pdu);
	
	pdu = recvPDU(sockfd);
	
	if(ENUM_MSG_TYPE_LOGIN_RESPOND&&0==strncmp(LOGIN_OK,pdu->caMsg,pdu->uiMsgLen))
	{
		printf("登录成功\n");
		g_uiId = id;
		return 1;
	}
	printf("登录失败\n");
	write(STDOUT_FILENO,pdu->caMsg,pdu->uiMsgLen);
	putchar('\n');

	return -1;
}
static void regist(int sockfd)
{
	PDU *pdu = makePDU(PWD_LEN);
	pdu->uiMsgType = ENUM_MSG_TYPE_REGIST_REQUEST;
	printf("请输入注册需要的密码:\n");
	scanf("%s",pdu->caMsg);
	sendPDU(sockfd,pdu);
	free(pdu);

	pdu = recvPDU(sockfd);
	if(ENUM_MSG_TYPE_REGIST_RESPOND==pdu->uiMsgType)
	{
		g_uiId = pdu->uiTo;
		printf("获得注册的id:%u\n",g_uiId);
	}
	else
	{
		printf("注册失败\n");
	}
	free(pdu);
}
int makeSocket()
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	return sockfd;
}
void connectToServer(int sockfd)
{
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(8888);
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(servAddr.sin_zero,8);

	int ret = -1;
	ret = connect(sockfd,(struct sockaddr *)&servAddr,sizeof(servAddr));
	if (-1 == ret)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	printf("connect to server success\n");
}
void exitPrograms(int sockfd)
{
	PDU *pdu = makePDU(0);
	pdu->uiFrom =g_uiId;
	pdu->uiMsgType = ENUM_MSG_TYPE_EXIT_REQUEST;
	sendPDU(sockfd,pdu);
	free(pdu);
	printf("发送退出请求\n");
}
void loginOrRegist(int sockfd)
{
	int num = -1;
	int ret = -1;
	while(1)
	{
		num = loginOrRegistFace();
		switch(num)
		{
			case 1:
				ret = login(sockfd);
				break;
			case 2:
				regist(sockfd);
				break;
			case 0:
				exitPrograms(sockfd);
				exit(EXIT_SUCCESS);
			default:
				printf("输入有误！！！\n");
				break;
		}
		if(1 == ret)
		{
			break;
		}
	}
}
static int chatFace()
{
	printf("  ^_^\n");
	printf("1、私聊\n");
	printf("2、群聊\n");
	printf("0、返回\n");
	printf("请输入选项:\n");
	int num = 0;
	scanf("%d",&num);
	return num;
}
static void privateChat(int sockfd)
{
	printf("请输入聊天的对象:\n");
	uint perid = 0;
	scanf("%u",&perid);

	char caMsg[PER_MAX_IO_BYTES] = {'\0'};
	printf("请输入聊天信息:\n");
	read(STDIN_FILENO,caMsg,PER_MAX_IO_BYTES);
	PDU *pdu = makePDU(strlen(caMsg));
	pdu->uiFrom = g_uiId;
	pdu->uiTo = perid;
	strncpy(pdu->caMsg,caMsg,strlen(caMsg));
	pdu->uiMsgType = ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST;
	sendPDU(sockfd,pdu);
	free(pdu);
}
static void groupChat(int sockfd)
{
	char caMsg[PER_MAX_IO_BYTES] = {'\0'};
	printf("请输入聊天信息:\n");
	read(STDIN_FILENO,caMsg,PER_MAX_IO_BYTES);
	PDU *pdu = makePDU(strlen(caMsg));
	pdu->uiFrom = g_uiId;
	strncpy(pdu->caMsg,caMsg,strlen(caMsg));
	pdu->uiMsgType = ENUM_MSG_TYPE_GROUP_CHAT_REQUEST;
	sendPDU(sockfd,pdu);
	free(pdu);
}
void chat(int sockfd)
{
	pthread_t thread;
	pthread_create(&thread,NULL,handleServer,(void *)sockfd);

	int num = -1;
	while(1)
	{
		num = chatFace();
		switch(num)
		{
			case 1:
				privateChat(sockfd);
				break;
			case 2:
				groupChat(sockfd);
				break;
			case 0:
				pthread_cancel(thread);
				return;
			default:
				break;
		}
	}
}

