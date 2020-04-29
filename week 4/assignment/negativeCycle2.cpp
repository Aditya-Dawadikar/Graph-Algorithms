#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src,des,weight;
};

class Graph
{
    int v,e;
    list < int >*adj;
    Edge *edges;
    bool flag;
public:
    int count;
    Graph (){}
    void create(int v,int e);
    void addEdgeList(int, int);
    void addEdgeVector(int ,int ,int ,int);
    void DFSUtil (int v, bool visited[]);
    void DFS ();
    void showadj();
    bool BellmanFord(int);
};

void Graph::create(int v,int e){
    this->v = v;
    this->e =e;
    adj = new list <int>[v];
    edges = new Edge[e];
}

void Graph:: showadj(){
    list<int>::iterator j;
    for(int i=0;i<v;i++){
        cout<<i<<":";
        for(j=adj[i].begin();j!=adj[i].end();j++){
            cout<<*j<<" ";
        }cout<<"\n";
    }
}

void Graph:: addEdgeList(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph:: addEdgeVector(int i,int u,int v,int w){
    edges[i].src=u;
    edges[i].des=v;
    edges[i].weight=w;
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v]=true;
    //cout<<v<<" ";
    list<int>:: iterator i;
    for(i=adj[v].begin(); i!= adj[v].end();i++){
        if(!visited[*i]){
            DFSUtil(*i,visited);
        }
    }
}

void Graph::DFS(){
    bool *visited=new bool[v];
    flag=false;
    bool temp;
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    count=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            //cout<<"dfsutil working\n";
            temp=BellmanFord(i);
            //cout<<temp<<"\n";
            DFSUtil(i,visited);
            count+=1;
        }
        flag= flag or temp;
        if(temp){
            break;
        }
    }
    cout<<flag;
}

bool Graph::BellmanFord(int src) 
{ 
    //cout<<"bellman called\n";
    int dist[v]; 
  
    for (int i = 0; i < v; i++) 
    {dist[i] = 0;} 
    
    dist[src] = 0; 
   
    for (int i = 1; i <= v - 1; i++) { 
        for (int j = 0; j < e; j++) { 
            int p = edges[j].src; 
            int q = edges[j].des; 
            int w =edges[j].weight; 
            if (dist[p] != INT_MAX && dist[p] + w < dist[q]) 
                dist[q] = dist[p] + w; 
        } 
    } 
  
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there 
    // is a cycle. 
    //cout<<"cycles complete\n";
    
    for (int i = 0; i < e; i++) { 
        //cout<<"validating\n";
        int p =edges[i].src; 
        int q =edges[i].des; 
        int w =edges[i].weight; 
        if (dist[p] != INT_MAX && dist[p] + w < dist[q]) { 
            //cout<<"negative cycle detected\n"; 
            return true;  
        } 
    } 
  
    //printArr(dist, V); 
    //cout<<"exiting bellman\n";
    return false; 
} 

int main()
{
    Graph g;
    int n,m,x,y,w;
    cin>>n>>m;
    g.create(n,m);
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        g.addEdgeVector(i,x-1,y-1,w);
        g.addEdgeList(x-1,y-1);
    }
    g.DFS();
    return 0;
}
