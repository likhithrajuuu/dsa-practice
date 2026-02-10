#include <iostream>
using namespace std;
void backtrack(string curr, vector<string>& res, int n){
    if(curr.length() == n){
        res.push_back(curr);
        return;
    }

    backtrack(curr + '0', res, n);
    if(curr.empty() || curr.back() != '1'){
        backtrack(curr + '1', res, n);
    }
}
vector<string> generateBinaryStrings(int n){
    vector<string> res;
    backtrack("", res, n);
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string> res = generateBinaryStrings(n);
    for(auto s : res){
        cout<<s<<" ";
    }
    return 0;
}