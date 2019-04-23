#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows==0)return 0;
        int cols = matrix[0].size();
        if(cols==0)return 0;
        int row = searchWhichRow(matrix,target,rows-1);
        if(row>=0){
            return searchTarget(matrix,target,row,cols-1);
        }
        else
            return 0;
    }

private:
    int searchWhichRow(vector<vector<int>>& matrix, int target, int end){
        int begin = 0, mid = (begin+end)/2;
        if(target<matrix[0][0])return -1;
        else if(target >matrix[end][0])return end;
        while(begin<end){
            mid = (begin+end)/2;
            if(matrix[mid][0]>target){
                end = mid;
            }
            else if(matrix[mid][0]<target){
                begin = mid+1;
            }
            else return mid;
        }  
        if(matrix[begin][0]==target)return begin;
        return begin-1;
    }

    bool searchTarget(vector<vector<int>>& matrix, int target, int row, int end){
        int begin = 0, mid = (begin+end)/2;
        while(begin<end){
            mid = (begin+end)/2;
            if(matrix[row][mid]>target){
                end = mid;
            }
            else if(matrix[row][mid]<target){
                begin = mid+1;
            }
            else return 1;
        }  
        if(matrix[row][begin]==target)return 1;
        return 0;
    }
};




int main(void){
    vector<vector<int>> m = {{1},{3}};
50;
    Solution s;
    bool x;
    x = s.searchMatrix(m,4);
    cout<<x<<endl;

    return 0;
}