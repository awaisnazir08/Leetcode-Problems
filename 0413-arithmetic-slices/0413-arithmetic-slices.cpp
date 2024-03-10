class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 2; j < nums.size(); j++)
            {
                bool check = true;
                int difference = nums[j] - nums[j-1];
                int k = j;
                while(k>i)
                {
                    if(difference == (nums[k]-nums[k-1]))
                    {
                        k--;
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }
                if(k==i && check)
                {
                    sum++;
                }
                else
                {
                    break;
                }
            }
        }
        return sum;
    }
};