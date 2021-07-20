#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);
    int prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    int q;
    cin >> q;

    while(q--){
        int p;
        cin >> p;

        int ind = upper_bound(arr,arr+n,p) - arr;
        cout <<  ind << " " << prefix[ind] << endl;
    }
}
