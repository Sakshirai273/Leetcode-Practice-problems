class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        int leftSmallerEle[n] , rightSmallerEle[n];
        
        for(int i = 0 ; i< n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty())
                leftSmallerEle[i]=0;
                else
                leftSmallerEle[i] = st.top() +1;
            st.push(i);
        }
        // clear the stack so that it will be reused
        while(!st.empty())
            st.pop();
        
        for(int i =n-1; i>=0;i--){
             while(!st.empty() && heights[st.top()] >= heights[i])
                 st.pop();
                 
        if(st.empty())
            rightSmallerEle[i] = n -1;
        else
            rightSmallerEle[i] = st.top()-1;
        
        st.push(i);
    }
    int maxA = 0 ;
    for(int i =0; i< n ; i++){
        maxA = max(maxA , heights[i] *(rightSmallerEle[i] - leftSmallerEle[i] +1));
    }
    return maxA;
    }
};