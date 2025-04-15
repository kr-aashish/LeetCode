class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int pointerOne = 0;
        int pointerTwo = 0;

        vector<vector<int>> numsMerged;
        while (pointerOne < nums1.size() and pointerTwo < nums2.size()) {
            auto pairOne = nums1[pointerOne];
            auto pairTwo = nums2[pointerTwo];

            if (pairOne[0] < pairTwo[0]) {
                numsMerged.push_back(pairOne);
                pointerOne++;
            } else if (pairOne[0] > pairTwo[0]) {
                numsMerged.push_back(pairTwo);
                pointerTwo++;
            } else {
                numsMerged.push_back({pairOne[0], pairOne[1] + pairTwo[1]});
                pointerOne++;
                pointerTwo++;
            }
        }

        while (pointerOne < nums1.size()) {
            auto pair = nums1[pointerOne];
            numsMerged.push_back(pair);
            pointerOne++;
        } 

        while (pointerTwo < nums2.size()) {
            auto pair = nums2[pointerTwo];
            numsMerged.push_back(pair);
            pointerTwo++;
        }

        return numsMerged;
    }
};