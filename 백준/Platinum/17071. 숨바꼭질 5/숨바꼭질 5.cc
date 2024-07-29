#include<bits/stdc++.h>
using namespace std;
const int max_n=500000;
int visited[2][max_n+4],a,b,ok,turn=1;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	if(a==b){
		cout<<0<<"\n";
		return 0;
	}
	queue<int> q;
	visited[0][a]=1; //visited[홀수나 짝수시간][지점]에 방문했는지 
	q.push(a);
	while(q.size()){
		b+=turn;
		if(b>max_n){
			break;
		}
		if(visited[turn%2][b]){ //짝수시간이나 홀수시간에 b에 도착했다면 
			ok=true;
			break;
		}
		int qSize=q.size();
		for(int i=0;i<qSize;i++){
			int x=q.front();
			q.pop();
			for(int nx:{x+1,x-1,x*2}){
				if(nx<0||nx>max_n||visited[turn%2][nx]){
					continue;
				}
				visited[turn%2][nx]=visited[(turn-1)%2][x]+1; //다음턴 설정해주기 
				if(nx==b){ 
					ok=1;
					break;
				} 
				q.push(nx);
			}
			if(ok){
				break;
			}
		}
		if(ok){
			break;
		}
		turn++;
	}
	if(ok){
		cout<<turn;
	}
	else{
		cout<<-1;
	}
	return 0;
}
//수빈이가 +1,-1만큼 갈 수 있어서 짝수 만큼 차이나는 시간동안 수빈이가 먼저 도착하면 만날수 있음 
//그래서 홀수시간 짝수시간 나눠서 해줌 