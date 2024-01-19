#include<bits/stdc++.h>
using namespace std;

string s,ret;
int cnt[200],flag;
char mid;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>s;
	for(char a:s){
		cnt[a]++;
	}
	for(int i='Z';i>='A';i--){ //오름차순 
		if(cnt[i]){
			if(cnt[i]%2==1){ //문자 등장횟수가 홀수인경우 
				mid=char(i); //펠린드롬 중간에 위치시키기 위해 mid에 저장 
				flag++; //홀수개인 문자개수 
				cnt[i]--; 
			}
		}
		if(flag==2){ //홀수개인 문자개수 2개이상인경우 
			break; //펠린드롬 불가능 
		}
		for(int j=0;j<cnt[i];j+=2){
			ret=char(i)+ret;
			ret+=char(i);
		}
	}
	if(mid){
		ret.insert(ret.begin()+ret.size()/2,mid); //ret.begin()이터레이터를 ret.size()/2에 위치시킴 
	}
	if(flag==2){
		cout<<"I'm Sorry Hansoo\n";
	} 
	else{
		cout<<ret<<"\n";
	}
}