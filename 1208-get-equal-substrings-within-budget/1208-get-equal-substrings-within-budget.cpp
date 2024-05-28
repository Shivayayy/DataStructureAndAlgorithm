class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len =0;
        int i =0,j =0;
        while(j<s.size())
        {
            maxCost =maxCost-(abs(s[j]-t[j]));
            while(i<=j&&maxCost<0)
            {
                maxCost =maxCost+abs(s[i]-t[i]);
                i++;
            }
            len =max(len,(j-i+1));
            j++;
        }
        return len;
    }
};