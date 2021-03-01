#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        
        int n1;
        cin >> n1;
        
        map<string,int> killer;
        map<string,int> killed;
        
        string s[n1][3];
      
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < 3; j++){
                cin >> s[i][j];
                if(j == 0) killer[s[i][j]]++;
                else if(j == 2) killed[s[i][j]]++;
            }
        }
      
        string str = s[0][0];
        int n = killer[s[0][0]];

        map<string,int> :: iterator itr;
        for(itr = killer.begin(); itr!= killer.end(); itr++){
            if(itr->second > n){
                n = itr->second;
                str = itr->first;
            }
            else if(itr->second == n){
                if(itr->first < str){
                    str = itr->first;
                }
            }
        }
        cout << str << " ";

        str = s[0][2];
        n = killed[s[0][2]];

        for(itr = killed.begin(); itr!= killed.end(); itr++){
            if(itr->second > n){
                n = itr->second;
                str = itr->first;
            }
            else if(itr->second == n){
                if(itr->first < str){
                    str = itr->first;
                }
            }
        }
        cout << str << endl;
    }
}
