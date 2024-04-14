#include<iostream>
#include<climits>
using namespace std;

struct node
{
    int from;
    int to;
    int weight;
    node* next;
};

struct vnode
{
    string name;
    int d;
    int pi;
};

class graph
{
    int m,n;
    vnode vertex[10];
    node* elist;
 public:
    void createGraph(int n1,int m1)
    {
   	 n = n1;
   	 for(int i=0 ; i<n ; i++)
   		 vertex[i].name = (i+1);
   	 m = m1;
   	 elist = NULL;
   	 node* last = NULL;   	 
   	 for(int j=0 ; j<m ; j++)
   	 {
   		 node* t = new node;
   		 cout<<"from:";
   		 cin>>t->from;
   		 cout<<"to:";
   		 cin>>t->to;
   		 cout<<"weight:";
   		 cin>>t->weight;
   		 t->next = NULL;
   		 if(last == NULL)
   			 elist = t;
   		 else
   			 last->next = t;
   		 last = t;
   	 }
    }
    
    void initializeSingleSource(int s)
    {
   	 for(int i=0 ; i<n ; i++)
   	 {
   		 vertex[i].d = INT_MAX;
   		 vertex[i].pi = 0;
   	 }
   	 vertex[s].d = 0;
    }

    void relax(int u,int v,int w)
    {
   	 if(vertex[v].d > (vertex[u].d+w))
   	 {
   		 vertex[v].d = vertex[u].d + u;
   		 vertex[v].pi = u;
   	 }
    }
    
    bool bellFord(int s)
    {
   	 initializeSingleSource(s);
   	 for(int  i=0; i<n-1; i++)
   	 {
   		 node* t = elist;
   		 while(t != NULL)
   		 {
   			 relax(t->from,t->to,t->weight);
   			 t = t->next;
   		 }
   		 delete(t);
   	 }
   	 node* t = elist;
   	 while(t != NULL)
   	 {
   		 cout<<t->from<<"->("<<t->weight<<")->"<<t->to<<"\t";
   		 if(vertex[t->to].d > (vertex[t->from].d + t->weight))
   			 return false;
   		 t = t->next;
   	 }
   	 cout<<endl;
   	 return true;
    }
};

int main(void)
{
    graph g;
    int m,n,s;
    cout<<"No.of vertices & edges:";
    cin>>n>>m;
    g.createGraph(n,m);
    cout<<"Source vertex:";
    cin>>s;
    bool x = g.bellFord(s-1);
    cout<<x<<endl;
}
