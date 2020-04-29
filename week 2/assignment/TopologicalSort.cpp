#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
  	int v;
    
public:
    int flag;
    list < int >*adj;
    Graph (){}
    void create(int v);
    void addEdge (int v, int w);
    void topologicalUtil (int v, bool visited[], stack<int> &stack);
    void topologicalSort();
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

void Graph::topologicalUtil(int v, bool visited[],stack<int> &stack){
    visited[v]=true;
    
    list <int>::iterator i;
    for(i=adj[v].begin(); i!= adj[v].end();i++){
        if(!visited[*i]){
            topologicalUtil(*i,visited,stack);
        }
    }
 	stack.push(v)   ;
}

void Graph::topologicalSort(){
	stack <int> stack;
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    for(int i=0;i<v;i++){
    	if(visited[i]==false)
        topologicalUtil(i,visited,stack);
    }
    
    while(stack.empty()==false){
    	cout<<stack.top()+1<<" ";
    	stack.pop();
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
    g.topologicalSort();
    //list<int>:: iterator l;
    /*
    for(int i=0;i<g.ans.size();i++){
    	cout<<g.ans[i]<<" ";
	}cout<<"\n";*//*
	for(int i=g.ans.size();i>=0;i--){
    	cout<<g.ans[i]<<" ";
	}cout<<"\n";*/
	  return 0;
}




