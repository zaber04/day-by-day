#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> testcases = [
	[ [ 1, 2, 4 ], [ 3, 4, 3 ], [ 2, 3, 1 ] ],
	[ [ 1, 2, 4 ], [ 3, 4, 3 ], [ 2, 3, 10 ] ],
	[ [ 1, 1, 1 ], [ 2, 2, 2 ], [ 3, 3, 3 ], [ 4, 4, 4 ] ],
	[ [ 1, 3, 4 ], [ 2, 4, 1 ], [ 1, 1, 4 ], [ 3, 5, 1 ], [ 2, 5, 5 ] ]
];

int binarySearch(int index, vector<vector<int>> &events, int value) {
	int left = index;
	int right = events.size() - 1;
	int res = -1;

	while (left < right) {
		int mid = left + (right - left) >> 1;

		if (events[mid][0] > value) {
			res = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return res;
}

int dynamicProgram(int start, vector<vector<int>> &events, int k, vector<vector<int>> &memo)
{
	if (start >= events.size() || k == 0 || start == -1) {
		return 0;
	}

	if (memo[start][k] != -1) {
		return memo[i][k];
	}

	int index   = binarySearch(i + 1, events, events[start][1]);
	int takeIt  = events[start][2] + helper(index, events, k - 1, memo);
	int leaveIt = helper(start + 1, events, k, memo);

	memo[start][k] = max(takeIt, leaveIt);

	return memo[start][k];
}

int maxValue(vector<vector<int>> &events, int k) {
	sort(events.begin(), events.end());
	int n = events.size();
	vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
	return dynamicProgram(0, events, k, memo);
}
