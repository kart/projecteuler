#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

#define INF				1 << 30
#define MAX				80
#define PII				pair<int, int>
#define NODE(i, j)			((i) * MAX + (j))

#define ADD_EDGE(graph, from, to)			\
{							\
	assert(from >= 0 && from < (MAX * MAX));	\
	assert(to.first >= 0 && to.first < (MAX * MAX));\
	assert(to.second > 0);				\
	if (graph.find(from) != graph.end())		\
		graph[from].push_back(to);		\
	else						\
	{						\
		vector<PII >	tolist;			\
		tolist.push_back(to);			\
		graph[from] = tolist;			\
	}						\
}

int dijkstra(int start, int startweight, map<int, vector<PII> > graph, int nvertices)
{
	priority_queue<PII, vector<PII >, greater<PII > >	pq;
	vector<bool>						seen(nvertices, false);

	pq.push(make_pair(startweight, start));
	while (!pq.empty())
	{
		pair<int, int> u = pq.top(); pq.pop();
		seen[u.second] = true;
		if (u.second == NODE(MAX - 1, MAX - 1))
			return u.first;
		if (graph.find(u.second) != graph.end())
		{
			vector<PII> adj = graph[u.second];
			for (int i = 0; i < adj.size(); i++)
				if (!seen[adj[i].first])
					pq.push(make_pair(u.first + adj[i].second, adj[i].first));
		}
	}
	return 0;
}

int PE083()
{
	int				ch, ans, arr[MAX][MAX];
	map<int, vector<PII> >		graph;

	// Read input
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> arr[i][j];

	// Construct graph
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			int node = NODE(i, j);
			if (i != 0)
				ADD_EDGE(graph, node, make_pair(NODE(i - 1, j), arr[i - 1][j])); 
			if (i != MAX - 1)
				ADD_EDGE(graph, node, make_pair(NODE(i + 1, j), arr[i + 1][j]));
			if (j != MAX - 1)
				ADD_EDGE(graph, node, make_pair(NODE(i, j + 1), arr[i][j + 1]));
			if (j != 0)
				ADD_EDGE(graph, node, make_pair(NODE(i, j - 1), arr[i][j - 1]));
		}

	// Run Dijkstra
	cout << dijkstra(NODE(0, 0), arr[0][0], graph, MAX * MAX) << endl;
	return 0;
}

int main()
{
	PE083();
	return 0;
}
