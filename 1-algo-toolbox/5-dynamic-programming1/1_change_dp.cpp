#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_change(vector<int> &cache, int m)
{
	if (m < 0)
		return 0;

	if (m < cache.size())
		return cache[m];

	vector<int> coins = {1, 3, 4};
	vector<int> possibilities;

	for (auto coin : coins)
		if (m >= coin)
			possibilities.push_back(get_change(cache, m - coin) + 1);

	int result = *min_element(possibilities.begin(), possibilities.end());

	cache.push_back(result);



	return result;
}

int main()
{
	int m;
	std::cin >> m;
	vector<int> cache = {0, 1};
	std::cout << get_change(cache, m) << '\n';
}