#include <ctest.h>
#include <MSC_lib.h>

CTEST(MSC_suite, memory_init)
{
    // Given
    const int SIZE = 100;
    int i = 0;

    // When
    sc_memoryInit();

    // Then
    
    const int expected_memory_cell = 0;

    for (i = 0; i < SIZE; i++)
        ASSERT_EQUAL(expected_memory_cell, RAM[i]);
}

CTEST(MSC_suite, memory_set)
{
    // Given
    const int address = 0;
    const int value = 1;
    
    // When
    sc_memorySet(address, value);

    // Then
    const int expected_memory_cell = 1;

    ASSERT_EQUAL(expected_memory_cell, RAM[address]);
}


CTEST(MSC_suite, memory_get)
{
    // Given
    const int address = 0;
    int value = 0;
    
    // When
    sc_memoryGet(address, &value);

    // Then
    const int expected_memory_cell = 1;

    ASSERT_EQUAL(expected_memory_cell, RAM[address]);
}

CTEST(MSC_suite, memory_save)
{
    // Given
    int answer;

    // When
    answer = sc_memorySave("RAM");

    // Then
    const int expected_answer = 0;

    ASSERT_EQUAL(expected_answer, answer);
}

CTEST(MSC_suite, memory_load)
{
    // Given
    int answer;

    // When
    answer = sc_memoryLoad("RAM");

    // Then
    const int expected_answer = 0;
    const int expected_memory_cell = 1;

    ASSERT_EQUAL(expected_answer, answer);
    ASSERT_EQUAL(expected_memory_cell, RAM[0]);
}

CTEST(MSC_suite, flag_init)
{
    // Given

    // When
    sc_regInit();

    // Then
    
    const int expected_register = 0;

    ASSERT_EQUAL(expected_register, reg_flag);
}

CTEST(MSC_suite, register_set)
{
    // Given
    const int regist = 0x8;
    const int value = 1;
    
    // When
    sc_regSet(regist, value);

    // Then
    const int expected_flag = 8;

    ASSERT_EQUAL(expected_flag, reg_flag);
}

CTEST(MSC_suite, register_get)
{
    // Given
    const int regist = 0x8;
    int value = 0;
    
    // When
    sc_regGet(regist, &value);

    // Then
    const int expected_value = 1;

    ASSERT_EQUAL(expected_value, value);
}

CTEST(MSC_suite, encode_test)
{
    // Given
    const int command = 15;
    const int operand = 24;
    int value = 0;


    // When
    sc_commandEncode(command, operand, &value);

    // Then
    const int expected_value = 1944;

    ASSERT_EQUAL(expected_value, value);
}

CTEST(MSC_suite, decode_test)
{
    // Given
    const int value = 1944;
    int command = 0;
    int operand = 0;


    // When
    sc_commandDecode(value, &command, &operand);

    // Then
    const int expected_command = 15;
    const int expected_operand = 24;

    ASSERT_EQUAL(expected_command, command);
    ASSERT_EQUAL(expected_operand, operand);
}