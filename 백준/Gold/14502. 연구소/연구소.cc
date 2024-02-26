#include <bits/stdc++.h>
using namespace std; 
int n,m,a[10][10],visited[10][10],ret;
vector<pair<int,int>> vList, wList;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
void dfs(int y,int x){
	visited[y][x]=1;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=m){
			continue;
		}
		if(visited[ny][nx]||a[ny][nx]==1){
			continue;
		}
		dfs(ny,nx);
	}
	return;
}

int solve(){
	fill(&visited[0][0], &visited[0][0]+10*10,0);
	for(pair<int,int> b:vList){
		visited[b.first][b.second]=1;
		dfs(b.first,b.second);
	}
	int cnt=0; //안전영역 크기
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0&&!visited[i][j]){
				cnt++;
			}
		}
	} 
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin>>a[i][j];
    		if(a[i][j]==2){
    			vList.push_back({i,j}); //바이러스 위치 
			}
			if(a[i][j]==0){
				wList.push_back({i,j}); //벽세울수 있는 후보위치 
			}
		}
	}
	for(int i=0;i<wList.size();i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<j;k++){
				a[wList[i].first][wList[i].second]=1;
				a[wList[j].first][wList[j].second]=1;	
				a[wList[k].first][wList[k].second]=1;
				ret=max(ret,solve());
				a[wList[i].first][wList[i].second]=0;
				a[wList[j].first][wList[j].second]=0;	
				a[wList[k].first][wList[k].second]=0;		
			}
		} 
	}
	cout<<ret<<"\n";
	return 0;
}
