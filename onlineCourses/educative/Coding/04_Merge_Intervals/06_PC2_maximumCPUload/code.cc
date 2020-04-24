// https://www.educative.io/courses/grokking-the-coding-interview/xVlyyv3rR93

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Job {
 public:
  int start = 0;
  int end = 0;
  int cpuLoad = 0;

  Job(int start, int end, int cpuLoad) {
    this->start = start;
    this->end = end;
    this->cpuLoad = cpuLoad;
  }
};

// similar to
// https://leetcode.com/problems/car-pooling/

class MaximumCPULoad {
 public:
  struct compareStart {
    bool operator()(const Job &j1, const Job &j2) {
      return j1.start < j2.start;
    }
  };

  struct compareEnd {
    bool operator()(const Job &j1, const Job &j2) {
      return j1.end > j2.end;
    }
  };

  static int findMaxCPULoad(vector<Job> &jobs) {
    int maxCPULoad = 0;
    // TODO: Write your code here
    priority_queue<Job, vector<Job>, compareEnd> minHeap;
    int load=0, start, end;

    sort(jobs.begin(), jobs.end(), compareStart());
    for(auto job: jobs) {
      while(minHeap.size() && job.start>=minHeap.top().end) {
        load -= minHeap.top().cpuLoad;
        minHeap.pop();
      }
      load += job.cpuLoad;
      maxCPULoad = max(maxCPULoad, load);
      minHeap.push(job);
    }
    return maxCPULoad;
  }
};

int main(int argc, char *argv[]) {
  vector<Job> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;
}
