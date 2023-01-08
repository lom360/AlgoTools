#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

long long pairwiseproduct(const vector<long long>& arr) {
    int n = arr.size();
    int maxindex1 = 1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > arr[maxindex1] || maxindex1 == -1) {
	    maxindex1 = i;
	}
    }

    int maxindex2 = -1;
    for(int j = 0; j < n; j++) {
        if((arr[j] > arr[maxindex2] || maxindex2 == -1) && j != maxindex1) {
	    maxindex2 = j;
	}
    }

    return ((long long)arr[maxindex1]) * arr[maxindex2];
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> numbers(n);
    for(int i = 0; i < numbers.size(); i++){
        cin >> numbers[i];
    }
    cout << pairwiseproduct(numbers);
    return 0;
}
