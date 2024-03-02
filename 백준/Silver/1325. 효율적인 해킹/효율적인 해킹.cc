#include <bits/stdc++.h>
using namespace std; 
int n,m,a,b,dp[10001],visited[10001],mx;
vector<int> v[10001];
int dfs(int here){
	visited[here]=1;
	int ret=1; //현재정점+연결된 정점 수 초기화 
	for(int there:v[here]){  //현재정점에서 연결된 모든 정점에 대해서 
		if(visited[there]){
			continue;
		}
		ret+=dfs(there);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    while(m--){
    	cin>>a>>b;
    	v[b].push_back(a);  
	}
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited)); //visited 배열 초기화
		dp[i]=dfs(i); //dp배열에 dfs값 저장
		mx=max(dp[i],mx); 
	}
	for(int i=1;i<=n;i++){
		if(mx==dp[i]){
			cout<<i<<" ";
		}
	}
	return 0;
}