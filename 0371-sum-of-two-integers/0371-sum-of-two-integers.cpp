class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0)
        return a;
        int sum = a ^ b;
        b = (a&b) ;
       b = (unsigned) b<< 1;
        sum = getSum(sum,b);
       return sum; 
}  
    };
//XOR for addition, AND for carry bit
