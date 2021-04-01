#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> al[], vector<int> &vis){

    vis[node] = 1;

    for(int i = 0; i < al[node].size(); i++){

        int child = al[node][i];
        if(vis[child] == 0){
            dfs(child, al, vis);
        }
    }
}
int main(){

    int n,e;
    cin >> n >> e;

    vector<int> al[n+1];

    int a,b;
    while(e--){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    int cc_count = 0;
    for(int i = 1; i <= n; i++){

        if(vis[i] == 0){
            cc_count++;
            dfs(i,al,vis);
        }
    }

    cout << cc_count << endl;
}
