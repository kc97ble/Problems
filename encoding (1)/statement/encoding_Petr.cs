using System;

public class PalindromeEncoding {
  public int getLength(string s) {
    while (s.Length > 1)
    {
      if (s[0] != s[1])
        break;
      s = s.Substring(1);
    }
    for (int i = 1; i < s.Length; ++i)
      if (s[i] == s[i - 1])
      {
        s = s.Substring(0, i);
        break;
      }
    return s.Length;
  }


}
