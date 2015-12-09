#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#define mp make_pair
using namespace std;

int gcd ( int a, int b ){
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int gcd(int a,int b,int c){
		return gcd(a,gcd(b,c));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<pair<long long int,long long int> > aa;
		set<pair<long long int,long long int> >ab;	
		set<pair<long long int,pair<long long int,long long int> > > ac;
		map<pair<int,int>,double> slope;
	//	set<pair<double,double> > uniqe;
	//	set<double> infi;
		double inficount_1=0;
		double inficount_2=0;
		while(n--){
			double a,b,c;
			cin>>a>>b>>c;
			if(b == 0){
				if(aa.find(mp(c/gcd(c,a),a/gcd(c,a))) != aa.end())continue;
				else{
					aa.insert(mp(c/gcd(c,a),a/gcd(c,a)));
				}
				inficount_1+=1;
			}
			else if(a == 0){
				if(ab.find(mp(c/gcd(c,b),b/gcd(c,b))) != ab.end())continue;
				else{
					ab.insert(mp(c/gcd(c,b),b/gcd(c,b)));
				}
				inficount_2+=1;
			}
			else{
				if (ac.find(mp(a/gcd(a,b,c),mp(b/gcd(a,b,c),c/gcd(a,b,c))))!=ac.end())continue;
				else{
					ac.insert(mp(a/gcd(a,b,c),mp(b/gcd(a,b,c),c/gcd(a,b,c))));
				}

				slope[mp(a/gcd(a,b),b/gcd(a,b))]+=1;
			}
		}
		
		double maxa=max(inficount_1,inficount_2);
		for(map<pair<int,int>,double>::iterator a = slope.begin();a!=slope.end();a++){
			maxa=max(maxa,a->second);
		}
		cout<<maxa<<"\n";
		slope.clear();
	}
}
