//7.7.3

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
	int diff;
	while (temp != NULL) {
		if (val > temp->data) {
			temp = temp->right;
		}
		else if (val < temp->data) {
			temp = temp->left;
		}
		else
		{
			return 1;
		}
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
void preorderInRB(RBNODE root) {
	if(root!=NULL){
		cout<<root->data<<"("<<root->color<<")\t";
		preorderInRB(root->left);
		preorderInRB(root->right);
	}
}

RBNODE min(RBNODE x) {
	while(x->left!=NULL) x=x->left;
	return x;
}

RBNODE successor(RBNODE x) {
	RBNODE y;
	if(x->right!=NULL) return min(x->right);
	y=x->parent;
	while(y!=NULL && x==y->right){
		x=y;
		y=y->parent;
	}
	return y;
}

void colorDelete(RBNODE x) {
	while(x!=root && x->color=='b'){
		RBNODE w;
		if(x==x->parent->left){
			w=w->parent->right;
			if(w!=NULL && w->color=='r'){
				w->color='b';
				leftRotate(x->parent);
				w=x->parent->right;
			}
			if(w!=NULL && w->left!=NULL && w->right!=NULL && w->left->color=='b'&& w->right->color=='b'){
				w->color='r';
				x=x->parent;
			}
			else{
				if(w!=NULL && w->right!=NULL && w->right->color=='b'){
					w->color='r';
					rightRotate(w);
					w=x->parent->right;
				}
				w->color=x->parent->color;
				x->parent->color='b';
				if(w->right!=NULL) w->right->color='b';
				leftRotate(x->parent);
				x=root;
			}
			
		}
		else{
			w=x->parent->left;
			if(w!=NULL&&w->color=='r'){
				w->color='b';
				x->parent->color='r';
				rightRotate(x->parent);
				w=x->parent->left;
			}
			if(w!=NULL && w->left!=NULL && w->right!=NULL && w->left->color=='b'&& w->right->color=='b'){
				w->color='r';
				x=x->parent;
			}
			else{
				if(w!=NULL && w->left!=NULL && w->left->color=='b'){
					if(w->right!=NULL) w->right->color='b';
					w->color = 'r';
					leftRotate(w);
					w=x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color='b';
					if(w->left!=NULL) w->left->color='b';
				rightRotate(x->parent);
				x=root;
			}
		}
	}
	x->color='b';
}
void transplant(RBNODE u,RBNODE v){
	if(u->parent==NULL) root=v;
	else if(u==u->parent->left) u->parent->left=v;
	else u->parent->right = v;
	if(v!=NULL) v->parent=u->parent;
}
void deleteNodeInRB(int ele) {
	RBNODE z=root;
	RBNODE x=NULL,y=NULL;
	while(z!=NULL){
		if(ele==z->data) break;
		if(ele<z->data) z=z->left;
		else z=z->right;
	}
	if(z==NULL){
		cout<<"Element "<<ele<<" not found in RBTree."<<endl;
		return;
	}
	y=z;
	COLOR y_original_color=y->color;
	if(z->left==NULL){
		x=z->right;
		transplant(z,z->right);
	}
	else if(z->right==NULL){
		x=z->left;
		transplant(z,z->left);
	}
	else{
		y=min(z->right);
		y_original_color = y->color;
		x=y->right;
		if(y->parent==z){
			if(x!=NULL) x->parent=y;}
			else{
				transplant(y,y->right);
				y->right=z->right;
				if(y->right!=NULL) y->left->parent=y;
			}
			transplant(z,y);
			y->left = z->left;
			if(y->left!=NULL) y->left->parent=y;
			y->color=z->color;
		
	}
	if(y_original_color=='b'){
		if(x!=NULL){
			colorDelete(x);
		}
	}
	cout<<"Element "<<ele<<" deleted from RBTree."<<endl;
	
}

//12.3.1

#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 20
int V,E;
int graph[MAX][MAX];
#define INFINITY 99999
void dijkstra(int G[MAX][MAX],int n,int startnode) {
	// Complete the code here
	int cost[MAX][MAX];
	int distance[MAX];
	int pred[MAX];
	int visited[MAX];
	int count,mindistance,i,j,nextNode;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(G[i][j]==0) cost[i][j]=INFINITY;
			else cost[i][j]=G[i][j];
		}
	}
	for(i=1;i<=n;i++){
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1){
		mindistance = INFINITY;
		for(i=1;i<=n;i++){
			if(distance[i]<mindistance&&visited[i]==0){
				mindistance=distance[i];
				nextNode=i;
			}
		}
			visited[nextNode]=1;
			for(i=1;i<=n;i++){
				if(visited[i]==0){
					if(mindistance+cost[nextNode][i]<distance[i]){
						distance[i]=mindistance+cost[nextNode][i];
						pred[i]=nextNode;
					}
				}
			}
			count++;
		}
		cout<<"Node\tDistance\tPath\n";
		for(i=1;i<=n;i++){
			if(i!=startnode){
				if(distance[i]==INFINITY) cout<<"   "<<i<<"     INF\t"<<"NO PATH\n";
				else{
					cout<<"   "<<i<<"       "<<distance[i]<<"\t"<<i;
					j=i;
					do{
						j=pred[j];
						cout<<"<-"<<j;
					}while(j!=startnode);
					cout<<endl;
				}
			}
		
	}
	
}
int main() { 
	int s,d,w,i,j;
	cout << "Enter the number of vertices : ";
	cin >> V;
	cout << "Enter the number of edges : ";
	cin >> E;
	for(i = 1 ; i <= V; i++) {
		for(j=1; j <= V; j++ ) {
			graph[i][i] = 0;
		}
	}
	for(i=1;i<=E;i++) {
		cout << "Enter source : ";
		cin >> s;
		cout << "Enter destination : ";
		cin >> d;
		cout << "Enter weight : ";
		cin >> w;
		if(s > V || d > V || s<=0 || d<=0) {
			cout << "Invalid index. Try again.\n";
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	cout << "Enter the source :";
	cin >> s;
	dijkstra(graph, V,s); 
	return 0; 
}

//13.1.1
  // write your code here 
	startNode--;
	int H[MAX][MAX];
	for(int i=1;i<=MAX;i++){
		for(int j=1;j<=MAX;j++){
			H[i-1][j-1]=G[i][j];
			if(H[i-1][j-1]<0) H[i-1][j-1]=abs(G[i][j]);
		}
	}
	int distance[n];
	for(int i=0;i<n;i++) distance[i]=INFINITY;
	int predecessor[n];
	for(int i=0;i<n;i++) predecessor[i]=-1;
	distance[startNode]=0;
	for(int i=0;i<n-1;i++){
		for(int u=0;u<n;u++){
			for(int v=0;v<n;v++){
				if(H[u][v]!=0 && distance[u]!=INFINITY && distance[u]+H[u][v]<distance[v]){
					distance[v]=distance[u]+H[u][v];
					predecessor[v]=u;
				}
			}
		}
	}
	for(int u=0;u<n;u++){
		for(int v=0;v<n;v++){
			if(H[u][v]!=0&&distance[u]!=INFINITY && distance[u]+H[u][v]<distance[v]){
				isNegativeWeights=1;
				break;
			}
		}
	}
	cout<<"Node\tDistance\tPath"<<endl;
	for(int i=0;i<n;i++){
		if(i==startNode) continue;
		cout<<i+1<<"\t";
		if(distance[i]==INFINITY) cout<<"INFINITY";
		else cout<<distance[i];
		cout<<"\t";
		int path[MAX];
		int current=i;
		int l=1;
		while(current!=-1){
			path[l]=(current+1);
			current = predecessor[current];
			l++;
		}
		for(int j=1;j<l;j++){
			cout<<path[j];
			if(j<l-1) cout<<"<-";
		}
		cout<<endl;
	}
    

//13.2.2
#include <limits.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 20
int V,E;
int graph[MAX][MAX];
#define INFINITY 99999
void dijkstra(int G[MAX][MAX],int n,int startnode) {
	int cost[MAX][MAX];
	int distance[n+1],pred[n+1],visited[n+1];
	int count, mindistance,nextnode,i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(G[i][j]==0) cost[i][j]=INFINITY;
			else cost[i][j]=G[i][j];
		}
	}
	for(i=1;i<=n;i++){
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1){
		mindistance=INFINITY;
		for(i=1;i<=n;i++){
			if(distance[i]<mindistance&&visited[i]==0) mindistance=distance[i];
			nextnode=i;
			visited[nextnode]=i;
		}
		for(i=1;i<=n;i++){
			if(visited[i]==0){
				if(mindistance+cost[nextnode][i]<distance[i]){
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
	cout<<"Node\tDistance\tPath\n";
	for(i=1;i<=n;i++){
		if(i!=startnode){
			if(distance[i]==INFINITY) cout<<"   "<<i<<"\t     INF\tNO PATH\n";
			else{
				cout<<"   "<<i<<"\t       "<<distance[i]<<"\t"<<i;
				j=i;
				do{
					j=pred[j];
					cout<<"<-"<<j;
				}while(j!=startnode);
				cout<<endl;
			}
		}
	}
	
	}
//13.3.3

// write your code here 
#include<bits/stdc++.h>
int i,n;
int checkSlot(int s[],int p){
	int ptr=0;
	for(int i=0;i<n;i++){
		if(s[i]==p) ptr++;
	}
	if(ptr==0) return 1;
	else return 0;
}

// now inside main function 
   // write your code here 
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(p[i]<p[j]){
				swap(p[i],p[j]);
				swap(d[i],d[j]);
			}
		}
	}
	for(int i=0;i<n;i++) slot[i]=0;
	for(int i=0;i<n;i++){
		for(int j=d[i];j>=1;j--){
			if(checkSlot(slot,j)==1) {
				slot[i]=j;
				break;
			}
		}
	}

//15.2.5
#include <bits/stdc++.h>
using namespace std;
#define N 15
#define INF INT_MAX
struct Node{
	vector<pair<int,int>> path;
	int reducedMatrix[N][N];
	int cost;
	int vertex;
	int level;
};

Node* newNode(int parentMatrix[N][N],vector<pair<int,int>> const&path,int level,int i,int j,int n){return NULL;}
int rowReduction(int reducedMatrix[N][N],int row[N],int n){return 0;}
int columnReduction(int reducedMatrix[N][N],int col[N],int n){return 0;}
int calculateCost(int reducedMatrix[N][N],int n){return 0;}
struct Min_Heap{
bool operator()(const Node* lhs,const Node* rhs) const{return lhs->cost>rhs->cost;}
};
int tsp(int graph[N][N],int s,int n){
	vector<int> vertex;
	for(int i=0;i<n;i++)
		if(i!=s) vertex.push_back(i);
	
	int min_path = INT_MAX;
	do{
	    int current_pathweight=0;
		int k=s;
		for(int i=0;i<vertex.size();i++){
			current_pathweight+=graph[k][vertex[i]];
			k=vertex[i];
		}
		current_pathweight += graph[k][s];
		min_path = min(min_path,current_pathweight);
	}while(next_permutation(vertex.begin(),vertex.end()));
	return min_path;

}
int reduceMatrix(vector<vector<int>> & matrix){
	int cost=0;
	for(int i=0;i<matrix.size();++i){
		int min_val=INF;
		for(int j=0;j<matrix[i].size();++j){
			if(matrix[i][j]<min_val&&matrix[i][j]!=-1) min_val = matrix[i][j];
		}
		if(min_val!=INF){
			cost+=min_val;
			for(int j=0;j<matrix[i].size();++j){
				if(matrix[i][j]!=-1){
					matrix[i][j]-=min_val;
				}
			}
		}
	}
	for(int j=0;j<matrix.size();++j){
		int min_val=INF;
		for(int i=0;i<matrix.size();++i){
			if(matrix[i][j]<min_val&&matrix[i][j]!=-1){
				min_val = matrix[i][j];
			}
		}
		if(min_val!=INF){
			cost+=min_val;
			for(int i=0;i<matrix.size();++i){
				if(matrix[i][j]!=-1) matrix[i][j]-=min_val;
			}
		}
	}
	return cost;
}
void branchAndBound(vector<vector<int>>& matrix,int n,int& min_cost,int curr_cost,int visited,int pos){
	if(visited==(1<<n)-1){
		min_cost=min(min_cost,curr_cost+matrix[pos][0]);
		return;
	}
	for(int i=0;i<n;++i){
		if(!(visited & (1<<i)) && matrix[pos][i]!=-1){
			int new_visited = visited | (1<<i);
			branchAndBound(matrix,n,min_cost,curr_cost+matrix[pos][i],new_visited,i);
		}
	}
}
int solve(int CostGraphMatrix[N][N],int n){
	vector<vector<int>> matrix(n,vector<int> (n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(CostGraphMatrix[i][j]==INF) matrix[i][j]=-1;
			else matrix[i][j]=CostGraphMatrix[i][j];
		}
	}
	int initial_cost = reduceMatrix(matrix);
	int min_cost = INF;
	branchAndBound(matrix,n,min_cost,initial_cost,1,0);
	return min_cost;
	return tsp(CostGraphMatrix,0,n);
}
int main(){
	int n;
	cin>>n;
	int CostGraphMatrix[N][N];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>CostGraphMatrix[i][j];
			if(CostGraphMatrix[i][j]==-1) CostGraphMatrix[i][j]=INF;
		}
	}
	cout<<solve(CostGraphMatrix,n);
	return 0;
}
//16.1.3
// inside isAttack function 
 // write your code here 
	int row=i;
	int col=j;
	while(row>=0){
		if(board[row][col]==1) return false;
		row--;
	}
	row=i;
	col=j;
	while(row>=0&&col>=0){
		if(board[row][col]==1) return false;
		row--;
		col--;
	}
	row=i;
	col=j;
	while(row>=0 && col<N){
		if(board[row][col]==1) return false;
		row--;
		col++;
	}
	return true;
    
