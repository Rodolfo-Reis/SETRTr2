/* ***************************************************** */
/* SETR 22/23, Paulo Pedreiras                           */
/* Base code for Unit Testing                            */
/*   A few tests to the cmdProcessor                     */
/*      just to illustrate how it works                  */
/*   Shoud be improved (e.g. test more cases)            */
/*                                                       */
/* Compile with: gcc cmdproc.c main.c -o main            */
/*                                                       */
/* ***************************************************** */
#include <stdio.h>
#include "cmdproc.h"

extern char Kp, Ti, Td;

int main(void) 
{
	int res;
	
	printf("Command processor test app\n\r");
	resetCmdString();
	newCmdChar('#');
	newCmdChar('P');
	newCmdChar('1');
	newCmdChar('2');
	newCmdChar('3');
	// o CS tem que levar com uma mascara de 128 por causa do espaço disponivel para o mesmo
	// 2^4 * 8bits, o 4 é o numero de espaços livres após inserir um comando do tipo P
	newCmdChar((unsigned char)('P'+'1'+'2'+'3')%9);
	newCmdChar('!');
	res=cmdProcessor();
	printf("cmdProcessor output to P 1 2 3: %d, Kp=%c,Ti=%c,Td=%c \n\r", res, Kp, Ti, Td);
	
	newCmdChar('#');
	newCmdChar('D');
	newCmdChar((unsigned char)('D')%9);
	newCmdChar('!');
	res=cmdProcessor();
	printf("cmdProcessor output to D (typo, should be S): % d\n\r", res);
	
	newCmdChar('#');
	newCmdChar('S');
	newCmdChar((unsigned char)('S')%9); 	//adicionado o CS
	newCmdChar('!');
	res=cmdProcessor();
	printf("cmdProcessor output to S with wrong SOF: % d\n\r", res);

}
