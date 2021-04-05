#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool isValid(int x, int y, vector<vector<int>> &jungle, vector<vector<int>> &vis){
    int n = jungle.size();
    if(x < 0 || x >= n || y < 0 || y >= n){
        return false;
    }

    if(vis[x][y] == 1 || jungle[x][y] == 'T'){
        return false;
    }

    return true;
}
void bfs(int sx,int sy,vector<vector<int>> &jungle,vector<vector<int>> &vis,vector<vector<int>> &dist){

    vis[sx][sy] = 1;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dist[sx][sy] = 0;

    while(!q.empty()){

        int currx = q.front().first;
        int curry = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(isValid(currx + dx[i],curry + dy[i],jungle,vis)){
                dist[currx + dx[i]][curry + dy[i]] = dist[currx][curry] + 1;
                vis[currx + dx[i]][curry + dy[i]] = 1;
                q.push({currx + dx[i],curry + dy[i]});
            }
        }
    }
}
int main(){

    int n;
    cin >> n;

    vector<vector<int>> jungle(n,vector<int>(n));

    int sx,sy,ex,ey;
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            jungle[i][j] = c;
            if(c == 'S'){
                sx = i;
                sy = j;
            }
            if(c == 'E'){
                ex = i;
                ey = j;
            }
        }
    }

    vector<vector<int>> dist(n,vector<int>(n));
    vector<vector<int>> vis(n,vector<int>(n,0));

    bfs(sx,sy,jungle,vis,dist);

    cout << dist[ex][ey] << endl; 
}
