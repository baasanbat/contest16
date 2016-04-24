#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#define INF -100000000
using namespace std;
vector <pair <int, int> >points;
int main() {
	set <int> id_set;
	map <int, int> pq, idx;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		points.push_back(make_pair(a, b));
		id_set.insert(b);
		idx[b] = INF;
	}
	pq[INF] = id_set.size();
	sort(points.begin(), points.end());
	//preprocession done!

	//solution starts!
	int ret = -1*INF+3;
	for (int i = 0; i < points.size(); i++) {
		int id   = points[i].second;
		int prev = idx[id];
		int ps   = points[i].first;
		pq[prev]--;
		if (pq[prev] == 0) pq.erase(prev);
		idx[id] = ps;
		pq[ps] = 1;
		ret = min(ret, ps-pq.begin()->first);
	}
	printf("%d\n", ret);
	return 0;
}
