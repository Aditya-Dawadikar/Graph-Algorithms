#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int v;
    list < int >*adj;
    
public:
    int count;
    Graph (){}
    void create(int v);
    void addEdge (int v, int w);
    void DFSUtil (int v, bool visited[]);
    void DFS ();
    void showadj();
};

void Graph::create(int v){
    this->v = v;
    adj = new list <int>[v];
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

void Graph:: addEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
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
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    count=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            DFSUtil(i,visited);
            count+=1;
        }
    }
}

int main ()
{
    Graph g;
    int n,m;
    cin>>n>>m;
    g.create(n);
    int i,j;
    for(int k=0;k<m;k++){
        cin>>i>>j;
        g.addEdge(i-1,j-1);
    }
    //g.showadj();
    g.DFS();
    cout<<g.count;
  return 0;
}



