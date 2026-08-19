/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<vector<int>> sweep;
        for(int i = 0; i<intervals.size(); i++){
            sweep.push_back({intervals[i].start, 1});
            sweep.push_back({intervals[i].end, -1});
        }
        sort(sweep.begin(), sweep.end());
        int rooms = 0;
        int maxr = 0;
        for(const auto& i: sweep){
            rooms+=i[1];
            maxr = max(maxr, rooms);
        }
        return maxr;
    }
};
