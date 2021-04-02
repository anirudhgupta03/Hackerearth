#include<bits/stdc++.h>
using namespace std;

void bfs(int src,vector<int> &vis,vector<int> al[],vector<vector<int>> &dist){

    vis[src] = 1;
    dist[src][src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){

        int curr = q.front();
        q.pop();

        for(int i = 0; i < al[curr].size(); i++){

            int child = al[curr][i];
            if(vis[child] == 0){

                vis[child] = 1;
                dist[src][child] = dist[src][curr] + 1;
                q.push(child);
            }
        }
    }
}
int main(){

    int n,e;
    cin >> n >> e;

    vector<int> al[n];
    int a,b;

    while(e--){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<vector<int>> dist(n,vector<int>(n));

    for(int i = 0; i < n; i++){
        vector<int> vis(n,0);
        bfs(i,vis,al,dist);
    }
    
    int m;
    cin >> m;
    
    int src,dis,count;
    while(m--){
        count = 0;
        cin >> src >> dis;
        for(int i = 0; i < n; i++){
            if(dist[src][i] == dis){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
