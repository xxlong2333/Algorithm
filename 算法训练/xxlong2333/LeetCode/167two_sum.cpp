#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//数组 2 7 11 15  有序数组
//target
//index1 index2 
class solution{

    vector<int>sumTwo(vector<int>&numbers,int target){

        int i=0;
        int j=numbers.size()-1;

        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum<target){
                i++;
            }else if(sum>target){
                j--;
            }else{
                return vector<int>{i+1,j+1};
            }

        }

        return vector<int>{-1,-1};
    }

    
    
};
int main(){

    return 0;
}