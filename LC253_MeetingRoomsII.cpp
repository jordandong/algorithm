/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class Solution { 
public:
    int findNonOverlapping(vector<Interval>& rooms, Interval& interval) {
        int N = rooms.size();
        for (int i = 0; i < N; i++)
            if (interval.start >= rooms[i].end)
                return i;
        return -1;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> rooms;
        int N = intervals.size();
        for (int i = 0; i < N; i++) {
            int idx = findNonOverlapping(rooms, intervals[i]);
            if (rooms.empty() || idx == -1)
              rooms.push_back(intervals[i]);
            else
              rooms[idx] = intervals[i];
        }
        return (int)rooms.size();
    } 
private:
    static bool compare(Interval& interval1, Interval& interval2) {
        return interval1.start < interval2.start;
    }
};
