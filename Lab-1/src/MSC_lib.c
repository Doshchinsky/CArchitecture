#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "MSC_lib.h"

const int SIZE = 100;

int sc_memoryInit()
{
	int *sc_memory;
	sc_memory = (int *)malloc(SIZE * sizeof(int));

	if (sc_memory == NULL)
	{
		error_handler(1);
	}

	return *sc_memory;
}

/*int sc_memorySet(int address, int value)
{

}

int sc_memoryGet(int address, int *value)
{

}

int sc_memorySave(char *filename)
{

}

int sc_memoryLoad(char *filename)
{

}

int sc_regInit(void)
{

}

int sc_regSet(int register, int value)
{

}

int sc_regGet(int register, int *value)
{

}

int sc_commandEncode(int command, int operand, int *value)
{

}

int sc_commandDecode (int value, int *command, int *operand)
{

} */

void error_handler(int error)
{
	printf("\nFATAL ERROR (Code-%d):\n", error);

	switch(error)
	{
		case 1:
			fprintf(stderr, "Unable to initialize RAM!\n");
			exit(EXIT_FAILURE);
		case 2:
			fprintf(stderr, "Unable to access RAM!\n");
			exit(EXIT_FAILURE);
//		case 3:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
//		case 4:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
//		case 5:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
//		case 6:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
//		case 7:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
//		case 8:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
//		case 9:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
//		case 10:
//			fprintf(stderr, "\n");
//			exit(EXIT_FAILURE);
	}
}