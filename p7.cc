#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define loc first
#define id second
using namespace std;
vector <pair <int, int> > points;
int main() {
	set <int> ids;
	map <int, int> in_window;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		ids.insert(b);
		in_window[b] = 0;
	}
	sort(points.begin(), points.end());
	int num_ids = ids.size(), start = 0, end = 0, ret = 1<<29;
	int window_size = 0;
	while (1) {
		while (window_size!=num_ids && end<n) {
			if (in_window[points[end].id] == 0) window_size++;
			in_window[points[end].id]++;
		}

		if (end==n && window_size!=num_ids) break;

		while (in_window[points[start].id] > 1) in_window[points[start++].id]--;
		ret = min(ret, points[end-1].loc-points[start].loc);
		in_window[points[start++].id]--;
		window_size--;
	}
	printf("%d\n", ret);
	return 0;
}
