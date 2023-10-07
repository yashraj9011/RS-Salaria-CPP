


//Program to illustrate the input and output of a non-weighted graph
 #include <bits/stdc++.h>
using namespace std;
 #define MAX 20

struct NWNode {
 int vertex;

//node declaration --

NWNode *next; 
};


class NonWeightedGraph // class modelling weighted graph
{
protected:
		 NWNode *adj[MAX];

		int size;

		public:

		NonWeightedGraph(int n);
		~NonWeightedGraph();

		void addEdge (int i, int j, int w);

		void deleteEdge (int i, int j );

		void inputGraph();
		 void printGraph();

		void BFS(int a);

		void DFSIterative (int s);

		void DFSRecursive (int s); 
		void DFSVisit (int u);

		void DFSRecursiveModified();

		void DFSVisitModified (int u);
		 void topologicalSort();
};
 NonWeightedGraph::NonWeightedGraph (int n) {

		int i;

		for (i = 1; i < n; i++)
		adj[i]=NULL;

		size=n;
}
//member function to input a weighted graph
 void NonWeightedGraph::inputGraph()
{

		NWNode *ptr, *last;
		 int i, j, m, val;

		for (i=1; i<=size; i++) {

			last= NULL;

		 cout<<"\nNumber of nodes in the adjacency" << "list of node " << i <<":";

			cin >> m;
			
			 for (j=1; j<= m; j++) 
			 {
			  cout << "Enter node i"<< j<<":";
			   cin >> val;

			ptr=new NWNode;
			 ptr->vertex= val;

			ptr->next = NULL;

			if(adj[i]== NULL)
			 adj[i]=last=ptr;

			else {
			

			last->next=ptr;


				last = ptr;
}

}
}
}
//member function to input a weighted graph 
void NonWeightedGraph::printGraph()
{

	NWNode *ptr; 
	int i;

		for (i = 1; i<=size; i++ ) {

		ptr = adj[i]; 
		cout << "\n" << i;

		while (ptr != NULL) 
		{
		

		cout << "->"<< ptr->vertex;
			ptr=ptr->next;
}
		cout << endl;
}
}
// destructor

NonWeightedGraph::~NonWeightedGraph()
{

int i;

NWNode *temp, *ptr;
 for (i = 1; i<=size; i++) {

	ptr =adj[i];
	 while (ptr != NULL) {

	temp = ptr;
	 ptr=ptr->next;
	  delete temp;

}
	 adj[i] = NULL;
}
}
int main()
{

		int n;

		cout<<"\nEnter number of nodes [<-20) in the graph : ";
	

		cin >> n;
	 NonWeightedGraph nwgraph (n);
			nwgraph.inputGraph();
			 cout<<"\nADJACENCY LIST FOR INPUT GRAPH \n\n";

			nwgraph.printGraph();

}

