class Solution {
public:
    int binarySearch(vector<int>& arr, int l, int r) {
        int result = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == 1) {
                result = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return result + 1;
    }

    typedef pair<int, int> P;

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<P> countOnes;

        for (int row = 0; row < n; row++) {
            int num_of_ones = binarySearch(mat[row], 0, m - 1);

            countOnes.push_back({num_of_ones, row});
        }

        sort(countOnes.begin(), countOnes.end());

        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(countOnes[i].second);
        }

        return result;
    }
};