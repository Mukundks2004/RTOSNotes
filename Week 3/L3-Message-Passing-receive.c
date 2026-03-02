/*
   ----- 48450 -- lab handout ------ 

To illustrate the concept of cooperating processes -- IPC, 

let us consider the sending-receiving problem

Method 2 -- Message passing

*/

/**********************************************/
/*	Question 4 -- which variable (1 or 2) declarations is/are used for message receiving?
	
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSZ 128

// Declare the message structure.
typedef struct msgbuf {
	long mtype;
	char mtext[MSGSZ];
} message_buf;

int main()
{
	int msqid;
	key_t key;
	message_buf rbuf;
/*
     * Get the message queue id for the
     * "name" 1234, the msqud is created by
     * the server.
     */
	key = 1234;

	if ((msqid = msgget(key, 0666)) < 0) {
		perror("wrong msgget");
		exit(1);
	}
	printf("\nmsgget: Getting Msg id (%d)\n", msqid);

	//rceive an answer of message type 1
	if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
		perror("wrong msgrcv");
		exit(1);
	}

	printf("received message: %s\n", rbuf.mtext);
	exit(0);
}
