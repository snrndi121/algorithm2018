#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//def
#define INF 9343948
#define MAX_EDGE 30000
#define MAX_V 30000

typedef struct node {
	node(unsigned _v, unsigned _w) { target = _v, weight = _w;}
	unsigned target, weight;
}node;

//var
unsigned V, E, start_num, end_num;
vector <node> edge_arr[MAX_EDGE];
int dist[MAX_V] = {0, };

//func
void input_data();
void disk();
void ouput_data();

int main()
{
	input_data();
	disk();
	ouput_data();
	return 0;
}
void input_data()
{
	cin >> V >> E;

	int from, to, w;
	//���� ����
	for (uint i=0; i<E; ++i)
	{
		cin >> from >> to >> w;
		edge_arr[from].push_back(node(to, w));
	}
	//������ �Ÿ� �ʱ�ȭ
	for (uint i=1; i<=V; ++i)
	{
		dist[i] = INF;
	}
	cin >> start_num >> end_num;
	dist[start_num] = 0;
}
void disk()
{
	priority_queue < pair <int, int> > pq;
	pq.push(make_pair(0, start_num));

	//��� �Ÿ� ������ V-1����ŭ �����ϸ� �ȴ�.
	while (!pq.empty())
	{
		int now_node = pq.top().second;
		//int cost = pq.top().first;
		pq.pop();
		//���� ��忡�� �ֺ��� �ִ� ����� ���� �����Ѵ�.
		for (uint k=0; k<edge_arr[now_node].size(); ++k)
		{
			int new_val = dist[now_node] + edge_arr[now_node][k].weight;
			int before_val = dist[edge_arr[now_node][k].target];

			//���� ���κ��� ����� ������ ���������� ���� �Ÿ��� ������ �Ÿ���
			//���Ͽ� ������ ���� �� ũ�� ���� �����Ѵ�.
			if (new_val < before_val) {
				dist[edge_arr[now_node][k].target] = new_val;
				pq.push(make_pair(-1 * new_val, edge_arr[now_node][k].target));
			}
		}
	}
}
void ouput_data()
{
		cout << dist[end_num];
}

