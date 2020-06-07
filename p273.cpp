class Solution {
public:
    string numberToWords(int num) {
        string result = "";
        if(num==0)
            return "Zero";
        
        int d0 = num/1000000000;
        int d1 = (num%1000000000)/1000000;
        int d2 = (num%1000000)/1000;
        int d3 = num%1000;
        
        if(d0>0){
            result += threeDigitsToString(d0) + " Billion ";   
        }
        if(d1>0){
            result += threeDigitsToString(d1) + " Million ";
        }
        if(d2>0){
            result += threeDigitsToString(d2) + " Thousand ";
        }
        if(d3>0){
            result += threeDigitsToString(d3) + " ";
        }
        
        return result.substr(0, result.length()-1);
    }
    
private:
    string threeDigitsToString(int num){
        int d0 = num/100;
        int d1 = (num%100)/10;
        int d2 = num%10;
        string result = "";
        
        if(d0>0){
            result += oneDigitsToString(d0)+" Hundred ";   
        }
        
        if(d1>0){
            result += twoDigitsToString(num%100) + " ";
        }
        else{
            if(d2>0)
                result += oneDigitsToString(d2) + " ";
        }
        
        return result.substr(0, result.length()-1);
    }
    
    string twoDigitsToString(int num){
        int d0 = num/10, d1 = num%10;
        if(num == 10) return "Ten";
        if(num == 11) return "Eleven";
        if(num == 12) return "Twelve";
        if(num == 13) return "Thirteen";
        if(num == 14) return "Fourteen";
        if(num == 15) return "Fifteen";
        if(num == 16) return "Sixteen";
        if(num == 17) return "Seventeen";
        if(num == 18) return "Eighteen";
        if(num == 19) return "Nineteen";
        
        string result = "";
        
        switch(d0){
            case 2: result = "Twenty";break;
            case 3: result = "Thirty";break;
            case 4: result = "Forty";break;
            case 5: result = "Fifty";break;
            case 6: result = "Sixty";break;
            case 7: result = "Seventy";break;
            case 8: result = "Eighty";break;
            case 9: result = "Ninety";break;
            default: ;    
        }
        if(d1>0)
            result += " " + oneDigitsToString(d1);
        
        return result;
    }

    string oneDigitsToString(int num){
        switch(num){
            case 0: return "Zero";
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            default: return "";
        }
    }
    
};