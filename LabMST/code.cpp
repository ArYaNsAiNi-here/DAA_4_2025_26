class Solution {
public:
    vector<vector<string>> res;
    bool checkPal(const string &s, int l, int r){
        while(l < r){
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void dfs(const string &s, int st, vector<string> &path){
        if (st == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = st; i < s.size(); i++) {
            if (checkPal(s, st, i)) {
                path.push_back(s.substr(st, i - st + 1));
                dfs(s, i + 1, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s,0,path);
        return res;
    }
};