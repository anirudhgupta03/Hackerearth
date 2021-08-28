#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main(){

    ll t;
    cin >> t;

    while(t--){

        ll n,q;
        cin >> n >> q;

        vector<pair<ll,ll>> v;

        for(int i = 0; i < n; i++){
            ll x,y;
            cin >> x >> y;
            v.push_back({x,y});
        }

        sort(v.begin(),v.end());
        ll idx = 0;

        for(int i = 1; i < v.size(); i++){
            if(v[idx].second >= v[i].first){
                v[idx].second = max(v[idx].second,v[i].second);
            }
            else{
                idx++;  
                v[idx] = v[i];
            }
        }

        while(q--){
            ll k;
            cin >> k;

            ll ans = -1;
            for(int i = 0; i <= idx; i++){
                if((v[i].second - v[i].first + 1) >= k){
                    ans = v[i].first + k - 1;
                    break;
                }
                else{
                    k = k - (v[i].second - v[i].first + 1);
                }
            }

            cout << ans << endl;
        }
    }
}

//
#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(pair<ll,ll> p1, pair<ll,ll> p2){
	return p1.first < p2.first;
}
void merge_intervals(vector<pair<ll,ll>> &v){

	sort(v.begin(),v.end(),cmp);

	vector<pair<ll,ll>> res;

	ll s = v[0].first, e = v[0].second;

	for(int i = 1; i < v.size(); i++){

		if(v[i].first <= e){
			e = max(e, v[i].second);
		}
		else{
			res.push_back({s,e});
			s = v[i].first;
			e = v[i].second;
		}
	}

	res.push_back({s,e});

	v.clear();

	for(int i = 0; i < res.size(); i++){
		v.push_back(res[i]);
	}
}
int main(){

	int t;
	cin >> t;

	while(t--){

		int n,q;
		cin >> n >> q;

		vector<pair<ll,ll>> v(n);

		ll a,b;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			v[i] = {a,b};
		}

		merge_intervals(v);

		while(q--){
			
			ll k;
			cin >> k;

			bool flag = false;

			for(int i = 0; i < v.size(); i++){

				ll a = v[i].first, b = v[i].second;

				ll count = (b - a) + 1;

				if(count >= k){
					cout << a + (ll)k - 1 << endl;
					flag = true;
					break;
				}
				else{
					k -= count;
				}
			}

			if(!flag){
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
