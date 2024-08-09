#include<iostream>
#include<cstring>

using namespace std;

int main() {
    int T, N;
    int n, start, end=0, res, ones;
    string att;

    cin>>T;

    while(T--) {
        cin>>N;
        cin>>att;
        res = 0;
        ones = 0;
        start = 0;

        for(end=0; end<N; end++) {
            if(att[end] == '1') {
                ones++;
            }
            while(ones+1 < end-start+1) {
                if(att[start] == '1') {
                    ones--;
                }
                start++;
            }
            res = max(res, end-start+1);
        }
        cout<<res<<endl;
    }

    return 0;
}

/*
1
7
0110011
*/