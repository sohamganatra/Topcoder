#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int a,b,m;
		cin>>a>>b>>m;
		long long int sum=m*(m+1);
		sum/=2;
		if(min(a,b)>=sum){
			cout<<(a+b-2*sum)<<"\n";
		}
		else{
			cout<<max(b,a) - min(b,a)<<"\n";
		}
	}
}
