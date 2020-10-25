#include <iostream>
using namespace std;

// https://leetcode.com/problems/complement-of-base-10-integer/

class CalculateComplement {
    public:
    static int bitwiseComplement(int n) {
        // TODO: Write your code here
        int pow=0, num=n;

        if(num == 0) {
            pow = 1;
        }

        while(n) {
            pow++;
            n>>=1;
        }

        return ((1<<pow) - 1)^num;
    }
};

int main(int argc, char* argv[]) {
        // your code goes here
        cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
        cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}