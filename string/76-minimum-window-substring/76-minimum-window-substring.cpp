class Solution {
  unordered_map<char, int> window, table;

  bool check() {
    for (const auto &iter : table) {
      if (window[iter.first] < iter.second) {
        return false;      
      }
    }
    return true;
  }

public:
  string minWindow(string s, string t) {
    for (const auto &c : t) {
      ++table[c];
    }
    int left = 0, right = 0;
    int ansLen = INT_MAX;
    int ansLeft = -1;
    while (right < s.size()) {
      if (table.find(s[right]) != table.end()) {
        ++window[s[right]];
      }
      while (check() && left <= right) {
        if (right - left + 1 < ansLen) {
          ansLen = right - left + 1;
          ansLeft = left;
        }
        if (table.find(s[left]) != table.end()) {
          --window[s[left]];
        }
        ++left;
      }
      ++right;
    }
    return ansLen == INT_MAX ? string() : s.substr(ansLeft, ansLen);
  }
};
