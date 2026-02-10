#include <iostream>
using namespace std;
int backtrack(int ind, vector<int>& nums, int sum){
    if(sum == 0) return 1;
    if(sum < 0 || ind >= nums.size()) return 0;
    return backtrack(ind+1, nums, sum - nums[ind]) + backtrack(ind +1, nums, sum);
}
int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    return backtrack(0, nums, k);
}
int main(){
    vector<int> nums = {4,9,2,5,1};
    int k = 10;
    cout<<countSubsequenceWithTargetSum(nums, k);
    return 0;
}