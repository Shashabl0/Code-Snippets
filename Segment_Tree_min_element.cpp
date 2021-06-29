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


int initST(vector<int> arr, int v, int tl, int tr) {   // modified segment tree- minimum queries
    if (tl == tr) 
    { 
        t[v] = arr[tl]; 
        return arr[tl]; 
    } 
    int mid = tl- (tl-tr)/2; 
    t[v] = min(initST(arr, v*2+1, tl, mid),initST(arr,v*2+2, mid+1, tr));   //min for min element
    return t[v]; 
}
int RMQ(int v, int tl, int tr, int l, int r) {                  // diff than max element
    if (l <= tl && r >= tr)
        return t[v];
    if(tr<l || tl > r)
        return INT_MAX;
    int tm = (tl + tr) / 2;
    return min(RMQ(v*2+1, tl, tm, l, min(r, tm)),RMQ(v*2+2, tm+1, tr, max(l, tm+1), r));
}
void updateST( int v,int tl,int tr,int pos,int new_val){
    if(tl ==tr)
        t[v] = new_val;
    else{
        int tm = tl-(tl - tr)/2;
        if(pos <= tm)
            updateST(v*2+1,tl,tm,pos,new_val);
        else
            updateST(v*2+2,tm+1,tr,pos,new_val);
        t[v] = min(t[v*2+1],t[v*2+2]);                      // min for min element after update
    }
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
    
    cout<<"low in range 1..3 : "<<RMQ(0,0,n-1,1,3)<<endl;  //for range [1..3]
    
    cout<<"t peek :";
    for(int i=0;i<2*n+3;i++)    cout<<t[i]<<" ";
    cout<<endl;
    
    updateST(0,0,n-1,5,39);


    cout<<"sum of value After update"<<endl;
    for(int i=0;i<2*n+3;i++)    cout<<t[i]<<" ";
    cout<<endl;
    return 0;
}