#include <bits/stdc++.h>
using namespace std;
bool tree = true;
struct Node
{
    int id = 0 ;
    vector<Node*>neighbors ={};
    bool visited = 0;
    Node(int _id) : id(_id) {}
};
void DFS(Node * node , Node * Parent)
{
    node->visited = 1;
    for(auto &neighbour : node->neighbors)
    {
        if(neighbour != Parent)
        {
            if(neighbour->visited)
            {
                tree = false;
                return;
            }
            DFS(neighbour,node);
        }
    }
}
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    vector<Node*>graph(n);
    int CurrentNode = 0;
    for(auto &node : graph)
    {
        node = new Node(++CurrentNode);
    }   
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x >> y;
        graph[x-1]->neighbors.push_back(graph[y-1]);
        graph[y-1]->neighbors.push_back(graph[x-1]);
    }
    DFS(graph[0],NULL);
    for(auto &Nodes : graph)
    {
        if(!Nodes->visited)
        {
            tree = false;
        }
    }
    cout<< ((tree)?"YES":"NO");
    return 0;
}