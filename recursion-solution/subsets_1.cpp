#include <iostream>
using namespace std;
void backtrack(int ind, int currSum, vector<int>& nums, vector<int>& res){
    if(ind == nums.size()){
        res.push_back(currSum);
        return;
    }

    backtrack(ind+1, currSum + nums[ind], nums, res);
    backtrack(ind+1, currSum, nums, res);
}
vector<int> subsetNums(vector<int>& nums){
    vector<int> res;
    backtrack(0, 0, nums, res);
    sort(res.begin(), res.end());
    return res;
}
int main(){
    vector<int> nums = {2, 3};
    vector<int> res = subsetNums(nums);
    for(auto r : res){
        cout<<r<<" ";
    }
    return 0;
}