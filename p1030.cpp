#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        int num = costs.size();
        int result = 0;
        sort(costs.begin(),costs.end(),cmp);
        for(int i = 0;i<num/2;++i){
            result+=costs[i][0];
            result+=costs[i+num/2][1];
        }
        

        
        return result;
    }
    
    
    static bool cmp(vector<int> a, vector<int> b){
        return a[1]-a[0]>b[1]-b[0];
    }
};