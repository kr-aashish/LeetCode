//freq bag
int freq[100100];
int cnt;
void intialise()
{
    memset(freq,0,sizeof(freq));
    cnt = 0;
}
void add(int x)
{
    if(freq[x]==0) cnt++;
    freq[x]++;
}
void remove(int x)
{
    freq[x]--;
    if(freq[x]==0) cnt--;
}

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int N = nums.size();
        
        int head = -1;
        int tail = 0;
        int ans = 0;
        
        int head1 = -1;
        intialise();
        
        while(tail<N)
        {
            // if(head+1<N and cnt<k)
            while(head+1<N and cnt<k)
            {
                head++;
                add(nums[head]);
            }
            
            // while(freq[nums[head1+1]]!=0 and head1+1<N) -- wrongg
            while(head1+1<N and freq[nums[head1+1]]!=0)
            {
                head1++;
            }
            
            // cout<<head<<" "<<head1<<"\n";
            if(cnt==k) ans += head1-head+1;
            
            if(tail>head)
            {
                tail++;
                head = tail-1;
            }
            else
            {
                remove(nums[tail]);
                tail++;
            }
        }
        
        return ans;
                        
    }
};

