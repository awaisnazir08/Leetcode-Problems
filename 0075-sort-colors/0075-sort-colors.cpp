class Solution {
public:
    void sortColors(vector<int>& nums) {
        int current = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==0)
            {
                int temp = nums[current];
                nums[current] = nums[i];
                nums[i] = temp;
                current++;
            }
        }
        for(int i = current; i < nums.size(); i++)
        {
            if(nums[i]==1)
            {
                int temp = nums[current];
                nums[current] = nums[i];
                nums[i] = temp;
                current++;
            }
        }
        // for(int i = current; i < nums.size(); i++)
        // {
        //     if(nums[i]==2)
        //     {
        //         int temp = current[i];
        //         nums[current] = nums[i];
        //         nums[i] = current[i];
        //         current++;
        //     }
        // }
    }
};