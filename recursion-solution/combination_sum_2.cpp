#include <iostream>
using namespace std;
void backtrack(int ind, vector<int> curr, vector<vector<int>>& res, vector<int>& candidates, int target){
    if(target == 0){
        res.push_back(curr);
        return;
    }
    
    for(int i = ind;i<candidates.size();i++){
        if(i>ind && candidates[i] == candidates[i-1]) continue;
        if(candidates[i] > target) break;
        curr.push_back(candidates[i]);
        backtrack(i+1, curr, res, candidates, target - candidates[i]);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    backtrack(0, curr, res, candidates, target);
    return res;
}
int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
    for (const auto& comb : res) {
        cout << "[";
        for (int i = 0; i < (int)comb.size(); i++) {
            if (i) cout << " ";
            cout << comb[i];
        }
        cout << "]\n";
    }
    return 0;
}