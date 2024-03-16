#include <bits/stdc++.h>
using namespace std; 
int n,m,a[54][54],result=987654321;
vector<vector<int>>chickenList; //조합된 치킨가게 리스트 
vector<pair<int,int>> _home,chicken; //집,치킨가게 위치 

void combi(int start, vector<int> v){
	if(v.size()==m){
		chickenList.push_back(v);
		return; 
	}
	for(int i=start+1;i<chicken.size();i++){ //치킨가게 리스트 순회 
		v.push_back(i); 
		combi(i,v);
		v.pop_back();
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>a[i][j];
    		if(a[i][j]==1){
    			_home.push_back({i,j});
			}
			if(a[i][j]==2){
				chicken.push_back({i,j});
			}
		}
	}
	vector<int> v;
	combi(-1,v);
	for(vector<int> cList:chickenList){
		int ret=0;
		for(pair<int,int> home: _home){ //모든 집에 대해 
			int _min=987654321;
			for(int ch:cList){ //선택된 치킨가게들과의 거리 계산 
				int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
				//거리 구하는 공식, abs=절대값 
				_min=min(_min,_dist); //최소거리 갱신 
			}
			ret+=_min; //총거리 
		}
		result=min(result,ret); //총거리 최소 
	}
	cout<<result<<"\n";
	return 0;
 }