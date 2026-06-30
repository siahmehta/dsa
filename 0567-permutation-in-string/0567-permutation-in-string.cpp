class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<int> s1freq(26,0);
        vector<int> windowfreq(26,0);
        if(m>n){
            return false;
        }
        for(char c:s1){
            s1freq[c-'a']++;
        }
        for(int i=0; i<m; i++){
            windowfreq[s2[i]-'a']++;
        }
        if(s1freq==windowfreq){
            return true;
        }
        for(int i=m;i<n; i++){
            windowfreq[s2[i]-'a']++;
            windowfreq[s2[i-m]-'a']--;
            if(windowfreq==s1freq){
                return true;
            }
        }
        return false;
    }
};