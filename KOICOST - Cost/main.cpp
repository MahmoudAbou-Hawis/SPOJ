#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD=1e9, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 9 ;

#define  Parent        int
#define  NodesNumber   int
struct Node
{
   Node * par  = this; 
   int sz = 1;
};
 
struct Edge
{
    int weight = 0;
    Node * fromNode = NULL;
    Node * toNode   = NULL;
    Edge(int _weight , Node * _fromNode , Node * _toNode) : weight(_weight) , fromNode(_fromNode) , toNode(_toNode){}
    bool operator > (const Edge &E2) const
    {
        return weight > E2.weight ;
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

void join(Node * First, Node * Second ,ll &Current) 
{
    First  = getParent(First);
    Second = getParent(Second);
    if(First != Second)
    {
        Current = (Current + ((ll)First->sz * Second->sz)%MOD)%MOD;
        Second->par = First;
        First->sz  += Second->sz;
    }
}


int main()
{
    Code By Abou_Hawis
    int n, m;
    cin >> n >> m;
    vector <Node*>Nodes(n);
    for(auto &i : Nodes) i =new Node;
    vector<Edge>Edges;
    for(int i = 0 ; i < m ; i++)
    {
        int u ,v ,c;
        cin >> u >> v >> c;
        Edges.pb(Edge(c , Nodes[u-1] , Nodes[v-1]));
    }
    sort(all(Edges),greater<>());
    ll cur = 0;
    ll ans = 0;
    for(auto &i : Edges)
    {
        join(i.fromNode,i.toNode,cur);
        ans = (ans + (cur * i.weight)%MOD)%MOD;
    }
    cout << ans << '\n';
    return 0;
}