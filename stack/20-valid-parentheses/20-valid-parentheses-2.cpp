class Solution {
private:
  map<char, char> table = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
  };
  map<char, int> level = {
    {')', 1},
    {']', 2},
    {'}', 3}
  };
public:
  bool isValid(string s) {
    if (s.empty())
      return true;
    else if (s.size() % 2)
      return false;
    stack<char> sc;
    int lev = 0;
    for (int i = 0; i < s.size(); i++) {
      if (sc.empty())
        sc.push(s[i]);
      else {
        if (s[i] == table[sc.top()]) {
          if (lev <= level[s[i]]) {
            lev = level[s[i]];
          } else {
            return false;
          }
          sc.pop();
        }
        else
          sc.push(s[i]);
      }
    }
    return sc.empty();
  }
};
