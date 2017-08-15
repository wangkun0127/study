#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "public.h"

int makeSocket();
void connectToServer(int sockfd);
int loginOrRegisFace();
void loginOrRegist(int sockfd);
void chat(int sockfd);
void exitPrograms(int sockfd);

#endif
