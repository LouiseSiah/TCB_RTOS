#include "TCB.h"
#include <stdlib.h>

Tcb mainTcb;
Tcb task1Tcb;
Tcb task2Tcb;
Tcb task3Tcb;



/**
 * Must call this function first
 */
void initTcb(void (*task1), void (*task2), void (*task3))
{
	CpuContext *context;
	mainTcb.name	= "Main";
	mainTcb.sp		= 0;
	mainTcb.next = &task1Tcb;
	
	task1Tcb.name = "task_1";
	task1Tcb.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE] - sizeof(CpuContext);
	context = (CpuContext *)task1Tcb.sp ;
	context->R4 = 0x11111104;
	context->R5 = 0x11111105;
	context->R6 = 0x11111106;
	context->R7 = 0x11111107;
	context->R8 = 0x11111108;
	context->R9 = 0x11111109;
	context->R10 = 0x11111010;
	context->R11 = 0x11111011;
	context->R0 = 0x11111100;
	context->R1 = 0x11111101;
	context->R2 = 0x11111102;
	context->R3 = 0x11111103;  
	context->R12 = 0x11111012;
	context->PC = (uint32_t)task1;
	context->xPSR = 0x01000000;
	task1Tcb.next = &task2Tcb;
	
	task2Tcb.name = "task_2";
	task2Tcb.sp = (uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE] - sizeof(CpuContext);
	context = (CpuContext *)task2Tcb.sp ;
	context->R4 = 0x222224;
	context->R5 = 0x122225;
	context->R6 = 0x22226;
	context->R7 = 0x12227;
	context->R8 = 0x2228;
	context->R9 = 0x22229;
	context->R10 = 0x1112210;
	context->R11 = 0x1222011;
	context->R0 = 0x11122200;
	context->R1 = 0x11112201;
	context->R2 = 0x1122202;
	context->R3 = 0x1112203;  
	context->R12 = 0x11122012;
	context->PC = (uint32_t)task2;
	context->xPSR = 0x01000000;
	task2Tcb.next = &task3Tcb;
	
	task3Tcb.name = "task_3";
	task3Tcb.sp = (uint32_t)&task3Tcb.virtualStack[TASK_STACK_SIZE] - sizeof(CpuContext);
	context = (CpuContext *)task3Tcb.sp ;
	context->R4 = 0x33333304;
	context->R5 = 0x33333305;
	context->R6 = 0x33333306;
	context->R7 = 0x33333307;
	context->R8 = 0x33333308;
	context->R9 = 0x33333309;
	context->R10 = 0x33333010;
	context->R11 = 0x33333011;
	context->R0 = 0x3333300;
	context->R1 = 0x3333301;
	context->R2 = 0x3333302;
	context->R3 = 0x3333303;  
	context->R12 = 0x33333012;
	context->PC = (uint32_t)task3;
	context->xPSR = 0x01000000;
	task3Tcb.next = &mainTcb;
}