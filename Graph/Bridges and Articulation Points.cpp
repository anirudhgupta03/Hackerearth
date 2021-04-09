//Finding Articulation Points and Bridges using Tarjan's Algo
//https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> &disc, vector<int> &low, vector<int> &vis, vector<int> al[], vector<pair<int,int>> &bridges, vector<int> &ap, int &timer){

	int children = 0;
	vis[node] = 1;
	disc[node] = low[node] = timer++;

	for(int i = 0; i < al[node].size(); i++){
		
		int child = al[node][i];

		if(child == par) continue;

		if(vis[child] == 1){
			low[node] = min(low[node],disc[child]);
		}
		else{

			dfs(child, node, disc, low, vis, al, bridges, ap, timer);
			children++;
			
			if(low[child] > disc[node]){

				if(child < node){
					bridges.push_back({child,node});
				}
				else{
					bridges.push_back({node,child});
				}
			}

			if(low[child] >= disc[node] && par != -1){
				ap.push_back(node);
			}

			low[node] = min(low[node], low[child]);
		}
	}
	if(par == -1 && children > 1){
		ap.push_back(node);
	}
}
bool cmp(pair<int,int> p1, pair<int,int> p2){

	if(p1.first == p2.first){
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}
int main(){

	int n,m;
	cin >> n >> m;

	vector<int> al[n];
	int a,b;
	while(m--){
		cin >> a >> b;
		al[a].push_back(b);
		al[b].push_back(a);
	}

	vector<int> disc(n);
	vector<int> low(n);
	vector<int> vis(n,0);
	int timer = 0;

	vector<pair<int,int>> bridges;
	vector<int> ap;

	dfs(0,-1,disc,low,vis,al,bridges,ap,timer);

	sort(ap.begin(),ap.end());
	cout << ap.size() << endl;
	for(int i = 0; i < ap.size(); i++){
		cout << ap[i] << " ";
	}
	cout << endl;
	cout << bridges.size() << endl;
	sort(bridges.begin(),bridges.end(),cmp);
	for(int i = 0; i < bridges.size(); i++){
		cout << bridges[i].first << " " << bridges[i].second << endl;
	}
}
