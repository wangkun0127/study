#ifndef _SERVER_H_
#define _SERVER_H_

#include "public.h"

void setBaseId();
int makeSocket();
void makeBind(int sockfd);
void makeListen(int sockfd);
void acceptClient(int sockfd);

#endif
