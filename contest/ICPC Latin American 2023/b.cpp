#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
using ll=long long;
 
int main(){
	int sum;
	short int arr[200010];
	memset(arr,0,sizeof(arr));
	int t,inp;
	cin>>t;
	t*=3;
	sum=0;
	while(t--){
		cin>>inp;
		arr[inp+100000]=(arr[inp+100000]+1)%3;
		if(arr[inp+100000]==1)sum++;
		if(arr[inp+100000]==0)sum--;
	}
	cout<<((sum==0)?"N":"Y")<<endl;
}
 