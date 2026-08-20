class Solution {
public:
    bool isPalindrome(string s) {
        string str = filter(s);
        return str == string(str.rbegin(), str.rend());
    }

    string filter(string s){
        string res = "";
        for(auto c : s){
            if(isalnum(c)){
                res += tolower(c);
            }
        }
        return res;
    }
};
