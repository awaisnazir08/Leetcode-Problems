class Solution {
public:

    bool isSorted(const vector<int>& arr)
    {
        if(arr.empty()) return true;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i]< arr[i-1]) return false;
        }
        return true;
    }
    // vector<int> reverseArray()
    int maxIndex(const vector<int>& arr, int end)
    {
        if(arr.empty())
        {
            return -1;
        }
        int max = 0;
        int maxValue = arr[0];
        for(int i = 1; i < end; i++)
        {
            if((arr[i]>= maxValue)) 
            {
                max = i;
                maxValue = arr[i];
            }
        }
        return max;
    }

    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        if(isSorted(arr))
        {
            return res;
        }
        int end = arr.size();
        while(!isSorted(arr))
        {
            int m = maxIndex(arr, end);
            if(m == 0)
            {
                std::reverse(arr.begin(), arr.begin() + end);
                res.push_back(end);
                end--;
            }
            else if(m==end-1)
            {
                end--;
            }
            else
            {
                std::reverse(arr.begin(), arr.begin() + m + 1);
                res.push_back(m+1);
            }
        }
        return res;
    }
};