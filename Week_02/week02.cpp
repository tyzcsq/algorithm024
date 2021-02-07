//有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.empty()) {
            if(s.empty()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if(t.size() != s.size()) {
                return false;
            }
        }
        
        map<char, int> map_s;
        map<char, int> map_t;
        for(auto var : s) {
            map_s[var]++;
        }
        for(auto var : t) {
            map_t[var]++;
        }
        for(auto var : map_s) {
            if(map_t.find(var.first) == map_t.end() ||
            map_t[var.first] != var.second) {
                return false;
            }
        }
        return true;
    }
};

//前 K 个高频元素
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt_list;
        for(int num : nums) {
            cnt_list[num]++;
        }

        priority_queue<pair<int, int>> queue;
        for(auto& var : cnt_list) {
            pair<int, int> info;
            info.first = var.second;
            info.second = var.first;
            queue.push(info);
        }

        vector<int> res;
        for(int i=0; i<k; i++) {
            pair<int, int> info = queue.top();
            res.push_back(info.second);
            queue.pop();
        }
        return res;
    }
};