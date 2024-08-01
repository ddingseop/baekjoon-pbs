#include <stdio.h>
#include <algorithm>
#include <queue>
//점프를 뛸때마다 주난이와 이어진 0 주변의 1들이 사라진다고 생각하면됨 
using namespace std;
char a[301][301];
int n,m,x1,y1,x2,y2; 
typedef pair<int,int> pii;
int visited[301][301];
const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
int ret;
queue<int> q;
int main(){
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
	y1--,x1--,y2--,x2--;
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	q.push(1000*y1+x1); //이렇게 하면 이차원 좌표를 하나의 정수형으로 표현가능 
	visited[y1][x1]=1;
	int cnt=0;
	while(a[y2][x2]!='0'){ //목표지점이 0이 될때까지 
		cnt++;
		queue<int> temp;
		while(q.size()){
			int y=q.front()/1000; //y좌표 
			int x=q.front()%1000; //x좌표 
			q.pop();
			for(int i=0;i<4;i++){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]){
					continue;
				}
				visited[ny][nx]=cnt;
				if(a[ny][nx]!='0'){ //1이라면 
					a[ny][nx]='0';
					temp.push(1000*ny+nx); //temp에 푸쉬하고 
				}
				else{
					q.push(1000*ny+nx); //0이면 q에 푸쉬함 
				}
			}
		}
		q=temp;	
	}
	printf("%d\n",visited[y2][x2]);
}