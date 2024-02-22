#include <bits/stdc++.h>
using namespace std; 
string s;
int acnt,bcnt;

bool Vowel(int num){
	return(num=='a'||num=='e'||num=='i'||num=='o'||num=='u');
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    while(true){
    	cin>>s;
    	if(s=="end"){
    		break;
		}
		acnt=bcnt=0;
		bool flag=0; //조건 만족하는지 여부
		bool inc_v=0; //모음이 포함되어있는지 여부
		int prev=-1; //이전 문자저장
		for(int i=0;i<s.size();i++){
			int num=s[i]; //num=문자의 아스키코드 
			if(Vowel(num)){ //연속하는 모음,자음 개수 세기위해 0으로 초기화 
				acnt++;
				bcnt=0;
				inc_v=1;
			}
			else{
				bcnt++;
				acnt=0;
			}
			if(acnt==3||bcnt==3){
				flag=1;
			} 
			if(i>=1&&(prev==num)&&(num!='e'&&num!='o')){
				flag=1; //현재문자 이전문자 비교 e나o를 제외  
			}
			prev=num;
		} 
		if(inc_v==0){
			flag=1;
		}
		if(flag){
			cout << "<" << s << ">" << " is not acceptable.\n";
		}
		else{
			cout << "<" << s << ">" << " is acceptable.\n";
		}
	}
	return 0;
}