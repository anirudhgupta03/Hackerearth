#include<bits/stdc++.h>
using namespace std;

void dfs(int src, int dis, vector<int> &vis, vector<int> &dist, vector<int> al[]){

    vis[src] = 1;
    dist[src] = dis;

    for(int i = 0; i < al[src].size(); i++){

        int child = al[src][i];
        if(vis[child] == 0){
            dfs(child, dist[src] + 1, vis, dist, al);
        }
    }
}
int main(){

    int n;
    cin >> n;

    int a,b;
    int e = n - 1;

    vector<int> al[n+1];
    
    while(e--){    
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    int q;
    cin >> q;

    int city[q];
    for(int i = 0; i < q; i++){
        cin >> city[i];
    }

    vector<int> dist(n+1);
    vector<int> vis(n+1,0);

    dfs(1,0,vis,dist,al);

    int min_dis = INT_MAX, min_id = INT_MAX;
    for(int i = 0; i < q; i++){

        if(dist[city[i]] < min_dis){
            min_dis = dist[city[i]];
            min_id = city[i];
        }
        else if(dist[city[i]] == min_dis){
            min_id = min(min_id,city[i]);
        }
    }
    cout << min_id << endl;
    return 0;
}
