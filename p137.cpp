#include <map>
#include <vector>
using namespace std;


/**
 * Two One B Two+ One+

    0  0  0  0  0

    0  0  1  0  1

    0  1  0  0  1

    0  1  1  1  0

    1  0  0  1  0

    1  0  1  0  0

    1  1  0  X  X

    1  1  1  X  X

    using two bit set to calculate the appearance of 1 in every bit.
    00 0
    01 1
    10 2

    So, 10 + 1 -> 00

 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++){
            one = (~two) & (one ^ nums[i]);
            two = (~one) & (two ^ nums[i]);
        }
        return one;
    }
};