#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int v;
	list<int> *adj;
	public:
		void create(int n);
		void addEdge(int x,int y);
		bool isBipartite();
};

void Graph::create(int n){
	v=n;
	adj=new list<int>[n];
}

void Graph::addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}

bool Graph::isBipartite(){
	int src=0;
	bool visited[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	queue<int> q;
	int color[v];
	color[src]=1;
	
	q.push(src);
	int temp;
	list<int>::iterator i;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		visited[temp]=true;
		
		for(i=adj[temp].begin();i!=adj[temp].end();i++){
			if(visited[*i]&&color[*i]==color[temp] ){
				return false;
			}else if(!visited[*i]){
				color[*i]=1-color[temp];
				q.push(*i);				
			}
		}
	}
	return true;
}

main(){
	int n,m;
	
	cin>>n>>m;
	int x,y;
	Graph g;
	g.create(n);
	for(int i=0;i<m;i++){
		cin>>x>>y;
		g.addEdge(x-1,y-1);
	}
	cout<<g.isBipartite();
	return 0;
}










