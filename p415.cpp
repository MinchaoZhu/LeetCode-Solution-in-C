class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length() > num2.length()){
            num1.swap(num2);
        }
        int len1 = num1.length(), len2 = num2.length();
        
        list<char> l;
        
        int res = 0;
        int i = 1;
        while(i <= len1){
            char sum = num1[len1 - i]-'0' + num2[len2 - i++] - '0' + res;
            res = sum/10;
            sum = (sum%10) + '0';
            l.push_front(sum);
        }
        while(i <= len2){
            char sum = num2[len2 - i++] - '0' + res;
            res = sum/10;
            sum = (sum%10) + '0';
            l.push_front(sum);
        }
        if(res > 0){
            l.push_front('1');
        }
        
        
        string result = "";
        for(auto c : l){
            result += c;
        }
        
        return result;
    }
};