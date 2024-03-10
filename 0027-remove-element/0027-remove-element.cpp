class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i=0; i<nums.size();) {
            if (nums[i]==val) {
                nums.erase(nums.begin()+i);
            //break; // Exit loop once the element is found and removed
            }
            else{
                i++;
            }
        }
        return nums.size();
    }
};