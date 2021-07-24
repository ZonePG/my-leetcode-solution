class Solution {
public:
  /* 每次左指针右移一位，移除set的一个字符，
   * 这一步会导致很多无用的循环。while循环发现的重复字符不一定就是Set最早添加那个，
   * 还要好多次循环才能到达，这些都是无效循环，不如直接用map记下每个字符的索引，直接进行跳转
   */
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int res = 0;
    int start = 0;
    for (int end = 0; end < s.size(); end++) {
      char ch = s[end];
      if (map.count(ch)) {
        start = max(map[ch] + 1, start);
      }
      res = max(res, end - start + 1);
      map[ch] = end;
    }
    return res;
  }
};
