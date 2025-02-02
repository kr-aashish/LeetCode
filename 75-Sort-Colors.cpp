class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int lo = 0, mid = 0, hi = n-1;
        while(mid<=hi) {
            if(a[mid]==1) mid++;
            else if(a[mid]==0) {
                swap(a[mid], a[lo]);
                mid++; lo++;
            }
            else {
                swap(a[mid], a[hi]);
                hi--;
            }
        }
        
    }
};