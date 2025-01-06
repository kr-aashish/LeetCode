class Solution {
    int getCostForMovingAllBalls(string boxes, int index) {
        int cost = 0;
        for (int i = 0; i < boxes.length(); i++) {
            if (boxes[i] == '1') {
                cost += abs(index - i);
            }
        }
        return cost;
    }

public:
    vector<int> minOperations(string boxes) {
        vector<int> cost;

        vector<int> costs;
        for (int i = 0; i < boxes.length(); i++) {
            costs.push_back(getCostForMovingAllBalls(boxes, i));
        }
        return costs;
    }
};