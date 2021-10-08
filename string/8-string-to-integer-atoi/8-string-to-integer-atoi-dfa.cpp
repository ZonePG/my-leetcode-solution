class Automation {
  string state = "start";

  unordered_map<string, vector<string>> table = {
    {"start", {"start", "signed", "in_number", "end"}},
    {"signed", {"end", "end", "in_number", "end"}},
    {"in_number", {"end", "end", "in_number", "end"}},
    {"end", {"end", "end", "end", "end"}}
  };

  int getcol(char c) {
    if (isspace(c)) {
      return 0;
    } else if (c == '+' || c == '-') {
      return 1;
    } else if (isdigit(c)) {
      return 2;
    } else {
      return 3;
    }
  }
public:
  bool negative = false;
  long long ans = 0;

  void get(char c) {
    state = table[state][getcol(c)];
    if (state == "in_number") {
      ans = ans * 10 + c - '0';
      ans = !negative ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
    } else if (state == "signed") {
      negative = c == '+' ? false : true;
    }
  }
};

class Solution {
public:
  int myAtoi(string s) {
    Automation automation;
    for (const char &c : s) {
      automation.get(c);
    }
    return automation.negative ? -automation.ans : automation.ans;
  }
};
