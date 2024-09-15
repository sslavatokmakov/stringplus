#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"

START_TEST(memchr_test) {
        char test_1[] = "012345";
        char test_2 = '5';
        char test_3 = '2';
        char test_4[] = "Hello World";
        char test_5[] = "l";
        char test_6 = ' ';
        char test_7 = 'l';
        char test_8 = 'W';
        char test_9 = 'd';
        ck_assert_uint_eq((unsigned long)my_memchr(test_1, test_2, 6),
        (unsigned long)memchr(test_1, test_2, 6));
        ck_assert_uint_eq((unsigned long)my_memchr(test_1, test_3, 6),
        (unsigned long)memchr(test_1, test_3, 6));
        ck_assert_uint_eq((unsigned long)my_memchr(test_4, test_6, 11),
        (unsigned long)memchr(test_4, test_6, 11));
        ck_assert_uint_eq((unsigned long)my_memchr(test_5, test_6, 1),
        (unsigned long)memchr(test_5, test_6, 1));
        ck_assert_uint_eq((unsigned long)my_memchr(test_4, test_7, 11),
        (unsigned long)memchr(test_4, test_7, 11));
        ck_assert_uint_eq((unsigned long)my_memchr(test_4, test_8, 11),
        (unsigned long)memchr(test_4, test_8, 11));
        ck_assert_uint_eq((unsigned long)my_memchr(test_4, test_9, 11),
        (unsigned long)memchr(test_4, test_9, 11));
}

END_TEST

START_TEST(memcmp_test) {
    char test_1[] = "Hello World";
    char test_2[] = "peace Hello";
    char test_3[] = "wow";
    char test_4[] = "Hello";
    char test_5[] = "Hello";
    ck_assert_uint_eq(my_memcmp(test_1, test_2, 11) < 0,
                      memcmp(test_1, test_2, 11) < 0);
    ck_assert_uint_eq(my_memcmp(test_1, test_3, 3) > 0,
                      memcmp(test_1, test_3, 3) > 0);
    ck_assert_uint_eq(my_memcmp(test_2, test_3, 3) > 0,
                      memcmp(test_2, test_3, 3) > 0);
    ck_assert_uint_eq(my_memcmp(test_4, test_2, 5) > 0,
                      memcmp(test_4, test_2, 5) > 0);
    ck_assert_uint_eq(my_memcmp(test_4, test_5, 5) == 0,
                      memcmp(test_4, test_5, 5) == 0);
}

END_TEST

