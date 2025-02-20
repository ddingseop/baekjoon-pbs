#include<bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;
const int INF=987654321;
int n,a[44],ret=INF; // n: 동전 개수, a[44]: 동전 상태 저장 배열, ret: 최소 뒤집기 횟수 저장
string s; // 동전의 상태를 저장할 문자열
void go(int here){
	// 베이스 케이스 (종료 조건)
	if(here==n+1){ // 모든 행을 확인했을 경우
		int sum=0; // 현재 경우의 최소 뒤집기 횟수
		for(int i=1;i<=(1<<(n-1));i*=2){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(a[j]&i){ // 현재 열에서 'T' 개수 카운트
					cnt++;
				}
			}
			sum+=min(cnt,n-cnt); // 뒤집기 최소 개수를 누적
		}
		ret=min(ret,sum); // 최소 뒤집기 횟수 갱신
		return;
	}
	go(here+1); //현재 행을 그대로 두고 다음 행으로 이동
	a[here]=~a[here]; //현재 행을 비트 반전하여 뒤집음
	go(here+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int value=1;
		for(int j=0;j<s.size();j++){ //// 각 문자열을 비트마스크로 변환
			if(s[j]=='T'){
				a[i]|=value;
			}
			value*=2; //1,2,4,8,...로 증가시키면서 비트마스킹 
		}
	}
	go(1); // 백트래킹 시작
	cout<<ret<<"\n";
	return 0;
}