#include <vector>
#include <iostream>

using namespace std;

int factorial(int x) {
  return (x <= 1) ? 1 : x * factorial(x - 1);
}

int f(int a, int b) {
  return factorial(a + b) / (factorial(a) * factorial(b));
}

template <typename T>
int n(vector<T>& P) {
  if (P.size() <= 1) return 1;
  vector<T> L, R;
  for (int i = 1; i < P.size(); i++) {
    if (P[i] < P[0])
      L.push_back(P[i]);
    else
      R.push_back(P[i]);
  }
  return n(L) * n(R) * f(L.size(), R.size());
}

int main() {
    vector<int>a;
    int x;

    while(cin>>x){
        a.push_back(x);
    }

  cout << n(a) - 1<< endl;
  return 0;
}