#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
int n,c,a[1004];
vector<pair<int,int>> v;
map<int,int> mp,mp_first; //mp_first는 해당 숫자가 처음 등장한 인덱스 저장 

bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first==b.first){ //개수 똑같을때 
		return mp_first[a.second]<mp_first[b.second]; //먼저 등장 오름차순 
	}
	return a.first>b.first; //내림차순 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>c;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	mp[a[i]]++; //빈도++ 
    	if(mp_first[a[i]]==0){ //맵에 요소가 있는지 확인하고 
    		mp_first[a[i]]=i+1;  //해당숫자가 처음 등장한 인덱스 저장
		}
	} 
	for(auto it:mp){
		v.push_back({it.second,it.first}); //mp값 벡터에 저장 
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		for(int j=0;j<i.first;j++){
			cout<<i.second<<" ";
		}
	}
	return 0;
}