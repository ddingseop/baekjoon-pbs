#include <bits/stdc++.h>
using namespace std; 
int n;
vector<string> v;
string s,ret;

void go(){
	while(true){
		if(ret.size()&&ret.front()=='0'){
			ret.erase(ret.begin());
		}
		else{
			break;
		}
	}
	if(ret.size()==0){
		ret="0";
	}
	v.push_back(ret); //벡터에 추가하고 초기화 
	ret="";
}

bool cmp(string a,string b){
	if(a.size()==b.size()){
		return a<b; //문자열 길이가 같은경우 사전순 
	}
	return a.size()<b.size();
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>s;
    	for(int j=0;j<s.size();j++){
    		if(s[j]<65){ //문자열이 알파벳이 아닌경우 
    			ret+=s[j]; //ret에 알파벳 아닌 숫자문자  추가 
			}
			else if(ret.size()){
				go();
			}
		} 
		if(ret.size()){ //문자열이 남아있는경우 
			go();
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(string i:v){
		cout<<i<<"\n";
	}
	return 0;
}