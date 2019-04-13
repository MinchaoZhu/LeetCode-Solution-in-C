#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i=0;
        while(i < intervals.size() && intervals[i].end < newInterval.start){
            res.push_back(intervals[i]);
            i++;
        }
        while(i< intervals.size() && intervals[i].start <= newInterval.end){
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            i++;
        }
        res.push_back(newInterval);
        while(i< intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};

int main(void){
    Solution s;
    vector<Interval> t;
    Interval i(0,4);
    t.push_back(i);
    
    i.start = 7;
    i.end = 12;
    t.push_back(i);
    /*
    i.start = 16;
    i.end = 22;
    t.push_back(i);
    /*
    i.start = 8;
    i.end = 10;
    t.push_back(i);
    i.start = 4;
    i.end = 8;
    t = s.insert(t,i); 
    */
       i.start = 0;
    i.end =5;
    s.insert(t,i);

    return 0;
}