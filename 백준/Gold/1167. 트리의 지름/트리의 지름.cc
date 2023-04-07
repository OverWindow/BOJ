#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 1167 BFS  and tree
// 임의의 노드에서 가장 긴 경로로 연결된 노드는
// 트리의 지름에 해당하는 두 노드 중 하나다  

typedef pair<int,int> edge;
static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> m_distance;

void BFS(int node) {
	queue<int> myqueue;
	myqueue.push(node);
	visited[node] = true;
	
	while(!myqueue.empty()) {
		int now_node = myqueue.front();
		myqueue.pop();
		for(edge i : A[now_node]) {
			if(!visited[i.first]) {
				visited[i.first] = true;
				myqueue.push(i.first);
				m_distance[i.first] = m_distance[now_node] + i.second;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	A.resize(N+1);
	
	for(int i = 0; i < N; i++) {
		int S;
		cin >> S;
		while(true) {
			int E,V;
			cin >> E;
			if(E == -1)break;
			cin >> V;
			A[S].push_back(edge(E,V));
		}
	}
	m_distance = vector<int>(N+1,0);
	visited = vector<bool> (N+1,false);
	BFS(1);
	int Max = 1;
	for(int i = 2; i <= N; i++) {
		if(m_distance[Max] < m_distance[i]) {
			Max = i;
		}
	}

	fill(m_distance.begin(), m_distance.end(),0);
	fill(visited.begin(),visited.end(),false);
	BFS(Max);
	sort(m_distance.begin(),m_distance.end());
	cout << m_distance[N] << "\n";
	return 0;
}
