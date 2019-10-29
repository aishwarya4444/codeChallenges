#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'efficientJanitor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts FLOAT_ARRAY weight as parameter.
 */
int findSmallIndex(vector<float> &small, float w) {
    int l=0, m, r=small.size()-1;
    if(r==-1 || w>small[r] || w<small[0]) {
        return -1;
    }
    while(l<=r) {
        m = l+(r-l)/2;
        if(w == small[m]) {
            return m;
        } else if(w<small[m]) {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return r;
}

int efficientJanitor(vector<float> weight) {
    // max heap containing weights in range (1.5, 2]
    priority_queue<float> big;
    // array containing weights in range [1.0, 1.5]
    vector<float> small;
    int trip=0, index;
    float bag;
    for(auto w: weight) {
        if(w > 2.0) {
            trip++;
        } else if(w > 1.5) {
            big.push(w);
        } else {
            small.push_back(w);
        }
    }
    sort(small.begin(), small.end());
    while(big.size()) {
        bag = big.top();
        big.pop();
        index = findSmallIndex(small, 3.0-bag);
        if(index != -1) {
            small.erase(small.begin()+index);
        }
        trip++;
    }
    trip = trip + small.size()/2 + small.size()%2;
    return trip;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string weight_count_temp;
    getline(cin, weight_count_temp);

    int weight_count = stoi(ltrim(rtrim(weight_count_temp)));

    vector<float> weight(weight_count);

    for (int i = 0; i < weight_count; i++) {
        string weight_item_temp;
        getline(cin, weight_item_temp);

        float weight_item = stof(ltrim(rtrim(weight_item_temp)));

        weight[i] = weight_item;
    }

    int result = efficientJanitor(weight);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
