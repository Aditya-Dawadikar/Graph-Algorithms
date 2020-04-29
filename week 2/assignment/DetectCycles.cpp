#include <iostream>
#include <list>
using namespace std;

class Graph
{
  int v;
    list < int >*adj;

public:
    int flag;
    Graph (){}
    void create(int v);
    void addEdge (int v, int w);
    bool isCycleUtil (int v, bool visited[],bool *rs);
    bool isCycle ();
    void showadj();
};

void Graph::create(int v){
    this->v = v;
    adj = new list < int >[v];
    flag=0;
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
}

bool Graph::isCycleUtil(int v, bool visited[],bool *recStack){
    visited[v]=true;
    recStack[v]=true;
    list<int>:: iterator i;
    for(i=adj[v].begin(); i!= adj[v].end();i++){
        if(!visited[*i] && isCycleUtil(*i,visited,recStack)){
            	return true;
        }
        else if(recStack[*i]){
        	return true;
		}
    }
    recStack[v]=false;
    return false;
}

bool Graph::isCycle(){
    bool *visited=new bool[v];
    bool *recStack=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        recStack[i]=false;
    }
    
    for(int i=0;i<v;i++){
	    	if(isCycleUtil(i,visited,recStack))
    		{
    			return true;
			}
	}
	return false;
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
    if(g.isCycle()){
        cout<<"1";
    }else{
        cout<<"0";
    }
  return 0;
}




