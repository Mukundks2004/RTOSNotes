/*
   ----- 48450 -- lab handout----- 

To illustrate the concept of cooperating processes -- IPC, 

let us consider the producer-consumer problem, which is a common paradigm for cooperating processes. A producer process produces information that is consumed by a consumer process

Method 1 -- shared memory
*/

/**********************************************/
/*	Question -- which variable declaration is used for shared memory?
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


#define BUFFER_SIZE 18 /* space from 0-17 */
#define TRUE 1

char *text="48450 of RTOS JIAN ";/*  18 characters*/

typedef struct
{
  char elem;
}item;

int main()
{
  item buffer[BUFFER_SIZE];/* buffer size is declared as 18, buffer [0] to buffer [17]*/
  int in=0;
  int out=0;

  item next_produced, next_comsumed;
  while(TRUE)
  {
	printf("Begin produce:\n"); //Producer Process
	while(1)
	{
	    if(in>0&((in)%BUFFER_SIZE)==out) /* module 18*/
		{
		printf("\ncharacter %d (18 characters)\nThe proceduce is full\n", in);
		break;
		}//break and enter the consume process
 
	    next_produced.elem=text[in]; // assign one character (text) to next_produced.elem
		
	    buffer[in]=next_produced;
	    printf("%c, character %d\n", next_produced.elem, in); 
 	  
	    in=in+1;

	}

	printf("\nBegin comsume:\n"); //Comsumer Process
	printf("\n in=%d\n", in);
	while(TRUE)
	{
	    if(in==out&(out%BUFFER_SIZE)==0)
	    {
		printf("\nComsume complete, it is empty now.\n");
	printf("\n out=%d\n", out);
	break;
	    }//break and exit this while loop

	    next_comsumed=buffer[out];
  	    printf("%c",next_comsumed.elem);
	out=out+1;
	}
	 exit (0);
	  }// complete the process and end
  
  }


