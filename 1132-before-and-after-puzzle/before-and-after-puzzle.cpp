class Solution {
    string getOutput(string one, string two) {
        int lastSpaceForOneIdx = 0;
        for (int i = 0; i < one.length(); i++) {
            if (one[i] == ' ') {
                lastSpaceForOneIdx = i;
            }
        }
        string lastWordForOne = "";
        if (lastSpaceForOneIdx) {
            lastWordForOne = one.substr(lastSpaceForOneIdx + 1, one.length());
        } else {
            lastWordForOne = one;
        }

        int firstSpaceForTwoIdx = 0;
        for (int i = 0; i < two.length(); i++) {
            if (two[i] == ' ') {
                firstSpaceForTwoIdx = i;
                break;
            }
        }

        string firstWordForTwo = "";
        if (firstSpaceForTwoIdx) {
            firstWordForTwo = two.substr(0, firstSpaceForTwoIdx);
        } else {
            firstWordForTwo = two;
        }
        
        string output = "";
        if (lastWordForOne != "" and 
            lastWordForOne == firstWordForTwo) {
            string firstPart = one.substr(0, lastSpaceForOneIdx);
            output += firstPart;
            if (firstPart != "") {
                output += " ";
            }
            output += lastWordForOne;
            output += (firstSpaceForTwoIdx != 0 ? 
                    two.substr(firstSpaceForTwoIdx, two.length()) : "");
        }

        return output;
    }

public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int phraseCount = phrases.size();
        set<string> outputs;
        for (int i = 0; i < phraseCount; i++) {
            for (int j = i + 1; j < phraseCount; j++) {
                string outputOne = getOutput(phrases[i], phrases[j]);
                if (outputOne != "") {
                    outputs.insert(outputOne);
                }

                string outputTwo = getOutput(phrases[j], phrases[i]);
                if (outputTwo != "") {
                    outputs.insert(outputTwo);
                }
            }
        }

        vector<string> sortedOutputs(outputs.begin(), outputs.end());
        return sortedOutputs;
    }
};