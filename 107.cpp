#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <cstdlib>

using namespace std;

#define INF				1 << 30
#define MAX				40
#define PII				pair<int, int>
#define MP				make_pair

int prim(vector<vector<PII> > graph, int start, int N)
{
	priority_queue<PII,
			vector<PII >,
			greater<PII > >	pq;
	int				mst_count, mst_weight;
	vector<bool>			mst_seen(N + 1, false);

	pq.push(MP(0, start));
	mst_count = mst_weight = 0;
	while (!pq.empty())
	{
		PII u = pq.top(); pq.pop();
		if (mst_seen[u.second]) continue;
		mst_seen[u.second] = true;
		mst_count++;
		mst_weight += u.first;
		vector<PII> adj = graph[u.second];
		for (int i = 0; i < adj.size(); i++)
			if (!mst_seen[adj[i].first])
				pq.push(MP(adj[i].second, adj[i].first));		
		if (mst_count == N)
			break;
	}
	return mst_weight;
}

// Ans = 2153
int main()
{
	int			N;
	string			s;

	cin >> N;
	vector<vector<PII> >	graph(N + 1);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> s;
			if (s[0] == '-') continue;
			int val = atoi(s.c_str());
			graph[i].push_back(MP(j, val));
		}
	}
	for (int i = 1; i <= N; i++)
	{
		vector<PII>	adj = graph[i];
		cout << ".... " << i << " ...." << endl;
		for (int j = 0; j < adj.size(); j++)
			cout << adj[j].first << ", " << adj[j].second << endl;
	}
	cout << prim(graph, 1, N) << endl;
	return 0;
}
