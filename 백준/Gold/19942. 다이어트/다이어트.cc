#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;
const int INF=987654321;
int n,mp,mf,ms,mv;
int b,c,d,e,ret=INF, sum;
struct A{
	int mp,mf,ms,mv,cost;
}a[16];
map<int, vector<vector<int>>> ret_v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	cin>>mp>>mf>>ms>>mv;
	for(int i=0;i<n;i++){
		cin>>a[i].mp>>a[i].mf>>a[i].ms>>a[i].mv>>a[i].cost;
	}
	for(int i=1;i<(1<<n);i++){ //1 << n은 2^n을 의미하며, 가능한 모든 조합 수
		b=c=d=e=sum=0;
		vector<int> v;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){ //if(i & (1 << j))는 i에 j번째 영양제가 포함되었는지 확인
				v.push_back(j+1);
				b+=a[j].mp;
				c+=a[j].mf;
				d+=a[j].ms;
				e+=a[j].mv;
				sum+=a[j].cost;
			}
		}
		if(b>=mp&&c>=mf&&d>=ms&&e>=mv){
			if(ret>=sum){
				ret=sum; //ret = 최소비용 
				ret_v[ret].push_back(v); //ret_v = 최소 비용에 해당하는 영양제 조합
			}
		}
	}
	if(ret==INF){
		cout<<-1<<'\n';
	}
	else{
		sort(ret_v[ret].begin(),ret_v[ret].end());
		cout<<ret<<"\n";
		for(int a:ret_v[ret][0]){
			cout<<a<<" ";
		}
	}
	return 0;
}

