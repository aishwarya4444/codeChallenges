// prefix sum

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int, int> meet;
        int sum = 0;

        for(auto i: intervals) {
            meet[i[0]]++;
            meet[i[1]]--;
        }

        for(auto m: meet) {
            sum += m.second;
            if(sum>1) {
                return false;
            }
        }

        return true;
    }
};