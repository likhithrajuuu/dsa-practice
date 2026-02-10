#include <iostream>
using namespace std;
void backtrack(int ind, int currSum, vector<int> curr, vector<vector<int>>& res, vector<int>& candidates, int target){
    if(currSum == target){
        res.push_back(curr);
        return;
    }

    if(currSum < 0 || ind >= candidates.size()) return;

    curr.push_back(candidates[ind]);
    backtrack(ind, currSum + candidates[ind], curr, res, candidates, target);
    curr.pop_back();
    backtrack(ind+1, currSum, curr, res, candidates, target);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(0, 0, curr, res, candidates, target);
    return res;
}
int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    return 0;
}