#include <bits/stdc++.h>

using namespace std;
const int MAX_W = 1e9;
bool can[MAX_W];
int main()
{
    int n,W;
    cin>>n>>W;
    can[0] = true;
    for(int id = 0;id<n;id++){
        int x;
        cin>>x;
        for(int i=W;i>=x;i--){
            if(can[i-x]) can[i] = true;
        }
    }
    puts(can[W]?"yes":"No");
}