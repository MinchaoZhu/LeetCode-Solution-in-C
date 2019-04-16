#include <iostream>
#include <vector>
#include <string>
using namespace std;




class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int width, first = 0, last, count, spaceNum;
        int size = words.size();
        vector<string> result;
        if(!size){
            string newStr;
            newStr.append(maxWidth+1,' ');
            result.push_back(newStr);
            return result;
        }
        while(last<size){
            string newStr;
            width = 0;count = 0;last = first;

            while((width+words[last].length())<=maxWidth){
                width +=words[last].length()+1;
                ++last;
                ++count;
                if(last>=size){
                    goto loopEnd;  
                }
            }            
            if(count==1){
                newStr.append(words[first]);
                newStr.append(maxWidth-width+1,' ');
                result.push_back(newStr);
                first=last;
                continue;
            }
            if(width==maxWidth+1){
                --width;
                spaceNum = count -1;
            }
            else spaceNum = maxWidth-width+count;

            int ave = spaceNum/(count-1);
            int aveNumPlusOne = spaceNum%(count-1);
            int i = 0;
            for(;i<aveNumPlusOne;++i){
                newStr.append(words[first+i]);
                newStr.append(ave+1,' ');
            }
            for(;i<count-1;++i){
                newStr.append(words[first+i]);
                newStr.append(ave,' ');
            }
            newStr.append(words[last-1]);
            result.push_back(newStr);
            first=last;
        }
    loopEnd:
        if(first<size){
            string newStr;width = 0;
            for(int i = first;i<size;++i){
                newStr.append(words[i]);
                width+=words[i].length()+1;
                if(width<=maxWidth)
                    newStr.append(1,' ');
            }
            newStr.append((maxWidth-width)>0?(maxWidth-width):0,' ');
            result.push_back(newStr);
        }
        return result;
    }
};




int main(void){
    vector<string> vs ={"Listen","to","many,","speak","to","a","few."};
    vector<string> newVs;
    Solution s;
    newVs = s.fullJustify(vs,6);

    for(int i = 0;i<newVs.size();++i){
        cout<<newVs[i]<<endl;
    }
    return 0;
}