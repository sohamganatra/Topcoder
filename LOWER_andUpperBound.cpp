#include <iostream>
#include <set>
using namespace std;

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator itlow,itup;

  for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

  itlow=myset.lower_bound (21);                //       ^
  itup=myset.upper_bound (20);                 //                   ^

	cout<<*itlow<<" "<<*itup;
  //~ std::cout << "myset contains:";
  //~ for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    //~ std::cout << ' ' << *it;
  //~ std::cout << '\n';

  return 0;
}
// Lowerbound of x = Upper bound of x-1
// Lower bound of x points to an element that is greater than or equal to x
// Upper BOund of an element points to an element that is greater than x
// Similar to both if no element is greater than x then they point to .end() 
// and if they are the smallest element they point to begin()
