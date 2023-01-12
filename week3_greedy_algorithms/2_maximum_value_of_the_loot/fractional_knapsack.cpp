#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    int n = weights.size();
    vector<pair<double, int>> items;
    for (int i = 0; i < n; i++) {
        double ratio = (double)values[i] / weights[i];
        items.push_back({ratio, i});
    }
    sort(items.begin(), items.end(), greater<pair<double, int>>());

    double value = 0;
    for (auto &item : items) {
        int index = item.second;
        if (weights[index] <= capacity) {
            value += values[index];
            capacity -= weights[index];
        } else {
            value += capacity * ((double)values[index] / weights[index]);
            break;
        }
    }
    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  //std::cout.precision(4);
  std::cout << fixed << setprecision(4) << optimal_value << std::endl;
  return 0;
}
