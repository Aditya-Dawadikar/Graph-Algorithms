#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
# define INF 0x3f3f3f3f 
   
typedef pair<int, int> iPair; 
  
class Graph 
{ 
    int V; 
   
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);  
   
    void addEdge(int u, int v, int w); 
   
    void shortestPath(int s,int d); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
} 
   
void Graph::shortestPath(int src,int des) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    vector<int> dist(V, INF); 
  
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    if(dist[des]==INF){
        cout<<"-1";
    }else{
        cout<<dist[des];
    }
} 
 
int main() 
{ 
    int n,m,x,y,w;
    cin>>n>>m;
    Graph *g;
    
    g=new Graph(n);
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        g->addEdge(x-1,y-1,w);
    }
    cin>>x>>y;
    g->shortestPath(x-1,y-1);
    
    return 0; 
} 