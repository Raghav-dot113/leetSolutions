
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currLen = 0, extraSpaces = 0, wordIncluded = 0;
        vector<int> spaceFit;
        string line = "";
        vector<string> justified;

        for (string word : words) {
            if (currLen + word.length() > maxWidth) {
                line.pop_back();
                spaceFit.pop_back();
                currLen--;

                extraSpaces = maxWidth - currLen;

                if (wordIncluded == 1) {
                    line += string(extraSpaces, ' ');
                } else {
                    int gaps = wordIncluded - 1;
                    int spacesPerGap = extraSpaces / gaps;
                    int remaining = extraSpaces % gaps;

                    for (int i = (int)spaceFit.size() - 1; i >= 0; i--) {
                        int spaces = spacesPerGap;
                        if (i < remaining) spaces++;
                        line.insert(spaceFit[i], string(spaces, ' '));
                    }
                }

                justified.push_back(line);

                currLen = 0;
                wordIncluded = 0;
                spaceFit.clear();
                line = "";
            }

            currLen += word.length() + 1;
            wordIncluded++;
            line += word + ' ';
            spaceFit.push_back(line.length() - 1);
        }

        line.pop_back();
        line += string(maxWidth - line.length(), ' ');
        justified.push_back(line);

        return justified;
    }
};
