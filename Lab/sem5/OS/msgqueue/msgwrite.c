#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#define BUFFER_SIZE 10
struct msgqueue
{
 long int msg_type;
 char data[BUFFER_SIZE];
};
typedef struct msgqueue msgqueue;
int main()
{
 char buffer[10];
 key_t key = 1234;
 msgqueue message;
 message.msg_type = 1;
 int msgid = msgget(key,IPC_CREAT|0666);
 if (msgid == -1)
 {
  printf("Not able to create.\n");
 }
  printf("Enter the message to be send : ");
  scanf("%s",&buffer);
  strcpy(message.data,buffer);
  msgsnd(msgid,&message,BUFFER_SIZE,0);
 return 0;
}
