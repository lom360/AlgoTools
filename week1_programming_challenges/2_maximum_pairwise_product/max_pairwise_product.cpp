#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long FastPairwiseProduct(const std::vector<long long>& numbers) {
    int n = numbers.size();

    int maxIndex1 = -1;
    for(int i = 0; i < n; i++){
        if(numbers[i] > numbers[maxIndex1] || maxIndex1 == -1) {
	    maxIndex1 = i;
	}
    }

    int maxIndex2 = -1;
    for(int j = 0; j < n; j++) {
        if((numbers[j] > numbers[maxIndex2] || maxIndex2 == -1) && j != maxIndex1) {
	    maxIndex2 = j;
	}
    }

    return ((long long) numbers[maxIndex1]) * numbers[maxIndex2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    //std::cout << MaxPairwiseProduct(numbers) << "\n";
    std::cout << FastPairwiseProduct(numbers) << "\n";
    return 0;
}
