#ifndef LANCHAT_PUBLIC_H
#define LANCHAT_PUBLIC_H

#define UN_LEN 20
#define PW_LEN 20

struct LanchatPDU
{
    int len;
    int type;
    char sendname[UN_LEN];
    char recvname[PW_LEN];
    char buf[1];
};

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8899

struct LanchatPDU* CreateLoginReqPDU(char* username,char* password);
struct LanchatPDU* CreatePriChatReqPDU(char* sendname,char* recvname,char* content);
struct LanchatPDU* CreateGrpChatReqPDU(char* sendname,char* content);
struct LanchatPDU* CreateGetULReqPDU(char* sendname,char* content);
struct LanchatPDU* CreateGrpChatReqPDU(char* sendname,char* content);
struct LanchatPDU* CreateGrpChatReqPDU(char* sendname,char* content);
struct LanchatPDU* CreateGrpChatReqPDU(char* sendname,char* content);

#endif