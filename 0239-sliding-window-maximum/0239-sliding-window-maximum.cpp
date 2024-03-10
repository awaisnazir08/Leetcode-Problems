class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
       std::deque<int> dq;
       std::vector<int> max_values;
       
       for (int i = 0; i < k; i++) {
           while (!dq.empty() && nums[i] >= nums[dq.back()])
               dq.pop_back();
           dq.push_back(i);
       }
       
       for (int i = k; i < nums.size(); i++) {
           max_values.push_back(nums[dq.front()]);
           
           // Remove elements outside the window
           while (!dq.empty() && dq.front() <= i - k)
               dq.pop_front();
           
           // Remove elements that are smaller than the current element
           while (!dq.empty() && nums[i] >= nums[dq.back()])
               dq.pop_back();
           
           dq.push_back(i);
       }
       
       max_values.push_back(nums[dq.front()]);  // Add the maximum for the last window
       
       return max_values;
    }
};