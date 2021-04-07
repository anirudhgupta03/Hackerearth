#include<bits/stdc++.h>
using namespace std;

int find(int a, int parent[]){

	if(parent[a] < 0){
		return a;
	}
	return parent[a] = find(parent[a],parent);
}
void unionp(int a, int b, int parent[]){

	parent[a] = min(parent[a],parent[b]);
	parent[b] = a;
}
int main(){

	int N,M;
	cin >> N >> M;

	int parent[N+1];

	for(int i = 1; i <= N; i++){
		parent[i] = -1*i;
	}

	int a,b;
	while(M--){

		cin >> a >> b;
		
		a = find(a,parent);
		b = find(b,parent);

		if(a != b){
			unionp(a,b,parent);
		}
	}
	int q;
	cin >> q;

	while(q--){
		cin >> a >> b;

		if(abs(parent[find(a,parent)]) > abs(parent[find(b,parent)])){
			cout << a << endl;
		}
		else if(abs(parent[find(a,parent)]) < abs(parent[find(b,parent)])){
			cout << b << endl;
		}
		else{
			cout << "TIE" << endl;
		}
	}
}
