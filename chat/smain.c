#include "server.h"
#include "list.h"
#include "file.h"

extern List *g_pList;

int main(void)
{
	g_pList = makeList();
	getUsrInfoFromFile(USRINFO_PATH,g_pList);
	showList(g_pList);

	setBaseId();

	printf("你好\n");
	int sockfd = makeSocket();
	makeBind(sockfd);
	makeListen(sockfd);
	acceptClient(sockfd);

	return 0;
}
