class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string word="";
        int i=0;
        while(i<s.size())
        {
            //cout<<ans.size()<<" index "<<i<<" char at that index "<<s[i]<<" word is "<<word<<" and ans is "<<ans<<endl;
            if(ans.size()&&s[i]==' ')
            {
                ans = word+" "+ans;
                word ="";
            }
            else if(!ans.size()&&s[i]==' ')
            {
                ans =word;
                word="";
            }
            while(i<s.size()&&s[i]==' ')i++;
            if(i<s.size())word =word+s[i];
            i++;
        }
        if(!ans.size())return word;
        return (word.size()>0)?word+" "+ans:ans;
    }
};