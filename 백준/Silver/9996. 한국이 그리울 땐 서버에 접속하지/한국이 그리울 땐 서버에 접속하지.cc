#include<bits/stdc++.h>
using namespace std;

int n;
string word,s,start,last;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n;
	cin>>word;
	int pos=word.find('*');
	start=word.substr(0,pos);
	last=word.substr(pos+1);
	for(int i=0;i<n;i++){
		cin>>s;
		if(start.size()+last.size()>s.size()){
			cout<<"NE\n";
		}
		else{
			if(start==s.substr(0,start.size())&&last==s.substr(s.size()-last.size())){
				cout<<"DA\n";
			}
			else{
				cout<<"NE\n";
			}
		}
	}
}
