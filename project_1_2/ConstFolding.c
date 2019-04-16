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

    Instruction *instr1, *instr2, *instr3;

    instr1 = head;

    do{

        instr2 = instr1 -> next;
        instr3 = instr2 -> next;

        if(instr1 && instr1 -> opcode == LOADI && instr2 && instr2 -> opcode == LOADI){
            switch(instr3 -> opcode){
                case ADD :

                    instr1 -> field1 = instr1 -> field1 + instr2 -> field1;
                    instr1 -> field2 = instr3->field3;



                    instr1->next = instr3 -> next;
                    instr3->next->prev = instr1;
                    free(instr2);
                    free(instr3);

                    break;
                case SUB :
                    instr1 -> field1 = instr1 -> field1 - instr2 -> field1;
                    instr1 -> field2 = instr3->field3;

                    instr1->next = instr3 -> next;
                    instr3->next->prev = instr1;
                    free(instr2);
                    free(instr3);

                    break;
                case MUL :
                    instr1 -> field1 = instr1 -> field1 * instr2 -> field1;
                    instr1 -> field2 = instr3->field3;

                    instr1->next = instr3 -> next;
                    instr3->next->prev = instr1;
                    free(instr2);
                    free(instr3);

                    break;

                default:
                    break;
            }

        }
        instr1 = instr1->next;

    }while(instr1 != NULL && instr2 != NULL && instr3 != NULL);

    if(head)
    PrintInstructionList(stdout, head);
    return EXIT_SUCCESS;
}