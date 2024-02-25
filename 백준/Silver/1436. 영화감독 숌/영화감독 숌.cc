#include <bits/stdc++.h>
using namespace std; 
int n;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int i=666;
    for(;;i++){ //i가 1씩 커지는 무한루프  
    	if(to_string(i).find("666")!=string::npos){
    		//문자열로 변환하고 666이 있다면 
    		n--;
		}
		if(n==0){
			break;
		} 
	}
	cout<<i<<"\n";
	return 0;
}