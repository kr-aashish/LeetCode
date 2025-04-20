class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (auto answer : answers) {
            freq[answer]++;
        }

        int count = 0;
        for (auto keyPair : freq) {
            int freqValue = keyPair.first;
            int updatedFreqValue = freqValue + 1;
            int occurance = keyPair.second;

            int ceilValue = (occurance + updatedFreqValue - 1) / updatedFreqValue;
            count += ceilValue * updatedFreqValue; 
        }
        return count;
    }
};