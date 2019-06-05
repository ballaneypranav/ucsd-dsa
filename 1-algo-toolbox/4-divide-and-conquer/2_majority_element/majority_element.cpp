#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int merge_sort(vector<int> &a, int low, int high)
{
	if ((high - low + 1) <= 1)
		return 0;

	int mid = (low + high)/2;

	merge_sort(a, low, mid);
	merge_sort(a, mid+1, high);

	vector<int> first;
	for (auto i = low; i <= mid; ++i)
		first.push_back(a[i]);

	vector<int> second;
	for (auto i = mid+1; i <= high; ++i)
		second.push_back(a[i]);

	int i = 0;
	int j = 0;
	int k = low;
	int f_len = mid - low + 1;
	int s_len = high - mid;
	while (i < f_len || j < s_len)
	{
		if (i < f_len && j < s_len)
		{
			if (first[i] <= second[j])
				a[k++] = first[i++];
			else
				a[k++] = second[j++];
		}
		else if (i < f_len)
			a[k++] = first[i++];
		else 
			a[k++] = second[j++];
	}
}

int get_majority_element(vector<int> &a) 
{
	int n = a.size();
	int count = 1;
	int value = a[0];
	int max = 1;
	int max_val = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] == value)
			count++;
		else
		{
			if (count > max)
			{
				max = count;
				max_val = value;
			}

			value = a[i];
			count = 1;
		}
	}
	if (count > max)
	{
		max = count;
		max_val = value;
	}
	return max > n/2;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	merge_sort(a, 0, n-1);
	std::cout << get_majority_element(a) << '\n';
}
