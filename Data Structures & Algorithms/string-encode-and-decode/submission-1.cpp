class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(const auto i: strs){
            s+=i;
            s+="/./.";
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s.length() == 0) return {""};
        int n = s.length();
        vector<string> v;
        string last = "";
        for(int i = 0; i<n; i++){
            last+=s[i];
            int size = last.length();
            if(size>=5){
                if(last.substr(size-4, 4) == "/./."){
                    string str = last.substr(0, size-4);
                    v.push_back(str);
                    last = "";
                }
            }
        }
        return v;
    }
};
