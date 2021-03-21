class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordSet;
        for(string& word : wordList) {
            wordSet.insert(word);
        }
        if(wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        deque<string> queue;
        queue.push_back(beginWord);
        int len = 1;
        while(!queue.empty()) {
            int size = queue.size();
            for(int i=0; i<size; i++) {
                string word = queue.front();
                queue.pop_front();
                int length = word.size();
                for(int i=0; i<length; i++) {
                    string temp = word;
                    for(char ch='a'; ch<='z'; ch++) {
                        if(ch == temp[i]) {
                            continue;
                        }
                        temp[i] = ch;
                        if(temp == endWord) {
                            return len+1;
                        }
                        auto iter = wordSet.find(temp);
                        if(iter != wordSet.end()) {
                            queue.push_back(temp);
                            wordSet.erase(iter);
                        }
                    }
                }
            }
            ++len;
        }
        return 0;
    }
};