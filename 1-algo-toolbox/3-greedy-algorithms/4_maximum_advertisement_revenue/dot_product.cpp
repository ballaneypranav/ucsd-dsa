#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> profits, vector<int> clicks)
{
	std::sort(profits.begin(), profits.end());
	std::sort(clicks.begin(), clicks.end());
	int n = profits.size();

	long long dot_product = 0;

	// for (int i = n-1; i >= 0; i--)
	// {
	// 	double max_current_product = profits[i] * clicks[0];
	// 	int index = 0;
	// 	for (int j = 1; j < clicks.size(); j++)
	// 	{
	// 		if (max_current_product < profits[i]  * clicks[j])
	// 		{
	// 			max_current_product = profits[i] * clicks[j];
	// 			index = j;
	// 		}
	// 	}

	// 	dot_product += max_current_product;
	// 	clicks.erase(clicks.begin() + index);
	// }

	for (int i = 0; i < n; i++)
	{
		dot_product += profits[i] * clicks[i];
	}

	return dot_product;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::cout << max_dot_product(a, b) << std::endl;
}
