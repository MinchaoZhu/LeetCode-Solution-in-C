class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if(size == 0)
            return 0;
        int l = 0, r = size - 1, m = (l + r)/2;
        while(l < r){
            m = (r - l)/2 + l;
            int c = citations[m];
            if(size - m > c){
                l = m + 1;
            }
            else if(size - m < c){
                r = m;
            }
            else{
                return c;
            }
        }
        
        if(r == size - 1){
            return citations[r] > 0 ;
        }
        
        return size - r;
    }
};