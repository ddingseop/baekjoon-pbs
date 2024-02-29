#include <bits/stdc++.h>
using namespace std; 
int n,par,root,d;
vector<int> adj[54];  //자식 노드 저장 
int dfs(int here){
	int sum=0; //리프노드의 수 
	int child=0;
	for(int b:adj[here]){ //자식노드들에 대하여 
		if(b==d){ //자식노드가 삭제해야할 노드면 
			continue; //탐색 X 
		}
		sum+=dfs(b); //반환한 1을 sum에 더해줌 
		child++; //자식 노드 있는지 확인  
	}
	if(child==0){
		return 1; //자식노드가 없다면 1을 반환 
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>par;
    	if(par==-1){
    		root=i;
		}
		else{
			adj[par].push_back(i);
		}
	}
	cin>>d;
	if(d==root){ //예외처리 
		cout<<0<<"\n";
		return 0;
	}
	cout<<dfs(root)<<"\n";
	return 0;
}