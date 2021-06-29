#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int N = 3e5+5;

vector<ll> adj[N];
void addEdge(){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void R_bfs(queue<int> &q,vector<bool> &d){
    if (q.empty()){
        return;
    }
    int v = q.front();
    q.pop();
    cout << v << " ";
    for (int u: adj[v]){
        if (!d[u]){
            d[u] = true;
            q.push(u);
        }
    }
    R_bfs(q, d);
}

void displayGraph(int size){
    for(int i=0;i<size;i++){
		cout<<i<<" -> ";
		for(auto it:adj[i])
			cout<<it<<" ";
		cout<<endl;
	}
}
int main(){
    int n = 5;
    vector<bool> d(N,0);
    for(int i=0;i<n;i++)	vector<ll>().swap(adj[i]);
    

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (d[i] == false)
        {
            // mark the source vertex as discovered
            d[i] = true;
 
            // enqueue source vertex
            q.push(i);
 
            // start BFS traversal from vertex `i`
            R_bfs(q, d);
        }
    }
    return 0;
}
