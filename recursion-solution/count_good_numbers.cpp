#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
long long power(long long base, long long exp){
    if(exp == 0) return 1;
    long long half = power(base, exp/2);
    half = (half * half) % MOD;
    if(exp % 2 == 1){
        half = (base * exp) % MOD;
    }
    return half;
}
int countGoodNumbers(int n){
    long long odd = n/2;
    long long even = n - odd;
    long long evenCount = power(5, even);
    long long oddCount = power(4, odd);
    return (evenCount * oddCount) % MOD;
}
int main(){
    cout<<"Please enter the value of n:";
    int n;
    cin>>n;
    int res = countGoodNumbers(n);
    cout<<"Output:"<<res;
    return 0;
}