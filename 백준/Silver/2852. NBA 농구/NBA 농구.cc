#include <bits/stdc++.h>
using namespace std; 
#define prev kundol
int n,t,awin,bwin,A,B; //A,B=점수, t=팀, awin,bwin=각팀이 이기고 있는시간 
string s,prev;

string print(int a){ //정수형 분을 문자열 시간으로 바꿔주는 함수 
	string d="00"+to_string(a/60);
	string e="00"+to_string(a%60);
	return d.substr(d.size()-2,2)+":"+e.substr(e.size()-2,2);
}

int changeToInt(string a){ //문자열 시간을 정수형 분으로 바꿔주는 함수 
	return atoi(a.substr(0,2).c_str())*60+atoi(a.substr(3,2).c_str());
}

void go(int &sum,string s){
	sum+=(changeToInt(s)-changeToInt(prev));
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>t>>s;
		if(A>B){
			go(awin,s);
		}
		else if(B>A){
			go(bwin,s);
		}
		t==1? A++:B++;
		prev=s;
	}
	if(A>B){
		go(awin,"48:00");
	}
	else if(B>A){
		go(bwin,"48:00");
	}
	cout<<print(awin)<<"\n";
	cout<<print(bwin)<<"\n";
} 