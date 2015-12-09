#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a_count = 1011;
		int b_count = 1011;
		while(n--){
			string s;
			cin>>s;
			int ac = count(s.begin(),s.end(),'a');
			int bc = count(s.begin(),s.end(),'b');			
			a_count = min(a_count,ac);
			b_count = min(b_count,bc);
		}
		cout<<min(a_count,b_count)<<"\n";
	}
}
