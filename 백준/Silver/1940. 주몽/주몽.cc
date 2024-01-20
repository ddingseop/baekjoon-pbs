#include<bits/stdc++.h>
using namespace std;

int N,M,a[15000],ans; 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(a[i]+a[j]==M){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}