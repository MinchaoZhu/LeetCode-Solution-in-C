class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& l, const vector<int>& r){
            return l[0] < r[0];
        }; 
        sort(intervals.begin(), intervals.end(), cmp); 
        
        vector<pair<int, int>> rooms;
        for(auto i : intervals){
            int j = 0; 
            for(; j < rooms.size(); ++j){
                if(rooms[j].second <= i[0]){
                    rooms[j].second = i[1];
                    break;
                }
            }
            
            if(j >= rooms.size()){
                rooms.emplace_back(pair<int, int>(i[0], i[1]));
            }
        }
        
        return rooms.size();
    }
};