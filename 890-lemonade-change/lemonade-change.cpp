class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarBills = 0;
        int tenDollarBills = 0;
        int twentyDollarBills = 0;
        bool isChangePossible = true;

        for (auto bill : bills) {
            fiveDollarBills += (bill == 5);
            tenDollarBills += (bill == 10);
            twentyDollarBills += (bill == 20);

            if (bill == 5) {
                continue;
            } else if (bill == 10) {
                if (!fiveDollarBills) {
                    isChangePossible = false;
                } else {
                    fiveDollarBills--;
                    continue;
                }
            } else {
                if (tenDollarBills and fiveDollarBills) {
                    tenDollarBills--;
                    fiveDollarBills--;
                    continue;
                } else if (fiveDollarBills >= 3) {
                   fiveDollarBills -= 3;
                   continue; 
                } else {
                    isChangePossible = false;
                }
            }
        }

        return isChangePossible;
    }
};