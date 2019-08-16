// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5679549973004288

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    vector<int> triplet;
    int sum, i, l, r, N=arr.size();
    sort(arr.begin(), arr.end());
    for(i=0; i<N-2; i++) {
      l = i+1;
      r = N-1;
      while(l<r) {
        sum = arr[i]+arr[l]+arr[r];
        if(sum == 0) {
          triplet.push_back(arr[i]);
          triplet.push_back(arr[l]);
          triplet.push_back(arr[r]);
          triplets.push_back(triplet);
          triplet.clear();
          l++;
          r--;
        } else if(sum>0) {
          r--;
        } else {
          l++;
        }
      }
    }

    return triplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
  auto result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {-5, 2, -1, -2, 3};
  result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