START_TEST(memcpy_test) {
    char test_1[] = "012345";
    char test_2[] = "  ";
    char test_3[] = "777   ";
    char test_4[] = "   555";
    char test_5[] = "assert";
    char test_6[] = "\0";
    ck_assert_str_eq(my_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
    ck_assert_str_eq(my_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
    ck_assert_str_eq(my_memcpy(test_4, test_3, 3), memcpy(test_4, test_3, 3));
    ck_assert_str_eq(my_memcpy(test_1, test_5, 6), memcpy(test_1, test_5, 6));
    ck_assert_str_eq(my_memcpy(test_5, test_6, 1), memcpy(test_5, test_6, 1));
}

END_TEST

START_TEST(memset_test) {
    unsigned char test_1[10] = "0123456789";
    unsigned char test_2[10] = "Hello";
    ck_assert_uint_eq((unsigned long) my_memset(test_1, '6', 10),
                      (unsigned long) memset(test_1, '6', 10));
    ck_assert_uint_eq((unsigned long) my_memset(test_1, '2', 10),
                      (unsigned long) memset(test_1, '2', 10));
    ck_assert_uint_eq((unsigned long) my_memset(test_1, '0', 1),
                      (unsigned long) memset(test_1, '0', 1));
    ck_assert_uint_eq((unsigned long) my_memset(test_1, '/', 6),
                      (unsigned long) memset(test_1, '/', 6));
    ck_assert_uint_eq((unsigned long) my_memset(test_2, '4', 4),
                      (unsigned long) memset(test_2, '4', 4));
}

END_TEST

START_TEST(strncat_test) {
    char test_1[6] = "<<<\0";
    char test_2[2] = "5";
    char test_3[2] = "5\0";
    char test_4[] = "\0";

    ck_assert_str_eq(my_strncat(test_1, test_2, 1), strncat(test_1, test_2, 1));
    ck_assert_str_eq(my_strncat(test_3, test_4, 0), strncat(test_3, test_4, 0));
}

END_TEST

START_TEST(strchr_test) {
    char str1[] = "dayofmylife";
    int arg1 = 'd';
    ck_assert_str_eq(my_strchr(str1, arg1), strchr(str1, arg1));

    char str2[] = "dayofmylife";
    int arg2 = 'd';
    ck_assert_str_eq(my_strchr(str2, arg2), strchr(str2, arg2));

    char str3[] = "dayofmylife";
    int arg3 = '\0';
    ck_assert_str_eq(my_strchr(str3, arg3), strchr(str3, arg3));

    char str4[] = "dayofmylife";
    int arg4 = 'y';
    ck_assert_str_eq(my_strchr(str4, arg4), strchr(str4, arg4));
}

END_TEST

START_TEST(strncmp_test) {
    char test1[] = "Hello World 1";
    char test2[] = "Hella peace 7";
    ck_assert_int_eq(my_strncmp(test1, test2, 13) < 0,
                     strncmp(test1, test2, 13) < 0);
    ck_assert_int_eq(my_strncmp(test1, test2, 4) == 0,
                     strncmp(test1, test2, 4) == 0);
}

END_TEST

START_TEST(strncpy_test) {
    char src[] = "\0";
    char res[] = "\0";
    char exp[] = "\0";
    size_t n_byte = 0;

    my_strncpy(res, src, n_byte);
    strncpy(exp, src, n_byte);

    ck_assert_str_eq(res, exp);
}

END_TEST

START_TEST(strcspn_test) {
    char test1[] = "01242410";
    char test2[] = "iiiii";
    char test3[] = "//\0\n";
    char test4[] = "vova";
    char test5[] = "77777111111111";
    char test6[] = "77777111111111";
    ck_assert_uint_eq(my_strcspn(test1, test2), strcspn(test1, test2));
    ck_assert_uint_eq(my_strcspn(test2, test3), strcspn(test2, test3));
    ck_assert_uint_eq(my_strcspn(test5, test4), strcspn(test5, test4));
    ck_assert_uint_eq(my_strcspn(test5, test6), strcspn(test5, test6));
    ck_assert_uint_eq(my_strcspn(test4, test3), strcspn(test4, test3));
}

END_TEST

START_TEST(strerror_test) {
    ck_assert_str_eq(my_strerror(0), strerror(0));
    ck_assert_str_eq(my_strerror(107), strerror(107));
    ck_assert_str_eq(my_strerror(-1), strerror(-1));
    ck_assert_str_eq(my_strerror(-100), strerror(-100));
    ck_assert_str_eq(my_strerror(106), strerror(106));
    ck_assert_str_eq(my_strerror(1009), strerror(1009));
}

END_TEST

START_TEST(strlen_test) {
    char *test_1 = malloc(15 * sizeof(char));
    strcpy(test_1, "World");
    ck_assert_int_eq(strlen(test_1), my_strlen(test_1));
    free(test_1);
    char test_2[16] = "hello peace";
    ck_assert_int_eq(strlen(test_2), my_strlen(test_2));
    char test_3[] = "0123345678";
    ck_assert_int_eq(strlen(test_3), my_strlen(test_3));
    char test_4[] = "";
    ck_assert_int_eq(strlen(test_4), my_strlen(test_4));
}

END_TEST

START_TEST(strpbrk_test) {
    char test1[] = "iloveschool21";
    char test2[] = "qwerty";
    ck_assert_str_eq(my_strpbrk(test1, test2), strpbrk(test1, test2));
    ck_assert_uint_eq((unsigned long) my_strpbrk(test1, test2),
                      (unsigned long) strpbrk(test1, test2));
    char *str = "Hello people";
    char *empty = "";
    ck_assert(my_strpbrk(str, empty) == strpbrk(str, empty));
}

END_TEST

START_TEST(strrchr_test) {
    char test1[] = "012345679498465146";
    char test2[] = ";;Hавп.(.%H%%//#)HH";
    char test3[] = "     /      |          \\";
    ck_assert_uint_eq((unsigned long) my_strrchr(test1, '6'),
                      (unsigned long) strrchr(test1, '6'));
    ck_assert_uint_eq((unsigned long) my_strrchr(test1, ' '),
                      (unsigned long) strrchr(test1, ' '));
    ck_assert_uint_eq((unsigned long) my_strrchr(test1, '6'),
                      (unsigned long) strrchr(test1, '6'));
    ck_assert_uint_eq((unsigned long) my_strrchr(test2, 'H'),
                      (unsigned long) strrchr(test2, 'H'));
    ck_assert_uint_eq((unsigned long) my_strrchr(test2, '$'),
                      (unsigned long) strrchr(test2, '$'));
    ck_assert_uint_eq((unsigned long) my_strrchr(test2, ';'),
                      (unsigned long) strrchr(test2, ';'));
    ck_assert_uint_eq((unsigned long) my_strrchr(test3, ' '),
                      (unsigned long) strrchr(test3, ' '));
}

END_TEST

START_TEST(strstr_test) {
    char test_1[] = "===3===";
    char test_2[] = "3";
    char test_3[] = "PeacePeacePeace";
    char test_4[] = "Peace";
    char test_5[] = "atata";
    char test_6[] = "";
    char test_7[] = "fdgh123ghfh1234gfh";
    char test_8[] = "1234";

    ck_assert_ptr_eq(my_strstr(test_1, test_2), strstr(test_1, test_2));
    ck_assert_ptr_eq(my_strstr(test_3, test_4), strstr(test_3, test_4));
    ck_assert_ptr_eq(my_strstr(test_5, test_6), strstr(test_5, test_6));
    ck_assert_ptr_eq(my_strstr(test_4, test_5), strstr(test_4, test_5));
    ck_assert_ptr_eq(my_strstr(test_7, test_8), strstr(test_7, test_8));
}

END_TEST

START_TEST(strtok_test) {
    char str_strtok1[] = "first{second}three/fourth/fifth";
    char delim1[] = "/{}";
    char str_strtok2[] = "first{second}three/fourth/fifth";
    char delim2[] = "/{}";
    char *curr_strtok = my_strtok(str_strtok1, delim1);
    char *origin_strtok = strtok(str_strtok2, delim2);
    while (curr_strtok != NULL) {
        ck_assert_str_eq(curr_strtok, origin_strtok);
        curr_strtok = my_strtok(NULL, delim1);
        origin_strtok = strtok(NULL, delim2);
    }
}

END_TEST

START_TEST(to_upper) {
    char test1[] = "TeLeGrAm";
    char test2[] = "mama";
    char *testup1 = my_to_upper(test1);
    ck_assert_str_eq(testup1, "TELEGRAM");
    char *testup2 = my_to_upper(test2);
    ck_assert_str_eq(testup2, "MAMA");
    char *test3 = NULL;
    char *testup3 = my_to_upper(test3);
    ck_assert_uint_eq((unsigned long) testup3, (unsigned long) test3);
    free(testup1);
    free(testup2);
    free(testup3);
}

END_TEST

START_TEST(to_lower) {
    char test1[] = "TeLeGrAm";
    char test2[] = "MAMA";
    char *test3 = NULL;
    char *testlower1 = my_to_lower(test1);
    ck_assert_str_eq(testlower1, "telegram");
    char *testlower2 = my_to_lower(test2);
    ck_assert_str_eq(testlower2, "mama");
    char *testlower3 = my_to_lower(test3);
    ck_assert_uint_eq((unsigned long) testlower3, (unsigned long) test3);
    free(testlower1);
    free(testlower2);
    free(testlower3);
}

END_TEST

START_TEST(insert) {
    char *src = "school 42";
    char *str = " 21";
    char *test1 = my_insert(src, str, 6);
    if (test1) {
        ck_assert_str_eq(test1, "school 21 42");
        free(test1);
    }

    char *test2 = my_insert(src, "", 40);
    ck_assert(test2 == NULL);
    char *test3 = my_insert(src, str, -1);
    ck_assert(test3 == NULL);
}

END_TEST

START_TEST(trim) {
    char str_trim[] = "townmoscow";

    char test1[] = "town";
    char test2[] = "townmoscow";
    char *trim1 = my_trim(str_trim, test1);
    ck_assert_str_eq(trim1, "mosc");
    char *trim2 = my_trim(str_trim, test2);
    char *trim3 = "";
    ck_assert_uint_eq(strcmp(trim2, trim3), 0);
    free(trim1);
    free(trim2);
}

END_TEST

START_TEST(sprintf_f) {
    char str_f[80] = {'\0'};
    char str_orig_f[80] = {'\0'};

    double b_2 = 0.02345;
    int res_2 = my_sprintf(str_f, "%+-5.3f", b_2);
    int res_2_orig = sprintf(str_orig_f, "%+-5.3f", b_2);
    ck_assert_int_eq(res_2, res_2_orig);
    ck_assert_str_eq(str_f, str_orig_f);

    double b_3 = 13.04;
    int res_3 = my_sprintf(str_f, "%15.5f", b_3);
    int res_3_orig = sprintf(str_orig_f, "%15.5f", b_3);
    ck_assert_int_eq(res_3, res_3_orig);
    ck_assert_str_eq(str_f, str_orig_f);
    double b_4 = 5.6;
    int res_4 = my_sprintf(str_f, "%+3.5f", b_4);
    int res_4_orig = sprintf(str_orig_f, "%+3.5f", b_4);
    ck_assert_int_eq(res_4, res_4_orig);
    ck_assert_str_eq(str_f, str_orig_f);

    double b_5 = 9.6;
    int res_5 = my_sprintf(str_f, "%-3.5f", b_5);
    int res_5_orig = sprintf(str_orig_f, "%-3.5f", b_5);
    ck_assert_int_eq(res_5, res_5_orig);
    ck_assert_str_eq(str_f, str_orig_f);
}

END_TEST

START_TEST(sprintf_d) {
    char str[256] = {'\0'};
    char str_orig[256] = {'\0'};
    int d = 256;

    int res_1 = my_sprintf(str, "%.5d", d);
    int res_1_orig = sprintf(str_orig, "%.5d", d);
    ck_assert_int_eq(res_1, res_1_orig);
    ck_assert_str_eq(str, str_orig);

    int res_2 = my_sprintf(str, "%10.5d", d);
    int res_2_orig = sprintf(str_orig, "%10.5d", d);
    ck_assert_int_eq(res_2, res_2_orig);
    ck_assert_str_eq(str, str_orig);

    int res_3 = my_sprintf(str, "% 10.5d", d);
    int res_3_orig = sprintf(str_orig, "% 10.5d", d);
    ck_assert_int_eq(res_3, res_3_orig);
    ck_assert_str_eq(str, str_orig);

    int res_4 = my_sprintf(str, "%3.5d", d);
    int res_4_orig = sprintf(str_orig, "%3.5d", d);
    ck_assert_int_eq(res_4, res_4_orig);
    ck_assert_str_eq(str, str_orig);

    int res_5 = my_sprintf(str, "%d", d);
    int res_5_orig = sprintf(str_orig, "%d", d);
    ck_assert_int_eq(res_5, res_5_orig);
    ck_assert_str_eq(str, str_orig);

    int res_6 = my_sprintf(str, "%-d", d);
    int res_6_orig = sprintf(str_orig, "%-d", d);
    ck_assert_int_eq(res_6, res_6_orig);
    ck_assert_str_eq(str, str_orig);

    int res_7 = my_sprintf(str, "%+d", d);
    int res_7_orig = sprintf(str_orig, "%+d", d);
    ck_assert_int_eq(res_7, res_7_orig);
    ck_assert_str_eq(str, str_orig);

    int res_8 = my_sprintf(str, "% d", d);
    int res_8_orig = sprintf(str_orig, "% d", d);
    ck_assert_int_eq(res_8, res_8_orig);
    ck_assert_str_eq(str, str_orig);

    int res_9 = my_sprintf(str, "%5d", d);
    int res_9_orig = sprintf(str_orig, "%5d", d);
    ck_assert_int_eq(res_9, res_9_orig);
    ck_assert_str_eq(str, str_orig);

    int res_10 = my_sprintf(str, "%-5d", d);
    int res_10_orig = sprintf(str_orig, "%-5d", d);
    ck_assert_int_eq(res_10, res_10_orig);
    ck_assert_str_eq(str, str_orig);

    int res_11 = my_sprintf(str, "%+5d", d);
    int res_11_orig = sprintf(str_orig, "%+5d", d);
    ck_assert_int_eq(res_11, res_11_orig);
    ck_assert_str_eq(str, str_orig);

    int res_12 = my_sprintf(str, "% 5d", d);
    int res_12_orig = sprintf(str_orig, "% 5d", d);
    ck_assert_int_eq(res_12, res_12_orig);
    ck_assert_str_eq(str, str_orig);

    int res_13 = my_sprintf(str, "%0d", d);
    int res_13_orig = sprintf(str_orig, "%0d", d);
    ck_assert_int_eq(res_13, res_13_orig);
    ck_assert_str_eq(str, str_orig);
}

END_TEST

START_TEST(sprintf_c) {
    char str[256] = {'\0'};
    char str_orig[256] = {'\0'};
    char C = 'C';

    int res_1 = my_sprintf(str, "%-2c", C);
    int res_1_orig = sprintf(str_orig, "%-2c", C);
    ck_assert_int_eq(res_1, res_1_orig);
    ck_assert_str_eq(str, str_orig);

    int res_2 = my_sprintf(str, "%-c", C);
    int res_2_orig = sprintf(str_orig, "%-c", C);
    ck_assert_int_eq(res_2, res_2_orig);
    ck_assert_str_eq(str, str_orig);

    int res_4 = my_sprintf(str, "%10c", C);
    int res_4_orig = sprintf(str_orig, "%10c", C);
    ck_assert_int_eq(res_4, res_4_orig);
    ck_assert_str_eq(str, str_orig);

    int res_5 = my_sprintf(str, "%c", C);
    int res_5_orig = sprintf(str_orig, "%c", C);
    ck_assert_int_eq(res_5, res_5_orig);
    ck_assert_str_eq(str, str_orig);
}

END_TEST

START_TEST(sprintf_s) {
    char str[256] = {'\0'};
    char str_orig[256] = {'\0'};
    char *A = "Farhad";

    int res_1 = my_sprintf(str, "%s", A);
    int res_1_orig = sprintf(str_orig, "%s", A);
    ck_assert_int_eq(res_1, res_1_orig);
    ck_assert_str_eq(str, str_orig);

    int res_2 = my_sprintf(str, "%-s", A);
    int res_2_orig = sprintf(str_orig, "%-s", A);
    ck_assert_int_eq(res_2, res_2_orig);
    ck_assert_str_eq(str, str_orig);

    int res_4 = my_sprintf(str, "%10s", A);
    int res_4_orig = sprintf(str_orig, "%10s", A);
    ck_assert_int_eq(res_4, res_4_orig);
    ck_assert_str_eq(str, str_orig);

    int res_5 = my_sprintf(str, "%.5s", A);
    int res_5_orig = sprintf(str_orig, "%.5s", A);
    ck_assert_int_eq(res_5, res_5_orig);
    ck_assert_str_eq(str, str_orig);

    int res_6 = my_sprintf(str, "%-10s", A);
    int res_6_orig = sprintf(str_orig, "%-10s", A);
    ck_assert_int_eq(res_6, res_6_orig);
    ck_assert_str_eq(str, str_orig);
}

END_TEST

START_TEST(sprintf_ld) {
    char str[256] = {'\0'};
    char str_orig[256] = {'\0'};
    long int d = 1504289465718;

    int res_1 = my_sprintf(str, "%10.5ld", d);
    int res_1_orig = sprintf(str_orig, "%10.5ld", d);
    ck_assert_int_eq(res_1, res_1_orig);
    ck_assert_str_eq(str, str_orig);

    int res_2 = my_sprintf(str, "% 10.5ld", d);
    int res_2_orig = sprintf(str_orig, "% 10.5ld", d);
    ck_assert_int_eq(res_2, res_2_orig);
    ck_assert_str_eq(str, str_orig);

    int res_3 = my_sprintf(str, "%3.5ld", d);
    int res_3_orig = sprintf(str_orig, "%3.5ld", d);
    ck_assert_int_eq(res_3, res_3_orig);
    ck_assert_str_eq(str, str_orig);

    int res_4 = my_sprintf(str, "%ld", d);
    int res_4_orig = sprintf(str_orig, "%ld", d);
    ck_assert_int_eq(res_4, res_4_orig);
    ck_assert_str_eq(str, str_orig);

    int res_6 = my_sprintf(str, "%-ld", d);
    int res_6_orig = sprintf(str_orig, "%-ld", d);
    ck_assert_int_eq(res_6, res_6_orig);
    ck_assert_str_eq(str, str_orig);

    int res_7 = my_sprintf(str, "%+ld", d);
    int res_7_orig = sprintf(str_orig, "%+ld", d);
    ck_assert_int_eq(res_7, res_7_orig);
    ck_assert_str_eq(str, str_orig);

    int res_8 = my_sprintf(str, "% ld", d);
    int res_8_orig = sprintf(str_orig, "% ld", d);
    ck_assert_int_eq(res_8, res_8_orig);
    ck_assert_str_eq(str, str_orig);

    int res_9 = my_sprintf(str, "%5ld", d);
    int res_9_orig = sprintf(str_orig, "%5ld", d);
    ck_assert_int_eq(res_9, res_9_orig);
    ck_assert_str_eq(str, str_orig);

    int res_10 = my_sprintf(str, "%-5ld", d);
    int res_10_orig = sprintf(str_orig, "%-5ld", d);
    ck_assert_int_eq(res_10, res_10_orig);
    ck_assert_str_eq(str, str_orig);

    int res_11 = my_sprintf(str, "%+5ld", d);
    int res_11_orig = sprintf(str_orig, "%+5ld", d);
    ck_assert_int_eq(res_11, res_11_orig);
    ck_assert_str_eq(str, str_orig);

    int res_12 = my_sprintf(str, "% 5ld", d);
    int res_12_orig = sprintf(str_orig, "% 5ld", d);
    ck_assert_int_eq(res_12, res_12_orig);
    ck_assert_str_eq(str, str_orig);

    int res_13 = my_sprintf(str, "%.5ld", d);
    int res_13_orig = sprintf(str_orig, "%.5ld", d);
    ck_assert_int_eq(res_13, res_13_orig);
    ck_assert_str_eq(str, str_orig);
}

END_TEST

START_TEST(sprintf_u) {
    char str[256] = {'\0'};
    char str_orig[256] = {'\0'};
    unsigned int u = 134;

    int res_1 = my_sprintf(str, "%10.5u", u);
    int res_1_orig = sprintf(str_orig, "%10.5u", u);
    ck_assert_int_eq(res_1, res_1_orig);
    ck_assert_str_eq(str, str_orig);

    int res_2 = my_sprintf(str, "%-10.5u", u);
    int res_2_orig = sprintf(str_orig, "%-10.5u", u);
    ck_assert_int_eq(res_2, res_2_orig);
    ck_assert_str_eq(str, str_orig);

    int res_3 = my_sprintf(str, "%3.5u", u);
    int res_3_orig = sprintf(str_orig, "%3.5u", u);
    ck_assert_int_eq(res_3, res_3_orig);
    ck_assert_str_eq(str, str_orig);

    int res_4 = my_sprintf(str, "%u", u);
    int res_4_orig = sprintf(str_orig, "%u", u);
    ck_assert_int_eq(res_4, res_4_orig);
    ck_assert_str_eq(str, str_orig);

    int res_6 = my_sprintf(str, "%u", u);
    int res_6_orig = sprintf(str_orig, "%u", u);
    ck_assert_int_eq(res_6, res_6_orig);
    ck_assert_str_eq(str, str_orig);

    int res_9 = my_sprintf(str, "%5u", u);
    int res_9_orig = sprintf(str_orig, "%5u", u);
    ck_assert_int_eq(res_9, res_9_orig);
    ck_assert_str_eq(str, str_orig);

    int res_10 = my_sprintf(str, "%-5u", u);
    int res_10_orig = sprintf(str_orig, "%-5u", u);
    ck_assert_int_eq(res_10, res_10_orig);
    ck_assert_str_eq(str, str_orig);

    int res_12 = my_sprintf(str, "%10.5u", u);
    int res_12_orig = sprintf(str_orig, "%10.5u", u);
    ck_assert_int_eq(res_12, res_12_orig);
    ck_assert_str_eq(str, str_orig);

    int res_13 = my_sprintf(str, "%.5u", u);
    int res_13_orig = sprintf(str_orig, "%.5u", u);
    ck_assert_int_eq(res_13, res_13_orig);
    ck_assert_str_eq(str, str_orig);
}

END_TEST

START_TEST(sprintf_all) {
    char str_all[200] = {'\0'};
    char str_orig_all[200] = {'\0'};
    char s[] = "Minnehanov\0";
    char s2[] = "captaink\0";
    short int d = 11954;
    long int d2 = 12345678915498;
    int d3 = -190;
    unsigned short int us = 10843;
    unsigned long int ul = 5987631580;
    char c = 'A';
    float f = 1.0002;
    float f2 = -356;
    float f3 = 1.0;
    const char format[15000] =
            "1234 x %+-5.3hd x %+-20.15ld x % 10.6d x %-5s x %-10.3s x %-5.7hu x "
            "%-10.2lu x %-5lc x %c x % -5.2f x %10.5f x %.f x %10f";
    int res_1 = my_sprintf(str_all, format, d, d2, d3, s, s2, us, ul, c, c, f,
                           f2, f3, f3);
    int res_1_orig = sprintf(str_orig_all, format, d, d2, d3, s, s2, us, ul, c, c,
                             f, f2, f3, f3);
    ck_assert_int_eq(res_1, res_1_orig);
    ck_assert_int_eq(strcmp(str_all, str_orig_all), 0);
}

END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, sprintf_all);
    tcase_add_test(tc1_1, sprintf_f);
    tcase_add_test(tc1_1, memchr_test);
    tcase_add_test(tc1_1, memcmp_test);
    tcase_add_test(tc1_1, memcpy_test);
    tcase_add_test(tc1_1, memset_test);
    tcase_add_test(tc1_1, strncat_test);
    tcase_add_test(tc1_1, strchr_test);
    tcase_add_test(tc1_1, strncmp_test);
    tcase_add_test(tc1_1, strncpy_test);
    tcase_add_test(tc1_1, strcspn_test);
    tcase_add_test(tc1_1, strerror_test);
    tcase_add_test(tc1_1, strlen_test);
    tcase_add_test(tc1_1, strpbrk_test);
    tcase_add_test(tc1_1, strrchr_test);
    tcase_add_test(tc1_1, strstr_test);
    tcase_add_test(tc1_1, strtok_test);
    tcase_add_test(tc1_1, to_upper);
    tcase_add_test(tc1_1, to_lower);
    tcase_add_test(tc1_1, insert);
    tcase_add_test(tc1_1, trim);
    tcase_add_test(tc1_1, sprintf_d);
    tcase_add_test(tc1_1, sprintf_c);
    tcase_add_test(tc1_1, sprintf_s);
    tcase_add_test(tc1_1, sprintf_ld);
    tcase_add_test(tc1_1, sprintf_u);

    srunner_run_all(sr, CK_ENV);
    srunner_set_fork_status(sr, CK_NOFORK);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
