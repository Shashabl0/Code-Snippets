#include <iostream>
using namespace std;

typedef long long ll;
const int MOD  = 1e9+7;

// Normal Method Complexity - O(m)
// Complexity - O(logm)
// Modular Exponention
long long gcdExtended(long long  a, long long  b, long long * x, long long * y)
{
     
    // Base Case
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    } 
    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

long long modInverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    if(g==1){
        ll res = (x % m + m) % m;       // m is added to handle negative x
        return res;
    }
    else 
        return -1;      //inverse doesnt exists
}

int main()
{
    cout << modInverse(2, 10);
    return 0;
}