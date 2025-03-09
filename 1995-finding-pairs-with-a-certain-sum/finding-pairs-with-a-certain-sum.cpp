class FindSumPairs {
    unordered_map<int, int> hashMap;
    vector<int> vectorOne, vectorTwo;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vectorOne = nums1, vectorTwo = nums2;
        for (auto element : vectorTwo)
            hashMap[element]++;
    }
    
    void add(int index, int val) {
        hashMap[vectorTwo[index]]--;
        vectorTwo[index] += val;
        hashMap[vectorTwo[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (auto element : vectorOne)
            cnt += hashMap[tot - element];
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */