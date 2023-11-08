class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // O(1)
        // Finding the minimum number of required moves and checking if the t is greater than required number of moves or not. If t is greater then simply checking if both sx and fx and sy and fy are equal or not.
        int alongX = abs(fx - sx);
        int alongY = abs(fy - sy);
        int minCount = 0;
        if(alongX <= alongY){
            minCount += alongX + (alongY - alongX);
        }
        else minCount += alongY + (alongX - alongY);
        if(sx == fx and sy == fy) 
            return t != 1;
        return 
            t >= minCount;
    }
};