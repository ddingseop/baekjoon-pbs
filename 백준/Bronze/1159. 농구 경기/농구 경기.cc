#include<bits/stdc++.h>
using namespace std;

int n,cnt[26];
string s,temp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		cnt[s[0]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]>=5){
			temp+=i+'a';	
		}
	}
	if(temp.size()){
		cout<<temp;
	}
	else{
		cout<<"PREDAJA";
	}
}