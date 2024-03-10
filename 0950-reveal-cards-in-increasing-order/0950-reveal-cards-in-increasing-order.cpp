class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n);
        queue<int> q;
        sort(deck.begin(), deck.end());
        for(int i = 0; i < n; i++)
        {
            q.push(i);
        }
        for(int i = 0; i<n; i++)
        {
            res[q.front()]= deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};