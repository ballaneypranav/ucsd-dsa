#include <iostream>
#include <vector>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
	double value = 0.0;
	int n = weights.size();
	double ratios[n];
	for (int i = 0; i < n; i++)
	{
		ratios[i] = (double) values[i] / weights[i];
	}

	int used = 0;
	while (capacity > 0 && used < n) 
	{
		// select item with max value/weight ratio
		double max = ratios[0];
		int index = 0;
		for (int i = 1; i < n; i++)
		{
			if (max < ratios[i])
			{
				max = ratios[i];
				index = i;
			}
		}

		// check if this item can fit in the sack
		if (weights[index] <= capacity)
		{
			value += values[index];
			capacity -= weights[index];
		}
		else 
		{
			value += ((double) values[index] * capacity / weights[index]);
			capacity = 0;
		}

		ratios[index] = 0;
		used++;

	}


	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) 
	{
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
