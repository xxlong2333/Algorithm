#include<iostream>
using namespace std;
#include<cmath>

/*
    非负数 c 判断是否存在 a*a+b*b=c

    平方数之和
    0<=c=<2^31-1 


*/

class Solution{
    public:
    bool judgeSquareSum(int c){
        int l=0;
        int r=sqrt(c);

         if(l*l+l*l>c){
            return false;
        }

        if(r*r+r*r<c){
            return false;
        }
    
        while(l<=r){
            long sum=l*l+r*r;
            if(sum<c){
                l++;        
            }else if(sum>c){
                r--;
            }else{
                return true;
            }
        }   
        return false;
    }
    
};

class Solution2{
    public:
        bool judgeSquareSum(int c){
            
            for(long a=0;a*a<c;a++){
                double b=sqrt(c-a*a);
                if(b==int(b)){
                    return true;
                }
            }
            return false;
        }
};
int main(){
    Solution s1;
    
    int c=5;
    cout<<s1.judgeSquareSum(c)<<endl;
    cout<<s1.judgeSquareSum(3)<<endl;
    cout<<s1.judgeSquareSum(4)<<endl;

    return 0;
}