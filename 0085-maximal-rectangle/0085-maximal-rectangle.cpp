class Solution {
private:    
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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
         int m=matrix.size();
        if(m==0) 
            return 0;
        int n=matrix[0].size(), result=0;
        vector<int> heights(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    heights[j]+=1;
                else
                    heights[j]=0;
            }
            
            result = max(result, largestRectangleArea(heights));
            cout<<result<<" ";
        }
        return result;
    }
};
