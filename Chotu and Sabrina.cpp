#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int count=0;
		for(int i=0;i<(1<<s.size());i++){
			string s1;
			for(int j=0;j<s.size();j++){
					int y=(1<<j);
					if((i&y)!=0){
						s1=s1+s[j];
					}
			}
			int l=0,r=s1.size()-1,flag=1;
			while(l<r){
				if(s1[l]!=s1[r]){
					flag=0;
					break;
				}
				l++;
				r--;
			}
			if(flag==1){
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
