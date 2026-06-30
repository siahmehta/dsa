class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),  m=p.size();
        vector<int> ans;
        vector<int> pfreq(26,0);
        vector<int> windowfreq(26,0);
        if(m>n){
            return ans;
        }
        for(char c:p){
            pfreq[c- 'a']++;
        }
        for(int i=0; i<m; i++){
            windowfreq[s[i]-'a']++;
        }
        if(windowfreq==pfreq){
            ans.push_back(0);
        }
        for(int i=m; i<n; i++){
            windowfreq[s[i]-'a']++;
            windowfreq[s[i-m]-'a']--;
        
        if(windowfreq==pfreq){
            ans.push_back(i-m+1);
        }
        }
        return ans;
    }
};