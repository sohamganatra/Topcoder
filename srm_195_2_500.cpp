#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class FanFailure{
	public:
	vector<int> getRange(vector<int> a, int b){
		sort(a.begin(),a.end());
		int total=0;
		vector<int> solution;
		int sol_a=0;
		int sol_b=0;
		for(int i=0;i<a.size();i++){
			total+=a[i];
		}
		
		int i=a.size()-1;
		int dummy=total;
		while(true){
			dummy-=a[i];
			if(dummy < b){
			break;
			}
			i--;			
		}
		sol_b=a.size()-1-i;
		
		i=0;
		dummy=total;
		while(true){
			dummy-=a[i];
			if(dummy < b){
			break;
			}
			i++;
		}
		sol_a=i;
		solution.push_back(sol_a);
		solution.push_back(sol_b);
		cout<<sol_a<<" "<<sol_b<<"\n";		
	return solution;
	}
};
