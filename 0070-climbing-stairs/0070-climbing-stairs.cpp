class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return 1;
        }
        else
        {
            int sum = 0;
            int a = 0;
            int b = 1;
            for(int i = 0; i <= n+1; i++)
            {
                sum += a;
                a = b;
                b = sum;
            }
            return sum;
        }
    }
};