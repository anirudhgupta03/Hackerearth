#include<bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
 
int main(){
    
        int n,m;
        cin >> n >> m;
        
        vector<pair<int,int>> adj[n+1];
        
        int a,b,w;
        
        while(m--){
            cin >> a >> b >> w;
            adj[a].push_back({b,w});
            //adj[b].push_back({a,w});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        vector<int> parent(n+1);
        vector<int> dist(n+1,INT_MAX);
        vector<int> vis(n+1,0);
        parent[1] = -1;
        pq.push({0,1});
        dist[1] = 0;
        
        while(!pq.empty()){
            
            int curr = pq.top().second;
            int curr_d = pq.top().first;
            
            pq.pop();
            
            if(vis[curr]) continue;
            vis[curr] = 1;
            for(int i = 0; i < adj[curr].size(); i++){
                
                if(curr_d + adj[curr][i].second < dist[adj[curr][i].first]){
                    dist[adj[curr][i].first] = curr_d + adj[curr][i].second;
                    pq.push({dist[adj[curr][i].first],adj[curr][i].first});
                    parent[adj[curr][i].first] = curr;
                }
            }
        }
        for(int i = 2; i <= n; i++){
            cout << dist[i] << " ";
        }
        cout << endl;
}
