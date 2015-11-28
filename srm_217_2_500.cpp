#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
class PlayGame{
	public:
	int saveCreatures(vector <int> you, vector <int> com){
		sort(you.begin(),you.end());
		multiset<int> x;
		for(int i=0;i<you.size();i++){
			x.insert(com[i]);
		}
		int str=0;
		int i=you.size()-1;
		while(i>=0){
			int y=you[i];
			cout<<x.size()<<" size\n";
			set<int>::iterator it = x.lower_bound(y);
			
			if(it == x.begin())return str;
			
			it--;
			
			if(*it >= y){
				cout<<y<<" " <<*it<<"\n";
				return str;
			}
			else{
				cout<<str<<" here\n";
				str+=y;
				x.erase(it);
			}
			i--;
		}
		return str;
	}

};
