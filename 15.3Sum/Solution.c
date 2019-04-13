typedef int Row[3];

int** threeSum(int* nums, int numsSize, int* returnSize) {
    Row rows[];
    int i,j,k;
    for(i=0; i<numsSize-2; i++) {
        for(j=i+1; j<numsSize-1; j++) {
            for(k=j+1; k<numsSize; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {

                }
            }
        }
    }
}