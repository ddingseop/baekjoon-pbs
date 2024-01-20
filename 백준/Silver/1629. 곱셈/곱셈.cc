#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,b,c;
ll ans(ll a,ll b){
	if(b==1){
		return a%c;
	}
	ll temp=ans(a,b/2);
	temp=(temp*temp)%c;
	if(b%2){
		temp=(temp*a)%c;
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>a>>b>>c;
	cout<<ans(a,b)<<"\n";
	return 0;
}
