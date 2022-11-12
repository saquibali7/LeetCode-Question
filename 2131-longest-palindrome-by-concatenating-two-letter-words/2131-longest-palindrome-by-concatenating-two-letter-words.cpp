class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string, int> m;
        for(auto i : words){
            m[i]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(words[i][0]!=words[i][1]){
                string temp = words[i];
                reverse(temp.begin(),temp.end());
                if(m.find(temp)!=m.end() && m[temp]>0 && m[words[i]]>0){
                    m[words[i]]--;
                    m[temp]--;
                    count+=4;
                }
            } else if(m[words[i]]>=2){
                count+=4;
                m[words[i]]-=2;
            }
        }
        for(auto i : m){
            if(i.first[0]==i.first[1] && i.second>0){
                count+=2;
                break;
            }
        }
        return count;
    }
};