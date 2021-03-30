#include<bits/stdc++.h>
using namespace std;
 
void dfs(int v,vector<int> &vis,vector<vector<int>> &ar){
 
    vis[v] = 1;
    for(int i = 0; i < ar[v].size(); i++){
        if(vis[ar[v][i]] == 0){
            dfs(ar[v][i],vis,ar);
        }
    }
}
int main(){
 
    int n,e;
    cin >> n >> e;
 
    vector<vector<int>> ar(n+1,vector<int>());
    
    while(e--){
        int a,b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
 
    vector<int> vis(n+1,0);
    
    int cc_count = 0;
    
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i,vis,ar);
            cc_count++;
        }
    }
    cout << cc_count << endl;
}
