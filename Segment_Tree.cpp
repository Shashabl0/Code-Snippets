#include<bits/stdc++.h>

using namespace std;
using ll = long long;


const int MAXN = 1e5+5;
const int N = 1e5 + 5;

void default_out(){
    #ifndef ONLINE_JUDGE
        freopen("fi.txt","r",stdin);
        freopen("fo.txt","w",stdout);
    #else
    #endif
}


int t[4*MAXN];        //define arr

int initST(vector<int> arr,int v,int tl,int tr){       //building tree
    if(tl==tr){
        t[v] = arr[tl];
        return arr[tl];
    }

    int tm = tl+(tr-tl)/2;
    t[v] = initST(arr,v*2+1,tl,tm) + initST(arr,v*2+2,tm+1,tr);
    return t[v];
}
void initST_1(vector<int> a, int v, int tl, int tr) {   // another approach to building tree
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        initST_1(a, v*2+1, tl, tm);
        initST_1(a, v*2+2, tm+1, tr);
        t[v] = t[v*2+1] + t[v*2+2];
    }
}
int sumST(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sumST(v*2+1, tl, tm, l, min(r, tm))+ sumST(v*2+2, tm+1, tr, max(l, tm+1), r);
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
        t[v] = t[v*2+1] + t[v*2+2];
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
    cout<<"Sum "<<sumST(0,0,n-1,1,3)<<endl;  //for range [1..3]
    /*
    cout<<"t peek :"
    for(int i=0;i<2*n+3;i++)    cout<<t[i]<<" ";
    cout<<endl;
    */
    updateST(0,0,n-1,5,39);
    cout<<"sum of value After update"<<endl;
    for(int i=0;i<2*n+3;i++)    cout<<t[i]<<" ";
    cout<<endl;
    return 0;
}