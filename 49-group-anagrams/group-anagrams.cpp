class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string> > result;

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++){
            string temp = strs[i];

            sort(begin(temp), end(temp));

            mp[temp].push_back(strs[i]);
        }

        for(auto ip: mp){
            result.push_back(ip.second);
        }

        return result;
    }
};