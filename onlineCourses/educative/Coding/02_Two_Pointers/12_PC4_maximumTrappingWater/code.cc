// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5619753626370048

using namespace std;

#include <iostream>
#include <vector>

class WaterContainer {
 public:
  static int findMaxWater(const vector<int>& buildingHeights) {
    int maxArea = 0;
    // TODO: Write your code here
    int N=buildingHeights.size(), l=0, r=N-1, lh, rh;
    while(l<r) {
      lh = buildingHeights[l];
      rh = buildingHeights[r];
      if(lh<rh) {
        maxArea = max(maxArea, lh*(r-l));
        l++;
      } else {
        maxArea = max(maxArea, rh*(r-l));
        r--;
      }
    }
    return maxArea;
  }
};

int main(int argc, char* argv[]) {
  cout << WaterContainer::findMaxWater(vector<int>{1, 3, 5, 4, 1}) << endl;
  cout << WaterContainer::findMaxWater(vector<int>{3, 2, 5, 4, 2}) << endl;
  cout << WaterContainer::findMaxWater(vector<int>{1, 4, 3, 2, 5, 8, 4}) << endl;
}
