#include <list>

// Helper function to merge two sorted lists
std::list<T> merge(std::list<T> list1, std::list<T> list2) {
  std::list<T> result;
  auto it1 = list1.begin(), it2 = list2.begin();
  while (it1 != list1.end() && it2 != list2.end()) {
    if (*it1 < *it2) {
      result.push_back(*it1++);
    } else {
      result.push_back(*it2++);
    }
  }
  result.splice(result.end(), list1, it1, list1.end());
  result.splice(result.end(), list2, it2, list2.end());
  return result;
}

void merge_sort(std::list<T>& list) {
  if (list.size() <= 1) {
    return;
  }
  auto mid = std::next(list.begin(), list.size() / 2);
  std::list<T> left(list.begin(), mid);
  std::list<T> right(mid, list.end());
  merge_sort(left);
  merge_sort(right);
  list = merge(left, right);
}
