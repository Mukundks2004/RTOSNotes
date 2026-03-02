/*
   ----- 48450 -- lab handout ------ 

To illustrate the concept of cooperating processes -- IPC, 

let us consider the sending-receiving problem

Method 2 -- Message passing

*/

/**********************************************/
/*	Question -- which variable declarations are used for message sending? 
	
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSGSZ 128	

// Declare the message structure

typedef struct msgbuf {
	long mtype;
	char mtext[MSGSZ];
} message_buf;

int main() 
{
	int msqid;
	int msgflg = IPC_CREAT | 0666;
	key_t key;
	message_buf sbuf;
	size_t buf_length;

/* Acquire a string from command line*/
   char second_chs[100];
   printf("please input a string for passing message\n");
   if (fgets(second_chs, sizeof(second_chs), stdin)==0)
	{perror ("faild to do fgets\n"); exit(1);}   
	//(void) strcpy(sbuf.mtext, second_chs);
    /*
     * Get the message queue id for the
     * "name" 1234, the msqid is created by
     * the server.
     */

	key = 1234;

	(void)printf("\nmsgget: Calling msgget(%#1x,\%#o)\n", key, msgflg);
	
	if ((msqid = msgget(key, msgflg)) < 0) {
		perror("worng msgget");
		exit(1);
	}
	else
		(void)printf("msgget: msgget succeeded: msgqid = %d\n", msqid);

	// We'll send message 
	sbuf.mtype = 1;
	
	
	(void) strcpy(sbuf.mtext, second_chs);
	
	buf_length = strlen(sbuf.mtext)+1;

	// Send a message, you can type "man msgsnd" on your linux terminal
	if((msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT)) < 0){
		printf("%d, %ld, %s, %ld\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
		perror("msgsnd");
		exit(1);
	}
	else
		{
	printf ("msqid=%d, sbuf.mtype=%ld, buf_length=%ld, sbuf.mtext=%s\n", msqid, sbuf.mtype, 	buf_length,sbuf.mtext);
       printf("Message: %s--Sent\n", sbuf.mtext);
}      

	exit(0);
}
