#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int cc_count,vector<int> &vis,vector<vector<int>> &ar,vector<int> &cc){

	vis[node] = 1;
	cc[node] = cc_count;

	for(int i = 0; i < ar[node].size(); i++){
		if(vis[ar[node][i]] == 0){
			dfs(ar[node][i],cc_count,vis,ar,cc);
		}
	}
}
int main(){

	int t;
	cin >> t;

	while(t--){

		int n,k;
		cin >> n >> k;

		vector<vector<int>> ar(n+1,vector<int>());
		vector<pair<int,int>> v;
		
        int a,b;
		string s;
		
        while(k--){
			cin >> a >> s >> b;

			if(s == "="){
				ar[a].push_back(b);
				ar[b].push_back(a);
			}
			else{
				v.push_back({a,b});
			}
		}
		bool flag = true;

		vector<int> cc(n+1);
		int cc_count = 0;
		vector<int> vis(n+1,0);

		for(int i = 1; i <= n; i++){

			if(vis[i] == 0){
				cc_count++;
				dfs(i,cc_count,vis,ar,cc);
			}
		}
		for(int i = 0; i < v.size(); i++){

			int a = v[i].first;
			int b = v[i].second;

			if(cc[a] == cc[b]){
				flag = false;
				break;
			}
		}
		if(flag == true){
			cout << "YES" << endl;
		} 
		else{
			cout << "NO" << endl;
 		}
	}
}
