 #include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
	int start, end;
};

bool compareSegmentsByEnd (Segment a, Segment b)
{
	if (a.end < b.end)
		return true;
	else
		return false;
}

vector<int> optimal_points(vector<Segment> segments)
{
	vector<int> points;

	int n = segments.size();
	sort(segments.begin(), segments.end(), compareSegmentsByEnd);

	while (segments.size() > 0)
	{
		int end = segments[0].end;
		for (int j = 0; j < segments.size(); j++)
		{
			if (segments[j].start <= end)
			{
				segments.erase(segments.begin() + j);
				j--;
			}
		}
		points.push_back(end);
	}


	return points;
}

int main() 
{
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	
	for (size_t i = 0; i < n; ++i)
	{
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	
	for (size_t i = 0; i < points.size(); ++i) 
	{
		std::cout << points[i] << " ";
	}
	cout << endl;
}
