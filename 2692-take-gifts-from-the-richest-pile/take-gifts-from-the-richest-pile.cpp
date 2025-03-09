class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> reducedGifts;
        for (auto gift : gifts) {
            reducedGifts.push(gift);
        }

        int iterations = k;
        while (!reducedGifts.empty() and iterations--) {
            int maxPile = reducedGifts.top();
            reducedGifts.pop();
            reducedGifts.push(sqrt(maxPile));
        }

        long long remainingGifts = 0;
        while (!reducedGifts.empty()) {
            remainingGifts += reducedGifts.top();
            reducedGifts.pop();
        }

        return remainingGifts;
    }
};