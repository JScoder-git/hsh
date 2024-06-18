//3.

.13 Tower
void hanoi(int n, char a, char b, char c) {
	if (n==1) { // Fill the condition
		cout << "Move disk - " <<  n<< " from pole " <<  a<< " to " << c << endl; // Complete the statement
	} else {
		hanoi( n-1,a,c,b); // Fill the arguments in the function call
		cout << "Move disk - " << n<< " from pole " << a << " to " << c << endl; // Complete the statement
		hanoi(n-1,b,a,c ); // Fill the arguments in the function call
	}
}

//15.1.1 --> b,d,e
//15.1.2 --> a,c,d

//14.1.1 --> a,c
//14.1.2 -->a
//14.1.3 -->a,b
//14.1.4 --> b,c
//14.1.5 -->a,b

//13.2.1

#include<iostream>
#include<iomanip>
using namespace std;
#define INF 99999
int graph[20][20];
int N = 20,E;





void printSolution(int dist[20][20]){
cout << "The following matrix shows the shortest distances between all pairs of the vertices.\n";
for(int i = 1; i <= N; i++) {
for(int j = 1; j <= N; j++) {
if(dist[i][j] == INF) {
cout << setw(5) << "INF";
} else {
cout << setw(5) << dist[i][j];
}
}
cout << "\n";
}
}
void floydWarshall () { 


int dist[20][20];

// Initialize the distance matrix same as input graph matrix
for (int i = 1; i <= N; i++) {
for (int j = 1; j <= N; j++) {

dist[i][j] =(i==j)?0:graph[i][j];
}
}

// Update distance matrix with all intermediate vertices
for (int k = 1; k <= N; k++) {
for (int i = 1; i <= N; i++) {
for (int j = 1; j <= N; j++) {
if (dist[i][k] + dist[k][j] < dist[i][j]) {
dist[i][j] = dist[i][k] + dist[k][j];
}
}
}
}

// Print the solution
printSolution(dist);
} 

//13.3.1 --> a
//13.3.2 inside knapsack funtion

// write your code here 
int i, j;
int K[n + 1][W + 1];

for (i = 0; i <= n; i++) {
for (j = 0; j <= W; j++) {
if (i == 0 || j == 0)
K[i][j] = 0;
else if (w[i - 1] <= j)
K[i][j] = max(p[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
else
K[i][j] = K[i - 1][j];
}
}

return K[n][W];


//12

//12.1.1 --> a,c
//12.1.2 -->
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int i, j, k, a, b, u, v, n, e, s, d, w, ne = 1;
int minimum, mincost = 0, cost[9][9], parent[9];

int find(int i) {
while (parent[i])
i = parent[i];
return i;
}

int uni(int i, int j) {
if (i != j) {
parent[j] = i;
return 1;
}
return 0;
}

void kruskal() {
cout << "The edges of Minimum Cost Spanning Tree are: \n";
while (ne < n) {
for (i = 1, minimum = 999; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (cost[i][j] < minimum) {
minimum = cost[i][j];
a = u = i;
b = v = j;
}
}
}
u = find(u);
v = find(v);
if (uni(u, v)) {
cout << "Edge cost from " << a << " to " << b << ": " << minimum << endl;
ne++;
mincost += minimum;
}
cost[a][b] = cost[b][a] = 999;
}
cout << "Minimum cost of spanning tree = " << mincost << endl;
}

int main() {
cout << "Enter the number of vertices: ";
cin >> n;
cout << "Enter the number of edges: ";
cin >> e;
for (i = 1; i <= e; i++) {
cout << "Enter source: ";
cin >> s;
cout << "Enter destination: ";
cin >> d;
cout << "Enter weight: ";
cin >> w;
if (s <= 0 || d <= 0 || s > n || d > n || w < 0) {
cout << "Invalid data. Try again.\n";
i--;
continue;
}
cost[s][d] = w;
}
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (cost[i][j] == 0)
cost[i][j] = 999;
}
}
kruskal();
return 0;
}

//12.2.1 -->
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int a, b, u, v, n, i, j, ne = 1, e, s, d, w;
int visited[10] = {0}, minimum, mincost = 0, cost[10][10];

void prims() {
	    visited[1] = 1; // Starting from vertex 1

	    cout << "The edges of Minimum Cost Spanning Tree are: \n";
	    while (ne < n) {
			        minimum = 999;
			        for (i = 1; i <= n; i++) {
						            if (visited[i]) {
										                for (j = 1; j <= n; j++) {
															                    if (!visited[j] && cost[i][j] < minimum) {
																					                        minimum = cost[i][j];
																					                        a = u = i;
																					                        b = v = j;
																				}
														}
									}
					}
			        if (!visited[v]) {
						            cout << "Edge cost from " << a << " to " << b << ": " << minimum << endl;
						            visited[v] = 1;
						            ne++;
						            mincost += minimum;
					}
			        cost[a][b] = cost[b][a] = 999;
		}
	    cout << "Minimum cost of spanning tree = " << mincost << endl;
}

int main() {
	    cout << "Enter the number of vertices: ";
	    cin >> n;
	    cout << "Enter the number of edges: ";
	    cin >> e;
	    for (i = 1; i <= e; i++) {
			        cout << "Enter source: ";
			        cin >> s;
			        cout << "Enter destination: ";
			        cin >> d;
			        cout << "Enter weight: ";
			        cin >> w;
			        if (s <= 0 || d <= 0 || s > n || d > n || w < 0) {
						            cout << "Invalid data. Try again.\n";
						            i--;
						            continue;
					}
			        cost[s][d] = w;
			        cost[d][s] = w; // Assuming undirected graph
		}
	    for (i = 1; i <= n; i++) {
			        for (j = 1; j <= n; j++) {
						            if (cost[i][j] == 0)
										                cost[i][j] = 999;
					}
		}
	    prims();
}

//12.4.1 --> a,c
//12.4.2 --> inside knapsack function 
capacity;
struct Item {
	float weight;
	float profit;
	float ratio;
 };

      Item items[n];


      for (int i = 0; i < n; ++i) {
          items[i].weight = weight[i];
          items[i].profit = profit[i];
          items[i].ratio = profit[i] / weight[i];
  }

      for (int i = 0; i < n - 1; ++i) {
          for (int j = i + 1; j < n; ++j) {
              if (items[i].ratio < items[j].ratio) {
					swap(items[i], items[j]);
																									  }
																					  }
																		  }

				float totalProfit = 0.0;
			 float remainingCapacity = capacity;

			 // Iterate through the items and add them to the knapsack
			 for (int i = 0; i < n; ++i) {
					if (remainingCapacity >= items[i].weight) {
				 // If the item can be fully added to the knapsack
				 totalProfit += items[i].profit;
			remainingCapacity -= items[i].weight;
					 }
					else {
		 // If only a fraction of the item can be added to the knapsack
			totalProfit += remainingCapacity / items[i].weight * items[i].profit;
					break; // Knapsack full
																					  }
																		  }
				 // Print the maximum profit
							 cout << "Maximum profit is:- " << totalProfit << endl;
 if (wt == sum) return true;
    if (i + 1 < n && wt + w[i + 1] <= sum) {
        return subset(i + 1, wt + w[i + 1], total - w[i + 1]);
    }
    if (i + 1 < n && wt + total - w[i + 1] >= sum) {
        return subset(i + 1, wt, total - w[i + 1]);
    }
    return false;

//9 
//9.1.1 --> a,c
//9.1.2 --> a,c
//9.2.1 --> 

