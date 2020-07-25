// https://leetcode.com/problems/3sum-closest/submissions/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX;
        int mini=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            int x=nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){

                if(x+nums[l]+nums[r]==target){
                    return target;
                }
                else if(x+nums[l]+nums[r]<target){
                    int s=x+nums[l]+nums[r];
                    int y=abs(target-s);
                    if(y<mini){
                        mini=y;
                        ans=s;
                    }
                    l++;
                }
                else{
                    int s=x+nums[l]+nums[r];
                    int y=abs(s-target);
                    if(y<mini){
                        mini=y;
                        ans=s;
                    }
                    r--;
                }
            }
        }
        return ans;
    }
};
