#ifndef MSCLIB_H
#define MSCLIB_H

#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW 0x1
#define ZERO_ERR 0x2
#define OUT_OF_MEMORY 0x4 
#define FREQ_ERR 0x8 
#define COMMAND_ERR 0x10

int RAM[100];
int reg_flag;

int sc_memoryInit(); /* Инициализирует оперативную память SC, задавая всем её ячейкам нулевые значения. */
int sc_memorySet(int address, int value); /* Задает значение указанной ячейки памяти как value. */
int sc_memoryGet(int address, int *value); /* Возвращает значение указанной ячейки памяти в value. */
int sc_memorySave(char *filename); /* Сохраняет содержимое памяти в файл в бинарном виде. */
int sc_memoryLoad(char *filename); /* Загружает из указанного файла содержимое оперативной памяти. */
int sc_regInit(void); /* Инициализирует регистр флагов нулевым значением. */
int sc_regSet(int register, int value); /* Устанавливает значение указанного регистра флагов. */
int sc_regGet(int register, int *value); /* Возвращает значение указанного флага. */
int sc_commandEncode(int command, int operand, int *value); /* Кодирует команду с указанным номером и операндом и помещает результат в value. */
int sc_commandDecode (int value, int *command, int *operand); /* Декодирует значение как команду SC. */

void error_handler(int error); /* Обработчик ошибок. */

#endif