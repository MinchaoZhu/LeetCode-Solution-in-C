#include <vector>
#include <map>
#include <math.h>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        int ret = 0;
        map<pair<int,int>,int> m;
        if(size>2){
            for(int i = 0;i<=size-ret;++i){
                m.clear();
                int repeat = 1;
                for(int j = i+1;j<size;++j){
                    if(points[i]==points[j])++repeat;
                    else{
                        int t = (++m[slope(points[i],points[j])]);
                        ret = ret>(t+repeat)?ret:(t+repeat);
                    }
                }
                ret = ret>repeat?ret:repeat;
                for(auto mItr : m) ret = ret>mItr.second+repeat?ret:mItr.second+repeat;
            }
            return ret;
        }
        else return size;
    }

private:
    pair<int,int> slope(vector<int> p0, vector<int> p1)
    {   
        int dx = p0[0]-p1[0], dy = p0[1]-p1[1];
        int gcdNum = gcd(abs(dx), abs(dy));
        dx = dx/gcdNum, dy = dy/gcdNum;
        if(dx<0){
            dx = -dx;
            dy = -dy;
        }
        else if(dx == 0&&dy!=0){
            dy = 1;
        }
        if(dy==0&&dx!=0){
            dx = 1;
        }
        return pair<int,int>(dx,dy);
    }

    int gcd(int a, int b){
        return b==0?a:gcd(b, a%b);
    }
};


int main(void){
    vector<vector<int>> vec = {{1,1},{1,1},{1,1}};
    Solution s;
    int t = s.maxPoints(vec);
    cout<<t<<endl;


    return 0;
}