#include "server.h"
#include "list.h"
#include "protocol.h"
#include "file.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <pthread.h>

List *g_pList = NULL;
uint g_uiBaseId = 1000;

static void handleRegistRequest(int sockfd,PDU *pdu)
{
	Node *node = makeNode();
	node->sockfd = -1;
	node->uiId = g_uiBaseId;
	strncpy(node->caPwd,pdu->caMsg,PWD_LEN);
	insertList(g_pList,node);

	saveUsrInfoToFile(USRINFO_PATH,g_pList);

	PDU *respdu = makePDU(0);
	respdu->uiMsgType = ENUM_MSG_TYPE_REGIST_RESPOND;
	respdu->uiTo = g_uiBaseId;
	g_uiBaseId++;
	sendPDU(sockfd,respdu);
	free(respdu);
}
static void handleLoginRequest(int sockfd,PDU *pdu)
{
	if(NULL == pdu)
	{
		return;
	}
	Node *node = g_pList->pFirstNode;
	while(NULL != node)
	{
		if(node->uiId == pdu->uiFrom&&0 == strncmp(node->caPwd,pdu->caMsg,PWD_LEN))
		{
			if(-1 == node->sockfd)
			{
				node->sockfd = sockfd;
			}
			else
			{
				node = NULL;
			}
			break;
		}
		node = node->pNext;
	}

	PDU *respdu = NULL;
	if(NULL !=node)
	{
		respdu = makePDU(strlen(LOGIN_OK));
		strncpy(respdu->caMsg,LOGIN_OK,strlen(LOGIN_OK));
	}
	else
	{
		respdu = makePDU(strlen(LOGIN_FAILEM));
		strncpy(respdu->caMsg,LOGIN_FAILEM,strlen(LOGIN_FAILEM));
	}
	respdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_RESPOND;
	sendPDU(sockfd,respdu);
	free(respdu);
}
static void handlePrivateChatRequest(int sockfd,PDU *pdu)
{
	if(NULL == pdu)
	{
		return;
	}
	Node *node = g_pList->pFirstNode;
	while(NULL != node)
	{
		if(node->uiId == pdu->uiTo)
		{
			sendPDU(node->sockfd,pdu);
			break;
		}
		node = node->pNext;
	}
}
static void handleGroupChatRequest(int sockfd,PDU *pdu)
{
	if(NULL == pdu)
	{
		return;
	}
	Node *node = g_pList->pFirstNode;
	while(NULL !=node)
	{
		if(node->sockfd>0)
		{
			sendPDU(node->sockfd,pdu);
		}
		node = node->pNext;
	}
}
static void handleExitRequest(int sockfd,PDU *pdu)
{
	if(NULL == pdu)
	{
		return;
	}
	Node *node = findNodeById(pdu->uiFrom,g_pList);
	if(NULL != node)
	{
		node->sockfd = -1;
	}
}
static void *handleClient(void *arg)
{
	int sockfd = (int)arg;
	PDU *pdu = NULL;
	while(1)
	{
		pdu = recvPDU(sockfd);
		if(NULL==pdu)
		{
			pthread_exit(NULL);
		}
		switch(pdu->uiMsgType)
		{
			case ENUM_MSG_TYPE_REGIST_REQUEST:
				handleRegistRequest(sockfd,pdu);
				break;
			case ENUM_MSG_TYPE_LOGIN_REQUEST:
				handleLoginRequest(sockfd,pdu);
				break;
			case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
				handlePrivateChatRequest(sockfd,pdu);
				break;
			case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
				handleGroupChatRequest(sockfd,pdu);
				break;
			case ENUM_MSG_TYPE_EXIT_REQUEST:
				handleExitRequest(sockfd,pdu);
				printf("线程退出\n");
				pthread_exit(NULL);
				break;
			default:
				break;
		}
		free(pdu);
	}
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
void makeBind(int sockfd)
{
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(8888);
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(servAddr.sin_zero,8);

	int ret = -1;
	ret = bind(sockfd,(struct sockaddr *)&servAddr,sizeof(servAddr));
	if (-1 == ret)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
}
void makeListen(int sockfd)
{
	int ret = listen(sockfd,10);
	if(-1 == ret)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
}
void setBaseId()
{
	Node *node = g_pList->pFirstNode;
	int sign = 0;
	while(NULL !=node)
	{
		if(g_uiBaseId < node->uiId)
		{
			g_uiBaseId = node->uiId;
			sign = 1;
		}
		node = node->pNext;
	}
	if(1 == sign)
	{
		g_uiBaseId++;
	}
}
void acceptClient(int sockfd)
{
	struct sockaddr_in clientAddr;
	int clientSockfd = -1;
	int ilen = sizeof(clientAddr);
	pthread_t thread;
	while(1)
	{
		printf("等待客户端连接...\n");
		clientSockfd = accept(sockfd,(struct sockaddr *)&clientAddr,&ilen);
		if(-1 == clientSockfd)
		{
			perror("accept");
			break;
		}
		printf("ip为%s的客户端连接到服务器\n",inet_ntoa(clientAddr.sin_addr));
		printf("产生的新的用于数据交换的socket:%d\n",clientSockfd);
		pthread_create(&thread,NULL,handleClient,(void *)clientSockfd);
	}
}




