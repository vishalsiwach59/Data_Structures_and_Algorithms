class Solution {
    int mini(vector<int> &nums,int l,int h){
        while(l< h)
        {
            int mid = l + (h - l)/2;
            if (nums[mid] == nums[h])
                h--;
            else if(nums[mid] > nums[h])
                l = mid + 1;
            else
                h = mid;
        }
        return nums[h];
    }
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        return mini(nums,0,nums.size()-1);
    }
};
