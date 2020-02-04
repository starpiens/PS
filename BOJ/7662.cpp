#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
template <typename T>
struct Q {
  Q() {
      max_heap.emplace_back(0, 0);
      min_heap.emplace_back(0, 0);
  }
  ~Q() = default;
  void insert(T key) {
      max_heap.emplace_back(key, 0);
      min_heap.emplace_back(key, 0);

      auto idx = max_heap.size() - 1;
      while (idx > 1 && max_heap[idx / 2].first < key) {
          swap(max_heap[idx / 2], max_heap[idx]);
          min_heap[max_heap[idx].second].second = idx;
          idx /= 2;
      }
      min_heap.back().second = idx;

      idx = min_heap.size() - 1;
      while (idx > 1 && min_heap[idx / 2].first > key) {
          swap(min_heap[idx / 2], min_heap[idx]);
          max_heap[min_heap[idx].second].second = idx;
          idx /= 2;
      }
      max_heap[min_heap[idx].second].second = idx;
  }
  void erase(int op) {
      if (empty()) return;
      if (op > 0) {
          erase_minheap(max_heap[1].second);
          erase_maxheap(1);
      } else {
          erase_maxheap(min_heap[1].second);
          erase_minheap(1);
      }
  }
  bool empty() {
      return max_heap.size() == 1;
  }
  T max() {
      return max_heap[1].first;
  }
  T min() {
      return min_heap[1].first;
  }

private:
  vector<pair<T, int>> max_heap, min_heap;
  void erase_minheap(int idx) {
      min_heap[idx] = min_heap.back();
      min_heap.pop_back();
      while (idx * 2 < min_heap.size()) {
          if (idx * 2 + 1 == min_heap.size() || min_heap[idx * 2].first < min_heap[idx * 2 + 1].first) {
              swap(min_heap[idx], min_heap[idx * 2]);
              max_heap[min_heap[idx].second].second = idx;
              idx *= 2;
          } else {
              swap(min_heap[idx], min_heap[idx * 2 + 1]);
              max_heap[min_heap[idx].second].second = idx;
              idx = idx * 2 + 1;
          }
      }
      max_heap[min_heap[idx].second].second = idx;
  }
  void erase_maxheap(int idx) {
      max_heap[idx] = max_heap.back();
      max_heap.pop_back();
      while (idx * 2 < max_heap.size()) {
          if (idx * 2 + 1 == max_heap.size() || max_heap[idx * 2].first > max_heap[idx * 2 + 1].first) {
              swap(max_heap[idx], max_heap[idx * 2]);
              min_heap[max_heap[idx].second].second = idx;
              idx *= 2;
          } else {
              swap(max_heap[idx], max_heap[idx * 2 + 1]);
              min_heap[max_heap[idx].second].second = idx;
              idx = idx * 2 + 1;
          }
      }
      min_heap[max_heap[idx].second].second = idx;
  }
};
 */

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int k;
        scanf("%d", &k);
        multiset<int> s;
        while (k--) {
            char op;
            int n;
            scanf(" %c%d", &op, &n);
            if (op == 'I') s.insert(n);
            else if (!s.empty()) s.erase(n > 0 ? --s.end() : s.begin());
        }
        if (s.empty()) printf("EMPTY\n");
        else printf("%d %d\n", *--s.end(), *s.begin());
    }
    return 0;
}