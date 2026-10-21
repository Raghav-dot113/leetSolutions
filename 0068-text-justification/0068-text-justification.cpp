
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currLen = 0,extraSpaces = 0,wordIncluded = 0;
        vector<int> spaceFit;
        string line = "";
        vector<string> justified;

        for(string word : words){

            if(currLen + word.length() > maxWidth){
                currLen--;
                line.pop_back();
                spaceFit.pop_back();

                extraSpaces = maxWidth - currLen;

                if(wordIncluded == 1){
                    line.insert(line.length(),string(extraSpaces,' '));
                }else if(extraSpaces % (wordIncluded - 1) == 0 && extraSpaces){
                    extraSpaces /= (wordIncluded - 1);

                    string spaces(extraSpaces,' ');

                    for(int i = (int)spaceFit.size()-1;i>=0;i--){
                        line.insert(spaceFit[i], spaces);
                    }
                }else if(extraSpaces){
                    int gaps = wordIncluded - 1;
                    int spaces = extraSpaces / gaps;
                    int remaining = extraSpaces % gaps;

                    for(int i = (int)spaceFit.size()-1;i>=0;i--){
                        int count = spaces + (i < remaining);
                        line.insert(spaceFit[i], string(count,' '));
                    }
                }

                justified.push_back(line);

                currLen = 0;wordIncluded = 0;
                spaceFit.clear();
                line = "";
            }

            currLen += word.length() + 1;
            wordIncluded++;
            line += word + ' ';
            spaceFit.push_back(line.length()-1);
        }

        line.pop_back();
        line += string(maxWidth - line.length(), ' ');
        justified.push_back(line);

        return justified;
    }
};
