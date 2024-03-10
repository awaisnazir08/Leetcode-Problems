
class Solution {
    vector<int> nextSmallerElement(vector<int> v) {
    stack<int> s;
    vector<int> result;
    for (int i = v.size() - 1; i >= 0; i--) {
        while (!s.empty() && v[s.top()] >= v[i]) {
            s.pop();
        }
        result.push_back(s.empty() ? -1 : s.top());
        s.push(i);
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> prevSmallerElement(vector<int> v) {
    stack<int> s;
    vector<int> result;
    for (int i = 0; i < v.size(); i++) {
        while (!s.empty() && v[s.top()] >= v[i]) {
            s.pop();
        }
        result.push_back(s.empty() ? -1 : s.top());
        s.push(i);
    }
    return result;
}








public:
    int largestRectangleArea(vector<int>& heights) {
        vector <int> next;
        vector <int> prev;
        next = nextSmallerElement(heights);
        prev = prevSmallerElement(heights);
        int area = INT_MIN;
        for(int i = 0; i < heights.size(); i++)
        {
            int l = heights[i];
            if(next[i] == -1)
            {
                next[i] = heights.size();
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;

    }
};