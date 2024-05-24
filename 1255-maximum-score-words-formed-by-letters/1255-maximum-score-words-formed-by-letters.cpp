class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    void scorer(vector<string>& words, vector<int>& count, vector<int>& score,int ind,int sum,int &ans)
    {
        if(ind == words.size())
        {
            ans =max(sum,ans);
            return;
        }
        scorer(words,count,score,ind+1,sum,ans);
        int temp =0;
        vector<int>tempCount =count;
        bool flag =false;
        for(int i=0;i<words[ind].size();i++)
        {
            int alp =words[ind][i]-'a';
            if(count[alp]>0)
            {
                count[alp]--;
                temp += score[alp];
            }
            else
            {
                flag =true;
                break;
            }
        }
        if(!flag)scorer(words,count,score,ind+1,sum+temp,ans);
        count = tempCount;

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        vector<int>count(26,0);
        for(int i=0;i<letters.size();i++)count[letters[i]-'a']++;
        int ans =INT_MIN;
        scorer(words,count,score,0,0,ans);
        return ans;
    }
};