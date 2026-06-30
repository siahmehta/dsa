class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int cnt=0;
        vector<int> freq(256,0); 
        for(int right=0; right<n; right++){
            freq[s[right]]++;
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            cnt=max(cnt,right-left+1);
        }
        return cnt;
    }
};