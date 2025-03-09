class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int N = nums.size();
        
        int head = -1;
        int tail = 0;
        int ans = 0;
        int pdt = 1;
        
        while(tail<N) {
            while(head+1<N and pdt*nums[head+1]<k) {
                head++;
                pdt *= nums[head];
            }
            
            ans += head-tail+1;
            
            if(head<tail) {
                tail++;
                head = tail-1;
            } else {
                pdt /= nums[tail];
                tail++;
            }
        }
        
        return ans;
    }
};