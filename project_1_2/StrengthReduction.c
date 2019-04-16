/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2017                                *
 *  Author: Uli                              *
 *  Student Version                          *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE GOES HERE */
	Instruction *instr2, *instr3;
    instr2 = head;

	do{
        instr3 = instr2 -> next;

		if(instr2 -> opcode == LOADI){
			switch(instr3 -> opcode){
				case DIV :

					instr3 -> field2 = instr2 -> field1/2;
					instr3 -> opcode = RSHIFTI;



					instr2->prev = instr3 -> next;
					instr3->next->prev = instr2->prev;
					free(instr2);
					break;

				case MUL :

					instr3 -> field2 = instr2 -> field1*2;
					instr3 -> opcode = LSHIFTI;



					instr2->prev = instr3 -> next;
					instr3->next->prev = instr2->prev;
					free(instr2);
					break;

				default:
					break;
			}

		}
		instr2 = instr2->next;

	}while(instr2 != NULL && instr3 != NULL);

	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}

