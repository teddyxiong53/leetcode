#include <stdio.h>

int * twoSum(int *sums, int numSize, int target)
{
    int *a = sums;
    int i,j;
    static int result[2] = {-1,-1};
    for(i=0; i<numSize-1; i++) {
        for(j=i+1; j<numSize; j++) {
            if(a[i]+a[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int sums[5] = {2,3,8,7,9};
    int *ret = twoSum(sums, 5, 16);
    printf("[%d][%d]\n", ret[0], ret[1]);
    return 0;
}

