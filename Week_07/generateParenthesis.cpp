class Solution {
public:
    vector<string> result;
    void dfs(string cur_str, int left, int right, int n) {
        if(left == n && right == n) {
            result.push_back(cur_str);
            return;
        }
        if(left < right) {
            return;
        }

        if(left < n) {
            dfs(cur_str+"(", left+1, right, n);
        }
        if(right < n) {
            dfs(cur_str+")", left, right+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return result;
    }
};