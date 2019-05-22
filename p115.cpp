#include <vector>
#include <string>
#include <iostream>
using namespace std;



class Solution {
public:
    int numDistinct(string s, string t) {
		/* the count of matching threads at each index of t */
        vector<uint64_t> threads(t.size(), 0);

		// iterate string s, see whether each s[i] opens (or moves forward) some matching threads
        for(int i=0;i<(int)s.size();i++){
			// iterate matching threads in reverse, see if there's any matches
            for(int j=threads.size()-1;j<threads.size();j--){				
                if(j==0){
					// if this is the first char of t, we record a "match" so far as this char equals to s[i]
                    if(t[j]==s[i])
                        threads[j]++;
                }else{
					// otherwise, if t[j-1] "wants" char s[i] to move forward, we add the thread count of threads[j-1] to threads[j]
                    if(j<(int)t.size() && t[j]==s[i])
                        threads[j]+=threads[j-1];
                }
            }
        }

        return threads.back();
    }
};




int main(void){
    string s = "rabbbit";
    string t = "rabbit";
    int i=0;
    Solution ss;
    i = ss.numDistinct(s,t);
    cout<<i<<endl;

    return 0;
}