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
int romanToInt(char* s) {
    char *p = s;
    int num = 0;
    int i = 0;
    int sz = sizeof(ex_table)/sizeof(struct int_to_roman);
    int idx = 0;
    while(*p) {
        for(i=idx; i<sz; i++) {
            int len = strlen(ex_table[i].roman);
            if(strncmp(p, ex_table[i].roman, len) == 0) {
                num += ex_table[i].val;
                p += len;
                idx = i;
                break;
            }
        }

    }
    return num;
}

int main()
{
    printf("result:%d\n", romanToInt("CMLII"));
}