#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int reverse(int x) {
	long result = 0;
    while(x != 0) {
        result *= 10;
        result += x%10;
        x = x/10;
        if(result > INT_MAX || result < INT_MIN) {
            result = 0;
        }
    }
    return result;
}
int main()
{

}