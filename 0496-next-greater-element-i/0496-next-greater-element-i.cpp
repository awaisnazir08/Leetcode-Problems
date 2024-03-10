class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> result;
        for(int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    if(j+1 == nums2.size())
                    {
                        result.push_back(-1);
                        break;
                    }
                    for(int k = j + 1; k < nums2.size(); k++)
                    {
                        if(nums2[j] < nums2[k])
                        {
                            result.push_back(nums2[k]);
                            break;
                        }
                        else if(((k+1)>= nums2.size()) &&(nums2[j]>=nums2[k]))
                        {
                            result.push_back(-1);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return result;
    }
};