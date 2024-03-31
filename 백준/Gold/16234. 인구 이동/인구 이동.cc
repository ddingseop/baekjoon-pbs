 #include <bits/stdc++.h>
using namespace std; 
int N,L,R, visited[54][54],a[54][54],sum,cnt; //sum=합계, cnt=그룹개수 
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
vector<pair<int,int>>v; //현재 좌표 저장하는 벡터 

void dfs(int y,int x,vector<pair<int,int>> &v){
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(nx<0||nx>=N||ny<0||ny>=N||visited[ny][nx]){
			continue;
		}
		if(abs(a[ny][nx]-a[y][x])>=L&&abs(a[ny][nx]-a[y][x])<=R){
			visited[ny][nx]=1;
			v.push_back({ny,nx});
			sum+=a[ny][nx];
			dfs(ny,nx,v);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>L>>R;    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>a[i][j];
        }
    }
    while(true){
    	bool flag=0; //그룹 내 값이 업데이트되었는지 여부 
    	fill(&visited[0][0],&visited[0][0]+54*54,0);
    	for(int i=0;i<N;i++){
    		for(int j=0;j<N;j++){
    			if(!visited[i][j]){ //방문하지 않은곳이면 
    				v.clear();
    				visited[i][j]=1;
    				v.push_back({i,j});
					sum=a[i][j]; //합계에 셀값 더하고
					dfs(i,j,v);  
					if(v.size()==1){
						continue;
					}
					for(pair<int,int> b : v){
						a[b.first][b.second]=sum/v.size(); //그룹네 모든 셀값을 평균값으로 업데이트 
						flag=1; //값이 업데이트됨  
					}	
				}
			}
		}
		if(!flag){
			break;
		} 
		cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
 }