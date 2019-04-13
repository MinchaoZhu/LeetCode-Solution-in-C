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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.size()<=1)
            return intervals;
        map<int,int> m;
        for(int i = 0;i<intervals.size();++i){
            if(m.find(intervals[i].start)==m.end())
                m.insert(pair<int,int>(intervals[i].start,intervals[i].end));
            else
                m.find(intervals[i].start)->second = m.find(intervals[i].start)->second>intervals[i].end?m.find(intervals[i].start)->second:intervals[i].end;
        }
        map<int,int>::iterator mit = m.begin();
        Interval temp;
        temp.start = mit->first;
        temp.end = mit->second;
        ++mit;
        result.push_back(temp);
        for(;mit!=m.end();++mit){
            if(mit->first<=result.back().end){
                result.back().end = result.back().end>mit->second?result.back().end:mit->second;
            }
            else{
                temp.start = mit->first;
                temp.end = mit->second;
                result.push_back(temp);
            }
        }
        return result;
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