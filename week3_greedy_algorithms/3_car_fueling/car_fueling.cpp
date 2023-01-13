#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::min;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int refills = 0, current_refill = 0;
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);
    while (current_refill <= stops.size()-2) {
        int last_refill = current_refill;
        while (current_refill <= stops.size()-2 && stops[current_refill + 1] - stops[last_refill] <= tank) {
            current_refill++;
        }
        if (current_refill == last_refill) {
            return -1;
        }
        if (current_refill <= stops.size()-2) {
            refills++;
        }
    }
    return refills;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
