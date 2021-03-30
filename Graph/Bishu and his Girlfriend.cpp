#include<bits/stdc++.h>
using namespace std;

void dfs(int v,int dis,vector<int> &dist,vector<int> &vis,vector<vector<int>> &ar){

    vis[v] = 1;
    dist[v] = dis;

    for(int i = 0; i < ar[v].size(); i++){
        if(vis[ar[v][i]] == 0){
            dfs(ar[v][i],dist[v]+1,dist,vis,ar);
        }
    }
}
int main(){

    int n;
    cin >> n;

    vector<vector<int>> ar(n+1,vector<int>());

    for(int i = 1; i <= n - 1; i++){
        int a,b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    } 

    int q;
    cin >> q;
    int city[q];

    for(int i = 0; i < q; i++){
        cin >> city[i];
    }

    vector<int> dist(n+1,0);
    vector<int> vis(n+1,0);

    dfs(1,0,dist,vis,ar);

    int min_id = INT_MAX,min_dist = INT_MAX;
    for(int i = 0; i < q; i++){

        if(dist[city[i]] < min_dist){
            min_dist = dist[city[i]];
            min_id = city[i];
        }
        else if(dist[city[i]] == min_dist){
            if(city[i] < min_id){
                min_id = city[i];
            }
        }
    }
    cout << min_id << endl;
    return 0;
}
