// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

struct compare {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first > p2.first;
    }
};

vector<int> lengthEachScene(vector<char> inputList)
{
    // WRITE YOUR CODE HERE
    map<char, vector<int> > m;
    int start, end, n, N=inputList.size();
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> minHeap;
    vector<int> result;
    vector<pair<int, int> > intervals;

    for(int n=0; n<N; n++) {
        m[inputList[n]].push_back(n);
    }

    for(auto entry: m) {
        start = entry.second[0];
        end = entry.second.back();
        minHeap.push(make_pair(start, end));
    }

    while(minHeap.size()) {
        auto minNode = minHeap.top();
        minHeap.pop();
        start = minNode.first;
        end = minNode.second;

        if(minHeap.size() && end>minHeap.top().first) {
            end = max(end, minHeap.top().second);
            minHeap.pop();
            minHeap.push(make_pair(start, end));
        } else {
            intervals.push_back(minNode);
        }
    }

    for(auto interval: intervals) {
        start = interval.first;
        end = interval.second;
        result.push_back(end-start+1);
    }

    return result;
}
// FUNCTION SIGNATURE ENDS