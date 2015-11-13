
#include "co_routine.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <stack>

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct {
	stCoRoutine_t *uiCoRoutine;
	stCoRoutine_t *controlCoRoutine;
	stCoRoutine_t *modelRoutine;
} statusMachine_t;


static void *ui_thread(void *args) 
{
	statusMachine_t *pStatusMachine = (statusMachine_t *)args;
	if (NULL == pStatusMachine)	
	{
		printf("UI... NULL?n");
		return NULL;
	}

	printf("UI... ~~~~~~~~~~~~~~~~~~~~~~~\n");
	return NULL;
}

static void *control_thread(void *args)
{
	statusMachine_t *pStatusMachine = (statusMachine_t *)args;
	if (NULL == pStatusMachine)	
	{
		printf("control... NULL?n");
		return NULL;
	}
	
	printf("Control... Just handler the logic and get/set data from/to model\n");
	co_resume(pStatusMachine->modelRoutine);
	printf("And now we get data from model\n");
	co_resume(pStatusMachine->modelRoutine);
	printf("And now we exit model and trigger ui\n");
	co_resume(pStatusMachine->uiCoRoutine);
	printf("exit from control...\n");
	return NULL;
}

static void *model_thread(void *args)
{
	statusMachine_t *pStatusMachine = (statusMachine_t *)args;
	if (NULL == pStatusMachine)	
	{
		printf("model... NULL?n");
		co_release(co_self());
		return NULL;
	}
	printf("~~~~ model here\n");
	co_yield(co_self());
	printf("model... handler by control, and do something\n");
	return NULL;	
}


int main(int argc,char *argv[])
{
	// init
	statusMachine_t statusMachineObj;
	co_create(&statusMachineObj.uiCoRoutine, NULL, ui_thread, &statusMachineObj);
	co_create(&statusMachineObj.controlCoRoutine, NULL, control_thread, &statusMachineObj);
	co_create(&statusMachineObj.modelRoutine, NULL, model_thread, &statusMachineObj);
	
	if (NULL != statusMachineObj.controlCoRoutine) 
	{
		co_resume(statusMachineObj.controlCoRoutine);
	}
	
	printf("----------- event loop 1\n");
	//co_eventloop(co_get_epoll_ct(), 0, 0);
	sleep(2);
	printf("----------- event loop 2\n");
	
	if (NULL != statusMachineObj.modelRoutine)
	{
		co_release(statusMachineObj.modelRoutine);
	}
	
	if (NULL != statusMachineObj.uiCoRoutine)
	{
		co_release(statusMachineObj.uiCoRoutine);
	}
	
	if (NULL != statusMachineObj.controlCoRoutine)
	{
		co_release(statusMachineObj.controlCoRoutine);
	}
	
	return 0;
}