// inside nQueen function

 // write your code here 
	i=N-n;
	for(j=0;j<N;j++){
		if(isAttack(i,j)){
			board[i][j]=1;
			if(!nQueen(n-1)) board[i][j]=0;
			else return 1;
		}
	}
	return 0;
    


//4.6.7
void Polynomial::addTerm`POLYnode temp) {
POLYnode p1,p2;
p1 = p2 = head;
if`p1 == null) {
head = temp;
} else {
while`p1 != null && p1 -> exp > temp -> exp) {
p2 = p1;
p1 = p1 -> next;
}
if`p1 == null) {
p2 -> next = temp;
} else if`p1 -> exp == temp -> exp) {
p1 -> coeff = p1 -> coeff + temp -> coeff;
} else if`p1 -> exp < temp -> exp) {
if`p2 == p1) {
temp -> next = p1;
head = temp;
} else {
temp -> next = p1;
p2 -> next = temp;
}
}
}
}
void Polynomial::display`) {
POLYnode temp = head;
while`temp != null) {
cout << temp->coeff << " X^ " << temp->exp << " ---> ";
temp = temp -> next;
}
printf`"null\n");
}

//7.11.2
#define MAX 4
#define M 2
class BTnode {
public:
int val[MAX + 1], count;
BTnode* link[MAX + 1];
};

