#include <vector>
#include <map>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<int,int>,int> m;
        int size = points.size(),ret=0;
        if(size>2){ 
            for(int i = 0;i<size-ret;++i){
                m.clear();
                int repeats = 1;
                for(int j = i+1;j<size;++j){
                    if(points[j]!=points[i]){
                        int temp = ++m[slope(points[i],points[j])];
                        ret = ret>temp+repeats?ret:temp+repeats;
                    }
                    else ++repeats;
                }
                ret = ret>repeats?ret:repeats;
                for(auto itr:m) ret = ret>itr.second+repeats?ret:itr.second+repeats;
            }
            return ret;
        }
        else return size;
    }

private:
    pair<int,int> slope(const vector<int>& a, const vector<int>& b){
        int dx = a[0]-b[0], dy = a[1]-b[1];
        int gcdNum = gcd(dx,dy);
        dx = dx/gcdNum, dy = dy/gcdNum;
        if(dx<0){
            dx = -dx;
            dy = -dy;
        }
        return make_pair(dx,dy);
    }

    int gcd(int a, int b)
    {
        if (b)
            while((a %= b) && (b %= a));
        return a + b;
    }

};


int main(void){
    vector<vector<int>> vec = {{1,1},{1,1},{1,1}};
    Solution s;
    int t = s.maxPoints(vec);
    cout<<t<<endl;


    return 0;
}