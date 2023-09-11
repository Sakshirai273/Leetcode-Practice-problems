class Solution {
public:
    int firstUniqChar(string s) {
     queue<int> q;
       int arr[26]={0};
       for(int i=0;i<s.length();i++){
           char ch=s[i];
           q.push(i);
           arr[ch-'a']++;
           while(!q.empty()){
               if(arr[s[q.front()]-'a']>1)
                    q.pop();
                else break;
           }
       }
        if(q.empty())
            return -1;
        return q.front(); 
    }
};