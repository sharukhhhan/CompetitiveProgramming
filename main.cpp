#include <bits/stdc++.h>
#define INF 10000000 
using namespace std;


vector<bool> visited; 
vector<vector<int>> graph;
vector<int> d;

int main() {
	#ifndef ONLINE_JUDGE 
	    freopen("input.txt", "r", stdin); 
	    freopen("output.txt", "w", stdout);  
	#endif
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	for (int e = 0; e < m; ++e){
		int from, to;
		cin >> from >> to >> d[e];
		--from; --to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	int s = 1;
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
	vector<int> path;
	for (int v=n; v!=s; v=p[v])
		path.push_back (v);
	path.push_back (s);
	reverse (path.begin(), path.end());

	for (auto i: path){
		cout << i << ' ';
	}
}