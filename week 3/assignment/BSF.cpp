#include<iostream>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int> *adj;
    public:
     bool *visited;
    
    Graph(int n){
        this->v=n;
        adj=new list<int>[v];
    }
    
    void addEdge(int p,int q){
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    
    int BFS(int s,int d);
    
    void show();
};

void Graph::show(){
	list<int>::iterator j;
	for(int i=0;i<v;i++){
		cout<<i+1<<":";
		for(j=adj[i].begin();j!=adj[i].end();j++){
			cout<<*j+1<<" ";
		}cout<<"\n";
	}
}

int Graph::BFS(int s,int d){
    list<int> queue;
    
    /*cout<<"s:"<<s;
    cout<<"d:"<<d;
    cout<<"\n";
    */
    visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    
    visited[s]=true;
    queue.push_back(s);
    int count=0;
    
    int k;
    int flag=0;
    
    list<int>:: iterator i;
    
    while(!queue.empty()){
        k=queue.front();
        queue.pop_front();
        //cout<<k+1<<" ";
        
        count++;
        //cout<<"\n";
        for(i=adj[k].begin();i!=adj[k].end();i++){
            if(!visited[*i]){
                visited[*i]=true;
                queue.push_back(*i);
                //cout<<*i+1<<" ";
                if(*i==d){
                    return count;
                }
            }
            
        }
    }
    
       return -1;
}

main(){
    
    Graph *g;
    int m,n,p,q,s,d;
    cin>>n>>m;
    g=new Graph(n);
    for(int i=0;i<m;i++){ 
        cin>>p>>q;
        g->addEdge(p-1,q-1);
    }
    g->show();
    cin>>s>>d;
    int ans= g->BFS(s-1,d-1);
    if(ans==1){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
















