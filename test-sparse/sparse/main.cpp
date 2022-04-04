#include <bits/stdc++.h>

using namespace std;

class SparseTable {
  vector<int> _arr;
  vector<vector<int>> st;
public:
  SparseTable() {}
  void initTable(vector<int> arr) {
    _arr = arr;
    int n = _arr.size();
    int log2 = 31 - __builtin_clz(n);
    for (int i = 0; i < log2; i++) {
      if (i == 0) {
        st.push_back(vector<int>(n));
        for (int j = 0; j < st[i].size(); j++) st[i][j] = j;
        continue;
      }
      int p = 1 << (i-1);
      int sz = st[i-1].size() - p;
      st.push_back(vector<int>(sz));
      for (int j = 0; j < sz; j++) {
          st[i][j] = (_arr[st[i-1][j]] <= _arr[st[i-1][j+p]]) ? st[i-1][j] : st[i-1][j+p];
      }
    }
  }

  int minIndex(int l, int r) {
    int p = 31 - __builtin_clz(r-l);
    return (_arr[st[p][l]] <= _arr[st[p][r-(1<<p)]]) ? st[p][l] : st[p][r-(1<<p)];
  }

  int minValue(int l, int r) {
    return _arr[minIndex(l, r)];
  }

  vector<vector<int>>& getTable() { return st; }
};


int main()
{
  vector<int> arr = {23, 29, 3, 16, 14, 19, 14, 4, 4, 11, 7, 25, 3, 8, 6, 13};
  SparseTable sparse;
  sparse.initTable(arr);
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i; j <= arr.size(); j++) {
      cout << "Min([" << i << ", " << j << "[) = " << sparse.minValue(i, j) << endl;
    }
  }
  return 0;
}
