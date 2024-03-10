class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string fE=strs.front();
        bool check;
        string prefix="";
        if(strs.size()==1)
        {
            return strs[0];
        }
        for (int i=1; i<strs.size(); i++) {
            string num=strs[i];
            if(prefix=="")
            {
                for (int j=0;j<(num.length()<fE.length()?num.length():fE.length()); )
                {
                    if(fE[j]==num[j])
                    {
                        prefix+=num[j];
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(prefix=="")
                {
                    return "";
                }
            }
            else
            {
                string updatedPrefix=prefix;
                while(updatedPrefix.length()>=1)
                {
                    // check=num.find(updatedPrefix);
                    size_t place=num.find(updatedPrefix);
                    if (place==0)
                    {
                        prefix=updatedPrefix;
                        break;
                    }
                    else{
                        updatedPrefix.pop_back();
                    }
                }
                if(updatedPrefix.length()<1)
                {
                    return "";
                }
                
            }
            
        }
        return prefix;
    }
};