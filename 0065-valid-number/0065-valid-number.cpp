class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            }
            else if (c == '.') {
                if (seenDot || seenExp)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit)
                    return false;

                seenExp = true;
                seenDigit = false;   // Need digits after exponent
            }
            else if (c == '+' || c == '-') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }

        return seenDigit;
    }
};