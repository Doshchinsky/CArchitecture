#include <ctest.h>
#include <MT_lib.h>

CTEST(MT_suite, clear_screen)
{
// Given
    const int expected_answer = 0;
    int answer;
// When
    answer = mt_clrscr();
// Then
    ASSERT_EQUAL(expected_answer, answer);
}

CTEST(MT_suite, go_to_XY)
{
// Given
    const int expected_answer = 0;
    int answer;
// When
    answer = mt_gotoXY(1, 1);
// Then
    ASSERT_EQUAL(expected_answer, answer);
}


CTEST(MT_suite, get_screensize)
{
// Given
    const int expected_answer = 0;
    int rows, cols;
    int answer;
// When
    answer = mt_getscreensize(&rows, &cols);
// Then
    ASSERT_EQUAL(expected_answer, answer);
}

CTEST(MT_suite, set_fg_color)
{
// Given
    const int expected_answer = 0;
    int answer;
// When
    answer = mt_setfgcolor(black);
// Then
    ASSERT_EQUAL(expected_answer, answer);
}

CTEST(MT_suite, set_bg_color)
{
// Given
    const int expected_answer = 0;
    int answer;
// When
    answer = mt_setbgcolor(white);
// Then
    ASSERT_EQUAL(expected_answer, answer);
}