#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//Multiplicative Primes are the primes such that the product of their digits is also a prime
ll digitProduct(ll n){
    ll p = 1;
    while(n){
        p *= n%10;
        n/=10;
    }
    return p;
}
void printMultiplicativePrime(ll n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;

    for(int p =2;p*p <= n;p++){
        if(prime[p]){
            for(int i=p*2;i<=n;i+=p){
                prime[i]= false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i] && prime[digitProduct(i)])
            cout<<i<<" ";
    }
}
int main(){
    ll n =10;
    printMultiplicativePrime(n);
    return 0;
}