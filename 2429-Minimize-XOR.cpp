class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);

        int x = 0;
        for (int i = 30; i >= 0; i--) {
            if (((num1 >> i) & 1) and count) {
                cout << "first loop: " << i << endl;
                x |= (1 << i);
                count--;
            }
        }
        if (count) {
            for (int i = 0; i < 31; i++) {
                if (((x >> i) & 1) == 0 and count) {
                    cout << "second loop" << i << endl;
                    x |= (1 << i);
                    count--;
                }
            }
        }

        return x;
    }
};