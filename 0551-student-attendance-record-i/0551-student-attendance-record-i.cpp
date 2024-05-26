class Solution {
public:
    bool checkRecord(string s) {
        int Absent =0;
        int late =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='L')late++;
            else 
            {
                late =0;
                if(s[i] == 'A')Absent++;
            }
            if(Absent>=2 ||late>=3)return false;
        }
        return true;
    }
};