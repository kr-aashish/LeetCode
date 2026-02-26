class Solution {
    void addOne(string &input, int len) {
        for (int i = len - 1; i >= 0; i--) {
            if (input[i] == '1') {
                input[i] = '0';
            } else {
                input[i] = '1';
                return;
            }
        }
        input = '1' + input;
    }

    void substractOne(string &input, int len) {
        input = input.substr(0, len - 1);
    }

public:
    int numSteps(string s) {
        // 1101 + 1
        // 1110
        int len = s.length();
        auto input = s;
        int counter = 0;
        while (input != "1") {
            len = input.length();
            if (input.back() == '0') {
                substractOne(input, len);
            } else {
                addOne(input, len);
            }
            counter++;
        }
        return counter;
    }
};