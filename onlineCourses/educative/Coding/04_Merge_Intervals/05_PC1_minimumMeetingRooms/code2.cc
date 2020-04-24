class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> meet;
        int sum = 0, rooms = 0;

        for(auto i: intervals) {
            meet[i[0]]++;
            meet[i[1]]--;
        }

        for(auto m: meet) {
            sum += m.second;
            rooms = max(rooms, sum);
        }

        return rooms;
    }
};