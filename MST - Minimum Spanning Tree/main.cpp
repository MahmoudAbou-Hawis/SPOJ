#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
typedef long long int ll;

struct Node
{
   Node * par = this; 
};

struct Edge
{
    Node * from = NULL;
    Node * to   = NULL  ;
    int weight  = 0;
    Edge(Node * Src , Node * dist , int _weight): from(Src), to(dist), weight(_weight){}
    bool operator < (const Edge &EdgeTwo) const
    {
        return weight < EdgeTwo.weight;
    }
};

Node * getParent(Node* _Node)
{
    if(_Node == _Node->par)
    {
        return _Node;
    }
    return _Node->par = getParent(_Node->par);
}

void join(Node * First, Node * Second)
{
    First  = getParent(First);
    Second = getParent(Second);
    if(First != Second)
    {
        Second->par = First;
    }
}

ll kruskal(vector<Edge>&edges)
{
    sort(all(edges));
    ll cost = 0;
    for(auto &i : edges)
    {
        if(getParent(i.from) != getParent(i.to))
        {
            join(i.from,i.to);
            cost += i.weight;
        }
    }
    return cost;
}

int main()
{
    Code By Abou_Hawis
    int n, m ;
    cin >> n >> m;
    vector<Node >nodes(n);
    vector<Edge>Edges;
    for(int i = 0 ; i < m ; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        Edges.push_back(Edge(&nodes[u-1],&nodes[v-1],c));
    }
    cout << kruskal(Edges) << '\n';



    return 0;
}