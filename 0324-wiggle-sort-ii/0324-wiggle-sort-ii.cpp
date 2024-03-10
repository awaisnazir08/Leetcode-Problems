class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int mid = nums.size()/2;
        int sec_array_start = mid;
        int left = 0;
        vector<int>f;
        while(left < mid && sec_array_start<nums.size())
        {
            f.push_back(nums[sec_array_start]);
            f.push_back(nums[left]);
            left++;
            sec_array_start++;
        }

        while(sec_array_start<nums.size())
        {
            f.push_back(nums[sec_array_start++]);
        }
        while(left<mid)
        {
            f.push_back(nums[left++]);
        }
        nums = f;

    }
};