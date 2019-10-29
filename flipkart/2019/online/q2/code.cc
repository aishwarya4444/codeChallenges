#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'getUmbrellas' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY p
 */

int getUmbrellas(int n, vector<int> p) {
    int dp[p.size()][n+1];
    int r, c, umb1, umb2;

    // for 0 people we need 0 umbrella
    for(r=0; r<p.size(); r++) {
        dp[r][0] = 0;
    }

    for(r=0; r<p.size(); r++) {
        for(c=1; c<=n; c++) {
            umb1 = INT_MAX;
            umb2 = INT_MAX;
            if(c>=p[r]) {
                umb1 = dp[r][c-p[r]];
                if(umb1 != INT_MAX) {
                    umb1++;
                }
            }
            if(r>0) {
                umb2 = dp[r-1][c];
            }
            dp[r][c] = min(umb1, umb2);
        }
    }

    return dp[p.size()-1][n] == INT_MAX ? -1 : dp[p.size()-1][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_count_temp;
    getline(cin, p_count_temp);

    int p_count = stoi(ltrim(rtrim(p_count_temp)));

    vector<int> p(p_count);

    for (int i = 0; i < p_count; i++) {
        string p_item_temp;
        getline(cin, p_item_temp);

        int p_item = stoi(ltrim(rtrim(p_item_temp)));

        p[i] = p_item;
    }

    int result = getUmbrellas(n, p);

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
