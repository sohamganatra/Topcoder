#include <iostream>
#include <algorithm>
using namespace std;
class RockStar{
	public:
	int getNumSongs(int ff, int fs, int sf, int ss){
		if(ff == 0 && fs ==0){
			if(sf == 0)return ss;
			else return ss+1;
		}
		
		else if(ff!=0 and fs==0){
		return ff;
		}
		else{
			if(sf > fs-1)
			return ff+ss+2+2*min(sf,fs-1);
			else
			return ff+ss+1+2*min(sf,fs-1);
		}
	}

};
