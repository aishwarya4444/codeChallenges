#include<iostream>
#include<vector>
#include<map>
using namespace std;

void printArray(vector<int> &v) {
  for(auto num: v) {
    cout<<num<<" ";
  }
  cout<<endl;
}

// upper_bound and lower_bound example
// if value is present, lb = startIndex and ub = endIndex+1
// if value is absent, lb = ub = insert position in sorted order

int main(void) {

  // example for arrays
  cout<<"\n\narray example\n";

  vector<int> v = {1,4,6,2,2,8,6,8,2,4,3};
  vector<int>::iterator it;

  cout<<"before sort : ";
  printArray(v);
  sort(v.begin(), v.end());
  cout<<"after  sort : ";
  printArray(v);

  cout<<"array index : ";
  for(int i=0; i<v.size(); i++) {
    cout<<i<<" ";
  }
  cout<<endl;

  // find ub and lb of 2
  it = lower_bound(v.begin(), v.end(), 2);
  cout<<"2 lb : "<<(it-v.begin())<<endl;
  it = upper_bound(v.begin(), v.end(), 2);
  cout<<"2 ub : "<<(it-v.begin())<<endl;

  // find ub and lb of 1
  it = lower_bound(v.begin(), v.end(), 1);
  cout<<"1 lb : "<<(it-v.begin())<<endl;
  it = upper_bound(v.begin(), v.end(), 1);
  cout<<"1 ub : "<<(it-v.begin())<<endl;

  // find ub and lb of 5
  it = lower_bound(v.begin(), v.end(), 5);
  cout<<"5 lb : "<<(it-v.begin())<<endl;
  it = upper_bound(v.begin(), v.end(), 5);
  cout<<"5 ub : "<<(it-v.begin())<<endl;

  // find ub and lb of 8
  it = lower_bound(v.begin(), v.end(), 8);
  cout<<"8 lb : "<<(it-v.begin())<<endl;
  it = upper_bound(v.begin(), v.end(), 8);
  cout<<"8 ub : "<<(it-v.begin())<<endl;

  // find ub and lb of 100
  it = lower_bound(v.begin(), v.end(), 100);
  cout<<"100 lb : "<<(it-v.begin())<<endl;
  it = upper_bound(v.begin(), v.end(), 100);
  cout<<"100 ub : "<<(it-v.begin())<<endl;

  // find ub and lb of 0
  it = lower_bound(v.begin(), v.end(), 0);
  cout<<"0 lb : "<<(it-v.begin())<<endl;
  it = upper_bound(v.begin(), v.end(), 0);
  cout<<"0 ub : "<<(it-v.begin())<<endl;



  // example for map
  cout<<"\n\nmap example\n";

  map<int, int> m = {{2,20}, {4,40}, {3,30}, {7,70}};
  map<int, int>::iterator mit;

  for(mit=m.begin(); mit!=m.end(); mit++) {
    cout<<(*mit).first<<" "<<(*mit).second<<endl;
  }

  // lb and ub of 4
  mit = m.lower_bound(4);
  cout<<"4 lb : "<<(*mit).first<<" "<<(*mit).second<<endl;
  mit = m.upper_bound(4);
  cout<<"4 ub : "<<(*mit).first<<" "<<(*mit).second<<endl;

  // lb and ub of 2
  mit = m.lower_bound(2);
  cout<<"2 lb : "<<(*mit).first<<" "<<(*mit).second<<endl;
  mit = m.upper_bound(2);
  cout<<"2 ub : "<<(*mit).first<<" "<<(*mit).second<<endl;

  // lb and ub of 7
  mit = m.lower_bound(7);
  cout<<"7 lb : "<<(*mit).first<<" "<<(*mit).second<<endl;
  mit = m.upper_bound(7);
  cout<<"7 ub : "<<(*mit).first<<" "<<(*mit).second<<endl;

  // lb and ub of 1
  mit = m.lower_bound(1);
  cout<<"1 lb : "<<(*mit).first<<" "<<(*mit).second<<endl;
  mit = m.upper_bound(1);
  cout<<"1 ub : "<<(*mit).first<<" "<<(*mit).second<<endl;

  // lb and ub of 8
  mit = m.lower_bound(8);
  cout<<"8 lb : "<<(*mit).first<<" "<<(*mit).second<<endl;
  mit = m.upper_bound(8);
  cout<<"8 ub : "<<(*mit).first<<" "<<(*mit).second<<endl;


  return 0;
}