#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int stoii(string s){
	int a = 1;
	int count = 0;
	for(int i=0;i<10;i++){
		if(s[i] == '+'){
			count+=a;
		}
		a*=2;
	}
	return count;
}

string intoss(int a){
	string s(10,'-');
	for(int i=0;i<10;i++){
		if(a%2 == 1){
			s[i]='+';
		}
		a/=2;
	}
	return s;
}

string diffs(string s, string a){
	string result(10,'-');
	for(int i=0;i<10;i++){
		if(s[i] != a[i])result[i]='+';
	}
	return result;
}

string diffs(string s){
	string result(10,'-');
	for(int i=0;i<10;i++){
		if(s[i] != 'b')result[i]='+';
	}
	return result;
}

int dynamic(int no , string bomb , vector<map <string,int> > & dynamite , map<int,int> & j){
	if(no == 1024) return (bomb == "----------");
	if(dynamite[no][bomb] != 0){
		
		return max(dynamite[no][bomb],0);
	}
	else{
		int sda = j[no];
		if(sda == 0){
			
			int aa = dynamic(no+1,bomb,dynamite,j);
			if(aa == 0){
				dynamite[no][bomb] = -1; 
			}
			else{
				dynamite[no][bomb] = aa;
			}
			return aa;
		}
		else{
			int aa = dynamic(no+1,bomb,dynamite,j)*pow(2,sda-1);
			string bomb_new = diffs(bomb,intoss(no));
			int ab = dynamic(no+1,bomb_new,dynamite,j)*pow(2,max(0,sda-1));
			
			if(aa+ab == 0){
				dynamite[no][bomb] = -1;
			}
			else{
				dynamite[no][bomb] = aa+ab;
			}
			return aa+ab;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string personal;
		cin>>personal;
		int m;
		vector<string> str;
		cin>>m;
		map<int,int> j;
		while(m--){
			string s;
			cin>>s;
			str.push_back(s);
			j[stoii(s)]++;
		}
		vector<map<string,int > > dyna_str(1024);
		cout<<dynamic(0,diffs(personal),dyna_str,j)<<"\n";
	}
}
