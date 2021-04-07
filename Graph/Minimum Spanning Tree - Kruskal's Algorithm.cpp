#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2){

    return p1.second < p2.second;

}

int find(int a, int parent[]){
    
    if(parent[a] < 0){
        return a;
    }
    return parent[a] = find(parent[a],parent);
}

void unionp(int a, int b, int parent[]){
    parent[b] = a;
}
int main(){

    int n,m;
    cin >> n >> m;

    int parent[n+1];

    for(int i = 1; i <= n; i++){
        parent[i] = -1;
    }
    vector<pair<pair<int,int>,int>> v;

    int a,b,w;

    pair<int,int> p;

    while(m--){
        cin >> a >> b >> w;
        p = {a,b};
        v.push_back({p,w});
    }

    sort(v.begin(),v.end(),cmp);

    
    int count = 0, wt = 0;

    for(int i = 0; i < v.size(); i++){
    
        
        a = find(v[i].first.first, parent);
        b = find(v[i].first.second, parent);
       
        if(a != b){
            unionp(a,b, parent);
            count++;
            wt += v[i].second;
        }
        if(count == n - 1){
            break;
        }
    }
    cout << wt << endl;
}
