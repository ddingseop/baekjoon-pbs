#include <bits/stdc++.h>
using namespace std; 
int n,a[1000004],ret[1000004];
stack<int> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    memset(ret,-1,sizeof(ret));
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	while(s.size()&&a[s.top()]<a[i]){ //현재요소가 이전에 처리한 요소보다 클때까지 반복 
    		ret[s.top()]=a[i]; //ret배열에 현재값 넣고 
    		s.pop(); //해당요소 제거 
		}
		s.push(i); //스택에 i값 넣어주기 
	}
	for(int i=0;i<n;i++){
		cout<<ret[i]<<" ";
	}
}