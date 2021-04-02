//SSSP in graph using BFS
#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> &dist, vector<vector<int>> &ar, vector<int> &vis){

    vis[src] = 1;
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < ar[curr].size(); i++){

            if(vis[ar[curr][i]] == 0){
                q.push(ar[curr][i]);
                dist[ar[curr][i]] = dist[curr] + 1;
                vis[ar[curr][i]] = 1;
            }
        }
    }
}
int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> ar(n+1,vector<int>());
        int a,b;
        while(m--){
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        vector<int> dist(n+1,0);
        vector<int> vis(n+1,0);
        
        bfs(1, dist, ar, vis);

        cout << dist[n] << endl;
    }
    return 0;
}
