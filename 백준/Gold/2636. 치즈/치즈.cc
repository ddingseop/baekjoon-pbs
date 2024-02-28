#include <bits/stdc++.h>
using namespace std; 
int n,m,a[104][104],visited[104][104],cnt,cnt2;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
vector<pair<int,int>> v;

void dfs(int y,int x){
	visited[y][x]=1;
	if(a[y][x]==1){
		v.push_back({y,x});
		return; //처음으로 1을 만났다면(가장자리의 1을 만났다면) 벡터에 저장하고 끝 
	}
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]){
			continue;
		}
		dfs(ny,nx);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>a[i][j];
		}
	}
	while(true){
		fill(&visited[0][0],&visited[0][0]+104*104,0);
		v.clear(); //치즈 녹고나서 벡터 초기화 
		dfs(0,0); 
		cnt2=v.size(); //벡터에 저장된 위치의 개수
		for(pair<int,int> b:v){
			a[b.first][b.second]=0; //벡터에 저장된 1이였던 위치->0(치즈녹이기) 
		} 
		bool flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]!=0){ //치즈가 남아있다면 
					flag=1;
				}
			}
		}
		cnt++;
		if(!flag){ //치즈가 다 녹았다면  
			break;
		}
	}
	cout<<cnt<<'\n'<<cnt2<<'\n';
	return 0;
}