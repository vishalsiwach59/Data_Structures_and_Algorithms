//https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
class Solution {
    int sea(vector<int>& nums,int l,int e,int target){
        if(l>e){
            return -1;
        }
        int mid=l+(e-l)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[l]<=nums[mid]){
            if(target>=nums[l]&&target<nums[mid]){
                return sea(nums,l,mid-1,target);
            }
            return sea(nums,mid+1,e,target);
        }
        if(target>nums[mid]&&target<=nums[e]){
            return sea(nums,mid+1,e,target);
        }
        return sea(nums,l,mid-1,target);
        
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        return sea(nums,0,nums.size()-1,target);
    }
};
