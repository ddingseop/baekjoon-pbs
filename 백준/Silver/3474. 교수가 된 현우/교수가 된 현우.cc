#include <bits/stdc++.h>
using namespace std; 
int n,a;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a;
    	int two=0;
    	int five=0;
    	for(int j=2;j<=a;j*=2){
    		two+=a/j;
		}
		for(int j=5;j<=a;j*=5){
			five+=a/j;
		}
		cout<<min(two,five)<<"\n";
	}
	return 0;
}