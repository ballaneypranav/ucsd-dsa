#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::endl;

int compute_min_refills(int dist, int tank, vector<int> & stops) 
{
	int n = stops.size();

	int refills = 0;
	int covered = 0;
	int capacity = tank;

	int i = 0;
	while (covered < dist)
	{
		if (i < n)
		{
			if (stops[i] - covered > tank)
			{
				tank = capacity;
				refills++;
			}

			if (stops[i] - covered > tank)
			{
				return -1;
			}
			else
			{
				tank -= (stops[i] - covered);
				covered = stops[i];
				i++;
			}
		}
		else if (i == n)
		{
			if (dist - covered <= tank)
			{
				return refills;
			}
			else 
			{
				refills++;
				tank = capacity;
			}

			if (dist - covered > tank)
			{
				return -1;
			}
			else
			{
				tank -= (dist - covered);
				covered = dist;
			}
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
