#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int index = 0;
    long long max1 = -1;
    long long max2 = -1;

    for (int i = 0; i < n; i++)
    {
    	if (max1 < numbers[i])
    	{
    		max1 = numbers[i];
    		index = i;
    	}
    }

    for (int i = 0; i < n; i++)
    {
    	if (max2 < numbers[i] && index != i)
    		max2 = numbers[i];
    }	

    return max2 * max1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
