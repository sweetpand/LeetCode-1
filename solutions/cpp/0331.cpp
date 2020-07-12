class Solution {
 public:
  bool isValidSerialization(string preorder) {
    int degree = 1;  // out-degree - in-degree
    istringstream iss(preorder);
    string token;

    while (getline(iss, token, ',')) {
      if (--degree < 0) return false;
      if (token != "#") degree += 2;
    }

    return degree == 0;
  }
};