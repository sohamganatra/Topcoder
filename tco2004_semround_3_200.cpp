#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


class Unblur{
	public:
	vector <string> original(vector <string> blu){
		
		if(blu.size() == 0){
			vector<string> a;
			return a;
		}
		
		vector<string> a(blu.size(),string(blu[0].size(),'.'));
		int n_row = blu.size();
		int n_col = blu[0].size();
		int bluu[n_row][n_col];
		
		for(int i=0;i<n_row;i++){
			for(int j=0;j<n_col;j++){
				bluu[i][j]=blu[i][j]-'0';
				cout<<bluu[i][j]<<" ";
			}
			cout<<"\n";
		}
		
		for(int i=1;i<n_row-1;i++){
			for(int j=1;j<n_col-1;j++){
				if(bluu[i-1][j-1]==1){
					a[i][j] = '#';
	
					bluu[i-1][j-1]--;
					bluu[i-1][j]--;
					bluu[i-1][j+1]--;
					bluu[i][j-1]--;
					bluu[i][j]--;
					bluu[i][j+1]--;
					bluu[i+1][j-1]--;
					bluu[i+1][j]--;
					bluu[i+1][j+1]--;
				
				}
			}
		}
		return a;
		
	}
	
};
