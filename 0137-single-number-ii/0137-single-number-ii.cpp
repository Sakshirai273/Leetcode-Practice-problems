class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(32,0);
        for(int i=0;i<n;i++){
            int temp=nums[i];
            if(temp<0)
                continue;
            int cnt=31;
            while(temp!=0){
                int lastbit=temp&1;
                ans[cnt]+=lastbit;
                cnt--;
                temp=temp>>1;
            }
        }
        long long finalans=0;
        for(int i=31;i>=0;i--){
            ans[i]=ans[i]%3;
            if(ans[i]==1){
                finalans+=pow(2,(31-i));
            }
        }
        
        if(finalans>0)
        return finalans;
        
        for(int i=0;i<n;i++){
            long long temp = nums[i];
            if(temp>=0)
                continue;
            temp*=-1;
            int cnt=31;
            while(temp!=0){
                int lastbit=temp&1;
                ans[cnt]+=lastbit;
                cnt--;
                temp=temp>>1;
            }
        }
        for(int i=31;i>=0;i--){
            ans[i]=ans[i]%3;
            if(ans[i]==1){
                finalans+=pow(2,(31-i));
            }
        }
        return finalans*-1;
    }
};