/*
    Symbol	Value
    I		1
    V		5
    X		10
    L		50
    C		100
    D		500
    M		1000
*/
#include <stdio.h>
#include <stdlib.h>

struct int_to_roman {
    int val;
    char *roman;
};
struct int_to_roman ex_table[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
};
char* intToRoman(int num) {
    int i;
    char *buf = (char *)malloc(32);
    memset(buf, 0, 32);
    for(i=0; i<sizeof(ex_table)/sizeof(struct int_to_roman); i++) {
        while(num >= ex_table[i].val) {
            strcat(buf, ex_table[i].roman);
            num -= ex_table[i].val;
        }
    }
    return buf;
}
