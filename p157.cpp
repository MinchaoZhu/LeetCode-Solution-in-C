#include <stdlib.h>
#include <string.h>

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0,extra;
        char buff4[4];
        while(count<=n){
            extra=read4(buff4);
            if(n-count<extra) extra = n-count;
            memcpy(buf+count,buff4,extra*sizeof(char));
            if(extra<4) return count+extra;
        }
        return count;
    }
};