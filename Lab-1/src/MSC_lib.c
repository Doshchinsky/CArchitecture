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
		sc_regSet(OUT_OF_MEMORY, 1);
		error_handler(3);
		return 0;
	}
}

int sc_memorySave(char *filename)
{
	FILE *file = fopen(filename, "wb");
	int passed = 0;

	if (!file)
	{
		passed = 1;
		error_handler(2);
	}

	if (!fwrite(RAM, sizeof(int), 100, file))
	{
		passed = 1;
		error_handler(4);
	}

	fclose(file);
	return passed;
}

int sc_memoryLoad(char *filename)
{
	FILE *file = fopen(filename, "rb");
	int passed = 0;

	if (!file)
	{
		passed = 1;
		error_handler(2);
	}
	
	sc_memoryInit();
	if (!fread(RAM, sizeof(int), 100, file))
	{
		passed = 1;
		error_handler(5);
	}
	fclose(file);
	return passed;
}

int sc_regInit(void)
{
	reg_flag = 0;
	return 0;
}

int sc_regSet(int regist, int value)
{
	if (regist >= 0x01 && regist <= 0x10) {
		if (value == 0)
			reg_flag &= regist;
		else if (value == 1)
			reg_flag |= regist;
		else {
			error_handler(8);
		}
	} else {
		error_handler(9);
	}
	return 0;
}

int sc_regGet(int regist, int *value)
{
	if (regist >= 0x1 && regist <= 0x10)
		*value = (reg_flag & regist) > 0 ? 1 : 0;
	else {
		error_handler(9);
	}
	return 0;
}

int sc_commandEncode(int command, int operand, int *value)
{
	if (command >= 10 && command <= 76) {
		if (operand >= 0 && operand < 128) {
			*value = (command << 7) | operand;
		} else {
			error_handler(6);
		}
	} else {
		sc_regSet(COMMAND_ERR, 1);
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
		sc_regSet(COMMAND_ERR, 1);
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
			fprintf(stderr, "Wrong value for the register!\n");
			exit(EXIT_FAILURE);
		case 9:
			fprintf(stderr, "Wrong register was selected!\n");
			exit(EXIT_FAILURE);
		case 10:
			fprintf(stderr, "Easter-egg ^-^\n");
			exit(EXIT_FAILURE);
	}
}

void MEM_CHECK()
{
	printf("\t\tMEMORY CHECK START: (1/3)\n");
	int tmp = 0;
	sc_memoryInit();
	if (!sc_memorySet(0, 1)) {
		printf("\t\t |-----> Set [PASSED]\n");
			if (!sc_memoryGet(0, &tmp) && tmp == 1) {
				printf("\t\t |-----> Get [PASSED]\n");
					if (!sc_memorySave("RAM")) {
						printf("\t\t |-----> Save [PASSED]\n");
							if (!sc_memoryLoad("RAM") && RAM[0] == 1) {
								printf("\t\t |-----> Load [PASSED]\n\tMEMORY CHECK COMPLETED SUCCESSFULLY!\n");
							} else
								printf("\t\tWrong loaded value\n");
					}
			} else
				printf("\t\tWrong get value\n");
	}
}

void REG_CHECK()
{
	printf("\n\n\t\tREGISTER CHECK START: (2/3)\n");
	sc_regInit();
	int tmp = 0;
	if (!sc_regSet(FREQ_ERR, 1)) {
		printf("\t\t |-----> Set [PASSED]\n");
		printf("\t\t |\t%d\n", reg_flag);
		if (!sc_regGet(FREQ_ERR, &tmp) && tmp == 1) {
			printf("\t\t |\t%d\n", tmp);
			printf("\t\t |-----> Get [PASSED]\n");
			printf("\tREGISTER CHECK COMPLETED SUCCESSFULLY!\n");
		}
	}
}

void COM_CHECK()
{
	printf("\n\n\t\t COMMAND CHECK START: (3/3)\n");
	int value = 0, command = 15, operand = 24;
	printf("\t    Encode: command = %d, operand = %d.\n", command, operand);
	if (!sc_commandEncode(command, operand, &value))
	{
		command = operand = 0;
		if (!sc_commandDecode(value, &command, &operand))
		{
			printf("\t    Decode: command = %d, operand = %d.\n", command, operand);
			if (command == 15 && operand == 24)
				printf("\tENCODE & DECODE COMPLETED SUCCESSFULLY!\n");
		}
	}
	return;
}

void RAM_TEST()
{
	MEM_CHECK();
	REG_CHECK();
	COM_CHECK();
}