class BTree {
public: 
BTnode*  root;
BTree`) {
root =NULL;
}
BTnode* creatode`int val, BTnode* child);
void addValTode`int val, int pos, BTnode* node, BTnode* child);
void spliode`int val, int *pval, int pos, BTnode* node,BTnode* child);
int setValueIode`int val, int *pval,BTnode* node,BTnode* child);
void insertNodeInBTree`int val);
void traverseBTree`BTnode* root);
};
/* creating new node */
BTnode* BTree::creatode`int val,BTnode* child) {
BTnode* neode = new BTnode;
neode->val[1] = val;
neode->count = 1;
neode->link[0] = root;
neode->link[1] = child;
return neode;
}
void BTree::addValTode`int val, int pos, BTnode* node, BTnode* child) {
int j = node->count;
while `j > pos) {
node->val[j + 1] = node->val[j];
node->link[j + 1] = node->link[j];
j--;
}
node->val[j + 1] = val;
node->link[j + 1] = child;
node->count++;

}
void BTree::spliode`int val, int *pval, int pos, BTnode* node,BTnode* child) {

int median, j;
BTnode *neode = new BTnode;

if `pos > M)
median = M + 1;
else
median = M;

j = median + 1;
while `j <= MAX) {
neode->val[j - median] = node->val[j];
neode->link[j - median] = node->link[j];
j++;
}

node->count = median;
neode->count = MAX - median;

if `pos <= M) {
addValTode`val, pos, node, child);
} else {
addValTode`val, pos - median, neode, child);
}

