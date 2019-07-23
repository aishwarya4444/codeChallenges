// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5689922476310528

#include<iostream>
#include<cstring>
using namespace std;

bool help(string &a, string &b, string &ab, int i, int j) {
  if(i == a.size() && j == b.size()) {
    return true;
  }
  if(i > a.size() || j > b.size()) {
    return false;
  }
  return ( (a[i] == ab[i+j]) && help(a, b, ab, i+1, j) ) ||
         ( (b[j] == ab[i+j]) && help(a, b, ab, i, j+1) );
}

bool isInterleaving(string a, string b, string ab) {
  if(a.size()+b.size() != ab.size()) {
    return false;
  }
  return help(a, b, ab, 0, 0);
}

int main() {
  cout<<isInterleaving("abd", "cef", "abcdef")<<'\n';
  cout<<isInterleaving("abd", "cef", "adcbef")<<'\n';
  cout<<isInterleaving("abc", "def", "abdccf")<<'\n';
  cout<<isInterleaving("abcdef", "mnop", "mnaobcdepf")<<'\n';
  return 0;
}
