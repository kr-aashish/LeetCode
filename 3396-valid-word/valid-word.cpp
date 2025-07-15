class Solution {
    inline const static vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }

        int countVowel = 0;
        int countConsonant = 0;

        for (auto character : word) {
            bool characterIsAlphanumeric = (character >= '0' and character <= '9') 
            or (character >= 'a' and character <= 'z') or (character >= 'A' and character <= 'Z');
            if (characterIsAlphanumeric) {
                bool characterIsVowel = false;
                auto it = find(vowels.begin(), vowels.end(), character);
                if (it != vowels.end()) {
                    characterIsVowel = true;
                }
                countVowel += characterIsVowel;

                bool characterIsConsonant = !characterIsVowel and !(character >= '0' and character <= '9');
                countConsonant += characterIsConsonant;
            } else {
                return false;
            }
        }

        if (!countVowel or !countConsonant) {
            return false;
        }

        return true;
    }
};