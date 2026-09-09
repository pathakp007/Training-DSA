class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n % 2 != 0){
            return {};
        }

        sort(begin(changed), end(changed));

        map<int, int> mp;

        for(int &num : changed){
            mp[num]++;
        }

        vector<int> result;

        for(int &num : changed){
            int twice = 2*num;

            if(mp[num] == 0){
                continue;
            } 

            if(mp.find(num) == mp.end() || mp[twice] == 0 ){
                return {};
            }

            result.push_back(num);
            mp[num]--;
            mp[twice]--;
        }

        return result;
        
    }
};