class Solution {
public:
    bool isPalindrome(string s) {
        string loStr = filter(s);
        /*transform(loStr.begin(), loStr.end(), loStr.begin(), 
                [](char c){ if (isalnum(c)) return tolower(c);});*/

        int l = 0, r = loStr.size()-1;
        cout << loStr<< endl;
        while(l < r){
            if(loStr[l] != loStr[r]) return false;
            l++;
            r--;
        }
        return true;
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
