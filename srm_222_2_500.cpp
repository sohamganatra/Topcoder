#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
class GroceryBagger{
	public:
	map<string,int> x;
	int minimumBags(int s , vector<string> Bag){
		
		for(int i=0;i<Bag.size();i++){
			x[Bag[i]]++;	
		}
		int total=0;
		for(map<string,int>::iterator ia=x.begin();ia!=x.end();ia++){
			int y= (ia->second)-1;
			if(y < 0){
				continue;
			}
			
			else{
				total+=((y/s)+1);
			}
			
		
		}
		return total;
		
	}
};
