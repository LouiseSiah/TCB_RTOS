/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"
#include "TCB.h"
//#include "stm32f4xx_hal.h"

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s
//extern int taskSp;							// Import from SaveRegisters.s
//extern int curSp;

//uint32_t taskFunc;
uint32_t variableInC = 0xdeaf;


uint32_t currentSP;
Tcb *currentTask;
Tcb *nextTask;
uint32_t nextSP;

void task1(void);

void task2(void);

void task3(void);

void switchTask(void);
void getNextTcb(void);
//============================================
int main() {	
	int i = 0;
	
	initTcb(task1, task2, task3);

	currentTask = &mainTcb;
  getNextTcb();
	initSysTick();

	
	while(1) {
		i++;
	}

//	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc()
{
	return 0xc00000 + twoBytes;		//
}
void task1(void)
{
	while(1) {}
}

void task2(void)
{
	while(1){}
}

void task3(void)
{
	while(1){}
}

void switchTask(void)
{
	currentTask->sp = currentSP;
	currentTask = currentTask->next;
}


void getNextTcb(void)
{
	nextSP = currentTask->next->sp;
	nextTask = currentTask->next;
}