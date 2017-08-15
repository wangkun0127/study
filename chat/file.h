#ifndef _FILE_H_
#define _FILE_H_

#include "public.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "list.h"

#define USRINFO_PATH "./usr.info"

int openFile(const char *pathname,int flags);
void saveUsrInfoToFile(const char *pathname,const List *list);
void getUsrInfoFromFile(const char *pathname,List *list);

#endif
