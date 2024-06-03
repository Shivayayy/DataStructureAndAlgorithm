class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int j=0;
        for(int i=0;i<s.size();i++)if(s[i] == t[j]) j++;
        return t.size()-j;
    }
};