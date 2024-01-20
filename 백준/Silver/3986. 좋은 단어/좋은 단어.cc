#include<bits/stdc++.h>
using namespace std;

int n,cnt; 
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		stack<char> stk;
		for(char a:s){
			if(stk.size()&&stk.top()==a){ //pop을 할때 size가 있는지 체크 
				stk.pop(); //스택의 top에 있는수와 같으면 top에 있는수 뺌  
			}
			else{
				stk.push(a); //다르면 추가해줌 
			}
		}
		if(stk.size()==0){
			cnt++;
		}
	}
	cout<<cnt<<"\n";
}
