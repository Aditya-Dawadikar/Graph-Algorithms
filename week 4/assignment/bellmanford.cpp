#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Edge{
  int s,d,w;  
};

class Graph{
    int v,e;
    Edge *edge;
    long int *dist;
    public:
    Graph(int v,int e){
        this->v=v;
        this->e=e;
        edge= new Edge[v];
        dist= new long int[v];
    }
    
    void addEdge(){
	int u,v,w;
        for(int i=0;i<e;i++){
		cin>>u>>v>>w;
		edge[i].s=u-1;
		edge[i].d=v-1;
		edge[i].w=w;
        }
    }
    
    void bellmanFord(){
        for(int i=0;i<v;i++){
            dist[i]=INT_MAX;
        }
        dist[0]=0;
        int u,v,weight;
        for(int i=1;i<v;i++){
        	cout<<"i: "<<i<<endl;
            for(int j=0;j<e;j++){
            	cout<<"j: "<<j<<endl;
                u=edge[j].s;
                v=edge[j].d;
                weight=edge[j].w;
                
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight){
                    dist[v]=dist[u]+weight;
                }
            }
            cout<<"s\td\twt"<<endl;
            for(int j=0;j<e;j++){
            	cout<<dist[u]<<"\t"<<dist[v]<<endl;
			}
        }
        for(int j=0;j<e;j++){
            u=edge[j].s;
            v=edge[j].d;
            weight=edge[j].w;
            
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight){
                cout<<1;
                return;
            }
        }
        
        cout<<0;
        return;
    }
    
    void show(){
        cout<<"vertex\tdist\n";
        for(int i=0;i<v;i++){
            cout<<i+1<<"\t"<<dist[i]<<endl;
        }
    }
};

int main()
{
    Graph *g;
    int v,e;
    cin>>v>>e;
    g=new Graph(v,e);
    g->addEdge();
    g->bellmanFord();
    cout<<"\n";
    //g->show();
    return 0;
}










