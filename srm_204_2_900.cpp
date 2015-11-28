#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int pow3(int a){
	int total=0;
	int ans=0;
	while(true){
		total+=pow(3,ans);
		if(pow(3,ans) <= a && pow(3,ans+1)>= a ){
			if(a <= total)return pow(3,ans);
				else return pow(3,ans+1);
		}
		else{

			ans++;
		}
	}
}
	
	

vector<int> neg(vector<int> ans){
	for(int i=0;i<ans.size();i++){
		ans[i]*=-1;
	}
	return ans;
}
	
class Apothecary{
	public:
	vector<int> balance(int W){
		vector<int> x;
		
		int p = pow3(W);
		
		if(p ==  W){
			x.push_back(W);
			sort(x.begin(),x.end());
			return x;
		}
		
		else if(p > W){
			x=neg(balance(p-W));
			x.push_back(p);
			sort(x.begin(),x.end());
			return x;
		}
		
		else{
			x=balance(W-p);
			x.push_back(p);
			sort(x.begin(),x.end());
			return x;
		}
	}
};
