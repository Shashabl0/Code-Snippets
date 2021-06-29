#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAXN = 1e5+5;
const int N = 1e5 + 5;
int t[4*MAXN];        //define arr


void default_out(){
    #ifndef ONLINE_JUDGE
        freopen("fi.txt","r",stdin);
        freopen("fo.txt","w",stdout);
    #else
    #endif
}

void initST(vector<int> arr, int v, int tl, int tr) {   // modified segment tree- maximum queries
    if (tl == tr) { 
        if(arr[tl]==0)
            t[v] = 1;
        else
            t[v] = 0;
    }
    else{
        int mid = tl- (tl-tr)/2; 
        initST(arr,v*2+1, tl, mid);
        initST(arr,v*2+2, mid+1, tr);
        t[v] = t[v*2+1] + t[2*v+2];
    }
}

int find_kth(int v, int tl, int tr, int k) {
    if (k > t[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[v*2+1] >= k)
        return find_kth(v*2+1, tl, tm, k);
    else 
        return find_kth(v*2+2, tm+1, tr, k - t[v*2+1]);
}
int main(){
    default_out();
    int n =0;
    cin>>n;
    vector<int> arr(n);
    for(auto &it:arr)    cin>>it;
    // input
    /*
    6
    1 3 5 7 9 11
    */
    initST(arr,0,0,n-1);
    
    cout<<"kth zero : "<<find_kth(0,0,n-1,2)<<endl;  // kth zero
    
    cout<<"t peek :";
    for(int i=0;i<2*n+3;i++)    cout<<t[i]<<" ";
    cout<<endl;
    
    return 0;
}