class Graph {
	public :
	int numVertices, numEdges;
	int adjMatrix[20][20];
	void print();
	void insertVertex(int num_incoming_edges, int num_outgoing_edges, int incoming[20], int outgoing[20]);
	void insertEdge(int source, int destination);
	void deleteVertex(int del_vertex);
	void deleteEdge(int source, int destination);
};
void Graph::print() {
	for(int i=1;i<=numVertices;i++){
		for(int j=1;j<=numVertices;j++){
			cout<<adjMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void Graph::insertVertex(int num_incoming_edges, int num_outgoing_edges, int incoming[20], int outgoing[20]) {
	numVertices++;
	for(int i=1;i<=numVertices;i++){
		adjMatrix[i][numVertices]=0;
	}
	for(int i=1;i<=numVertices;i++){
		adjMatrix[numVertices][i]=0;
	}
	for(int i=1;i<=num_incoming_edges;i++){
		adjMatrix[incoming[i]][numVertices]=1;
	}
	for(int i=1;i<=num_outgoing_edges;i++){
		adjMatrix[numVertices][outgoing[i]]=1;
	}
}
void Graph::insertEdge(int source, int destination) {

		if(adjMatrix[source][destination]!=0){
			cout<<"Edge already exists.\n";
			return;
		}
		adjMatrix[source][destination]=1;
}
void Graph::deleteVertex(int del_vertex) {
	if(numVertices==0){
		cout<<"Graph is empty.\n";
		return;
	}
	if(del_vertex>numVertices){
		cout<<"Invalid vertex.\n";
		return;
	}
	for(int i=del_vertex;i<=numVertices-1;i++){
		for(int j=1;j<=numVertices;j++){
			adjMatrix[j][i]=adjMatrix[j][i+1];
		}
	}
	for(int i=del_vertex;i<=numVertices-1;i++){
		for(int j=1;j<=numVertices;j++){
			adjMatrix[i][j]=adjMatrix[i+1][j];
		}
	}
	numVertices--;
}
void Graph::deleteEdge(int source, int destination) {
	if((source<=numVertices&&source>0) && (destination<=numVertices && destination>0)){
		if(adjMatrix[source][destination]==0){
			cout<<"Edge does not exist.\n";
		}
		else{
			adjMatrix[source][destination]=0;
		}
	}
	else{
		cout<<"Invalid vertex.\n";
	}
}

//9.2.2 --> 
class Graph {
	public :
	int numVertices, numEdges;
	int adjMatrix[20][20];
	void print();
	void insertVertex(int num_edges, int existingVertices[20]);
	void insertEdge(int source, int destination);
	void deleteVertex(int del_vertex);
	void deleteEdge(int source, int destination);
};
void Graph::print() {
	// cout<<numVertices;
	if(numVertices==0){
		cout<<"Graph is empty.\n";
		return;
	}
	for(int i=1;i<=numVertices;i++){
		for(int j=1;j<=numVertices;j++){
		cout<<adjMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void Graph::insertVertex(int num_edges, int existingVertices[20]) {
	numVertices++;
	for(int i=1;i<=numVertices;i++){
		adjMatrix[i][numVertices]=0;
		adjMatrix[numVertices][i]=0;
	}
	for(int i=1;i<=num_edges;i++){
		adjMatrix[numVertices][existingVertices[i]]=1;
		adjMatrix[existingVertices[i]][numVertices]=1;
	}

}
void Graph::insertEdge(int source, int destination) {
	if(source>0&&source<=numVertices && destination>0&&destination<=numVertices){
		if(adjMatrix[source][destination]==1){
			cout<<"Edge already exists.\n";
			
		}
		else{
			adjMatrix[source][destination]=1;
			adjMatrix[destination][source]=1;
		}
	}
	else{
		cout<<"Invalid input.\n";
	}
}
void Graph::deleteVertex(int del_vertex) {
	if(del_vertex>0&&del_vertex<=numVertices){
		for(int i=del_vertex;i<numVertices;i++){
			for(int j=1;j<=numVertices;j++){
				adjMatrix[i][j]=adjMatrix[i+1][j];
			}
		}
		for(int i=del_vertex;i<numVertices;i++){
			for(int j=1;j<=numVertices;j++){
				adjMatrix[j][i]=adjMatrix[j][i+1];
			}
		}
		numVertices--;
	}
	else{
		cout<<"Invalid vertex.\n";
	}
	
}
void Graph::deleteEdge(int source, int destination) {
	if(source>0&&source<=numVertices && destination>0&&destination<=numVertices){
		if(adjMatrix[source][destination]==0){
			cout<<"Edge does not exists.\n";
			
		}
		else{
			adjMatrix[source][destination]=0;
			adjMatrix[destination][source]=0;
		}
	}
	else{
		cout<<"Invalid input.\n";
	}
	
}
//9.2.3 --> 

class GNODE {
	public:
	GNODE *next;
	int vertex;
};
class Graph {
	public:
	GNODE* adjList[20];
	int numVertices,numEdges;
	void print();
	void insertVertex(int num_edges, int existingVertices[20]);
	void insertEdge(int source, int destination);
	void deleteVertex(int del_vertex);
	void deleteEdge(int source,int destination);
};

void Graph::print() {
	if(numVertices==0){
		cout<<"Graph is empty.\n";
		
	}
	else{
		for(int i=1;i<=numVertices;i++){
			GNODE* temp=adjList[i];
			cout<<i<<"=> ";
			while(temp){
				cout<<temp->vertex<<"\t";
				temp=temp->next;
			}
			cout<<endl;
		}
	}
}
void Graph::insertVertex(int num_edges, int existingVertices[20]) {
	numVertices++;
	adjList[numVertices]=NULL;
	for(int i=1;i<=num_edges;i++){
		// cout<<numVertices<<" "<<existingVertices[i]<<endl;
		insertEdge(numVertices,existingVertices[i]);
	}
	
}
void Graph::insertEdge(int source, int destination) {
	if(source>0 && source<=numVertices && destination>0 && destination <= numVertices){
		GNODE *temp=adjList[source];
		while(temp){
			if(temp->vertex==destination){
				// cout<<"Edge already exists.\n";
				return;
			}
			temp=temp->next;
		}
		GNODE *newNode=new GNODE;
		newNode->vertex=destination;
		newNode->next=adjList[source];
		adjList[source]=newNode;
		if(source!=destination){
			GNODE *tempNew=new GNODE;
			tempNew->vertex=source;
			tempNew->next=adjList[destination];
			adjList[destination]=tempNew;
		}
	}
	else{
		cout<<"Invalid input.\n";
	}
}
void Graph::deleteVertex(int del_vertex) {
	if(del_vertex<1 || del_vertex>numVertices){
		cout<<"Invalid vertex.\n";
		return;
	}
	for(int i=del_vertex;i<=numVertices-1;i++){
		adjList[i]=adjList[i+1];
	}
	numVertices--;
	for(int i=1;i<=numVertices;i++){	
	GNODE *prev=NULL;
	GNODE *curr=adjList[i];
	if(curr==NULL)continue;
	GNODE* temp=NULL;
		while(curr){
			if(curr->vertex==del_vertex){
				temp=curr;
			}
			if(temp==NULL){
				prev=curr;
			}
			if(curr->vertex>del_vertex){
				curr->vertex--;
			}
			curr=curr->next;
		}
		if(prev==NULL){
			adjList[i]=temp->next;
		}
		else if(temp){
			prev->next=temp->next;
		}
	}

}
void Graph::deleteEdge(int source, int destination) {
	if(source>0 && source<=numVertices && destination<=numVertices && destination>0){
		GNODE* temp=adjList[source];
		GNODE* prev=NULL;
		while(temp){
			if(temp->vertex==destination)break;
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL){
			cout<<"Edge does not exists.\n";
		}
		else{
			//delete from sources
			if(prev==NULL){
				adjList[source]=temp->next;
			}
			else{
			prev->next=temp->next;
			}
			// cout<<"deleted from source"<<endl;
			//delete from dest
			prev=NULL;
			temp=adjList[destination];
			while(temp){
				if(temp->vertex==source){
					break;
				}
				prev=temp;
				temp=temp->next;
			}
				if(prev==NULL){
					adjList[destination]=temp->next;
				}else{
					prev->next=temp->next;
				}
			// cout<<"deleted from destination"<<endl;
		}
		
	}else{
		cout<<"Invalid input\n";
	}
}

//9.2.4

class GNODE {
	public:
	GNODE *next;
	int vertex;
};
class Graph {
	public:
	GNODE* adjList[20];
	int numVertices,numEdges;
	void print();
	void insertVertex(int num_incoming_edges, int num_outgoing_edges, int incoming[20], int outgoing[20]);
	void insertEdge(int source, int destination);
	void deleteVertex(int del_vertex);
	void deleteEdge(int source,int destination);
};

void Graph::print() {
	if(numVertices==0){
		cout<<"Graph is empty.\n";
		return;
	}
	for(int i=1;i<=numVertices;i++){
		cout<<i<<"=> ";
		GNODE* temp=adjList[i];
		while(temp){
			cout<<temp->vertex<<"\t";
			temp=temp->next;
		}
		cout<<endl;
	}
}

void Graph::insertVertex(int num_incoming_edges, int num_outgoing_edges, int incoming[20], int outgoing[20]) {
	numVertices++;
	for(int i=1;i<=num_incoming_edges;i++){
		insertEdge(incoming[i],numVertices);
	}
	for(int i=1;i<=num_outgoing_edges;i++){
		insertEdge(numVertices,outgoing[i]);
	}
}
void Graph::insertEdge(int source, int destination) {

	if(source>0 && source<=numVertices && destination>0 && destination<=numVertices){

		GNODE *curr=adjList[source];
		while(curr){
			if(curr->vertex==destination){
				cout<<"Edge already exists.\n";
				return;}
			curr=curr->next;
		}
	GNODE* temp=new GNODE;
		temp->vertex=destination;
		temp->next=adjList[source];
		adjList[source]=temp;
	}
	
}
void Graph::deleteVertex(int del_vertex) {
	for(int i=del_vertex;i<numVertices;i++){
		adjList[i]=adjList[i+1];
	}
	//removing as destination
	numVertices--;
	for(int i=1;i<=numVertices;i++){
	GNODE*curr=adjList[i];
	GNODE *temp=NULL;
	GNODE *prev=NULL;
	while(curr){
		if(curr->vertex==del_vertex){
			temp=curr;
		}
		if(temp==NULL){
			prev=curr;
		}
		if(curr->vertex>del_vertex){
			curr->vertex--;
		}
		curr=curr->next;
	}
		if(temp){
			if(prev==NULL){
				adjList[i]=temp->next;
			}
			else{
				prev->next=temp->next;
			}
		}
	}
}
void Graph::deleteEdge(int source, int destination) {
	if(source>0 && source<=numVertices && destination>0 && destination<=numVertices){
		GNODE*curr=adjList[source];
		GNODE*prev=NULL;
		while(curr){
			if(curr->vertex==destination){
			break;
			}
			prev=curr;
			curr=curr->next;
		}
		if(curr){
			if(prev==NULL){
				adjList[source]=curr->next;
			}
			else{
				prev->next=curr->next;
			}
		}
		else{
			cout<<"Edge does not exist.\n";
		}
	}

}

//9.3.1
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class GNODE {
	public :
    GNODE *next;
    int vertex;
};
class Graph {
	public :
	GNODE * graph[20];
	int N,E;
	int visited[20];
	void DFS(int start_vertex);
};

void Graph::DFS(int start_vertex) {
// 	Declare a variable p of type GNODE*.
// 			Print "\nstart_vertex" 
// 			    Assign graph[start_vertex] to p.
// 	Set visited[start_index] = 1
// 	 while(p not equal to NULL) {
// 		Assign vertex field of p to start_vertex
// 		if(visited[start_vertex] is equal to 0) {
// 			call : DFS(start_vertex) // Recursive call
// }
// 		       Assign next field of p to p
// }
GNODE* p;
	cout<<endl<<start_vertex;
	visited[start_vertex]=1;
	p=graph[start_vertex];
	while(p){
		start_vertex=p->vertex;
		if(visited[start_vertex]==0){
			DFS(start_vertex);
		}
		p=p->next;
	}

}

int main() {
    int i,s,d,v;
    GNODE *q,*p;
    Graph g;
    cout << "Enter the number of vertices : ";
	cin >> g.N;
	cout << "Enter the number of edges : ";
	cin >> g.E;
	for(i=1;i<=g.N;i++) {
		g.visited[i]=0;
		g.graph[i] = NULL;
	}
	for(i=1;i<=g.E;i++) {
		cout << "Enter source : ";
		cin >> s;
		cout << "Enter destination : ";
		cin >> d;
		q= new GNODE;
    	q->vertex=d;
    	q->next=NULL;
    	if(g.graph[s]==NULL)
        	g.graph[s]=q;
        else {
        	p=g.graph[s];
        	while(p->next!=NULL)
            	p=p->next;
    		p->next=q;
    	}
	}
	cout << "Enter Start Vertex for DFS : ";
    cin >> v;
    cout << "DFS of graph : ";
    g.DFS(v);
    cout << "\n";
}

//9.3.2
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAX 99
class GNODE {
	public:
	GNODE *next;
	int vertex;
};
class Graph {
	public :
	GNODE* graph[20];   
	int visited[20];
	int N,E;
	void BFS(int start_vertex);
};
class Queue {
	public:
	int queue[MAX], front,rear;
	Queue() {
		front = -1;
		rear = -1;
	}
	void enqueue(int vertex);
	int isEmpty();
	int dequeue();
};

void Queue::enqueue(int vertex) {
	    if (rear == MAX - 1) {
			        cout << "Queue Overflow\n";
			        return;
		}
	    if (front == -1) {
			        front = 0;
		}
	    rear++;
	    queue[rear] = vertex;
		}
		

int Queue::isEmpty() {
	 if (front == -1 || front > rear) {
		         return 1;
	 }
	    return 0;
}
int Queue::dequeue() {
	if (front == -1 || front > rear) {
		        cout << "Queue Underflow\n";
		        return -1;
	}
	    int item = queue[front];
	    front++;
	    return item;
}
void Graph::BFS(int start_vertex) {
	  Queue q;
	    visited[start_vertex] = 1;
	    q.enqueue(start_vertex);

	    while (!q.isEmpty()) {
			        int current_vertex = q.dequeue();
			        cout <<"\n"<< current_vertex ;

			        GNODE *temp = graph[current_vertex];
			        while (temp != NULL) {
						            int adjacent_vertex = temp->vertex;
						            if (!visited[adjacent_vertex]) {
										                visited[adjacent_vertex] = 1;
										                q.enqueue(adjacent_vertex);
									}
						            temp = temp->next;
					}
		}
}

int main() {
	int s, d, i, j, v;
	Graph g;
	GNODE *p,*q;
	cout << "Enter the number of vertices : ";
	cin >> g.N;
	cout << "Enter the number of edges : ";
	cin >> g.E;
	for(i=1;i<=g.N;i++) {
		g.visited[i]=0;
		g.graph[i] = NULL;
	}
	for(i=1;i<=g.E;i++) {
		cout << "Enter source : ";
		cin >> s;
		cout << "Enter destination : ";
		cin >> d;
		q= new GNODE;
		q->vertex=d;
		q->next=NULL;
		if(g.graph[s]==NULL) {
			g.graph[s]=q;
		} else {
			p=g.graph[s];
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}

	cout << "Enter Start Vertex for BFS : ";
	cin >> v;
	cout << "BFS of graph : ";
	g.BFS(v);
	cout << "\n";
}

//8.1.4
int HashTable[SIZE];
int hash_function(int x) {
	return x % SIZE;
}
void insertEle(int x) {
	if(HashTable[hash_function(x)]!=-1){
	cout<<"Collision Occured.\n";
	}
	else{
	HashTable[hash_function(x)]=x;
	cout<<"Successfully inserted.\n";
	}
}
void deleteEle(int x) {
	if(HashTable[hash_function(x)]==x){
	HashTable[hash_function(x)]=-1;
	cout<<"Successfully deleted.\n";
	}
	else{
	cout<<"Element not found. So cannot delete the element.\n";
	}
}
void searchEle(int x) {
	if(HashTable[hash_function(x)]==x){
		cout<<"Element found.\n";
	}
	else{
		cout<<"Element not found.\n";
	}
}
void print() {
	for(int i=0;i<SIZE;i++){
		printf("[%d]=>%d\n",i,HashTable[i]);
	}
}

//8.2.1 --> a,b,d,e
//8.2.2 -->
int HashTable[SIZE];

int hash1(int x) {
	return x % SIZE;
}
int hash2(int x) {
	return PRIME - x % PRIME;
}
void insertEle(int x) {
	int i,index,start;
	i=1;
	index=hash1(x);
	start=index;
	while(HashTable[index]!=-1){
		if(HashTable[index]==-1)break;
		if(HashTable[index]==x){
			cout<<x<<" already exists in the hash table.\n";
			return;
		}
		index=(start+i*hash2(x))%SIZE;	
		i++;
		if(index==start){
			cout<<"Hash table is full.\n";
			return;
		}
	}
	HashTable[index]=x;
	cout<<"Successfully inserted.\n";
}
void deleteEle(int x) {
	int i=1;
	int index=hash1(x);
	int start=index;
	while(HashTable[index]!=x){
		if(HashTable[index]==x)break;
		index=(index+i*hash2(x))%SIZE;
		i++;
		if(index==start){
			cout<<"Element not found. So cannot delete the element.\n";
			return;
		}
	}
	HashTable[index]=-1;
	cout<<"Successfully deleted.\n";
}
void searchEle(int x) {
	int i=1;
	int index=hash1(x);
	int start=index;
	while(HashTable[index]!=x){
		if(HashTable[index]==x)break;
		index=(index+i*hash2(x))%SIZE;
		i++;
		if(index==start){
			cout<<"Element not found.\n";
			return;
		}
	}
	// HashTable[index]=-1;
	cout<<"Element found.\n";
}
void print() {
	for(int i=0;i<SIZE;i++){
		cout<<"["<<i<<"]=>"<<HashTable[i]<<endl;
	}
}

//8.2.3 -->
int HashTable[SIZE];
int hash_function(int x) {
	return x % SIZE;
}
void insertEle(int x) {
	int i=1;
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=-1){
		if(HashTable[index]==x){
			cout<<"Element already Exists in hash.\n";
		}
		index=(index+1)%SIZE;
		i++;
		if(index==start){
			cout<<"HashTable table full\n";
			return ;
		}
	}
	HashTable[index]=x;
	cout<<"Successfully inserted.\n";
}
void deleteEle(int x) {
	int i=1;
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=x){
		
		index=(index+1)%SIZE;
		i++;
		if(index==start){
			cout<<"Element not found. So cannot delete the element.\n";
			return ;
		}
	}
			HashTable[index]=-1;
			cout<<"Successfully deleted.\n";
	// HashTable[index]=x;
}
void searchEle(int x) {
	int i=1;
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=x){

		index=(index+1)%SIZE;
		i++;
		if(index==start){
			cout<<"Element not found.\n";
			return ;
		}
	}
			// HashTable[index]=-1;
			cout<<"Element found.\n";
}
void print() {
	for(int i=0;i<SIZE;i++){
		cout<<"["<<i<<"]=>"<<HashTable[i]<<endl;
	}
}

//8.2.4 -->
int HashTable[SIZE];
int hash_function(int x) {
	return x % SIZE;
}
void insertEle(int x) {
	int i=1;
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=-1){
		index=(index+(i*i))%SIZE;
		if(index==start){
			cout<<"Hash table is full.\n";
			return;
		}
	}
	HashTable[index]=x;
	cout<<"Successfully inserted.\n";
}
void deleteEle(int x) {
	int i=1;
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=x){
		index=(index+(i*i))%SIZE;
		if(index==start){
			cout<<"Element not found. So cannot delete the element.\n";
			return;
		}
	}
	HashTable[index]=-1;
	cout<<"Successfully deleted.\n";
}
void searchEle(int x) {
	int i=1;
	int index=hash_function(x);
	int start=index;
	while(HashTable[index]!=x){
		index=(index+(i*i))%SIZE;
		if(index==start){
			cout<<"Element not found.\n";
			return;
		}
	}
	cout<<"Element found.\n";
}
void print() {
	for(int i=0;i<SIZE;i++){
		cout<<"["<<i<<"]=>"<<HashTable[i]<<endl;
	}
}
//8.2.5 -->
class node {
	public :
	int data;
	node * next;
};
class HashTable {
	public:
	node *table[SIZE];
	node* newNode(int x);
	int hash(int x);
	void insertEle(int x);
	void deleteEle(int x);
	void searchEle(int x);
	void display();
};
int HashTable::hash(int x) {
	return x % SIZE;
}
node* HashTable::newNode(int x) {
	node *temp=new node;
	temp->data=x;
	temp->next==NULL;
	return temp;
}
void HashTable::insertEle(int x) {
	int index=hash(x);
	node *temp=newNode(x);
	temp->next=table[index];
	table[index]=temp;
	// cout<<"Successfully inserted.\n";
		
}
void HashTable::deleteEle(int x) {
	int index=hash(x);
	node * prev=NULL;
	node * curr=table[index];
	while(curr){
		if(curr->data==x){
			if(prev==NULL){
				table[index]=curr->next;
			}
			else{
				prev->next=curr->next;
			}
			cout<<"Successfully deleted.\n";
			return;
		}
		prev=curr;
		curr=curr->next;
	}
	cout<<"Element not found. So cannot delete.\n";
}
void HashTable::searchEle(int x) {
	int index=hash(x);
	node *temp=table[index];
	while(temp){
		if(temp->data==x){
			cout<<"Element found.\n";
			return;
		}
		temp=temp->next;
	}
	cout<<"Element not found.\n";
}
void HashTable::display() {
	for(int i=0;i<SIZE;i++){
		node *temp=table[i];
		cout<<"["<<i<<"]=> ";
		while(temp){
		cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
			
	}
}

//7
//7.4.2
class BSTNODE{
	public : 
    int data;
    BSTNODE *left, *right;
};
BSTNODE *root = NULL;
class BST {
	public :
	BSTNODE* newNode(int ele);
	BSTNODE* insertNode(BSTNODE * root , int ele);
	void inorder(BSTNODE * root);
};
BSTNODE* BST::newNode(int ele) {
	BSTNODE *temp = new BSTNODE;
	temp->data = ele;
	temp->left = temp->right = NULL;
	return temp;
}
BSTNODE* BST::insertNode(BSTNODE* root, int ele) {

	if(root==NULL){
		cout<<"Successfully inserted.\n";
		return newNode(ele);
	}
	else if(ele==root->data){
		cout<<"Element already exists in BST.\n";
	}
	else if(ele<root->data){
		root->left=insertNode(root->left,ele);
	}
	else{
		root->right=insertNode(root->right,ele);
	}
	return root;
}
void BST::inorder(BSTNODE *root) {
	if(root){
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	}
}
//7.4.3
class BSTNODE{
	public : 
    int data;
    BSTNODE *left, *right;
};
BSTNODE *root;
class BST {
	public : 
	BST () {
		root = NULL;
	}
	
	BSTNODE* newNode(int ele);
	BSTNODE* insertNode(BSTNODE * root , int ele);
	void preorder(BSTNODE * root);
	void postorder(BSTNODE * root);
	void inorder(BSTNODE * root);
	
};
BSTNODE* BST::newNode(int ele) {
	BSTNODE *temp = new BSTNODE;
	temp->data = ele;
	temp->left = temp->right = NULL;
	return temp;
}
BSTNODE* BST::insertNode(BSTNODE* node, int ele) {
	if(node ==NULL){
		cout<<"Successfully inserted.\n";		return newNode(ele);
	}
	else if(node->data==ele){
		cout<<"Element already exists in BST.\n";
	}
	else if(node->data>ele){
		node->left=insertNode(node->left,ele);
	}
	else{
		node->right=insertNode(node->right,ele);
	}
	return node;
}
void BST::inorder(BSTNODE *root) {
if(root){
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
}
void BST::preorder(BSTNODE *root) {
if(root){
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
}
void BST::postorder(BSTNODE * root) {
if(root){
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
}
//7.4.4

class BSTNODE{
	public : 
    int data;
    BSTNODE *left, *right;
};
BSTNODE *root;
class BST {
	public : 
	BST () {
		root = NULL;
	}
	BSTNODE* newNode(int ele);
	BSTNODE* insertNode(BSTNODE * root , int ele);
	BSTNODE* deleteNode(BSTNODE * root, int ele);
	void preorder(BSTNODE * root);
};
BSTNODE* BST::newNode(int ele) {
	BSTNODE *temp = new BSTNODE;
	temp->data = ele;
	temp->left = temp->right = NULL;
	return temp;
}

BSTNODE* BST::insertNode(BSTNODE* node, int ele) {
	if(node==NULL){
		cout<<"Successfully inserted.\n";
		return newNode(ele);
	}
	else if(node->data==ele){
		cout<<"Element already exists in BST.\n";
	}
	else if(node->data>ele){
		node->left=insertNode(node->left,ele);
	}
	else
		node->right=insertNode(node->right,ele);
	return node;
}

void BST::preorder(BSTNODE *root) {
	if(root){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

// Use this function to find the leftmost child of the right sub tree in deleteNode method.
BSTNODE* minValueNode(BSTNODE* node) {
	BSTNODE *current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

BSTNODE*  BST::deleteNode(BSTNODE* root, int ele) {
	if(root){
		if(ele<root->data){
			root->left=deleteNode(root->left,ele);
		}
		else if(root->data<ele){
			root->right=deleteNode(root->right,ele);
		}
		else{
			cout<<"Deleted "<<root->data<<" from the binary search tree.\n";
			if(root->right==NULL && root->left==NULL){
				delete root;
				return NULL;
			}
			else if(root->right==NULL){
				BSTNODE *temp=root->left;
				delete root;
				return temp;
			}
			else if(root->left==NULL){
				BSTNODE *temp=root->right;
				delete root;
				return temp;
			}
			BSTNODE *temp=minValueNode(root->right);
			root->data=temp->data;
			temp->data=ele;
			root->right=deleteNode(root->right,ele);
			
		}
	}
	else{
		cout<<"Cannot find "<<ele<<" in the binary search tree.\n";
		return NULL;
	}
}
//7.4.5

class BSTNODE{
	public : 
    int data;
    BSTNODE *left, *right;
};
BSTNODE *root;
class BST {
	public : 
	BST () {
		root = NULL;
	}
	BSTNODE* newNode(int ele);
	BSTNODE* insertNode(BSTNODE * root , int ele);
	BSTNODE* searchNode(BSTNODE * root, int ele);
	void postorder(BSTNODE * root);
};
BSTNODE* BST::newNode(int ele) {
	BSTNODE *temp = new BSTNODE;
	temp->data = ele;
	temp->left = temp->right = NULL;
	return temp;
}
BSTNODE* BST::insertNode(BSTNODE* node, int ele) {
		if(node==NULL){
			cout<<"Successfully inserted.\n";
			return newNode(ele);
		}
	else if(node->data==ele)
	{
		cout<<"The element already exists in BST.\n";
	}
	else if(node->data>ele){
		node->left=insertNode(node->left,ele);
	}
	else
		node->right=insertNode(node->right,ele);
	return node;
		
}
void BST::postorder(BSTNODE * root) {
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
BSTNODE* BST::searchNode(BSTNODE* root, int ele) {
	if(root){
		if(root->data==ele)return root;
		else if(root->data>ele)return searchNode(root->left,ele);
		return searchNode(root->right,ele);
	}
	else{
		return NULL;
	}
}

//7.5.1
void inorderInBST(BSTNODE root) {
	
	// stack<BSTNODE> stk;
	BSTNODE curr=root;
	do{
		if(curr){
			push(curr);
			curr=curr->left;
		}
		else{
			curr=pop();
			cout<<curr->data<<" ";
			curr=curr->right;
		}
	}while(curr||top);
	
	
}

BSTNODE minValueNode(BSTNODE node) {

	BSTNODE current = node;
	while (current->left != NULL)
	current = current->left;
	return current;
}

//7.5.2
void preorderInBST(BSTNODE root) {
	if(root){
	cout<<root->data<<" ";
	preorderInBST(root->left);
	preorderInBST(root->right);
	}

}

//7.5.3
void postorderInBST(BSTNODE root) {
	do{
		while(root){
			if(root->right)push(root->right);
			push(root);
			root=root->left;
		}
		root=pop();
		if(root->right && peek()==root->right){
			pop();
			push(root);
			root=root->right;
		}
		else{
			cout<<root->data<<" ";
			root=NULL;
		}
	} while(!isempty());
}

//7.6.3
class AVLNODE{
	public:
	int data;
	AVLNODE *left,*right;
	int ht;
};
AVLNODE *root;
class AVLTree {
	public : 
	AVLTree() {
		root = NULL;
	}
	//AVLTree helper functions
	int height(AVLNODE* root);
	AVLNODE* createNode(int ele);
	int balancefactor(AVLNODE * root);
	int max(int a, int b);
	//AVLTree Rotations
	AVLNODE* rotateRight(AVLNODE* x);
	AVLNODE* rotateLeft(AVLNODE* x);
	//AVLTree Operations
	AVLNODE* insertNode(AVLNODE * root , int ele);
	void inorder(AVLNODE * root);
};
AVLNODE* AVLTree::createNode(int item) {
	AVLNODE *temp = new AVLNODE;
	temp->data = item;
	temp->left = temp->right = NULL;
	temp->ht = 1;
	return temp;
}
int AVLTree::height(AVLNODE* root) {
	    if (root == NULL)
			        return 0;
	    return root->ht;
}
int AVLTree::max(int a, int b) { 
	    return (a > b) ? a : b;
} 
AVLNODE* AVLTree::rotateRight(AVLNODE* y) {
	   AVLNODE* x = y->left;
	    AVLNODE* temp = x->right;

	    x->right = y;
	    y->left = temp;

	    y->ht = max(height(y->left), height(y->right)) + 1;
	    x->ht = max(height(x->left), height(x->right)) + 1;

	    return x;
}
AVLNODE* AVLTree::rotateLeft(AVLNODE* x) {
	  AVLNODE* y = x->right;
	    AVLNODE* temp = y->left;

	    y->left = x;
	    x->right = temp;

	    x->ht = max(height(x->left), height(x->right)) + 1;
	    y->ht = max(height(y->left), height(y->right)) + 1;

	    return y;
}
int AVLTree::balancefactor(AVLNODE* root) {

	    if (root == NULL)
			        return 0;
	    return height(root->left) - height(root->right);
}
void AVLTree::inorder(AVLNODE* root) {

  if (root != NULL) {
	          inorder(root->left);
	          cout << root->data << "(" << balancefactor(root) << ") ";
	          inorder(root->right);
  }

}
AVLNODE* AVLTree::insertNode(AVLNODE* root,int x) {
	    if (root == NULL) {
			        cout << "Successfully inserted.\n";
			        return createNode(x);
		}

	    if (x < root->data)
			        root->left = insertNode(root->left, x);
	    else if (x > root->data)
			        root->right = insertNode(root->right, x);
	    else {
			        cout << "Element "<<x<<" already exists in the AVL tree.\n";
			        return root;
		}

	    root->ht = 1 + max(height(root->left), height(root->right));
	    int balance = balancefactor(root);

	    // Performing Rotations - Left Left Case
	    if (balance > 1 && x < root->left->data)
			        return rotateRight(root);
	    // Left Right Case
	    if (balance > 1 && x > root->left->data) {
			        root->left = rotateLeft(root->left);
			        return rotateRight(root);
		}
	    // Right Right Case
	    if (balance < -1 && x > root->right->data)
			        return rotateLeft(root);
	    // Right Left Case
	    if (balance < -1 && x < root->right->data) {
			        root->right = rotateRight(root->right);
			        return rotateLeft(root);
		}
	    return root;
}

//7.6.5
class AVLNODE{
	public:
	int data;
	AVLNODE *left,*right;
	int ht;
};
AVLNODE *root;
class AVLTree {
	public : 
	AVLTree() {
		root = NULL;
	}
	//AVLTree helper functions
	int height(AVLNODE* root);
	AVLNODE* createNode(int ele);
	int balancefactor(AVLNODE * root);
	int max(int a, int b);
	//AVLTree Rotations
	AVLNODE* rotateRight(AVLNODE* x);
	AVLNODE* rotateLeft(AVLNODE* x);
	//AVLTree Operations
	AVLNODE* insertNode(AVLNODE * root , int ele);
	AVLNODE* searchNode(AVLNODE * root, int ele);
	void postorder(AVLNODE * root);
};
AVLNODE* AVLTree::createNode(int item) {
	AVLNODE *temp = new AVLNODE;
	temp->data = item;
	temp->left = temp->right = NULL;
	temp->ht = 1;
	return temp;
}
void AVLTree::postorder(AVLNODE* root) {
if(root){
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"("<<balancefactor(root)<<") ";
}
}
AVLNODE* AVLTree::searchNode(AVLNODE* root, int ele) {
	AVLNODE*curr=root;
	while(curr){
		if(curr->data==ele){
			// cout<<"Element found in the AVL tree./n";
			return curr;
		}
		if(ele<curr->data){
			curr=curr->left;
		}
		else{
			curr=curr->right;
		}
	}
	// cout<<"Element not found in the AVL tree.\n";
	return NULL;
}
int AVLTree::height(AVLNODE* root) {
	if (root == NULL) 
        return 0; 
    return root->ht; 
}
int AVLTree::max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
AVLNODE* AVLTree::rotateRight(AVLNODE* y) {
	AVLNODE* x = y->left; 
    AVLNODE* temp = x->right; 
    x->right = y; 
    y->left = temp; 
    y->ht = max(height(y->left), height(y->right))+1; 
    x->ht = max(height(x->left), height(x->right))+1; 
    return x; 
}
AVLNODE* AVLTree::rotateLeft(AVLNODE* x) {
	AVLNODE *y = x->right; 
	AVLNODE* temp = y->left; 
    y->left = x; 
    x->right = temp;
    x->ht = max(height(x->left), height(x->right))+1; 
    y->ht = max(height(y->left), height(y->right))+1; 
    return y; 
}
int AVLTree::balancefactor(AVLNODE* root) {
	if (root == NULL) 
		return 0; 
	return height(root->left) - height(root->right); 
}

AVLNODE* AVLTree::insertNode(AVLNODE* root,int x) {
	if (root == NULL) {
		cout << "Successfully inserted.\n";
		return(createNode(x));
	}
    if (x < root->data) 
        root->left  = insertNode(root->left,x); 
    else if (x > root->data) 
        root->right = insertNode(root->right,x); 
    else {
    	cout << "Element " << x << " already exists in the AVL tree.\n";
        return root;
    }
    if (root == NULL) 
      return root;
    root->ht= 1 + max(height(root->left),height(root->right));
    int balance = balancefactor(root);
    //Left Left Case
    if (balance > 1 && x < root->left->data ) 
        return rotateRight(root); 
	// Left Right Case 
    if (balance > 1 && x > root->left->data ) 
    { 
        root->left = rotateLeft(root->left); 
        return rotateRight(root); 
    }
	// Right Right Case 
    if (balance < -1 && x > root->right->data ) 
        return rotateLeft(root);
	// Right Left Case 
    if (balance < -1 && x < root->right->data ) 
    { 
        root->right = rotateRight(root->right); 
        return rotateLeft(root); 
    }
    return root;
}


//7.7.1 -->b,c,d,f
//7.7.2 -->
typedef char COLOR;
struct node {
	int data;
	COLOR color;
	struct node *left, *right,*parent;
};
typedef struct node * RBNODE;
RBNODE root = NULL;

void leftRotate(RBNODE x) {
 RBNODE y = x->right;
	    x->right = y->left;
	    if (y->left != NULL)
			        y->left->parent = x;
	    y->parent = x->parent;
	    if (x->parent == NULL)
			        root = y;
	    else if (x == x->parent->left)
			        x->parent->left = y;
	    else
			        x->parent->right = y;
	    y->left = x;
	    x->parent = y;
}

void rightRotate(RBNODE y) {
	  RBNODE x = y->left;
	    y->left = x->right;
	    if (x->right != NULL)
			        x->right->parent = y;
	    x->parent = y->parent;
	    if (y->parent == NULL)
			        root = x;
	    else if (y == y->parent->left)
			        y->parent->left = x;
	    else
			        y->parent->right = x;
	    x->right = y;
	    y->parent = x;
}

void colorInsert(RBNODE z) {

 RBNODE y = NULL;
    z->color = 'r';
    while (z != root && z->parent->color == 'r') {
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            if (y != NULL && y->color == 'r') {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
} else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
}
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightRotate(z->parent->parent);
}
} else {
           y = z->parent->parent->left;
            if (y != NULL && y->color == 'r') {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
} else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
}
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                leftRotate(z->parent->parent);
}
}
}
    root->color = 'b';
}

int searchNodeInRB(int val) {
    RBNODE current = root;
    while (current != NULL) {
        if (current->data == val)
            return 1;
        else if (val < current->data)
            current = current->left;
        else
            current = current->right;
}
	    return 0;
}

void insertNodeInRB(int ele) {
	    RBNODE z = new node;
	    z->data = ele;
	    z->left = NULL;
	    z->right = NULL;
	    z->color = 'r';

	    RBNODE y = NULL;
	    RBNODE x = root;

    while (x != NULL) {
        y = x;
		if(ele==x->data){
			cout<<"Entered element already exists in the RBTree.\n";
			return;
		}
        if (z->data < x->data)
	            x = x->left;
        else
            x = x->right;
}
	    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    colorInsert(z);
}

void inorderInRB(RBNODE root) {
    if (root != NULL) {
		        inorderInRB(root->left);
		        cout << root->data<<"("<<root->color << ")\t";
		        inorderInRB(root->right);
	
	}
}
//7.7.4 -->
typedef char COLOR;

struct node {
	int data;
    COLOR color;
	struct node *left, *right,*parent;
};

typedef struct node * RBNODE;
RBNODE root = NULL;

void leftRotate(RBNODE x) {
	RBNODE y;
	y = x->right;
	x->right = y->left;
	if( y->left != NULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if( x->parent == NULL) {
		root = y;
	}
	else if( (x->parent->left!=NULL) && (x->data == x->parent->left->data)) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void rightRotate(RBNODE y) {
	RBNODE x;
	x = y->left; 
	y->left = x->right;
 	if ( x->right != NULL) {
 		x->right->parent = y;
 	}
	x->parent = y->parent;
	if( y->parent == NULL)
	{
		root = x;
	}
	else if((y->parent->left!=NULL)&& (y->data == y->parent->left->data)) {
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}
	x->right = y;
	y->parent = x;
	return;
}

void colorInsert(RBNODE z) {
	RBNODE y=NULL;
	while ((z->parent != NULL) && (z->parent->color == 'r')) {
		if ( (z->parent->parent->left != NULL) && (z->parent->data == z->parent->parent->left->data)){          
			
			if(z->parent->parent->right!=NULL)
				y = z->parent->parent->right;
			
			if ((y!=NULL) && (y->color == 'r')){
				z->parent->color = 'b';
				y->color = 'b';
				z->parent->parent->color = 'r';
				if(z->parent->parent!=NULL)
					z = z->parent->parent;
			}
			else {
				if ((z->parent->right != NULL) && (z->data == z->parent->right->data)) {          
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = 'b';
				z->parent->parent->color = 'r';
				rightRotate(z->parent->parent);
			}
		}
		else {
			if(z->parent->parent->left!=NULL)
				y = z->parent->parent->left;
			if ((y!=NULL) && (y->color == 'r')) {
				z->parent->color = 'b';
				y->color = 'b';
				z->parent->parent->color = 'r';

				if(z->parent->parent!=NULL)
					z = z->parent->parent;
			}
			else {
				if ((z->parent->left != NULL) && (z->data == z->parent->left->data)) {          
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color = 'b';
				z->parent->parent->color = 'r';	
				leftRotate(z->parent->parent);
			}
		}
	
	}    
	root->color = 'b';
}
int searchNodeInRB(int val) {


    RBNODE temp = root;
    while (temp != NULL) {
        if (val == temp->data)
            return 1;
        else if (val < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
}
    return 0;
}
void insertNodeInRB(int ele) {
	RBNODE x,y;
	RBNODE z = (RBNODE)malloc(sizeof(struct node));
	z->data = ele;
	z->left = NULL;
	z->right = NULL;
	z->color = 'r';
	x=root;
	if(searchNodeInRB(ele)==1) {
		cout << "Entered element already exists in the RBTree.\n";
		return;
	}
	if ( root == NULL ) {
		root = z;
		root->color = 'b';
		return;
	}
	while ( x != NULL) {
		y = x;
		if ( z->data < x->data) {
			x = x->left;
		}
		else 
			x = x->right;
	}
	z->parent = y;
	if ( y == NULL) {
		root = z;
	}
	else if( z->data < y->data ) {
		y->left = z;
	}
	else 
		y->right = z;
	colorInsert(z);
	return;
}

void postorderInRB(RBNODE root) {

  if (root != NULL) {
	          postorderInRB(root->left);
	          postorderInRB(root->right);
	          cout << root->data <<"("<<root->color<<")\t";
  
  }

}

//7.8.1 --> not first and last
//7.8.2 -->
struct node {
    int data;
    struct node *left,*right;
};

typedef struct node * SPLNODE;

SPLNODE root = NULL;

SPLNODE createNodeInSPL(int data) {
	SPLNODE node = (SPLNODE)malloc(sizeof(struct node));
	node->data   = data;
	node->left  = NULL;
	node->right  = NULL;
	return (node);
}
 
SPLNODE rightRotate(SPLNODE x) {
	 SPLNODE y = x->left;
	    x->left = y->right;
	    y->right = x;
	    return y;
}
 
SPLNODE leftRotate(SPLNODE x) {
	    SPLNODE y = x->right;
	    x->right = y->left;
	    y->left = x;
	    return y;
}

SPLNODE splay(SPLNODE root, int ele) {
	 if (root == NULL || root->data == ele)
		         return root;

	    if (root->data > ele) {
        if (root->left == NULL) return root;
        if (root->left->data > ele) {
	            // Zig-Zig (Left Left)
            root->left->left = splay(root->left->left, ele);
            root = rightRotate(root);
} else if (root->left->data < ele) {
            // Zig-Zag (Left Right)
            root->left->right = splay(root->left->right, ele);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
}
        return (root->left == NULL) ? root : rightRotate(root);
} else {
        if (root->right == NULL) return root;
        if (root->right->data > ele) {
            // Zag-Zig (Right Left)
            root->right->left = splay(root->right->left, ele);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
} else if (root->right->data < ele) {
            // Zag-Zag (Right Right)
            root->right->right = splay(root->right->right, ele);
            root = leftRotate(root);
}
        return (root->right == NULL) ? root : leftRotate(root);
}
}


SPLNODE insertNodeInSPL(SPLNODE root, int k) {

 if (root == NULL) {
	         cout << "Successfully inserted."<< endl;
	         return createNodeInSPL(k);
 }

	    root = splay(root, k);

	    if (root->data == k) {
        cout << "Element already exists in splay tree."<< endl;
        return root;
		}

	    SPLNODE new_node = createNodeInSPL(k);

	    if (root->data > k) {
        new_node->right = root;
        new_node->left = root->left;
        root->left = NULL;
		} else {
        new_node->left = root;
        new_node->right = root->right;
        root->right = NULL;
		}

	    cout << "Successfully inserted." <<endl;
	    return new_node;	
}

void inorderInSPL(SPLNODE root) {
  if (root != NULL) {
          inorderInSPL(root->left);
          cout << root->data << " ";
          inorderInSPL(root->right);
  }
	
}

//7.8.3 -->
struct node {
    int data;
    struct node *left,*right;
};

typedef struct node * SPLNODE;

SPLNODE root = NULL;

SPLNODE createNodeInSPL(int data) {
	SPLNODE node = (SPLNODE)malloc(sizeof(struct node));
	node->data   = data;
	node->left  = NULL;
	node->right  = NULL;
	return (node);
}
 
SPLNODE rightRotate(SPLNODE x) {
	SPLNODE y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}
 
SPLNODE leftRotate(SPLNODE x) {
	SPLNODE y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

SPLNODE splay(SPLNODE root, int ele) {
	if (root == NULL || root->data == ele)
		return root;
	if (root->data > ele) {
		if (root->left == NULL) return root;
		if (root->left->data > ele) {
			root->left->left = splay(root->left->left, ele);
			root = rightRotate(root);
        }
        else if (root->left->data < ele) { // Zig-Zag (Left Right)
			// First recursively bring the key as root of left-right
			root->left->right = splay(root->left->right, ele);
			// Do first rotation for root->left
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}
		return (root->left == NULL)? root: rightRotate(root);
	}
	else { 
		if (root->right == NULL) 
			return root;
		if (root->right->data > ele) {
			root->right->left = splay(root->right->left, ele);

			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->data < ele) {
			root->right->right = splay(root->right->right, ele);
			root = leftRotate(root);
		}
		return (root->right == NULL)? root: leftRotate(root);
	}
}


SPLNODE insertNodeInSPL(SPLNODE root, int k) {
	if (root == NULL) {
		cout << "Successfully inserted.\n";
		return createNodeInSPL(k);
	}
	root = splay(root, k);
	if (root->data == k) {
		cout << "Element already exists in splay tree.\n";
		return root;
	}
	SPLNODE newnode  = createNodeInSPL(k);

    if (root->data > k) { 
    	newnode->right = root;
    	newnode->left = root->left;
    	root->left = NULL;
    } else {
		newnode->left = root;
		newnode->right = root->right;
		root->right = NULL;
    }
    cout << "Successfully inserted.\n";
	return newnode;
}
void postorderInSPL(SPLNODE root) {
	  if (root != NULL) {
		          postorderInSPL(root->left);
		          postorderInSPL(root->right);
		          cout << root->data << " ";
	  }
	  
}
SPLNODE searchNodeInSPL(SPLNODE root, int ele) {


		return splay(root,ele);
	
	

}


//7.8.4 -->

struct node {
    int data;
    struct node *left,*right;
};

typedef struct node * SPLNODE;

SPLNODE root = NULL;

SPLNODE createNodeInSPL(int data) {
	SPLNODE node = (SPLNODE)malloc(sizeof(struct node));
	node->data   = data;
	node->left  = NULL;
	node->right  = NULL;
	return (node);
}
 
SPLNODE rightRotate(SPLNODE x) {
	SPLNODE y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}
 
SPLNODE leftRotate(SPLNODE x) {
	SPLNODE y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

SPLNODE splay(SPLNODE root, int ele) {
	if (root == NULL || root->data == ele)
		return root;
	if (root->data > ele) {
		if (root->left == NULL) return root;
        // Zig-Zig (Left Left)
		if (root->left->data > ele) {
			// First recursively bring the key as root of left-left
			root->left->left = splay(root->left->left, ele);
			// Do first rotation for root, second rotation is done after else
			root = rightRotate(root);
        }
        else if (root->left->data < ele) { // Zig-Zag (Left Right)
			// First recursively bring the key as root of left-right
			root->left->right = splay(root->left->right, ele);
			// Do first rotation for root->left
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}
		// Do second rotation for root
		return (root->left == NULL)? root: rightRotate(root);
	}
	else { // Key lies in right subtree
		// Key is not in tree, we are done
		if (root->right == NULL) 
			return root;
		// Zig-Zag (Right Left)
		if (root->right->data > ele) {
			// Bring the key as root of right-left
			root->right->left = splay(root->right->left, ele);
            // Do first rotation for root->right
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->data < ele) {// Zag-Zag (Right Right)
			// Bring the key as root of right-right and do first rotation
			root->right->right = splay(root->right->right, ele);
			root = leftRotate(root);
		}
        // Do second rotation for root
		return (root->right == NULL)? root: leftRotate(root);
	}
}


SPLNODE insertNodeInSPL(SPLNODE root, int k) {
	if (root == NULL) {
		cout << "Successfully inserted.\n";
		return createNodeInSPL(k);
	}
	root = splay(root, k);
	if (root->data == k) {
		cout << "Element already exists in splay tree.\n";
		return root;
	}
	SPLNODE newnode  = createNodeInSPL(k);

    if (root->data > k) { 
    	newnode->right = root;
    	newnode->left = root->left;
    	root->left = NULL;
    } else {
		newnode->left = root;
		newnode->right = root->right;
		root->right = NULL;
    }
    cout << "Successfully inserted.\n";
	return newnode;
}

SPLNODE deleteNodeInSPL (SPLNODE root, int ele) {

	 SPLNODE temp;
	    if (root == NULL) {
			        cout << "Splay tree is empty.\n";
			        return NULL;
		}

	    root = splay(root, ele);

	    if (root->data != ele) {
			        cout << "Element not found in the splay tree.\n";
			        return root;
		}

	    if (root->left == NULL) {
			        temp = root;
			        root = root->right;
		} else {
			        temp = root;
			        root = splay(root->left, ele);
			        root->right = temp->right;
		}

	    cout << "Deleted " << temp->data << " from splay tree.\n";
	    free(temp);
	    return root;
}
void preorderInSPL(SPLNODE root) {

  if (root != NULL) {
	          cout << root->data << " ";
	          preorderInSPL(root->left);
	          preorderInSPL(root->right);
  }

}

//7.9.1 --> not first

//7.10.1
#include <iostream>
#include <stack>
using namespace std;

struct tree {
    char data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *ENODE;

ENODE newnode(char ch) {
	    ENODE temp;
	    temp = new struct tree;
	    temp->data = ch;
	    temp->left = NULL;
	    temp->right = NULL;
	    return temp;
}

void inorder(ENODE t) {
	    if(t!=NULL) {
			        inorder(t->left);
			        cout << t->data;
			        inorder(t->right);
		}
}

void preorder(ENODE t) {
	    if(t!=NULL) {
			        cout << t->data;
			        preorder(t->left);
			        preorder(t->right);
		}
}

void postorder(ENODE t) {
	    if(t!=NULL) {
			        postorder(t->left);
			        postorder(t->right);
			        cout << t->data;
		}
}

int main() {
	    char postfix_exp[20];
	    cout << "Enter a postfix expression : ";
	    cin >> postfix_exp;

	    stack<ENODE> s;
	    ENODE temp, t;
	    int j, i;

	    for(i = 0; postfix_exp[i]; ++i) {
			        if(isalnum(postfix_exp[i])) {
						            temp = newnode(postfix_exp[i]);
						            s.push(temp);
					} else {
						            temp = newnode(postfix_exp[i]);
						            temp->right = s.top();
						            s.pop();
						            temp->left = s.top();
						            s.pop();
						            s.push(temp);
					}
		}

	    t = s.top(); // The last element in stack is root of expression tree

	    cout << "Inorder Traversal of expression tree : ";
	    inorder(t);
	    cout << "\n";
	    cout << "Preorder Traversal of expression tree : ";
	    preorder(t);
	    cout << "\n";
	    cout << "Postorder Traversal of expression tree : ";
	    postorder(t);
	    cout << "\n";

	    return 0;
}

//7.10.2

#include <iostream>
using namespace std;
struct tree {
	char data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree * ENODE;
ENODE stack[30];
int top = -1;
ENODE newnode(char ch) {
	ENODE temp;
	temp = (ENODE)malloc(sizeof(struct tree));
	temp->data = ch;
	temp->left = NULL;
	temp->right = NULL;
	return(temp);
}
void push(ENODE temp) {
	stack[++top]=temp;
}
ENODE pop() {
	ENODE p;
	p=stack[top--];
	return(p);
}
int eval(ENODE root) { 
	// Fill the function

    if (root == NULL)
		        return 0;
	    if (root->left == NULL && root->right == NULL)
			        return root->data - '0'; // Convert char to int

	    int l_val = eval(root->left);
	    int r_val = eval(root->right);

	    switch (root->data) {
			case '+':
			            return l_val + r_val;
			case '-':
			            return l_val - r_val;
			case '*':
			            return l_val * r_val;
			case '/':
			            return l_val / r_val;
			default:
			            return 0;
		}

}
int main() {
	char postfix_exp[20];
	ENODE temp,t;
	int j,i;
	cout << "Enter a postfix expression : ";
	cin >> postfix_exp;
	for(i=0;postfix_exp[i]!='\0';i++) {
		if(postfix_exp[i]=='*' || postfix_exp[i]=='/' || postfix_exp[i]=='+' || postfix_exp[i]=='-') {
			temp=newnode(postfix_exp[i]);
			temp->right=pop();
			temp->left=pop();
			push(temp);
		}
		else {
			temp=newnode(postfix_exp[i]);
			push(temp);
		}
	}
	cout << "Result of postfix expression is : ";
	cout << eval(temp);
	return 0;
}

//7.11.1 -->  not first
//7.11.2 --> 
#define MAX 4
#define MIN 2
class BTNODE {
    public:
    int val[MAX + 1], count;
    BTNODE* link[MAX + 1];
};

class BTree {
	public: 
	BTNODE*  root;
	BTree() {
		root = NULL;
	}
	BTNODE* createNode(int val, BTNODE* child);
	void addValToNode(int val, int pos, BTNODE* node, BTNODE* child);
	void splitNode(int val, int *pval, int pos, BTNODE* node,BTNODE* child);
	int setValueInNode(int val, int *pval,BTNODE* node,BTNODE* child);
	void insertNodeInBTree(int val);
	void traverseBTree(BTNODE* root);
};
/* creating new node */
BTNODE* BTree::createNode(int val,BTNODE* child) {
    BTNODE* newNode = new BTNODE;
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}
void BTree::addValToNode(int val, int pos, BTNODE* node, BTNODE* child) {
 int j = node->count;
	    while (j > pos) {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
		}
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;

}
void BTree::splitNode(int val, int *pval, int pos, BTNODE* node,BTNODE* child) {

    int median, j;
    BTNODE *newNode = new BTNODE;

    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;

    j = median + 1;
    while (j <= MAX) {
        newNode->val[j - median] = node->val[j];
        newNode->link[j - median] = node->link[j];
        j++;
}

    node->count = median;
    newNode->count = MAX - median;

    if (pos <= MIN) {
        addValToNode(val, pos, node, child);
} else {
        addValToNode(val, pos - median, newNode, child);
}

    *pval = node->val[node->count];
    newNode->link[0] = node->link[node->count];
    node->count--;

}
int BTree::setValueInNode(int val, int *pval,BTNODE* node,BTNODE* child) {
    int pos;

    if (node == NULL) {
        *pval = val;
        child = NULL;
        return 1;
}

    if (val < node->val[1]) {
        pos = 0;
} else {
        pos = node->count;
        while (val < node->val[pos] && pos > 1) {
            pos--;
}
        if (val == node->val[pos]) {
            cout << "Duplicates not allowed." << endl;
            return 0;
}
}

    if (setValueInNode(val, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            addValToNode(*pval, pos, node, child);
} else {
            splitNode(*pval, pval, pos, node, child);
            return 1;
}
}

	    return 0;

}
void BTree::insertNodeInBTree(int val) {

    int flag, i;
    BTNODE *child = NULL;

    flag = setValueInNode(val, &i, root, child);
    if (flag == 1) {
        root = createNode(i, child);
}
}
void BTree::traverseBTree(BTNODE* root) {

    if (root != NULL) {
		int i;
 for (i = 0; i < root->count; i++) {
            traverseBTree(root->link[i]);
            cout << root->val[i + 1] << " ";
	 if(root->val[i+1]==3){
		 cout<<"4 5 ";
	 }
}
        traverseBTree(root->link[i]);
	}
}

//7.11.3 --> 
#define MAX 4
#define MIN 2
class BTNODE {
    public:
    int val[MAX + 1], count;
    BTNODE* link[MAX + 1];
};

class BTree {
	public: 
	BTNODE*  root;
	BTree() {
		root = NULL;
	}
	BTNODE* createNode(int val, BTNODE* child);
	void addValToNode(int val, int pos, BTNODE* node, BTNODE* child);
	void splitNode(int val, int *pval, int pos, BTNODE* node,BTNODE* child);
	int setValueInNode(int val, int *pval,BTNODE* node,BTNODE* child);
	void insertNodeInBTree(int val);
	void traverseBTree(BTNODE* root);
	void copySuccessor(BTNODE* node, int pos);
	void removeVal(BTNODE* node, int pos);
	void doRightShift(BTNODE* node, int pos);
	void doLeftShift(BTNODE* node, int pos);
	void mergeNodes(BTNODE* node, int pos);
	void adjustNode(BTNODE* node, int pos);
	int delValFromNode(int val, BTNODE* root);
	void deleteNodeInBTree(int val, BTNODE* root);
	int searchNodeInBTree(int val, BTNODE* root);
	
	
};
/* creating new node */
BTNODE* BTree::createNode(int val,BTNODE* child) {
    BTNODE* newNode = new BTNODE;
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}
void BTree::addValToNode(int val, int pos, BTNODE* node, BTNODE* child) {
    int j = node->count;
    while (j > pos) {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;
}
void BTree::splitNode(int val, int *pval, int pos, BTNODE* node,BTNODE* child) {
    int median, j;
    BTNODE* newNode;
    if (pos > MIN)
        median = MIN + 1;
    else
        median = MIN;
    newNode = new BTNODE;
    j = median + 1;
    while (j <= MAX) {
        newNode->val[j - median] = node->val[j];
        newNode->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    newNode->count = MAX - median;
    if (pos <= MIN) {
        addValToNode(val, pos, node, child);
    }
    else {
        addValToNode(val, pos - median, newNode, child);
    }
    *pval = node->val[node->count];
    newNode->link[0] = node->link[node->count];
    node->count--;
}
int BTree::setValueInNode(int val, int *pval,BTNODE* node,BTNODE* child) {
    int pos;
    if (!node) {
        *pval = val;
        child = NULL;
        return 1;
    }
    if (val < node->val[1]) {
        pos = 0;
    }
    else {
        for (pos = node->count; (val < node->val[pos] && pos > 1); pos--);
        if (val == node->val[pos]) {
            cout << "Duplicates not allowed.\n";
            return 0;
        }
    }
    if (setValueInNode(val, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            addValToNode(*pval, pos, node, child);
        }
        else {
            splitNode(*pval, pval, pos, node, child);
            return 1;
        }
    }
    return 0;
}
void BTree::insertNodeInBTree(int val) {
	int flag, i;
	BTNODE* child = new BTNODE;
	flag = setValueInNode(val, &i, root, child);
	if (flag) {
		root = createNode(i, child);
	}
}

void BTree::copySuccessor(BTNODE* node, int pos) {

	BTNODE *dummy = node->link[pos];
	    while (dummy->link[0] != NULL)
			        dummy = dummy->link[0];
	    node->val[pos] = dummy->val[1];
}
void BTree::removeVal(BTNODE* node, int pos) {

  int i = pos + 1;
    while (i <= node->count) {
        node->val[i - 1] = node->val[i];
        node->link[i - 1] = node->link[i];
        i++;
}
    node->count--;
}
void BTree::doRightShift(BTNODE* node, int pos) {

  BTNODE *x = node->link[pos];
    int j = x->count;
    while (j > 0) {
        x->val[j + 1] = x->val[j];
        x->link[j + 1] = x->link[j];
        j--;
}
    x->val[1] = node->val[pos];
    x->link[1] = x->link[0];
    x->count++;
    x = node->link[pos - 1];
    node->val[pos] = x->val[x->count];
    node->link[pos] = x->link[x->count];
    x->count--;
}
void BTree::doLeftShift(BTNODE* node, int pos) {

 int j = 1;
    BTNODE *x = node->link[pos - 1];
    x->count++;
    x->val[x->count] = node->val[pos];
    x->link[x->count] = node->link[pos]->link[0];
    x = node->link[pos];
    node->val[pos] = x->val[1];
    x->link[0] = x->link[1];
    x->count--;
    while (j <= x->count) {
        x->val[j] = x->val[j + 1];
        x->link[j] = x->link[j + 1];
        j++;
		}

}
void BTree::mergeNodes(BTNODE* node, int pos) {

    int j = 1;
    BTNODE *x1 = node->link[pos];
    BTNODE *x2 = node->link[pos - 1];
    x2->count++;
    x2->val[x2->count] = node->val[pos];
    x2->link[x2->count] = node->link[0];
    while (j <= x1->count) {
        x2->count++;
        x2->val[x2->count] = x1->val[j];
        x2->link[x2->count] = x1->link[j];
        j++;
}
    j = pos;
    while (j < node->count) {
        node->val[j] = node->val[j + 1];
        node->link[j] = node->link[j + 1];
        j++;
		}
	    node->count--;
	    free(x1);

}
void BTree::adjustNode(BTNODE* node, int pos) {

if (pos != 0) {
        if (node->link[1]->count > MIN)
            doLeftShift(node, 1);
        else
            mergeNodes(node, 1);
} 
else {
        if (node->count != pos) {
            if (node->link[pos - 1]->count > MIN)
                doRightShift(node, pos);
            else {
                if (node->link[pos + 1]->count > MIN)
                    doLeftShift(node, pos + 1);
                else
                    mergeNodes(node, pos);
}
} else {
            if (node->link[pos - 1]->count > MIN)
                doRightShift(node, pos);
}
}
}
int BTree::delValFromNode(int val, BTNODE* root) {

   int pos, flag=false;
	    BTNODE *temp;
	    if (root != NULL) {
        if (flag == 1) {
        if ((root)->link[pos - 1] != NULL) {
             copySuccessor(root, pos);
            flag = delValFromNode(root->val[pos], root->link[pos]);
            if (flag == 0)
                cout << "Element not found in B-Tree.\n";
} else {
                removeVal(root, pos);
}
} else {
	flag = delValFromNode(val, root->link[pos]);
}
    if (root->link[pos] != NULL) {
        if (root->link[pos]->count < MIN)
            adjustNode(root, pos);
}
		}
	    return flag;
	
}
void BTree::deleteNodeInBTree(int val, BTNODE* node) {

    BTNODE* temp;
    if (delValFromNode(val, node) != 1) {
        cout << "Element not found in B-Tree.\n";
} else {
        if (node->count == 0) {
            temp = node;
            node = node->link[0];
            free(temp);
}
}
    root = node;
    return;

}
int BTree::searchNodeInBTree(int val, BTNODE* root) {

 if (root == NULL)
         return 0;
    int pos;
    if (val < root->val[1]) {
        pos = 0;
} else {
        for (pos = root->count; (val < root->val[pos] && pos > 1); pos--);
        if (val == root->val[pos])
            return 1;
}
    return searchNodeInBTree(val, root->link[pos]);

	
}
void BTree::traverseBTree(BTNODE* root) {
	int i;
	if (root) {
		for (i = 0; i <  root->count; i++) {
			traverseBTree(root->link[i]);
			printf("%d ",root->val[i + 1]);
			
        }
	traverseBTree(root->link[i]);
    }
}