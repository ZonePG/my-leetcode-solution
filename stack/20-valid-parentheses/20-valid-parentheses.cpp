class Solution {
private:
  map<char, char> table = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
  };
public:
  bool isValid(string s) {
    if (s.empty())
      return true;
    else if (s.size() % 2)
      return false;
    stack<char> sc;
    for (int i = 0; i < s.size(); i++) {
      if (sc.empty())
        sc.push(s[i]);
      else {
        if (s[i] == table[sc.top()])
          sc.pop();
        else
          sc.push(s[i]);
      }
    }
    return sc.empty();
  }
};