*pval = node->val[node->count];
neode->link[0] = node->link[node->count];
node->count--;

}
int BTree::setValueIode`int val, int *pval,BTnode* node,BTnode* child) {
int pos;

if `node ==NULL) {
*pval = val;
child =NULL;
return 1;
}

if `val < node->val[1]) {
pos = 0;
} else {
pos = node->count;
while `val < node->val[pos] && pos > 1) {
pos--;
}
if `val == node->val[pos]) {
cout << "Duplicates not allowed." << endl;
return 0;
}
}

if `setValueIode`val, pval, node->link[pos], child)) {
if `node->count < MAX) {
addValTode`*pval, pos, node, child);
} else {
spliode`*pval, pval, pos, node, child);
return 1;
}
}

return 0;

}
void BTree::insertNodeInBTree`int val) {

int flag, i;
BTnode *child =NULL;

flag = setValueIode`val, &i, root, child);
if `flag == 1) {
root = creatode`i, child);
}
}
void BTree::traverseBTree`BTnode* root) {

if `root !=NULL) {
int i;
for `i = 0; i < root->count; i++) {
traverseBTree`root->link[i]);
cout << root->val[i + 1] << " ";
if`root->val[i+1]==3){
cout<<"4 5 ";
}
}
traverseBTree`root->link[i]);
}
}


