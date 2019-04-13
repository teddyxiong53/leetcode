#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    #define LEN 1024*1024

    char *result = (char *)malloc(LEN);
    memset(result, 0, LEN);
    if(strsSize == 0) {
        strcpy(result, "");
        return result;
    }
    if(strsSize == 1) {
        return strs[0];
    }
    char *s0 = strs[0];
    char *s1 = strs[1];
    int len = 0;
    while(*s0 && *s1) {
        if(*s0 == *s1) {
            len ++;
        } else {
            break;
        }
        s0++;
        s1++;
    }
    if(len == 0) {
        strcpy(result, "");
        return result;
    }
    char *common = (char *)malloc(LEN);
    memset(common, 0, LEN);
    strncpy(common, strs[0], len);
    int i= 2;
    for(i=2; i<strsSize; i++) {
        for(;;) {
            if(strncmp(common, strs[i], len) == 0) {
                break;
            } else {
                len --;
            }
            if(len == 0) {
                goto end;
            }
        }
    }
    strncpy(result, common, len);
    return result;
end:
    strcpy(result, "");
    return result;
}

char *strs[] = {
    "flower","flow","flight"
};

int main()
{
    printf("%s\n", longestCommonPrefix(strs, 3));
}