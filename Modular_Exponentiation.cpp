#include <iostream>
using namespace std;


const int MOD  = 1e9+7;

// Normal Method Complexity - O(n)
// Complexity - O(logn)
// Modular Exponention
long long int calculatepower(long long int A, long long int B)
{
    if (B == 0)
        return 1;

    else if (B % 2 == 0)
        return calculatepower((A*A) % MOD, B >> 1) % MOD;
    else
        return (A * calculatepower((A*A) % MOD, B >> 1) % MOD );
}

int main()
{
    cout << calculatepower(2, 10);
    return 0;
}