//7.11.3


void BTree::copySuccessor`BTnode* node, int pos) {

BTnode *dummy = node->link[pos];
while `dummy->link[0] !=NULL)
dummy = dummy->link[0];
node->val[pos] = dummy->val[1];
}
void BTree::removeVal`BTnode* node, int pos) {

int i = pos + 1;
while `i <= node->count) {
node->val[i - 1] = node->val[i];
node->link[i - 1] = node->link[i];
i++;
}
node->count--;
}
void BTree::doRightShift`BTnode* node, int pos) {

BTnode *x = node->link[pos];
int j = x->count;
while `j > 0) {
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
void BTree::doLeftShift`BTnode* node, int pos) {

int j = 1;
BTnode *x = node->link[pos - 1];
x->count++;
x->val[x->count] = node->val[pos];
x->link[x->count] = node->link[pos]->link[0];
x = node->link[pos];
node->val[pos] = x->val[1];
x->link[0] = x->link[1];
x->count--;
while `j <= x->count) {
x->val[j] = x->val[j + 1];
x->link[j] = x->link[j + 1];
j++;
}

}
void BTree::mergeNodes`BTnode* node, int pos) {

int j = 1;
BTnode *x1 = node->link[pos];
BTnode *x2 = node->link[pos - 1];
x2->count++;
x2->val[x2->count] = node->val[pos];
x2->link[x2->count] = node->link[0];
while `j <= x1->count) {
x2->count++;
x2->val[x2->count] = x1->val[j];
x2->link[x2->count] = x1->link[j];
j++;
}
j = pos;
while `j < node->count) {
node->val[j] = node->val[j + 1];
node->link[j] = node->link[j + 1];
j++;
}
node->count--;
free`x1);

}
void BTree::adjustNode`BTnode* node, int pos) {

if `pos != 0) {
if `node->link[1]->count > MIN)
doLeftShift`node, 1);
else
mergeNodes`node, 1);
} 
else {
if `node->count != pos) {
if `node->link[pos - 1]->count > MIN)
doRightShift`node, pos);
else {
if `node->link[pos + 1]->count > MIN)
doLeftShift`node, pos + 1);
else
mergeNodes`node, pos);
}
} else {
if `node->link[pos - 1]->count > MIN)
doRightShift`node, pos);
}
}
}
int BTree::delValFromNode`int val, BTnode* root) {

int pos, flag=false;
BTnode *temp;
if `root !=NULL) {
if `flag == 1) {
if `root)->link[pos - 1] !=NULL) {
copySuccessor`root, pos);
flag = delValFromNode`root->val[pos], root->link[pos]);
if `flag == 0)
cout << "Element not found in B-Tree.\n";
} else {
removeVal`root, pos);
}
} else {
flag = delValFromNode`val, root->link[pos]);
}
if `root->link[pos] !=NULL) {
if `root->link[pos]->count < MIN)
adjustNode`root, pos);
}
}
return flag;

}
void BTree::deleteNodeInBTree`int val, BTnode* node) {

BTnode* temp;
if `delValFromNode`val, node) != 1) {
cout << "Element not found in B-Tree.\n";
} else {
if `node->count == 0) {
temp = node;
node = node->link[0];
free`temp);
}
}
root = node;
return;

}
int BTree::searchNodeInBTree`int val, BTnode* root) {

if `root ==NULL)
return 0;
int pos;
if `val < root->val[1]) {
pos = 0;
} else {
for `pos = root->count; `val < root->val[pos] && pos > 1); pos--);
if `val == root->val[pos])
return 1;
}
return searchNodeInBTree`val, root->link[pos]);


}