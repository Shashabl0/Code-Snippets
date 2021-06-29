#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//  Euclidean algorithm : GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number.

ll gcd(ll a,ll b){
    if(!a)
        return b;
    if(!b)
        return a;

    if(a==b)
        return a;
    
    if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}
int main(){
    ll a = 625,b =125;

    cout<< gcd(a,b)<<endl;
}