#include "MSC_lib.h"

int sc_memoryInit()
{
	for (int i = 0; i < 100; i++)
		RAM[i] = 0;

	if (RAM == NULL)
	{
		error_handler(1);
	}

	return 0;
}

int sc_memorySet(int address, int value)
{
	if (address >= 0 && address < 100) {
		RAM	[address] = value;
		return 0;
	} else {
		error_handler(3);
		return 0;
	}
}

int sc_memoryGet(int address, int *value)
{
	if (address >= 0 && address < 100) {
		*value = RAM[address];
		return 0;
	} else {

		error_handler(3);
		return 0;
	}
}

int sc_memorySave(char *filename)
{
	FILE *file = fopen(filename, "w");

	if (!file)
	{
		error_handler(2);
	}

	if (!fwrite(RAM, sizeof(int), 100, file))
	{
		error_handler(4);
	}

	fclose(file);
	return 0;
}

int sc_memoryLoad(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file) {
		error_handler(2);
	}
	
	sc_memoryInit();
	if (!fread(RAM, sizeof(int), 100, file))
	{
		error_handler(5);
	}
	fclose(file);
	return 0;
}

/*int sc_regInit(void)
{

}

int sc_regSet(int register, int value)
{

}

int sc_regGet(int register, int *value)
{

}*/

int sc_commandEncode(int command, int operand, int *value)
{
	if (command >= 10 && command <= 76) {
		if (operand >= 0 && operand < 128) {
			*value = (command << 7) | operand;
		} else {
			error_handler(6);
		}
	} else {

		error_handler(7);
	}
	return 0;
}

int sc_commandDecode (int value, int *command, int *operand)
{
	*command = (value >> 7);
	*operand = value & (~(*command << 7));
	if (*command >= 10 && *command <= 76) {
		if (*operand >= 0 && *operand < 128) {
			return 0;
		} else {
			error_handler(6);
		}
	} else {

		error_handler(7);
	}
	return 0;
}

void error_handler(int error)
{
	printf("\nFatal error has been caught (Code %d):\n", error);
	switch(error)
	{
		case 1:
			fprintf(stderr, "Unable to initialize RAM!\n");
			exit(EXIT_FAILURE);
		case 2:
			fprintf(stderr, "Unable to access RAM!\n");
			exit(EXIT_FAILURE);
		case 3:
			fprintf(stderr, "Out of memory!\n");
			exit(EXIT_FAILURE);
		case 4:
			fprintf(stderr, "Unable to save RAM!\n");
			exit(EXIT_FAILURE);
		case 5:
			fprintf(stderr, "Unable to load RAM!\n");
			exit(EXIT_FAILURE);
		case 6:
			fprintf(stderr, "Wrong operand!\n");
			exit(EXIT_FAILURE);
		case 7:
			fprintf(stderr, "Wrong command!\n");
			exit(EXIT_FAILURE);
		case 8:
			fprintf(stderr, "\n");
			exit(EXIT_FAILURE);
		case 9:
			fprintf(stderr, "\n");
			exit(EXIT_FAILURE);
		case 10:
			fprintf(stderr, "\n");
			exit(EXIT_FAILURE);
	}
}