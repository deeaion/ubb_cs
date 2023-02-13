/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *returnpozitions=(int *)malloc(sizeof(int)*2);
    int i,j;
    i=0;
    j=i+1;
    while(i<numsSize)
    {while(j<numsSize)
      {if(nums[i]+nums[j]==target)
               {
                returnpozitions[0]=i;
                returnpozitions[1]=j;
                return returnpozitions;}
       j++;}
     i++; 
     j=i+1;}  
     returnpozitions[0]=-1;
     returnpozitions[1]=-1;
    return returnpozitions;
}