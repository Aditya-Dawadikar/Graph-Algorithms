#include <iostream>
#include <list>
using namespace std;

class Graph
{
  int v;
    list < int >*adj;

public:
    int flag;
    int count;
    Graph (){}
    void create(int v);
    void addEdge (int v, int w);
    void DFSUtil (int v,int d, bool visited[]);
    void DFS (int s,int d);
    void showadj();
};

void Graph::create(int v){
    this->v = v;
    adj = new list < int >[v];
    flag=0;
    count=0;
}

void Graph:: showadj(){
    list<int>::iterator j;
    for(int i=0;i<v;i++){
        cout<<i+1<<":";
        for(j=adj[i].begin();j!=adj[i].end();j++){
            cout<<*j+1<<" ";
        }cout<<"\n";
    }
}

void Graph:: addEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v,int d, bool visited[]){
    visited[v]=true;
    list<int>:: iterator i;
    for(i=adj[v].begin(); i!= adj[v].end();i++){
        if(!visited[*i]){
            if(*i==d){
                flag=1;
                break;
            }
            visited[*i]=true;
            DFSUtil(*i,d,visited);
        }
    }
}

void Graph::DFS(int s,int d){
    bool *visited=new bool[s];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    DFSUtil(s,d,visited);
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
    g.showadj();
    cin>>i>>j;
    g.DFS(i-1,j-1);
    if(g.flag==1){
        cout<<"1";
    }else{
        cout<<"-1";
    }
  return 0;
}



