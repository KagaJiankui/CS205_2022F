#include "exercise1.h"

int main() {
  Pair<string, int> one("Tom", 19);
  Pair<string, int> two("Alice", 20);

  if (one < two) {
    cout << one << endl;
  } else {
    cout << two << endl;
  }

  return 0;
}
