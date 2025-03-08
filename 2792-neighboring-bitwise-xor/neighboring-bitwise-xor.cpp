// https://leetcode.com/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-01-17
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        
        // Helper function to check validity with a given start
        auto isValid = [&](int firstElement) {
            vector<int> original(n);
            original[0] = firstElement;
            
            // Compute the rest of the array
            for (int i = 1; i < n; ++i) {
                original[i] = derived[i - 1] ^ original[i - 1];
            }
            
            // Check the cyclic condition
            return (original[n - 1] ^ original[0]) == derived[n - 1];
        };
        
        // Try both possible starting values
        return isValid(0) || isValid(1);
    }
};