#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
class Boxing{
	public:
	int maxCredit(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> e){
		int maxCred = 0;
		vector<pair < int,int > > val;
		
		for(int i=0;i<a.size();i++){
			val.push_back(make_pair(a[i],1));
		}
		for(int i=0;i<b.size();i++){
			val.push_back(make_pair(b[i],2));
		}
		for(int i=0;i<c.size();i++){
			val.push_back(make_pair(c[i],3));
		}
		for(int i=0;i<d.size();i++){
			val.push_back(make_pair(d[i],4));
		}
		for(int i=0;i<e.size();i++){
			val.push_back(make_pair(e[i],5));
		}
		
		sort(val.begin(),val.end());
		
		
		vector<pair<int ,int> >::iterator str;
		for(str = val.begin();str!=val.end();){
			int aa = str->first;
			int ab = str->second;
			vector<pair<int,int> >::iterator str_j = str;
			str_j++;
			int count=0;
			set<int> con;
			con.insert(ab);
		//	cout<<ab<<" u\n";
			while(str_j != val.end() && count!=2){
				if(str_j->first > 1000 + aa)break;
				else if(con.find(str_j->second) != con.end()){
					//cout<<"en \n"<<str_j->first<<" "<< str_j->second<<" "<<*(con.find(str_j->second))<<" j\n";
					str_j++;continue;
				}
				else {
					//cout<<str_j->first<<" "<<str_j->second<<" k\n";
					con.insert(str_j->second);
					count++;
					str_j++;

				}
			}
			con.clear();
			//cout<<aa<<" "<<count<<" h\n";
			if(count != 2){
				str++;
				continue;
			}
			else{

				str_j--;
				int a_final = str_j->first;
								//cout<<"here\n"<<aa<<" "<<ab<<" "<<a_final<<"\n";
				str = upper_bound(val.begin(),val.end(),make_pair(a_final,5));
				maxCred++;
			}
		}
		return maxCred;
	}
};
