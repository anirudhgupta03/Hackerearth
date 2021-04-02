#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int cc_count, vector<int> &vis, vector<int> &cc, vector<int> al[]){

	vis[node] = 1;
	cc[node] = cc_count;

	for(int i = 0; i < al[node].size(); i++){
		int child = al[node][i];

		if(vis[child] == 0){
			dfs(child, cc_count, vis, cc, al);
		}
	}
}
int main(){

	int t;
	cin >> t;

	while(t--){

		int n,k;
		cin >> n >> k;

		int a,b;
		string s;

		vector<int> al[n+1];

		vector<pair<int,int>> v;

		while(k--){
			cin >> a >> s >> b;
			
			if(s == "="){
				al[a].push_back(b);
				al[b].push_back(a);
			}
			else{
				v.push_back({a,b});
			}
		}

		vector<int> cc(n+1);
		int cc_count = 0;
		vector<int> vis(n+1,0);

		for(int i = 1; i <= n; i++){

			if(vis[i] == 0){
				cc_count++;
				dfs(i, cc_count, vis, cc, al);
			}
		}
		bool flag = true;
		for(int i = 0; i < v.size(); i++){
			
			int a = v[i].first;
			int b = v[i].second;

			if(cc[a] == cc[b]){
				flag = false;
			}
		}

		if(flag){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}
