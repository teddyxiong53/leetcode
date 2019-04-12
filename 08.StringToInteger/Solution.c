#include <limits.h>
#include <stdio.h>

int myAtoi(char* str) {
    //skip white space
    while(*str == ' ') {
        str ++;
    }
    if(strlen(str) == 0) {
        return 0;
    }
    //check first digit
    if(*str != '+' && *str != '-' && !(*str >= '0' && *str <= '9')) {
        return 0;
    }
    long result = 0;
    int sign = 0;
    if(*str == '-') {
        sign = 1;
        str ++;
    } else if(*str == '+') {
        str ++;
    }

    while(*str) {
        int d = *str;
        if(d >= '0' && d<='9') {
            result *= 10;
            result += d - '0';
            if(result >= INT_MAX || result <= INT_MIN) {
                goto end;
            }
        } else {
            break;
        }
        str ++;
    }
end:
    if(sign) {
        result *= -1;
    }
    if(result >= INT_MAX) {
        result = INT_MAX;
    }
    if(result <= INT_MIN) {
        result = INT_MIN;
    }
    return result;
}

int main()
{

}