#include<bits/stdc++.h>
using namespace std;

int n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	while(scanf("%d",&n)!=EOF){
		int cnt=1,temp=1;
		while(true){
			if(cnt%n==0){
				printf("%d\n",temp); //temp=자릿수 
				break;
			}
			else{
				cnt=(cnt*10)+1;
				cnt%=n;
				temp++;
			}
		}
	}
}
