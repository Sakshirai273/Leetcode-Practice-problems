class Solution {
public:
    int reverse(int x) {
        int revnum=0;
        while(x!=0)
        {
            int lastdig=x%10;
            if((revnum>INT_MAX/10) || (revnum<INT_MIN/10)) return 0; 
            revnum=revnum*10+lastdig;
            x=x/10;
        }
        return revnum;
    }
};
/*
To reverse an integer, we can repeatedly extract the last digit and build the reversed integer by adding the digits in reverse order.
We start with an initial value of 0 for the reversed integer and continuously add the last digit from the original number to the reversed integer.
By multiplying the reversed integer by 10 before adding the last digit, we shift the existing digits to the left, creating space for the new digit.
We divide the original number by 10 to remove the last digit in each iteration until the original number becomes 0.
To handle overflow, we check if the reversed integer exceeds the limits of a 32-bit signed integer before returning the result.
*/

