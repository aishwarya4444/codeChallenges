/*
https://codeforces.com/problemset/problem/706/B
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int SHOPS, DAYS, price;
  vector<int> prices;

  cin>>SHOPS;
  while(SHOPS--) {
    cin>>price;
    prices.push_back(price);
  }

  sort(prices.begin(), prices.end());

  cin>>DAYS;
  while(DAYS--) {
    cin>>price;
    cout<<upper_bound(prices.begin(), prices.end(), price)-prices.begin()<<endl;
  }

  return 0;
}
