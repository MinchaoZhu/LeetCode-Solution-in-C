#include <algorithm>
#include <iostream>
#include <vector>
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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        sort(intervals.begin(),intervals.end() ,cmp);
        result.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();++i){
            if(intervals[i].start<=result.back().end){
                result.back().end = result.back().end>intervals[i].end?result.back().end:intervals[i].end;
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
private:
    static bool cmp(const Interval a, const Interval b){
        return a.start>b.start;
    }
};


int main(void){
    Solution s;
    vector<Interval> t;
    Interval i(1,3);
    t.push_back(i);
    i.start = 2;
    i.end = 6;
    t.push_back(i);
    t = s.merge(t);



    return 0;
}