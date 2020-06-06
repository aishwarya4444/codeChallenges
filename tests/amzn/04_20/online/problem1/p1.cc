// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
struct compare {
    bool operator()(const pair<string, int> &p1, const pair<string, int> &p2) {
        if(p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

vector<string> topNCompetitors(int numCompetitors, int topNCompetitors,
							   vector<string> competitors,
							   int numReviews,
							   vector<string> reviews)
{
    // WRITE YOUR CODE HERE
    map<string, int> freq;
    string name;
    vector<string> result;
    vector<pair<string, int> > res;

    for(auto review: reviews) {
        transform(review.begin(), review.end(), review.begin(), ::tolower);
        for(auto competitor: competitors) {
            name = competitor;
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            if(review.find(name) != string::npos) {
                freq[competitor]++;
            }
        }
    }

    for(auto entry: freq) {
        res.push_back(entry);
    }

    sort(res.begin(), res.end(), compare());
    for(int n=0; n<min((int)res.size(), topNCompetitors); n++) {
        result.push_back(res[n].first);
    }
    return result;
}
// FUNCTION SIGNATURE ENDS