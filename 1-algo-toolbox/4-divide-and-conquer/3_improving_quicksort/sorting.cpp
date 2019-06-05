#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void randomized_quick_sort(vector<int> &a, int l, int r);
void partition2(vector<int> &a, int l, int r);

void partition2(vector<int> &a, int l, int r) 
{
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	int k = j-1;
	for (int i = j-1; i >= l; --i)
	{
		if (a[i] == x)
		{
			swap(a[i], a[k]);
			k--;
		}
	}

	randomized_quick_sort(a, l, k);
	randomized_quick_sort(a, j, r);
}

void randomized_quick_sort(vector<int> &a, int l, int r) 
{
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	partition2(a, l, r);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
	std::cout << "\n";
}
