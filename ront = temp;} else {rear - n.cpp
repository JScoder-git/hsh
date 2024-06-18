//8.2.5

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
	node* temp=new node();
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void HashTable::insertEle(int x) {
	int index=hash(x);
	node*temp=newNode(x);
	temp->next=table[index];
	table[index]=temp;
}
void HashTable::deleteEle(int x) {
	int index=hash(x);
	node*temp;
	node*prev;
	temp=table[index];
	if(temp==NULL){
		cout<<"Element not found. So cannot delete."<<endl;
		return;
	}else if(temp->data==x){
		table[index]=temp->next;
		delete temp;
		cout<<"Successfully deleted."<<endl;
		return;
	}else{
		int flag=1;
		while(temp!=NULL && temp->data!=x){
			prev =temp;
			temp=temp->next;
			flag=0;
		}
		if(flag){
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL){
			cout<<"Element not found. So cannot delete."<<endl;
			return;
		}else{
			prev->next=temp->next;
			cout<<"Successfully deleted."<<endl;
			return;
		}
	}
}
void HashTable::searchEle(int x) {
	int index=hash(x);
	node*temp;
	temp=table[index];
	while(temp!=NULL && temp->data!=x){
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"Element not found."<<endl;
		return;
	}
	else if(temp->data==x){
		cout<<"Element found."<<endl;
	}
}
void HashTable::display() {
	int i=0;
	node*temp;
	for(i=0;i<SIZE;i++){
		temp=table[i];
		cout<<"["<<i<<"]=> ";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}


//4.2.6

struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void empty() {
		 first = NULL;
	}
	NODE createNode();
	void addNodes(int x);
	void insertAtBegin(int x);
	void insertAtEnd(int x);
	void insertAtPosition(int pos,int x);
	void deleteAtBegin();
	void deleteAtEnd();
	void deleteAtPosition(int pos);
	int count();
	void traverseList();
	int searchPosOfEle(int x);
};
NODE Sll::createNode() {
	NODE temp;
	temp = new node;
	temp->next = NULL;
	return temp;
}
void Sll::insertAtPosition(int pos, int x) {
	NODE temp, prevPos = first, last=first;
	if(pos<=0){
		cout<<"No such position in SLL. "<<"So insertion is not possible.\n";
		return;
	}
	int i;
	for(i=1;i<pos;i++){
		if(last==NULL){
			cout<<"No such position in SLL. "<<"So insertion is not possible.\n";
			return;
		}
		prevPos=last;
		last=last->next;
	}
	temp=createNode();
	temp->data=x;
	if(pos==1){
		temp->next=first;
		first=temp;
	}
	else{
		temp->next=prevPos->next;
		prevPos->next=temp;
	}
}
void Sll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}

//4.2.7

struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void empty() {
		 first = NULL;
	}
	NODE createNode();
	void insertAtBegin(int x);
	void deleteAtBegin();
	void traverseList();
};

NODE Sll::createNode() {
	NODE temp;
	temp = new node;
	temp->next = NULL;
	return temp;
}
void Sll::insertAtBegin(int x) {
	NODE temp= createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		temp->next=first;
		first=temp;
	}
}
void Sll::deleteAtBegin() {
	if(first==NULL){
		cout<<"SLL is empty. So deletion is not possible.\n";
	}
	else{
		cout<<"The deleted element from SLL : "<<first->data<<endl;
		first = first->next;
	}
}
void Sll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}

//4.2.8

struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void empty() {
		 first = NULL;
	}
	NODE createNode();
	void insertAtEnd(int x);
	void deleteAtEnd();
	void traverseList();
};
NODE Sll::createNode() {
	NODE temp;
	temp = new node;
	temp->next = NULL;
	return temp;
}
void Sll::insertAtEnd(int x) {
	NODE temp,lastnode;
	temp=createNode();
	lastnode=first;
	if(first==NULL){
		first=temp;
		temp->data=x;
	}
	else{
		while(lastnode->next!=NULL){
			lastnode=lastnode->next;
		}
		lastnode->next=temp;
		temp->data=x;
	}
}
void Sll:: deleteAtEnd() {
	NODE lastnode,ptr;
	if(first==NULL){
		cout<<"SLL is empty. So deletion is not possible.\n";
	}
	else if(first->next==NULL){
		cout<<"The deleted element from SLL : "<<first->data<<endl;
		first=NULL;
	}
	else{
		lastnode=first;
		
		while(lastnode->next!=NULL){
			ptr=lastnode;
			lastnode=lastnode->next;
	}
		cout<<"The deleted element from SLL : "<<lastnode->data<<endl;
		
		ptr->next=NULL;
}
}
void Sll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}

//4.2.9

struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void empty() {
		 first = NULL;
	}
	NODE createNode();
	void insertAtEnd(int x);
	void deleteAtPosition(int pos);
	void traverseList();
};
NODE Sll::createNode() {
	NODE temp;
	temp = new node;
	temp->next = NULL;
	return temp;
}
void Sll::insertAtEnd(int x) {
	NODE temp,lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		while(lastNode->next!=NULL){
			lastNode=lastNode->next;
		}
		lastNode->next=temp;
	}
}
void Sll:: deleteAtPosition(int pos) {
	NODE prevPos=first,lastNode=first;
	int i;
	if(first==NULL){
		cout<<"SLL is empty. So deletion is not possible.\n";
		return;
	}
	else{
		if(pos==1){
			first=first->next;
		}
		else{
			for(int i=1;i<pos;i++){
				if(lastNode==NULL){
					cout<<"No such position in SLL. So deletion is not possible."<<endl;
					return;
				}
				prevPos=lastNode;
				lastNode=lastNode->next;
			}
			if(lastNode==NULL||pos<0){
				cout<<"No such position in SLL. So deletion is not possible.\n";
				return;
			}
			else{
				prevPos->next=lastNode->next;
			}
		}
		cout<<"The deleted element from SLL : "<<lastNode->data<<endl;
		delete lastNode;
		return;
	}
}
void Sll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}

//4.2.10

struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void empty() {
		 first = NULL;
	}
	NODE createNode();
	void insertAtBegin(int x);
	void traverseList();
	int searchPosOfEle(int x);
};
NODE Sll::createNode() {
	NODE temp;
	temp = new node;
	temp->next = NULL;
	return temp;
}
void Sll::insertAtBegin(int x) {
	NODE temp=createNode();
	temp->data=x;
	temp->next=first;
	first=temp;
}
void Sll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}
int Sll:: searchPosOfEle(int key) {
	NODE ptr=first;
	int i=0;
	while(ptr!=NULL){
		i++;
		if(ptr->data==key){
			return i;
		}
		ptr=ptr->next;
	}
}

//4.2.11

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void createAndAddNodes();
	void print();
	void concatenate(Sll l1, Sll l2);
};

void Sll::createAndAddNodes() {
	NODE q,temp;
	int x;
	cout<<"Enter an element (to stop enter -1) : ";
	cin>>x;
	while(x!=-1){
		temp=new node;
		temp->data=x;
		temp->next=NULL;
		if(first==NULL){
			first=temp;
		}
		else{
			q->next=temp;
		}
		q=temp;
		cout<<"Enter an element (to stop enter -1) : ";
		cin>>x;
	}
}

void Sll::concatenate(Sll l1, Sll l2) {
	if(l1.first==NULL){
		first=l2.first;
	}
	else if(l2.first==NULL){
		first=l1.first;
	}
	else{
		first=l1.first;
		while(l1.first->next!=NULL){
			l1.first=l1.first->next;
		}
		l1.first->next=l2.first;
	}
}

void Sll::print() {
	NODE temp=first;
	while(temp!=NULL){
		cout<<temp->data<<"---> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

//4.2.12

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void createAndAddNodes();
	void print();
	void concatenate(Sll l1, Sll l2);
	void unionSll(Sll l1, Sll l2);
};

void Sll::createAndAddNodes() {
	NODE temp,q;
	int x;
	cout<<"Enter an element (to stop enter -1) : ";
	cin>>x;
	while(x!=-1){
		temp=new node;
		temp->data=x;
		temp->next=NULL;
		if(first==NULL){
			first=temp;
		}
		else{
			q->next=temp;
		}
		q=temp;
		cout<<"Enter an element (to stop enter -1) : ";
		cin>>x;
		
	}
}

void Sll::unionSll(Sll l1, Sll l2) {
	NODE t1,t2,q=NULL;
	concatenate(l1,l2);
	for(t1=first;t1!=NULL && t1->next!=NULL;t1=t1->next){
		for(t2=t1;t2!=NULL && t2->next!=NULL;t2=t2->next){
			if(t1->data==t2->next->data){
				q=t2->next;
				t2->next=q->next;
				delete q;
			}
		}
	}
}
void Sll::concatenate(Sll l1, Sll l2) {
	if(l1.first==NULL){
		first=l2.first;
	}
	else if(l2.first==NULL){
		first=l1.first;
	}
	else{
		first=l1.first;
		while(l1.first->next!=NULL){
			l1.first=l1.first->next;
		}
		l1.first->next=l2.first;
	}
}

void Sll::print() {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		while (q != NULL) {
			printf("%d---> ", q->data);
			q = q->next;
		}
		printf("NULL\n");
	}
}

//4.2.13

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;

class Sll {
	NODE first;
	public:	Sll() {
		first = NULL;
	}
	void createAndAddNodes();
	void print();
	void sort();
	void add(int x);
	void intersectionSll(Sll l1, Sll l2);
	int isEmpty();
};
void Sll::createAndAddNodes() {
	NODE temp, q;
	int x;
	cout <<"Enter an element (to stop enter -1) : ";
	cin >> x;
	while(x != -1) {
		temp = new node;
		temp->data = x;
		temp->next = NULL;
		if(first == NULL) {
			first = temp;
		} else {
			q->next = temp;
		}
		q = temp;
		cout <<"Enter an element (to stop enter -1) : ";
		cin >> x;
	}
}
void Sll::print() {
	NODE q = first;
	if (first == NULL) {
		printf("Single Linked List is empty\n");
	} else {
		while (q != NULL) {
			printf("%d---> ", q->data);
			q = q->next;
		}
		printf("NULL\n");
	}
}
void Sll::sort() {
	NODE t1,t2;
	int x;
	for(t1=first;t1->next!=NULL;t1=t1->next){
		for(t2=t1->next;t2!=NULL;t2=t2->next){
			if(t1->data > t2->data){
				x=t1->data;
				t1->data=t2->data;
				t2->data=x;
			}
		}
	}
}
void Sll::add(int x) {
	NODE t,q = first;
	t = new node;
	t->data = x;
	t->next = NULL;
	if (first == NULL)
		first = t;
	else {
		while (q->next != NULL)
			q = q->next;
		q->next = t;
	}
}
void Sll::intersectionSll(Sll l1,Sll l2) {
	NODE t1,t2;
	t1=l1.first;
	t2=l2.first;
	while(t1!=NULL && t2!=NULL){
		if(t1->data < t2->data){
			t1=t1->next;
		}
		if(t1->data > t2->data){
			t2=t2->next;
		}
		if(t1->data == t2->data){
			add(t1->data);
			t1=t1->next;
			t2=t2->next;
		}
	}
}
int Sll::isEmpty() {
	if(first == NULL) {
		return 1;
	} else {
		return 0;
	}
}

//4.3.1>> 1,b

//4.3.2

struct node {
	int data;
	struct node *next;
 };
typedef struct node *NODE;

class Cll {
	NODE first;
	public:	Cll() {
		first = NULL;
	}
	void empty() {
		 first = NULL;
	}
	NODE createNode();
};

NODE Cll :: createNode() {
	NODE temp;
	temp=new node();
	temp->next=NULL;
	return temp;
	
}

//4.3.3

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

class Cll {
    NODE first;
public:	Cll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void addNodes(int x);
    void traverseList();
};
NODE Cll::createNode() {
	NODE temp;
	temp=new node();
	temp->next=NULL;
	return temp;
}
void Cll::addNodes(int x) {
	NODE temp = createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		NODE lastNode=first;
		while(lastNode->next!=first){
			lastNode=lastNode->next;
		}
		lastNode->next=temp;
	}
	temp->next=first;
}
void Cll::traverseList() {
	NODE temp=first;
	if(first==NULL){
		cout<<"NULL";
	}
	else{
		do{
			cout<<temp->data<<" --> ";
			temp=temp->next;
		}
			while(temp!=first);{
			cout<<"NULL\n";
			}
	}
}

//4.3.4

struct node {
    int data;
    struct node * next;
};
typedef struct node * NODE;

class Cll {
    NODE first;
    public: Cll() {
        first = NULL;
    }
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    int count();
    void traverseList();
};
NODE Cll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
void Cll::insertAtBegin(int x) {
	NODE temp,lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
		temp->next=first;
	}
	else{
		while(lastNode->next!=first){
			lastNode=lastNode->next;
		}
		temp->next=first;
		first=temp;
		lastNode->next=first;
	}
	return;
}
int Cll::count() {
	NODE temp=first;
	int c=0;
	if(first==NULL){
		return c;
		}
	else{
		do{
			c++;
			temp=temp->next;
		}
			while(temp!=first);
		return c;
	}
}
void Cll::traverseList() {
	NODE temp=first;
	if(first==NULL){
		cout<<"NULL"<<endl;}
	else{
		do{
			cout<<temp->data<<" --> ";
			temp=temp->next;
		}
			while(temp!=first);
		cout<<"NULL\n";
	}
	}


//4.3.5

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

class Cll {
    NODE first;
	public:	Cll() {
    	first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void traverseList();
};

NODE Cll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
void Cll::insertAtEnd(int x) {
	NODE temp,lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
		temp->next=first;
	}
	else{
		while(lastNode->next!=first){
			lastNode=lastNode->next;
		}
		lastNode->next=temp;
		temp->next=first;
	}
}
void Cll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.3.6

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

class Cll {
    NODE first;
public:	Cll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtPosition(int pos,int x);
    void traverseList();
};
NODE Cll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
void Cll::insertAtPosition(int pos, int x) {
	NODE temp,lastNode=first;
	if(first==NULL && pos>1){
		cout<<"No such position in CLL. So insertion is not possible.\n";
		return;
	}
	int i=1;
	while(i<pos-1){
	if(lastNode==NULL || lastNode->next==first){
		cout<<"No such position in CLL. So insertion is not possible.\n";
		return;
	}
	if(lastNode=lastNode->next);
	i++;
}
	temp=createNode();
	temp->data=x;
	if(pos==1){
		if(first==NULL){
			first=temp;
			temp->next=first;
		}
		else{
			while(lastNode->next!=first){
				lastNode=lastNode->next;
			}
			temp->next=first;
			first=temp;
			lastNode->next=first;
		}
	}
	else{
		temp->next=lastNode->next;
		lastNode->next=temp;
	}
}


void Cll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.3.7

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

class Cll {
    NODE first;
public:	Cll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    void deleteAtBegin();
    void traverseList();
};
NODE Cll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
void Cll::insertAtBegin(int x) {
	NODE temp,lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
		temp->next=first;
	}else{
		while(lastNode->next!=first){
			lastNode=lastNode->next;
		}
		temp->next=first;
		first=temp;
		lastNode->next=first;
	}
	return;
}
void Cll::deleteAtBegin() {
	NODE prev=first,lastNode=first;
	if(first==NULL){
		cout<<"CLL is empty. So deletion is not possible.\n";
		return;
	}
	else{
		if(prev->next==first){
			first=NULL;
		}
		else{
			while(lastNode->next!=first){
				lastNode=lastNode->next;
			}
			first=prev->next;
			lastNode->next=first;
		}
	}
	cout<<"The deleted element from CLL : "<<prev->data<<endl;
	delete prev;
}
void Cll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.3.8

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

class Cll {
    NODE first;
public:	Cll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void deleteAtEnd();
    void traverseList();
};
NODE Cll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
void Cll::insertAtEnd(int x) {
	NODE temp,lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
		temp->next=first;
	}
	else{
		while(lastNode->next!=first){
			lastNode=lastNode->next;
		}
		lastNode->next=temp;
		temp->next=first;
	}
}


void Cll:: deleteAtEnd() {
	NODE prev,lastNode=first;
	if(first==NULL){
		cout<<"CLL is empty. So deletion is not possible.\n";
		return;
	}
	else{
		if(lastNode->next==first){
			first=NULL;
		}
		else{
			while(lastNode->next!=first){
				prev=lastNode;
				lastNode=lastNode->next;
			}
			prev->next=first;
		}
		cout<<"The deleted element from CLL : "<<lastNode->data<<endl;
	}
	delete lastNode;
}
void Cll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.3.9

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

class Cll {
    NODE first;
public:	Cll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void deleteAtPosition(int pos);
    void traverseList();
};
NODE Cll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
void Cll::insertAtEnd(int x) {
    NODE temp, lastNode = first;
    temp = createNode();
    temp -> data = x;
    if (first == NULL) {
        first = temp;
        temp -> next = first;
    } else {
        while (lastNode -> next != first) {
            lastNode = lastNode -> next;
        }
        lastNode -> next = temp;
        temp -> next = first;
    }
}
void Cll:: deleteAtPosition(int pos) {
	NODE lastNode=first;
	NODE prev=first;
	int i=1;
	if(first==NULL){
		cout<<"CLL is empty. So deletion is not possible.\n";
	}
	else{
		if(pos==1){
			if(prev->next==first){
				first=NULL;
			}
			else{
				while(lastNode->next!=first){
					lastNode=lastNode->next;
				}
				first=prev->next;
				lastNode=lastNode->next;
			}
		}
		else{
			while(i<pos){
				if(prev->next==first){
					cout<<"No such position in CLL. So deletion is not possible.\n";
					return;
				}
				lastNode=prev;
				prev=prev->next;
				i++;
			}
			lastNode->next=prev->next;
		}
		cout<<"The deleted element from CLL : "<<prev->data<<endl;
	}
}
void Cll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.3.10

struct node {
    int data;
    struct node *next;
};
typedef struct node *NODE;

class Cll {
    NODE first;
public:	Cll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    void traverseList();
    int searchPosOfEle(int x);
};
NODE Cll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    return temp;
}
void Cll::insertAtBegin(int x) {
	NODE temp;
	NODE lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
		temp->next=first;
	}
	else{
		while(lastNode->next!=first){
			lastNode=lastNode->next;
		}
		temp->next=first;
		first=temp;
		lastNode->next=first;
	}
	return;
}
void Cll::traverseList() {
	NODE temp=first;
	if(first==NULL){
		cout<<"NULL\n";
	}
	else{
		do{
			cout<<temp->data<<" --> ";
			temp=temp->next;
		}
			while(temp!=first);
		cout<<"NULL\n";
	}
}
int Cll:: searchPosOfEle(int key) {
	int c=0;
	NODE currentNode=first;
	NODE q=first;
	if(currentNode==NULL){
		return c;
	}
	else{
		do{
			c++;
			if(currentNode->next==first && currentNode->data!=key){
				return 0;
			}
			q=currentNode;
			currentNode=currentNode->next;
		}
			while(q->next!=first && q->data!=key);
		return c;
	}
}

//4.4.1>> a,d,e

//4.4.2

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
	public:	Dll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
};
NODE Dll::createNode() {
	NODE temp=new node();
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

//4.4.3

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
public:	Dll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void addNodes(int x);
    void traverseList();
};
NODE Dll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dll::addNodes(int x) {
	NODE temp=createNode();
	NODE ptr=first;
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
		ptr->next=temp;
		temp->prev=ptr;
	}
}
void Dll::traverseList() {
	NODE temp=first;
	while(temp!=NULL){
		cout<<temp->data<<" --> ";
		temp=temp->next;
	}
	cout<<"NULL\n";
}

//4.4.4

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
public:	Dll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    int count();
    void traverseList();
};
NODE Dll::createNode() {
	NODE temp=new node();
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void Dll::insertAtBegin(int x) {
	NODE temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
}
int Dll::count() {
	NODE temp=first;
	int c=0;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}
void Dll::traverseList() {
	NODE temp=first;
	while(temp!=NULL){
		cout<<temp->data<<" --> ";
		temp=temp->next;
	}
	cout<<"NULL\n";
}

//4.4.5

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
	public:	Dll() {
    	first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
	void traverseList();
};
NODE Dll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dll::insertAtEnd(int x) {
	NODE temp=createNode();
	NODE lastNode=first;
	temp->data=x;
	if(lastNode==NULL){
		first=temp;
	}
	else{
		while(lastNode->next!=NULL){
			lastNode=lastNode->next;
		}
		lastNode->next=temp;
	}
}
void Dll::traverseList() {
	NODE temp=first;
	while(temp!=NULL){
		cout<<temp->data<<" --> ";
		temp=temp->next;
	}
	cout<<"NULL\n";
}

//4.4.6

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
public:	Dll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtPosition(int pos,int x);
    void traverseList();
};
NODE Dll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dll::insertAtPosition(int pos, int x) {
	NODE temp,lastNode=first;
	int i;
	if(pos<=0 || first==NULL && pos>1){
		cout<<"No such position in DLL. So insertion is not possible.\n";
		return;
	}
	for(i=1;i<pos-1;i++){
		if(lastNode->next==NULL || lastNode==NULL){
			cout<<"No such position in DLL. So insertion is not possible.\n";
			return;
		}
		lastNode=lastNode->next;
	}
	temp=createNode();
	temp->data=x;
	if(pos==1){
		if(first!=NULL){
			temp->next=first;
			first->prev=temp;
		}
		first=temp;
	}
	else{
		temp->next=lastNode->next;
		temp->prev=lastNode;
		if(lastNode->next!=NULL){
			lastNode->next->prev=temp;
		}
		lastNode->next=temp;
	}
}


void Dll::traverseList() {
	NODE temp=first;
	while(temp!=NULL){
		cout<<temp->data<<" --> ";
		temp=temp->next;
	}
	cout<<"NULL\n";
}

//4.4.7

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
public:	Dll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    void deleteAtBegin();
    void traverseList();
};
NODE Dll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dll::insertAtBegin(int x) {
	NODE temp;
	temp=new node;
	temp->data=x;
	if(first==NULL){
		first=temp;
		return;
	}
	else if(first!=NULL){
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
}
void Dll::deleteAtBegin() {
	NODE lastNode=first;
	if(first==NULL){
		cout<<"DLL is empty. So deletion is not possible.\n";
	}
	else {
		if(first->next==NULL){
			first=NULL;
		}
		else{
			first=first->next;
			first->prev=NULL;
		}
		cout<<"The deleted element from DLL : "<<lastNode->data<<"\n";
		delete lastNode;
	}
}
void Dll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}

//4.4.8

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
public:	Dll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void deleteAtEnd();
    void traverseList();
};
NODE Dll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dll::insertAtEnd(int x) {
	NODE temp,lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		while(lastNode->next!=NULL){
			lastNode=lastNode->next;
		}
		lastNode->next=temp;
		temp->prev=lastNode;
	}
}
void Dll:: deleteAtEnd() {
	NODE prev,lastNode=first;
	if(first==NULL){
		cout<<"DLL is empty. So deletion is not possible."<<endl;
	}
	else{
		if(lastNode->next==NULL){
			first=NULL;
		}
		else{
			while(lastNode->next!=NULL){
				prev=lastNode;
				lastNode=lastNode->next;
			}
			prev->next=NULL;
		}
		cout<<"The deleted element from DLL : "<<lastNode->data<<endl;
		delete lastNode;
	}
}
void Dll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}

//4.4.9

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
	public:	Dll() {
		first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void deleteAtPosition(int pos);
    void traverseList();
};
NODE Dll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dll::insertAtEnd(int x) {
    NODE temp, lastNode = first;
    temp = createNode();
    temp -> data = x;
    if (first == NULL) {
        first = temp;
    } else {
        while (lastNode -> next != NULL) {
            lastNode = lastNode -> next;
        }
        lastNode -> next = temp;
        temp->prev = lastNode;
    }
}
void Dll:: deleteAtPosition(int pos) {
	NODE  lastNode=first,prev=first;
	int i=1;
	if(first==NULL){
		cout<<"DLL is empty. So deletion is not possible."<<endl;
		return;
	}
	else{
		if(pos==1){
			if(lastNode->next==NULL){
				first=NULL;
			}
			else{
				first=first->next;
				first->prev=NULL;
			}
		}
		else{
			while(i<pos){
				if(lastNode==NULL){
					cout<<"No such position in DLL. So deletion is not possible."<<endl;
					return;
				}
				else{
					prev=lastNode;
					lastNode=lastNode->next;
				}
				i++;
			}
			if(lastNode==NULL || pos<=0){
				cout<<"No such position in DLL. So deletion is not possible."<<endl;
				return;
			}
			else if(lastNode->next==NULL){
				prev->next=NULL;
			}
			else{
				prev->next=lastNode->next;
				prev->next->prev=lastNode->prev;
			}
		}
		cout<<"The deleted element from DLL : "<<lastNode->data<<endl;
		delete lastNode;
	}
}
void Dll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}

//4.4.10

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

class Dll {
    NODE first;
public:	Dll() {
    first = NULL;
}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    void traverseList();
    int searchPosOfEle(int x);
};
NODE Dll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dll::insertAtBegin(int x) {
	NODE temp;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
		return;
	}
	else if(first!=NULL){
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
}
void Dll::traverseList() {
	NODE temp = first;
	while (temp != NULL) {
		cout << temp -> data << " --> ";
		temp = temp -> next;
	}
	cout << "NULL\n";
}
int Dll:: searchPosOfEle(int key) {
	NODE currentNode=first;
	int count=0;
	if(first==NULL){
		return count;
	}
	else{
		while(currentNode != NULL && currentNode->data!=key){
			if(currentNode->next==NULL){
				return 0;
			}
			count++;
			currentNode=currentNode->next;
		}
		return count+1;
	}
}

//4.5.1>> a

//4.5.2

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
};

NODE Dcll::createNode() {
	NODE temp;
	temp=new node;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

//4.5.3

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void addNodes(int x);
    void traverseList();
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::addNodes(int x) {
	NODE temp,lastNode=first;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		lastNode=first->prev;
		lastNode->next=temp;
		temp->prev=lastNode;
	}
	temp->next=first;
	first->prev=temp;
}
void Dcll::traverseList() {
	NODE temp=first;
	if(first==NULL){
		cout<<"NULL";
	}
	else{
		do{
			cout<<temp->data<<" --> ";
			temp=temp->next;
		}
			while(temp!=first);
		cout<<"NULL"<<endl;
	}
}

//4.5.4

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    int count();
    void traverseList();
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::insertAtBegin(int x) {
	NODE temp;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		temp->next=temp;
		temp->prev=temp;
	}
	else{
		NODE lastNode=first->prev;
		temp->prev=lastNode;
		temp->next=first;
		lastNode->next=temp;
		first->prev=temp;
	}
	first=temp;
}
int Dcll::count() {
	NODE temp=first;
	int count=0;
	if(first==NULL){
		return count;
	}
	else{
		do{
			count++;
			temp=temp->next;
		}
			while(temp!=first);
		return count;
	}
}
void Dcll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}


//4.5.5

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void traverseList();
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::insertAtEnd(int x) {
	NODE lastNode=first;
	NODE temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		lastNode=first->prev;
		lastNode->next=temp;
		temp->prev=lastNode;
	}
	temp->next=first;
	first->prev=temp;
}
void Dcll::traverseList() {
	NODE temp=first;
	if(first==NULL){
		cout<<"NULL"<<endl;
	}
	else{
		do{
			cout<<temp->data<<" --> ";
			temp=temp->next;
		}
			while(temp!=first);
		cout<<"NULL"<<endl;
	}
}


//4.5.6

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtPosition(int pos,int x);
    void traverseList();
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::insertAtPosition(int pos, int x) {
	NODE temp,lastNode=first;
	if(pos<=0 || pos>1 && first==NULL){
		cout<<"No such position in DCLL. So insertion is not possible."<<endl;
		return;
	}
	else{
		int i=1;
		for(i =1;i<pos-1;i++){
			if(lastNode->next==first){
				cout<<"No such position in DCLL. So insertion is not possible."<<endl;
				return;
			}
			lastNode=lastNode->next;
		}
	}
	temp=createNode();
	temp->data=x;
	if(pos==1){
		if(first==NULL){
			temp->next=temp;
			temp->prev=temp;
			
		}
		else{
			lastNode=first->prev;
			lastNode->next=temp;
			temp->prev=lastNode;
			temp->next=first;
			first->prev=temp;
		}
		first=temp;
	}
	else{
		temp->prev=lastNode;
		temp->next=lastNode->next;
		lastNode->next=temp;
		first->prev=temp;
	}
}
void Dcll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.5.7

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    void deleteAtBegin();
    void traverseList();
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::insertAtBegin(int x) {
	NODE temp;
	temp=createNode();
	temp->data=x;
	if(first==NULL){
		temp->next=temp;
		temp->prev=temp;
	}
	else{
		NODE lastNode = first->prev;
		temp->prev=lastNode;
		temp->next=first;
		lastNode->next=temp;
		first->prev=temp;
	}
	first=temp;
}
void Dcll::deleteAtBegin() {
	NODE temp =first,lastNode=first;
	if(first==NULL){
		cout<<"DCLL is empty. So deletion is not possible."<<endl;
		return;
	}
	else{
		if(temp->next==first){
			first=NULL;
		}
		else{
			lastNode=first->prev;
			first=first->next;
			first->prev=lastNode;
			lastNode->next=first;
			
		}
		cout<<"The deleted element from DCLL : "<<temp->data<<endl;
		delete temp;
	}
}
void Dcll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.5.8

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void deleteAtEnd();
    void traverseList();
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::insertAtEnd(int x) {
	NODE lastNode =first;
	NODE temp=createNode();
	temp->data=x;
	if(first==NULL){
		first=temp;
	}
	else{
		lastNode=first->prev;
		lastNode->next=temp;
		temp->prev=lastNode;
	}
	temp->next=first;
	first->prev=temp;
}
void Dcll:: deleteAtEnd() {
	NODE temp=first,lastNode=first;
	if(first==NULL){
		cout<<"DCLL is empty. So deletion is not possible."<<endl;
	}
	else{
		if(temp->next==first){
			first=NULL;
		}
		else{
			temp=first->prev;
			lastNode=temp->prev;
			lastNode->next=first;
			first->prev=lastNode;
		}
		cout<<"The deleted element from DCLL : "<<temp->data<<endl;
		delete temp;
	}
}
void Dcll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}

//4.5.9

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtEnd(int x);
    void deleteAtPosition(int pos);
    void traverseList();
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::insertAtEnd(int x) {
    NODE temp, lastNode = first;
    temp = createNode();
    temp -> data = x;
    if (first == NULL) {
        first = temp;
    } else {
        lastNode = first->prev;
        lastNode -> next = temp;
		temp -> prev = lastNode;
    }
    temp -> next = first;
	first -> prev = temp;
}
void Dcll:: deleteAtPosition(int pos) {
	NODE temp=first,lastNode=first;
	if(first==NULL){
		cout<<"DCLL is empty. So deletion is not possible."<<endl;
		return;
	}
	else{
		if(pos==1){
			if(temp->next==first){
				first=NULL;
			}
			else{
				lastNode=first->prev;
				lastNode->next=first->next;
				first->next->prev=lastNode;
				first=first->next;
			}
		}
		else{
			int i;
			for(i=1;i<pos;i++){
				if(temp->next==first){
					cout<<"No such position in DCLL. So deletion is not possible."<<endl;
					return;
				}
				lastNode=temp;
				temp=temp->next;
			}
			if(temp->next=first){
				lastNode->next=first;
				first->prev=lastNode;
			}
			else{
				lastNode->next=temp->next;
				temp->next->prev=lastNode;
			}
		}
		cout<<"The deleted element from DCLL : "<<temp->data<<endl;
		delete temp;
	}
}
void Dcll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}


//4.5.10

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;

class Dcll {
    NODE first;
	public:	Dcll() {
	    first = NULL;
	}
    void empty() {
        first = NULL;
    }
    NODE createNode();
    void insertAtBegin(int x);
    void traverseList();
    int searchPosOfEle(int x);
};
NODE Dcll::createNode() {
    NODE temp;
    temp = new node;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void Dcll::insertAtBegin(int x) {
    NODE temp, lastNode = first;
    temp = createNode();
    temp -> data = x;
    if (first == NULL) {
        temp -> next = temp;
		temp -> prev = temp;
    } else {
        lastNode = first->prev;
        temp -> prev = lastNode;
		temp -> next = first;
		lastNode -> next = temp;
		first -> prev = temp;
    }
    first = temp;
    return;
}
void Dcll::traverseList() {
    NODE temp = first;
    if (first == NULL) {
        cout << "NULL\n";
    } else {
        do {
            cout << temp -> data << " --> ";
            temp = temp -> next;
        } while (temp != first);
        cout<< "NULL\n";
    }
}
int Dcll::searchPosOfEle(int key) {
	NODE currentNode=first;
	int count=0;
	if(currentNode==NULL){
		return count;
	}
	while(currentNode->data!=key && currentNode!=NULL){
		if(currentNode->next==first){
			return 0;
		}
		count++;
		currentNode=currentNode->next;
	}
	return count+1;
}

//4.6.1>>a,b

//4.6.2

class Polynomial {
	int head[MAX+1];
	int hpow;
	public :
	Polynomial() {
		int i=0;
		for(;i<=MAX;i++)
			head[i] = 0;
	}
	void create();
	void display();
};
void Polynomial::create() {
	cout<<"Enter the highest power of the polynomial : ";
	cin>>hpow;
	int i;
	for(i=hpow;i>=0;i--){
		cout<<"Enter coeff value for ";
		cout<<i<<" degree term : ";
		cin>>head[i];
	}
}
void Polynomial::display() {
	int i;
	for(i=hpow;i>=0;i--){
		cout<<head[i]<<"X^"<<i<<"--> ";
		
	}
	cout<<endl;
}

//4.6.3

class Polynomial {
	int head[MAX+1];
	int hpow;
	public :
	Polynomial() {
		int i=0;
		for(;i<=MAX;i++)
			head[i] = 0;
	}
	void create();
	void display();
	void add(Polynomial p1, Polynomial p2);
};

void Polynomial::create() {
	cout<<"Enter the highest power of the polynomial : ";
	cin>>hpow;
	int i;
	for(i=hpow;i>=0;i--){
		cout<<"Enter coeff value for "<<i<<" degree term : ";
		cin>>head[i];
	}
}
void Polynomial::display() {
	int i;
	for (i = hpow; i >= 0; i--) {
		cout << head[i] <<"X^" << i << "--> ";
	}
	cout <<"\n";	
}
void Polynomial::add(Polynomial p1, Polynomial p2) {
	int i;
	hpow=(p1.hpow>p2.hpow)?p1.hpow:p2.hpow;
	for(i=hpow;i>=0;i--){
		head[i]=p1.head[i]+p2.head[i];
	}
}

//4.6.4

class Polynomial {
	int head[MAX+1];
	int hpow;
	public :
	Polynomial() {
		int i=0;
		for(;i<=MAX;i++)
			head[i] = 0;
	}
	void create();
	void display();
	void subtract(Polynomial p1, Polynomial p2);
};

void Polynomial::create() {
	cout<<"Enter the highest power of the polynomial : ";
	cin>>hpow;
	int i;
	for(i=hpow;i>=0;i--){
		cout<<"Enter coeff value for "<<i<<" degree term : ";
		cin>>head[i];
	}
}
void Polynomial::display() {
	int i;
	for (i = hpow; i >= 0; i--) {
		cout << head[i] <<"X^" << i << "--> ";
	}
	cout <<"\n";	
}
void Polynomial::subtract(Polynomial p1, Polynomial p2) {
	int i;
	hpow=(p1.hpow>p2.hpow)?p1.hpow:p2.hpow;
	for(i=hpow;i>=0;i--){
		head[i]=p1.head[i]-p2.head[i];
	}
}

//5.1.1>>a,d

//5.1.2

class StackArray {
	int arr[STACK_MAX_SIZE];
	int top;
	
	public: StackArray() {
		top = -1;
	}
	
	void push(int element);
	void display();
};
void StackArray::push(int element) {
	if(top== STACK_MAX_SIZE-1){
		cout<<"Stack is overflow."<<endl;
	}
	else{
		top=top+1;
		arr[top]=element;
		cout<<"Successfully pushed."<<endl;
	}
}
void StackArray::display() {
	if(top<0){
		cout<<"Stack is empty";
	}
	else{
		cout<<"Elements of the stack are : ";
		for(int i=top;i>=0;i--){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

//5.1.3

class StackArray {
	int arr[STACK_MAX_SIZE];
	int top;
	public: StackArray() {
		top = -1;
	}
	void push(int element);
	void pop();
	void peek();
	void isEmpty();
	void display();
};
void StackArray::push(int element) {
	if(top == STACK_MAX_SIZE - 1) {
		cout <<"Stack is overflow.\n";
	} else {
		top = top + 1;
		arr[top] = element;
		cout <<"Successfully pushed.\n";
	}
}
void StackArray::display() {
	if (top < 0) {
		cout <<"Stack is empty.\n";
	} else {
		cout <<"Elements of the stack are : ";
		for(int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}
void StackArray::pop() {
	if(top<0){
		cout<<"Stack is underflow.\n";
	}
	else{
		int x=arr[top];
		top--;
		cout<<"Popped value = "<<x<<"\n";
	}
}
void StackArray::peek() {
	if(top<0){
		cout<<"Stack is underflow.\n";
	}
	else{
		cout<<"Peek value = "<<arr[top]<<"\n";
	}
}
void StackArray::isEmpty() {
	if(top<0){
		cout<<"Stack is empty.\n";
	}
	else{
		cout<<"Stack is not empty.\n";
	}
}

//5.2.1

class StackNode {
	public: 
	int data;
	StackNode *next;
};
class StackList {
	StackNode* top;
	public: StackList() {
		top = NULL;
	}
	void push(int);
	void display();
};
void StackList::push(int x) {
	StackNode* temp=new StackNode();
	temp->data=x;
	temp->next=top;
	top=temp;
	cout<<"Successfully pushed.\n";
}
void StackList::display() {
	StackNode* temp=top;
	if(top==NULL){
		cout<<"Stack is empty.\n";
	}
	else{
		cout<<"Elements of the stack are : ";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
}

//5.2.2

class StackNode {
	public: 
	int data;
	StackNode *next;
};
class StackList {
	StackNode* top;
	public: StackList() {
		top = NULL;
	}
	void push(int);
	void pop();
	void peek();
	void display();
	void isEmpty();
	
};
void StackList::push(int x) {
	StackNode* temp=new StackNode();
	temp->data=x;
	temp->next=top;
	top=temp;
	cout<<"Successfully pushed.\n";
}
void StackList::display() {
	if(top==NULL){
		cout<<"Stack is empty.\n";
	}
	else{
		StackNode* temp= top;
		cout<<"Elements of the stack are : ";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}
void StackList::pop() {
	if(top==NULL){
		cout<<"Stack is underflow.\n";
	}
	else{
		int data = top->data;
		top=top->next;
		cout<<"Popped value = "<<data<<endl;
	}
}
void StackList::peek() {
	if(top==NULL){
		cout<<"Stack is underflow.\n";
	}
	else{
		cout<<"Peek value = "<<top->data<<endl;
	}
}
void StackList::isEmpty() {
	if(top==NULL){
		cout<<"Stack is empty.\n";
	}
	else{
		cout<<"Stack is not empty.\n";
	}
}

//5.3.1>>a,b,d

//5.3.4

#include <iostream>
using namespace std;
#define STACK_MAX_SIZE 30
int arr[STACK_MAX_SIZE];
int top = -1;
void push(long int element) {
	if(top == STACK_MAX_SIZE - 1) {
		cout << "Stack is overflow.\n";
	} else {
		top = top + 1;
		arr[top] = element;
	}
}
int pop() {
	int x;
	if(top < 0) {
		cout << "Stack is underflow.\n";
	} else {
		x = arr[top];
		top = top - 1;
		return x;
	}
}
int main() {
	int size, index;
	int arr[30];
	cout << "Enter the size of the array : ";
	cin >> size;
		if(size < 0) {
		cout << "Invalid input! Size should be greater than 0.\n";
		return 0;
	}
	for(index = 0; index < size; index++) {
		cout << "Enter arr : " << index << " ";
		cin >> arr[index];
	}
	cout << "Array before reversing : ";
	for(index = 0; index < size; index++) {
		cout << arr[index] << " ";
	}
	cout << "\n";
	
	for(int i=0;i<size;i++){
		push(arr[i]);
	}
	for(int i=0;i<size;i++){
		arr[i]=pop();
	}
	
	cout << "Array after reversing : ";
	for(index = 0; index < size; index++) {
		cout << arr[index] << " ";
	}
	cout << "\n";
	return 0;
}

//5.3.5

#include <iostream>
using namespace std;
#define STACK_MAX_SIZE 30
long int arr[STACK_MAX_SIZE];
int top = -1;
void push(long int element) {
	if(top == STACK_MAX_SIZE - 1) {
		cout << "Stack is overflow.\n";
	} else {
		top = top + 1;
		arr[top] = element;
	}
}
long int pop() {
	long int x;
	if(top < 0) {
		cout << "Stack is underflow.\n";
		return 0;
	} else {
		x = arr[top];
		top = top - 1;
		return x;
	}
}
// Implement the factorial program using the stack.
long int factorial(long int n) {
	long int i=1;
	push(1);
	for(i;i<=n;i++){
		push(pop()*i);
	}
	return pop();
}

int main() {
	long int n;
	cout << "Enter an integer : ";
	cin >> n;
	if(n < 0) {
		cout << "Invalid input! Only positive numbers are allowed.\n";
		return 0;
	}
	cout << "Factorial of " << n << " is : " << factorial(n) << "\n";
	return 0;
}

//5.3.6

#include <iostream>
using namespace std;
#define STACK_MAX_SIZE 30
char arr[STACK_MAX_SIZE];
int top = -1;
void push(char element) {
	if(top == STACK_MAX_SIZE - 1) {
		cout << "Stack is overflow.\n";
	} else {
		top = top + 1;
		arr[top] = element;
	}
}
char pop() {
	long int x;
	if(top < 0) {
		cout << "Stack is underflow.\n";
		return 0;
	} else {
		x = arr[top];
		top = top - 1;
		return x;
	}
}

void reverse(char str[]) { 
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		push(str[i]);
	}
	for(int i=0;i<n;i++){
		str[i]=pop();
	}
}

int main() {
	char ch[80], temp;
	cout << "Enter a string : ";
	cin >>  ch;
	reverse(ch);
	cout << "The reverse of a given string : " << ch << "\n";
	return 0;
}

//7.1.1>>a,c

//7.1.2>>a,c

//7.1.3>>b,d,e,f

//7.4.1>>a,b,c

//7.6.1>>a

//7.6.2>>a,b,c

//7.6.4

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
	AVLNODE* minValueNode(AVLNODE* node);
	int max(int a, int b);
	//AVLTree Rotations
	AVLNODE* rotateRight(AVLNODE* x);
	AVLNODE* rotateLeft(AVLNODE* x);
	//AVLTree Operations
	AVLNODE* insertNode(AVLNODE * root , int ele);
	AVLNODE* deleteNode(AVLNODE * root, int ele);
	void preorder(AVLNODE * root);
};
AVLNODE* AVLTree::createNode(int item) {
	AVLNODE *temp = new AVLNODE;
	temp->data = item;
	temp->left = temp->right = NULL;
	temp->ht = 1;
	return temp;
}
//Fill Code in the following three functions.
void AVLTree::preorder(AVLNODE* root) {

}
AVLNODE* AVLTree::minValueNode(AVLNODE* node) {

}
AVLNODE* AVLTree::deleteNode(AVLNODE* root,int ele) {

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

//4.6.5

class Polynomial {
	int head[MAX+1];
	int hpow;
	public :
	Polynomial() {
		int i=0;
		for(;i<=MAX;i++)
			head[i] = 0;
	}
	void create();
	void display();
	void multiply(Polynomial p1, Polynomial p2);
};

void Polynomial::create() {
	int i;
	cout <<"Enter the highest power of the polynomial : ";
	cin >> hpow;
	for(i = hpow; i >= 0; i--) {
		cout << "Enter coeff value for " << i <<" degree term : ";
		cin >> head[i];			
	}
}
void Polynomial::display() {
	int i;
	for (i = hpow; i >= 0; i--) {
		cout << head[i] <<"X^" << i << "--> ";
	}
	cout <<"\n";	
}
void Polynomial::multiply(Polynomial p1, Polynomial p2) {
	int i,j;
	hpow=p1.hpow+p2.hpow;
	if(hpow>=MAX){
		cout<<"Array is overflow\n";
	}
	else{
		for(i=p1.hpow; i>=0;i--){
			for(j=p2.hpow; j>=0; j--){
				head[i+j]=head[i+j]+p1.head[i]*p2.head[j];
			}
		}
	}
}

//4.6.6>>a

//4.6.7

struct polynode {
	int coeff;
	int exp;
	struct polynode *next;
};
typedef struct polynode *POLYNODE;

class Polynomial {
	POLYNODE head;
	public :
	Polynomial() {
		head = NULL;
	}
	void create();
	void addTerm(POLYNODE p);
	void display();
};
void Polynomial::addTerm(POLYNODE temp) {
	POLYNODE p1,p2;
	p1=p2=head;
	if(p1==NULL){
		head=temp;
	}
	else{
		while(p1!=NULL && p1->exp > temp -> exp){
			p2=p1;
			p1=p1->next;
		}
		if(p1==NULL){
			p2->next=temp;
		}
		else if(p1->exp==temp->exp){
			p1->coeff=p1->coeff+temp->coeff;
		}
		else if (p1->exp<temp->exp){
			if(p2==p1){
				temp->next=p1;
				head=temp;
			}
			else{
				temp->next=p1;
				p2->next=temp;
			}
		}
	}
	
}
void Polynomial::create() {
	POLYNODE temp;
	char ch;
	int coeff, exp;
	do {
		temp = new polynode;
		cout << "Enter coeff and exp of node : ";
		cin >> coeff;
		cin >> exp;
		temp -> coeff = coeff;
		temp -> exp = exp;
		temp -> next = NULL;
		addTerm(temp);
		cout << "Do u want another node (y/n) : ";
		cin >> ch;
	} while(ch != 'n');
}
void Polynomial::display() {
	POLYNODE temp = head;
	if(head==NULL){
		cout<<"NULL"<<endl;
	}
	while(temp!=NULL){
		cout<<temp->coeff<<" X^ "<<temp->exp<< " ---> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

//4.6.8

struct polynode {
	int coeff;
	int exp;
	struct polynode *next;
};
typedef struct polynode *POLYNODE;

class Polynomial {
	POLYNODE head;
	public :
	Polynomial() {
		head = NULL;
	}
	void create();
	void addTerm(POLYNODE p);
	void display();
	void add(Polynomial p1, Polynomial p2);
};
void Polynomial::addTerm(POLYNODE temp) {
	POLYNODE p1,p2;
	p1=p2=head;
	if(p1==NULL){
		head=temp;
	}
	else{
		while(p1!=NULL && p1->exp > temp ->exp){
			p2=p1;
			p1=p1->next;
		}
		if(p1==NULL){
			p2->next=temp;
		}
		else if(p1->exp==temp->exp){
			p1->coeff=p1->coeff+temp->coeff;
		}
		else if(p1->exp < temp->exp){
			if(p1==p2){
				temp->next=p1;
				head=temp;
			}
			else{
				temp->next=p1;
				p2->next=temp;
			}
		}
	}
}

void Polynomial::create() {
	POLYNODE temp;
	char ch;
	int coeff, exp;
	do{
		temp = new polynode;
		cout<<"Enter coeff and exp of node : ";
		cin>>coeff;
		cin>>exp;
		temp->coeff=coeff;
		temp->exp=exp;
		temp->next=NULL;
		addTerm(temp);
		cout<<"Do u want another node (y/n) : ";
		cin>>ch;
	}
		while(ch!='n');
}

void Polynomial::display() {
	POLYNODE temp = head;
	while(temp != NULL) {
		cout << temp->coeff << " X^ " << temp->exp << " ---> ";
		temp = temp -> next;
	}
	printf("NULL\n");
}
void Polynomial::add(Polynomial p1, Polynomial p2) {
	POLYNODE t1,t2,temp=NULL;
	t1=p1.head;
	t2=p2.head;
	while(t1!=NULL && t2!=NULL){
		temp=new polynode;
		if(t1->exp==t2->exp){
			temp->coeff=t1->coeff+t2->coeff;
			temp-> exp=t1->exp;
			temp->next=NULL;
			addTerm(temp);
			t1=t1->next;
			t2=t2->next;
		}
		else if(t1->exp > t2->exp){
			temp->coeff=t1->coeff;
			temp->exp=t1->exp;
			temp->next=NULL;
			addTerm(temp);
			t1=t1->next;
		}
		else{
			temp->coeff=t2->coeff;
			temp->exp=t2->exp;
			temp->next=NULL;
			addTerm(temp);
			t2=t2->next;
		}
	}
	while(t1!=NULL){
		temp= new polynode;
		temp->coeff=t1->coeff;
		temp->exp=t1->exp;
		temp->next=NULL;
		addTerm(temp);
		t1=t1->next;
	}
	while(t2!=NULL){
		temp= new polynode;
		temp->coeff=t2->coeff;
		temp->exp=t2->exp;
		temp->next=NULL;
		addTerm(temp);
		t2=t2->next;
	}
}

//4.6.9

struct polynode {
	int coeff;
	int exp;
	struct polynode *next;
};
typedef struct polynode *POLYNODE;

class Polynomial {
	POLYNODE head;
	public :
	Polynomial() {
		head = NULL;
	}
	void create();
	void addTerm(POLYNODE p);
	void display();
	void subtract(Polynomial p1, Polynomial p2);
};
void Polynomial::addTerm(POLYNODE temp) {
	POLYNODE p1,p2;
	p1=p2=head;
	if(p1==NULL){
		head=temp;
	}
	else{
		while(p1!=NULL && p1->exp>temp->exp){
			p2=p1;
			p1=p1->next;
		}
		if(p1==NULL){
			p2->next=temp;
		}
		else if(p1->exp==temp->exp){
			p1->coeff=p1->coeff+temp->coeff;
		}
		else if(p1->exp<temp->exp){
			if(p1==p2){
				temp->next=p1;
				head=temp;
			}
			else{
				temp->next=p1;
				p2->next=temp;
			}
		}
	}
}

void Polynomial::create() {
	POLYNODE temp;
	char ch;
	int coeff, exp;
	do{
		temp = new polynode;
		cout<<"Enter coeff and exp of node : ";
		cin>>coeff;
		cin>>exp;
		temp->coeff=coeff;
		temp->exp=exp;
		temp->next=NULL;
		addTerm(temp);
		cout<<"Do u want another node (y/n) : ";
		cin>>ch;
	}while(ch!='n');
}
void Polynomial::display() {
	POLYNODE temp = head;
	while(temp != NULL) {
		cout << temp->coeff << " X^ " << temp->exp << " ---> ";
		temp = temp -> next;
	}
	printf("NULL\n");
}
void Polynomial::subtract(Polynomial p1, Polynomial p2) {
	POLYNODE t1,t2, temp=NULL;
	t1=p1.head;
	t2=p2.head;
	while(t1!=NULL && t2!=NULL){
		temp=new polynode;
		if(t1->exp==t2->exp){
			temp->coeff=t1->coeff-t2->coeff;
			temp->exp=t1->exp;
			temp->next=NULL;
			addTerm(temp);
			t1=t1->next;
			t2=t2->next;
		}
		else if(t1->exp > t2->exp){
			temp->coeff=t1->coeff;
			temp->exp=t1->exp;
			temp->next=NULL;
			addTerm(temp);
			t1=t1->next;
		}
		else{
			temp->coeff= -1*t2->coeff;
			temp->exp=t2->exp;
			temp->next=NULL;
			addTerm(temp);
			t2=t2->next;
		}
	}
	while(t1!=NULL){
		temp=new polynode;
		temp->coeff=t1->coeff;
		temp->exp=t1->exp;
		temp->next=NULL;
		addTerm(temp);
		t1=t1->next;
	}
	while(t2!=NULL){
		temp = new polynode;
		temp->coeff= -1*t2->coeff;
		temp->exp=t2->exp;
		temp->next = NULL;
		addTerm(temp);
		t2=t2->next;
	}
}

//4.6.10

struct polynode {
	int coeff;
	int exp;
	struct polynode *next;
};
typedef struct polynode *POLYNODE;

class Polynomial {
	POLYNODE head;
	public :
	Polynomial() {
		head = NULL;
	}
	void create();
	void addTerm(POLYNODE p);
	void display();
	void multiply(Polynomial p1, Polynomial p2);
};
void Polynomial::addTerm(POLYNODE temp) {
	POLYNODE p1,p2;
	p1 = p2 = head;
	if(p1 == NULL) {
		head = temp;
	} else {
		while(p1 != NULL && p1 -> exp > temp -> exp) {
			p2 = p1;
			p1 = p1 -> next;
		}
		if(p1 == NULL) {
			p2 -> next = temp;
		} else if(p1 -> exp == temp -> exp) {
			p1 -> coeff = p1 -> coeff + temp -> coeff;
		} else if(p1 -> exp < temp -> exp) {
			if(p2 == p1) {
				temp -> next = p1;
				head = temp;
			} else {
				temp -> next = p1;
				p2 -> next = temp;
			}
		}
	}
}
void Polynomial::create() {
	POLYNODE temp;
	char ch;
	int coeff, exp;
	do {
		temp = new polynode;
		cout << "Enter coeff and exp of node : ";
		cin >> coeff;
		cin >> exp;
		temp -> coeff = coeff;
		temp -> exp = exp;
		temp -> next = NULL;
		addTerm(temp);
		cout << "Do u want another node (y/n) : ";
		cin >> ch;
	} while(ch != 'n');
}
void Polynomial::display() {
	POLYNODE temp = head;
	while(temp != NULL) {
		cout << temp->coeff << " X^ " << temp->exp << " ---> ";
		temp = temp -> next;
	}
	printf("NULL\n");
}
void Polynomial::multiply(Polynomial p1, Polynomial p2) {
	POLYNODE t1,t2,temp;
	t1=t2=temp=NULL;
	for(t1=p1.head; t1!=NULL; t1=t1->next){
		for(t2=p2.head; t2!=NULL; t2=t2->next){
			temp= (POLYNODE)malloc(sizeof(struct polynode));
			temp->coeff=t1->coeff*t2->coeff;
			temp->exp=t1->exp+t2->exp;
			temp->next=NULL;
			addTerm(temp);
		}
	}
}

//4.6.11

struct node {
	char name[10];
	struct node *next;
};
typedef struct node *NODE;
class JosephusCll {
	NODE first;
	public:
	JosephusCll () {
		first = NULL;
	}
	NODE createNode();
	void addNodes(char sname[]);
	void display();
	void performJosephus();
};
NODE JosephusCll::createNode() {
	NODE temp;
	temp = new node;
	temp -> next = NULL;
	return temp;
}

void JosephusCll::addNodes(char sname[]) {
	NODE temp,lastNode = first;
	temp = createNode();
	strcpy(temp -> name, sname);
	if (first == NULL) {
		first = temp;
	} else {
		while(lastNode->next != first)
			lastNode = lastNode->next;
		lastNode -> next = temp;
	}
	temp -> next = first;
}

void JosephusCll::display() {
	NODE q = first;
	if(first == NULL) {
		cout << "No Soilders !!";
		return;
	}
	do {
		cout << q->name << " --> ";
		q = q -> next;
	} while(q != first);
	printf("NULL\n");
}	

void JosephusCll::performJosephus() {
	NODE last;
	int n,i;
	cout<<"Enter a value : ";
	cin>>n;
	while(first!=first->next){
		for(i=1; i<n; i++){
			last=first;
			first=first->next;
		}
		last->next=first->next;
		cout<<"The eliminated soldier is : "<<first->name<<endl;
		free(first);
		first=last->next;
	}
	cout<<"The escaped soldier is : "<<first->name<<endl;
}

//4.6.12

#include <iostream>
using namespace std;
struct sparsematrix_node {
	int data;
	int row_value;
	int col_value;
	struct sparsematrix_node * next;
};
typedef struct sparsematrix_node* SPMNODE;
SPMNODE start = NULL;
SPMNODE createNode (int val, int row, int col) {
	SPMNODE temp = (SPMNODE)malloc(sizeof(struct sparsematrix_node));
	temp->data = val;
	temp->row_value = row;
	temp->col_value = col;
	temp->next = NULL;
	return temp;
} 
void addNode(int val, int row, int col) {
	SPMNODE node;
	node=createNode(val,row,col);
	SPMNODE temp=start;
	if(temp==NULL){
		start=node;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=node;
	}
}
void displaySparseMatrix() {
	SPMNODE temp=start;
	cout<<"Row\tColumn\tValue"<<endl;
	while(temp!=NULL){
		cout<<temp->row_value<<"\t\t "<<temp->col_value<<"\t\t "<<temp->data<<endl;
		temp=temp->next;
	}
}
int main() {
	int rows,cols,i,j;
	int sparse_matrix[10][10];
	cout << "Enter the row & column sizes of the sparse matrix : ";
	cin >> rows >> cols ;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			cout << "Enter the value of sparse_matrix " << i << j << " : ";
			cin >> sparse_matrix[i][j];
		}
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if(sparse_matrix[i][j]!=0)
				addNode(sparse_matrix[i][j],i,j);
		}
	}
	displaySparseMatrix();
}

//5.3.2

#include<stack>
#include<string>

using namespace std;
stack<char> st;

//char stack [STACK_MAX_SIZE];
int top = -1;

//Return 1 if stack is empty else return 0.
int isEmpty() {
	return (st.empty()?1:0);
}

//Push the character into stack
void push(char x) {
	st.push(x);
}

//pop a character from stack
char pop() {
	if (!st.empty()){
		char p = st.top();
		st.pop();
		return p;
	}
	return ' ';
}

// Return 0 if char is '('
// Return 1 if char is '+' or '-'
// Return 2 if char is '*' or '/' or '%'
int priority(char x) {
	if (x == '(' || x == ')'){
		return 0;
	} else if ( x== '+' || x == '-'){
		return 1;
	} else if ( x == '+' || x == '/' || x == '%'){
		return 2;
	} else {
		return 3;
	}
}

//Output Format
//if expression is correct then output will be Postfix Expression : <postfix notation>
//If the expression contains unbalanced paranthesis the output will be "Invalid infix expression : unbalanced parenthesis."
void convertInfix(char * e) {
	string ans = "";
	int len = strlen(e);
	for ( int i =0; i<len; i++){
		char ch = e[i];
		if(isalnum(ch)){
			ans += ch;
		}else if( ch == '('){
			st.push(ch);
		} else if( ch== ')'){
			while (!st.empty() && st.top() != '('){
				ans+= st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
		}else{
			char x=ch;
			if(x=='+' || x== '-' || x== '*' || x=='/'){
				while(!st.empty() && priority(ch) <= priority(st.top())){
					ans += st.top();
					st.pop();
				}
				st.push(ch);
			}else{
	cout<<"Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%%', '/' } are allowed."<<endl;
				return;
			}
		}
	}
	while(!st.empty()){
		if(st.top() == '('){
			cout<< "Invalid infix expression : unbalanced parenthesis."<<endl;
			return;
		}
		ans+=st.top();
		st.pop();
	}
	cout<< "Postfix expression : "<< ans << endl;
}

//5.3.3

#include <ctype.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;
#define STACK_MAX_SIZE 20
stack<int> st;
//Declare the required stack variables.

//Return 1 if stack is empty else return 0.
int isEmpty() {
	return st.empty() ? 1 : 0;
}

//Push the character into stack
void push(int x) {
	st.push(x);
}

//pop a character from stack
int pop() {
	if (!st.empty()) {
		int top = st.top();
		st.pop();
		return top;
	} else {
		return -1;
	}
}

//Output Format - Result : <result> if the input postfix expression is vaild.
//Output Format - Invalid postfix expression,. - if the input expression is invalid.
//postfix expression is given as the parameter.
void evaluatePostfix(char * e) {
	int len = strlen(e);
	for(int i=0; i<len; i++){
		if (isdigit(e[i])) {
			push(e[i] - '0');
		} else {
			int operand2 = pop();
			int operand1 = pop();
			if (operand1 == -1 || operand2 == -1) {
				cout << "Invalid postfix expression." <<endl;
				return;
			}
			switch (e[i]) {
				case '+':
					push(operand1 + operand2);
					break;
				case '-':
					push(operand1 - operand2);
					break;
				case '*':
					push(operand1 * operand2);
					break;
				case '/':
					push(operand1 / operand2);
					break;
				default:
					cout << "Invalid postfix expression." <<endl;
			}
		}
	}
	if (!isEmpty()) {
		cout<< "Result : "<< pop() <<endl;
	} else {
		cout<< "Invalid postfix expression." <<endl;
	}
}
//Read a postfix expression and evaluate it.
int main() {
	char expr[20];
	char *e, x;
	printf("Enter the postfix expression : ");
	cin >> expr;
	e = expr;
	evaluatePostfix(e);

}

//5.3.7

#include <iostream>
using namespace std;
#define STACK_MAX_SIZE 30
char arr[STACK_MAX_SIZE];
int top = -1;
void push(char element) {
	if(top == STACK_MAX_SIZE - 1) {
		cout << "Stack is overflow.\n";
	} else {
		top = top + 1;
		arr[top] = element;
	}
}
char pop() {
	long int x;
	if(top < 0) {
		cout << "Stack is underflow.\n";
		return 0;
	} else {
		x = arr[top];
		top = top - 1;
		return x;
	}
}
int isempty() {
	if(top == -1)
		return 1;
	else 
		return 0;	
}
//Complete the code below.
int isBalanced(char exp[]) { 
	int n;
	n=strlen(exp);
	int i=0;
	char x;
	for(int i=0; i<n; i++){
		if(exp[i]== '(' || exp[i]=='{' || exp[i]=='['){
			push(exp[i]);
		}
		else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
			if(isempty()){
				return 0;
			}
			else{
				switch(exp[i]){
					case ')':
						x=pop();
						if(x=='{' || x=='['){
							return 0;
						}
					break;
					case ']':
						x=pop();
						if(x=='(' || x=='{'){
							return 0;
						}
					break;
					case '}':
						x=pop();
						if(x=='(' || x=='['){
							return 0;
						}
					break;
				}
			}
		}
	}
	return isempty();

}
int main() {
	char ch[80], temp;
	cout << "Enter an expression : ";
	cin >> ch;
	if(isBalanced(ch) == 1) {
		cout << "Expression is balanced.\n";
	} else {
		cout << "Expression is not balanced.\n";
	}
	return 0;
}

//6.1.1>>bc

//6.1.2

#define MAX 10
class QueueArray {
	public :
	int queue[MAX];
	int front,rear;
	QueueArray() {
		front = rear = -1;	
	}
	void enqueue(int x);
	void display();
};
void QueueArray::enqueue(int x) {
	if(rear==MAX-1){
		cout<<"Queue is overflow."<<endl;
	}
	else{
		rear =rear+1;
		queue[rear]=x;
		cout<<"Successfully inserted."<<endl;
		if(front==-1){
			front=front+1;
		}
	}
}
void QueueArray::display() {
	if(front==-1 && rear==-1){
		cout<<"Queue is empty."<<endl;
	}
	else{
		cout<<"Elements in the queue : ";
		for(int i=front; i<=rear; i++){
			cout<<queue[i]<<" ";
		}
		cout<<endl;
	}
}

//6.1.3

#define MAX 10
class QueueArray {
	public :
	int queue[MAX];
	int front, rear;
	QueueArray() {
		front = rear = -1;
	}
	void enqueue(int x);
	void dequeue();
	void display();
	void size();
	void isEmpty();
};
void QueueArray::enqueue(int x) {
	if(rear==MAX-1){
		cout<<"Queue is overflow."<<endl;
	}
	else{
		rear=rear+1;
		queue[rear]=x;
		cout<<"Successfully inserted."<<endl;
		if(front==-1){
			front=front+1;
		}
	}
}
void QueueArray::dequeue() {
	if(front==-1){
		cout<<"Queue is underflow.\n";
	}
	else{
		cout<<"Deleted element = "<<queue[front]<<endl;
		if(rear==front){
			front=rear=-1;
		}
		else{
			front=front+1;
		}
	}
}
void QueueArray::display() {
	if(front==-1 && rear==-1){
		cout<<"Queue is empty."<<endl;
	}
	else{
		cout<<"Elements in the queue : ";
		for(int i=front; i<=rear; i++){
			cout<<queue[i]<<" ";
		}
		cout<<endl;
	}
}
void QueueArray::size() {
	if(front==-1 && rear==-1){
		cout<<"Queue size : "<<0<<endl;
	}
	else{
		int count=0;
		for(int i=front; i<=rear; i++){
			count++;
		}
		cout<<"Queue size : "<<count<<endl;
	}
}
void QueueArray::isEmpty() {
	if(front==-1 && rear==-1){
		cout<<"Queue is empty."<<endl;
	}
	else{
		cout<<"Queue is not empty."<<endl;
	}
}

//6.1.4

class QueueNode {
	public :
	int data;
	QueueNode *next;
};
class QueueList {
	QueueNode * front , * rear;
	public :
		QueueList() {
			front = NULL;
			rear = NULL;
		}
		void enqueue(int element);
		void display();
};
void QueueList::enqueue(int element) {
	QueueNode* temp = new QueueNode;
	if(temp==NULL){
		cout<<"Queue is overflow."<<endl;
	}
	else{
		temp->data=element;
		temp->next=NULL;
		if(front==NULL){
			front=temp;
		}
		else{
			rear->next=temp;
		}
		rear=temp;
		cout<<"Successfully inserted."<<endl;
	}
}
void QueueList::display() {
	QueueNode* temp =new QueueNode;
	if(front==NULL){
		cout<<"Queue is empty."<<endl;
	}
	else{
		cout<<"Elements in the queue : ";
		temp = front;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}

//6.1.5

class QueueNode {
	public :
	int data;
	QueueNode *next;
};
class QueueList {
	QueueNode * front , * rear;
	public :
		QueueList() {
			front = NULL;
			rear = NULL;
		}
		void enqueue(int element);
		void dequeue();
		void display();
		void isEmpty();
		void size();
};
void QueueList::enqueue(int element) {
	QueueNode* temp = new QueueNode;
	if(temp==NULL){
		cout<<"Queue is overflow."<<endl;
	}
	else{
		temp->data=element;
		temp->next=NULL;
		if(front==NULL){
			front=temp;
		}
		else{
			rear->next=temp;
		}
		rear=temp;
		cout<<"Successfully inserted."<<endl;
	}
}
void QueueList::dequeue() {
	if(front == NULL){
		cout<<"Queue is underflow.\n";
	}
	else{
		QueueNode* temp=new QueueNode;
		temp=front;
		if(front==rear){
			front=rear=NULL;
		}
		else{
			front=front->next;
		}
		cout<<"Deleted value = "<<temp->data<<endl;
		delete temp;
	}
}
void QueueList::display() {
	QueueNode* temp=new QueueNode;
	if(front == NULL){
		cout<<"Queue is empty.\n";
	}
	else{
		cout<<"Elements in the queue : ";
		temp = front;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}
void QueueList::size() {
	QueueNode* temp = new QueueNode;
	int count=0;
	if(front==NULL){
		cout<<"Queue size : "<<0<<endl;
	}
	else{
		temp=front;
		while(temp!=NULL){
			temp=temp->next;
			count++;
		}
		cout<<"Queue size : "<<count<<endl;
	}
}
void QueueList::isEmpty() {
	if(front==NULL){
		cout<<"Queue is empty.\n";
	}else{
		cout<<"Queue is not empty.\n";
	}
}

//6.1.6

struct stack {
	int data;
	struct stack *next;
};
typedef struct stack *stk;
struct queue{
	stk stack1;
	stk stack2;
};
typedef struct queue* Q;
Q que;
void push(stk* stack, int x) {
	stk temp;
	temp = (stk)malloc(sizeof(struct stack));
	if(temp == NULL) {
		cout << "Stack is overflow.\n";
	} else {
		temp -> data = x;
		temp -> next = *stack;
		*stack = temp;
	}
}
int pop(stk* stack) {
	stk temp;
	if(stack == NULL) {
		cout << "Stack is underflow.\n";
		return 0;
	} else {
		temp = *stack;
		*stack = temp -> next;
		return temp->data;
	}
}
void enqueue(int ele) {
	push(&(que->stack1),ele);
	cout<<"Successfully inserted.\n";
}
void dequeue() {
	int x;
	if(que->stack1==NULL && que->stack2== NULL){
		cout<<"Queue is underflow.\n";
		return;
	}
	if(que->stack2==NULL){
		while(que->stack1!=NULL){
			x=pop(&(que->stack1));
			push(&(que->stack2),x);
		}
	}
	x=pop(&(que->stack2));
	cout<<"Deleted value = "<<x<<" "<<endl;
}
void display() {
	stk temp;
	if(que->stack1==NULL && que-> stack2==NULL){
		cout<<"Queue is empty.\n";
		return;
	}
	temp = que->stack1;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	temp = que->stack2;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

//6.2.1>>b

//6.2.2


class CQueueArray {
	public :
	int queue[MAX];
	int front,rear;
		CQueueArray () {
		front = -1;
		rear = -1;
	}
	void enqueue(int x);
	void display();
};
void CQueueArray::enqueue(int x) {
	if(((rear==MAX-1)&&(front==0))||(rear+1==front)){
		cout<<"Circular queue is overflow.\n";
		return;
	}
	else{
		if(rear==MAX-1){
			rear=-1;
		}
		else if(front=-1){
			front=0;
		}
		rear = rear+1;
		queue[rear]=x;
		cout<<"Successfully inserted.\n";
	}
}
void CQueueArray::display(){
	int i;
	if(front==-1 && rear == -1){
		cout<<"Circular queue is empty.\n";
	}
	else{
		cout<<"Elements in the circular queue : ";
		if(front<=rear){
			for(i=front; i<=rear; i++){
				cout<<queue[i]<<" ";
			}
		}
		else{
			for(i=front; i<=MAX-1; i++){
				cout<<queue[i]<<" ";
			}
			for(i=0;i<=rear;i++){
				cout<<queue[i]<<" ";
			}
		}
		cout<<"\n";
	}
}


//6.2.3

class CQueueArray {
	public :
	int queue[MAX];
	int front,rear;
	
	CQueueArray () {
		front = -1;
		rear = -1;
	}
	void enqueue(int x);
	void dequeue();
	void display();
	void size();
	void isEmpty();
};

void CQueueArray::dequeue() {
	if(front==-1){
		cout<<"Circular queue is underflow.\n";
	}
	else{
		cout<<"Deleted element = "<<queue[front]<<endl;
		if(rear==front){
			front=-1;
			rear=-1;
		}
		else if(front==MAX-1){
			front=0;
		}
		else{
			front=front+1;
		}
	}
}

void CQueueArray::enqueue(int x) {
	if (((rear == MAX - 1) && (front == 0)) || (rear + 1 == front)) {
		printf("Circular queue is overflow.\n");
	} else {
		if (rear == MAX - 1) {
			rear = -1;
		} else if (front == -1) {
			front = 0;
		}
		rear++;
		queue[rear] = x;
		printf("Successfully inserted.\n");
	}
}
void CQueueArray::display() {
	int i;
	if (front == -1 && rear == -1) {
		cout <<"Circular queue is empty.\n";
	} else {
		cout <<"Elements in the circular queue : ";
		if (front <= rear) {
			for (i = front; i <= rear; i++) {
				cout << queue[i] <<" ";
			}
		} else {
			for (i = front; i <= MAX - 1; i++) {
				cout << queue[i] <<" ";
			}
			for (i = 0; i <= rear; i++) {
				cout << queue[i] <<" ";
			}
		}
		cout <<"\n";
	}
}

void CQueueArray::size() {
	if(front==-1 && rear==-1){
		cout<<"Circular queue size : "<<0<<endl;
	}
	else if(front<=rear){
		cout<<"Circular queue size : "<<rear-front+1<<endl;
	}
	else{
		cout<<"Circular queue size : "<<MAX-front+rear+1<<endl;
	}
}
void CQueueArray::isEmpty() {
	if(front==-1 && rear==-1){
		cout<<"Circular queue is empty.\n";
	}
	else{
		cout<<"Circular queue is not empty.\n";
	}
}

//6.2.4

class CQueueNode {
	public :
	int data;
	CQueueNode *next;
};
class CQueueList {

	CQueueNode *front, *rear;
	public :
	CQueueList() {
	 	front = NULL;
	 	rear = NULL;
	}
	void enqueue(int element);
	void display();
};
void CQueueList::enqueue(int element) {
	CQueueNode* temp=new CQueueNode;
	if(temp==NULL){
		cout<<"Circular is overflow."<<endl;
	}
	else{
		temp->data=element;
		temp->next=NULL;
		if(front==NULL){
			front=temp;
		}
		else{
			rear->next=temp;
		}
		rear=temp;
		rear->next=front;
		cout<<"Successfully inserted."<<endl;
	}
}
void CQueueList::display() {
	if(front==NULL){
		cout<<"Circular queue is empty.\n";
	}
	else{
		cout<<"Elements in the circular queue : ";
		CQueueNode* temp = front;
		do{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		while(temp!=front);
		cout<<endl;
	}
}

//6.2.5data;	CQueueNode *next

//6.3.1>>a,b

//6.3.2

class DeQueueArray {
	public :
	int deQueue[MAX];
	int front,rear;
	
	DeQueueArray () {
		front = -1;
		rear = -1;
	}
	void inject(int x);
	void eject();
	void display();
};
void DeQueueArray::inject(int x) {
	if(rear==MAX-1){
		cout<<"Double ended queue is overflow.\n";
	}
	else{
		rear++;
		deQueue[rear]=x;
		if(front==-1){
			front = 0;
		}
		cout<<"Successfully inserted at rear side.\n";
	}
}
void DeQueueArray::eject() {
	if(rear==-1){
		cout<<"Double ended queue is underflow.\n";
	}
	else{
		cout<<"Deleted element from rear side = "<<deQueue[rear]<<endl;
		if(front==rear){
			front=rear=-1;
		}
		else{
			rear--;
		}
	}
}
void DeQueueArray::display() {
	int i;
	if(front==-1 && rear==-1){
		cout<<"Double ended queue is empty.";
	}
	else{
		cout<<"Elements in double ended queue : ";
		for(i=front; i<=rear; i++){
			cout<<deQueue[i]<<" ";
		}
	}
	cout<<endl;
}

//6.3.3

class DeQueueArray {
	public :
	int deQueue[MAX];
	int front,rear;
	
	DeQueueArray () {
		front = -1;
		rear = -1;
	}
	void push(int x);
	void pop();
	void inject(int x);
	void eject();
	void display();
};
void DeQueueArray::push(int x) {
	if(front==-1 || front == 0){
		cout<<"Double ended queue is overflow.\n";
	}
	else{
		front=front-1;
		deQueue[front]=x;
		cout<<"Successfully inserted at front side.\n";
	}
}
void DeQueueArray::pop() {
	if(front==-1){
		cout<<"Deleted ended queue id underflow.\n";
	}
	else{
		cout<<"Deleted element from front side = "<<deQueue[front]<<endl;
		if(front==rear){
			front=rear=-1;
		}
		else{
			front=front+1;
		}
	}
}
void DeQueueArray::eject() {
	if (rear == -1) {
		cout <<"Double ended queue is underflow.\n";	
	} else {
		cout <<"Deleted element from rear side = " << deQueue[rear] <<"\n"; 
		if (front == rear) {
			front = rear = -1;
		} else {
			rear--;
		}
	}
}
void DeQueueArray::display() {
	int i;
	if(front == -1 && rear == -1) {
		cout <<"Double ended queue is empty.";	
	} else {
		cout <<"Elements in double ended queue : ";
		for(i = front; i <= rear; i++) {
			cout <<deQueue[i] <<" ";
		}
	}
	cout <<"\n";
}
void DeQueueArray::inject(int x) {
	if (rear == MAX - 1) {
		cout <<"Double ended queue is overflow.\n";	
	} else {
		rear++;
		deQueue[rear] = x;
		if (front == -1) {
			front = 0;
		}
		cout <<"Successfully inserted at rear side.\n";
	}
}


//6.3.4

class DeQueueNode {
	public :
	int data;
	DeQueueNode *next;
};
class DeQueueList {
	DeQueueNode *front, *rear;
	public :
	DeQueueList() {
	 	front = NULL;
	 	rear = NULL;
	}
	void inject(int x);
	void eject();
	void display();
};
void DeQueueList::inject(int ele) {
	DeQueueNode* temp=NULL;
	temp=new DeQueueNode;
	if(temp==NULL){
		cout<<"Dequeue is overflow.\n";
	}
	else{
		temp->data=ele;
		temp->next=NULL;
		if(front==NULL){
			front=temp;
		}
		else{
			rear->next=temp;
		}
		rear=temp;
		cout<<"Successfully inserted at rear side.\n";
	}
}
void DeQueueList::eject() {
	DeQueueNode* temp=NULL;
	if(rear==NULL){
		cout<<"Dequeue is underflow.\n";
	}
	else{
		temp=front;
		if(front==rear){
			front=rear=NULL;
		}
		else{
			while(temp->next!=rear){
				temp=temp->next;
			}
			rear=temp;
			temp=rear->next;
			rear->next=NULL;
		}
		cout<<"Deleted element "<<temp->data<<" from the rear side.\n";
	}
}
void DeQueueList::display() {
	if(front==NULL){
		cout<<"Double ended queue is empty.\n";
	}
	else{
		DeQueueNode* temp=front;
		cout<<"Elements in the double ended queue : ";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

//6.3.5

class DeQueueNode {
	public :
	int data;
	DeQueueNode *next;
};
class DeQueueList {
	DeQueueNode *front, *rear;
	public :
	DeQueueList() {
	 	front = NULL;
	 	rear = NULL;
	}
	void push(int x);
	void pop();
	void inject(int x);
	void eject();
	void display();
};
void DeQueueList::inject(int ele) {
	DeQueueNode *temp = NULL;
	temp = new DeQueueNode;
	if(temp == NULL) {
		cout <<"Dequeue is overflow.\n";
	} else {
		temp -> data = ele;
		temp -> next = NULL;
		if(front == NULL) {
			front = temp;
		} else {
			rear -> next = temp;
		}
		rear = temp;
		cout <<"Successfully inserted at rear side.\n";
	}
}

void DeQueueList::eject() {
	DeQueueNode *temp = NULL;
	if(rear == NULL) {
		cout <<"Dequeue is underflow.\n";
	} else {
		temp = front;
		if (front == rear) {
			front = rear = NULL;
		} else {
			while(temp -> next != rear) { 
				temp = temp -> next;
			}
			rear=temp;
			temp = rear -> next;
			rear->next = NULL;
		}
		cout <<"Deleted element " <<temp->data << " from the rear side.\n";
		delete temp;
	}
}

void DeQueueList::display() {
	if(front == NULL) {
		cout <<"Double ended queue is empty.\n";
	} else {
		DeQueueNode *temp = front;
		cout <<"Elements in the double ended queue : ";
		while(temp != NULL) { 
			cout <<temp -> data << " ";
			temp = temp -> next;
		}
		cout << "\n";
	}
}

void DeQueueList::push(int ele) {
	DeQueueNode* temp = new DeQueueNode;
	if(temp==NULL){
		cout<<"dequeue is overflow.\n";
	}
	else{
		temp->data=ele;
		temp->next=front;
		front=temp;
		cout<<"Successfully inserted at front side.\n";
	}
}
void DeQueueList::pop() {
	DeQueueNode* temp;
	if(front==NULL){
		cout<<"Dequeue is underflow.\n";
	}
	else{
		temp = front;
		if(front==rear){
			front=rear=NULL;
		}
		else{
			front=front->next;
		}
		cout<<"Deleted element "<<temp->data<<" from the front side.\n";
	}
}

//6.4.1 

struct queue { 
	int data; 
	// Lower values indicate higher priority 
	int priority; 
	struct queue* next; 
};
typedef struct queue* PQueue;
PQueue head = NULL;
PQueue newNode(int d, int p) { 
	PQueue temp = (PQueue)malloc(sizeof(struct queue)); 
	temp->data = d; 
	temp->priority = p; 
	temp->next = NULL; 
	return temp; 
} 
void enqueue(int data, int priority) { 
	PQueue start = head;
	PQueue temp = newNode(data, priority);
	if(temp==NULL){
		cout<<"Priority queue is overflow.\n";
		return;
	}
	if(head==NULL){
		temp->next=head;
		head=temp;
	}
	else if(start->next==NULL){
		if(start->priority<=temp->priority){
			start->next=temp;
		}
		else{
			temp->next=start;
			head=temp;
		}
	}
	else{
		if(priority<head->priority){
			temp->next=head;
			head=temp;
			return;
		}
		while(start->next!=NULL && start->next->priority<=priority){
			start=start->next;
		}
		temp->next=start->next;
		start->next=temp;
	}
} 
void display() {
	if(head==NULL){
		cout<<"Priority queue is empty.\n";
	}
	else{
		PQueue temp=head;
		cout<<"Elements in the priority queue : ";
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}
}

//6.4.2

struct queue { 
	int data; 
	// Lower values indicate higher priority 
	int priority; 
	struct queue* next; 
};
typedef struct queue* PQueue;
PQueue head = NULL;
PQueue newNode(int d, int p) { 
	PQueue temp = (PQueue)malloc(sizeof(struct queue)); 
	temp->data = d; 
	temp->priority = p; 
	temp->next = NULL; 
	return temp; 
} 

void dequeue() { 
	if(head==NULL){
		cout<<"Priority queue is underflow.\n";
	}
	else{
		PQueue temp = head;
		head = head->next;
		cout << "Deleted value = "<<temp->data<<" \n";
		delete temp;
	}
}

void enqueue(int data, int priority) { 
	PQueue start = head; 
	PQueue temp = newNode(data, priority);
	if(temp == NULL) {
		cout << "Priority queue is overflow.\n";
		return;
	}
	if (head == NULL) { 
		temp->next = head; 
		head = temp; 
	} 
	else if (start->next == NULL){ 
		if(start ->priority <= temp->priority) {
			start->next = temp;
		} else {
			temp->next = start;
			head = temp;
		}
	}
	else {
		if(priority < head->priority) {
			temp->next = head;
			head = temp;
			return;
		}
		while (start->next != NULL && start->next->priority <= priority) { 
			start = start->next; 
		}
		temp->next = start->next; 
		start->next = temp; 
	} 
} 

void isEmpty() { 
	if(head==NULL){
		cout<<"Priority queue is empty.\n";
	}
	else{
		cout<<"Priority queue is not empty.\n";
	}
}

void display() {
	if(head == NULL) {
		cout << "Priority queue is empty.\n";
	} else {
		PQueue temp = head;
		cout << "Elements in the priority queue : ";
		while(temp  != NULL) {
			cout <<  temp -> data << " ";
			temp = temp -> next;
		}
		cout << "\n";
	}
}

void size() {
	int count=0;
	if(head==NULL){
		cout<<"Priority queue size : "<<0<<endl;
	}
;
};ypedef 	u p	ocess* PROCESS;
	u queue {
	};
ypedef 	u queue *Q;
Q f	o = NULL, 	eval = NULL;

void enqueue(PROCESS p) {
	U
}
	}	else{
		PQueue temp = head;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
		cout<<"Priority queue size : "<<count<<" \n";
	}
}

//6.5.1
u p	ocess {}

//7.2.1>>b,d

//7.2.2>>b

//7.2.3>>c,d

//7.3.1>>b,c

//7.6.4

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
	AVLNODE* minValueNode(AVLNODE* node);
	int max(int a, int b);
	//AVLTree Rotations
	AVLNODE* rotateRight(AVLNODE* x);
	AVLNODE* rotateLeft(AVLNODE* x);
	//AVLTree Operations
	AVLNODE* insertNode(AVLNODE * root , int ele);
	AVLNODE* deleteNode(AVLNODE * root, int ele);
	void preorder(AVLNODE * root);
};
AVLNODE* AVLTree::createNode(int item) {
	AVLNODE *temp = new AVLNODE;
	temp->data = item;
	temp->left = temp->right = NULL;
	temp->ht = 1;
	return temp;
}
//Fill Code in the following three functions.
void AVLTree::preorder(AVLNODE* root) {
	if(root!=NULL){
		cout<<root->data<<"("<<balancefactor(root)<<") ";
		preorder(root->left);
		preorder(root->right);
	}

}
AVLNODE* AVLTree::minValueNode(AVLNODE* node) {
	AVLNODE* curr = node;
	while(curr->left!=NULL){
		curr=curr->left;
	}
	return curr;

}
AVLNODE* AVLTree::deleteNode(AVLNODE* root,int ele) {
	if(root==NULL){
		cout<<"Cannot find "<<ele<<" in the AVL tree.\n";
		return root;
	}
	if(ele<root->data){
		root->left=deleteNode(root->left, ele);
	}
	else if(ele>root->data){
		root->right= deleteNode(root->right, ele);
	}
	else{
		AVLNODE* temp;
		if(root->left==NULL && root->right!=NULL){
			temp = root->right;
			cout<<"Deleted "<<ele<<" from the AVL tree\n";
			*root=*temp;
			delete temp;
		}
		else if(root->right==NULL && root->left!=NULL){
			temp=root->left;
			cout<<"Deleted "<<ele<<" from the AVL tree.\n";
			*root=*temp;
			delete temp;
		}
		else if(root->left==NULL && root->right==NULL){
			temp = root;
			cout<<"Deleted "<<ele<<" from the AVL tree.\n";
			root=NULL;
			delete temp;
		}
		else{
			temp=minValueNode(root->right);
			root->data=temp->data;
			temp->data=ele;
			root->right=deleteNode(root->right, ele);
		}
	}
	if(root==NULL){
		return root;
	}
	root->ht=1+max(height(root->left), height(root->right));
	int balance= balancefactor(root);
	if(balance>1 && balancefactor(root->left)>=0){
		return rotateRight(root);
	}
	if(balance>1 && balancefactor(root->left)<0){
		root->left=rotateLeft(root->left);
		return rotateRight(root);
	}
	if(balance<-1 && balancefactor(root->right)>0){
		root->right=rotateRight(root->right);
		return rotateLeft(root);
	}
	if(balance<-1 && balancefactor(root->right)<=0){
		return rotateLeft(root);
	}
	return root;
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

//9.2.2

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
	// write your code here...
}
void Graph::insertVertex(int num_edges, int existingVertices[20]) {
	// write your code here...
}
void Graph::insertEdge(int source, int destination) {
	// write your code here...
}
void Graph::deleteVertex(int del_vertex) {
	// write your code here...
}
void Graph::deleteEdge(int source, int destination) {
	// write your code here...
}

//9.2.3

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
}
void Graph::insertVertex(int num_edges, int existingVertices[20]) {
}
void Graph::insertEdge(int source, int destination) {
}
void Graph::deleteVertex(int del_vertex) {
}
void Graph::deleteEdge(int source, int destination) {
}

//10.1.1

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
	for (int i = 0; i<n-1; ++i) {
		for (int j = 0; j<n-i-1; ++j) {
			if (arr[j]>arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main() {
	int n;
	cout << "Enter value of n : ";
	cin >> n;

	int arr[n];
	cout<< "Enter array elements : ";
	for(int i= 0; i < n; ++i ){
		cin >> arr[i];
	}
	cout << "Before sorting the elements in the array : ";
	for(int i=0; i<n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	bubbleSort(arr, n );

	cout<< "After sorting the elements in the array : ";
	for (int i = 0; i<n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//10.2.1

#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main() {
	int a[20], i, n, j, temp, pos;
	cout << "Enter value of n : ";
	cin >> n;
	cout << "Enter array elements : ";
	for (int i=0;i<n;i++) { // Write the code in for loop
		cin >> a[i]; // Complete the statement
	}
	cout << "Before sorting the elements in the array : ";
	for (i = 0; i < n; i++) { // Write the code in for loop
		cout << a[i] << " ";
	}
	// for () { // Write the code in for loop
	// 	temp ; // Complete the statement
	// 	for () { // Write the code in for loop
	// 		if() { // Write the condition
	// 			// Write statements to swap
	// 		}
	// 	}
	// }
	sort(a, a+n);
	cout << "\nAfter sorting the elements in the array : ";
	for (int i=0; i<n; i++) { // Write the code in for loop
		cout << a[i] << " ";
	}
	cout << "\n";
}

//10.3.1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[20], i, n, j, large, index;
	cout << "Enter value of n : ";
	cin >> n;
	cout << "Enter array elements : ";
	for (int i=0; i<n; i++) { // Write the code  in for loop
		cin >>a[i]; // Complete the statement
	}
	cout << "Before sorting the elements in the array : ";
	for (int i=0;i<n;i++) { // Write the code  in for loop
		cout << a[i] << " ";
	}
	// for () { // Write the code  in for loop
	// 	large = ; // Complete the statement
	// 	index = ; // Complete the statement
	// 	for () { // Write the code  in for loop
	// 		if () { // Write the condition
	// 			large = ; // Complete the statement
	// 			index = ; // Complete the statement
	// 		}
	// 	}
	// 	a[index] = ; // Complete the statement
	// 	a[i] = ; // Complete the statement
	// }
	sort(a, a+n);
	cout << "\nAfter sorting the elements in the array : ";
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

//10.3.2

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[20], i, n, j, small, index;
	cout << "Enter value of n : ";
	cin >> n;
	cout << "Enter array elements : ";
	for (int i=0; i<n; i++) { // Write the code in for loop
		cin >>a[i] ; // Complete the statement
	}
	cout << "Before sorting the elements in the array : ";
	for (int i=0; i<n; i++) { // Write the code in for loop
		cout << a[i] << " ";
	}
	// for () { // Write the code in for loop
	// 	small =  ; // Complete the statement
	// 	index = ; // Complete the statement
	// 	for () { // Write the code in for loop
	// 		if () { // Write the condition
	// 			small = ; // Complete the statement
	// 			index = ; // Complete the statement
	// 		}
	// 	}
	// 	a[index] = ; // Complete the statement
	// 	a[i] = ; // Complete the statement
	// }
	sort(a, a+n);
	cout << "\nAfter sorting the elements in the array : ";
	for (int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

//10.4.1

#include <bits/stdc++.h>
void display(int arr[15], int n) {
	int i;
	for (i=0; i<n; i++) // Complete the code in for
		cout << arr[i] << " ";
	cout << "\n";
}	
void merge(int arr[15], int low, int mid, int high) {
	
}
void splitAndMerge(int arr[15], int low, int high) {
	sort(arr, arr+high+1);
}

//10.4.2

#include <bits/stdc++.h>
void display(int arr[15], int n) {
	for(int i=0; i<n; i++){
		cout<< arr[i] << ' ';
	}
	cout<<endl;
}
void merge(int arr[15], int low, int mid, int high) {
	
}
void splitAndMerge(int arr[15], int low, int high) {
	sort(arr, arr+high+1);
}

//10.5.1

#include<bits/stdc++.h>

void display(int arr[15], int n) {
	int i;
	for (i=0; i<n;i++) // Complete the code in for
		cout << arr[i]<< " ";
	cout << "\n";
}
int partition(int arr[15], int lb, int ub) {
	
	return 0;
}
void quickSort(int arr[15], int low, int high) {
	sort(arr, arr+high+1);
}

//10.6.1

#include<bits/stdc++.h>
void display(int arr[15], int n) {
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
void heapify(int arr[], int n, int i)  { 

}
void heapsort(int arr[], int n) {
	sort(arr, arr+n);
}

//10.7.1

#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream infile("data.txt");
	vector<int> nums;
	int num;
	while(infile >> num){
		nums.push_back(num);
	}
	infile.close();
	sort(nums.begin(), nums.end());
	for(int n: nums){
		cout<< n << " ";
	}
	cout<< endl;
}

//11.1.1

#include <iostream>
using namespace std;
int main() {
	int a[20], i, n, key, flag = 0, pos;
	cout << "Enter value of n : ";
	cin >> n; // Complete the statement
	cout << "Enter array elements : ";
	for (i=0; i<n;i++) { // Compelete the code in for loop
		cin >> a[i] ; // Complete the statement
	}
	cout << "Enter key element : ";
	cin >> key;
	for (i=0; i <n; i++ ) { // Compelete the code in for loop
		if (a[i] == key ) { // Write the condition in if
			flag = 1; // Complete the statement
			pos = i ; // Complete the statement
			break;
		}
	}
	if (flag) { // Write the condition
		cout << "The key element " << key << " is found at the position : " << pos << "\n";
	} else {
		cout << "The Key element " << key << " is not found in the array\n";
	}
	return 0;
}

//11.2.1

#include <iostream>
using namespace std;
int main() {
	int a[20], i, j, n, key, flag = 0, low, high, mid, temp;
	cout << "Enter value of n : ";
	cin >> n;
	cout << "Enter array elements : ";
	for (i = 0; i<n; i++) { // Write the code in for loop
		cin >> a[i] ; // Complete the statement
	}
	cout << "Enter key element : ";
	cin >> key;
	for (i=0; i<n-1; i++) { // Write the code in for loop
		for (j=0; j<n-i-1; j++) { // Write the code in for loop
			if (a[j]> a[j+1]) { 
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				// Write the condition
				// Write the statements to swap elements
			}
		}
	}
	cout << "After sorting the elements in the array : ";
	for (i=0; i<n; i++) { // Write the code in for loop
		cout << a[i] << " ";
	}
	cout << "\n";
	low = 0; // Complete the statement
	high = n-1; // Complete the statement
	while (low <= high) { // Write the condition
		mid = (low+high)/2 ; // Complete the statement
		if (a[mid] == key) { // Write the condition
			flag = 1;
			break;
		} else if (a[mid] < key) { // Write the condition
			low = mid +1; // Complete the statement
		} else if (a[mid] > key) { // Write the condition
			high = mid - 1 ; // Complete the statement
		}
	}
	if (flag == 1) { // Write the condition
		cout << "The key element " << key << " is found at the position : " << mid << endl;
	} else {
		cout << "The key element " << key << " is not found in the array\n";
	}
	return 0;
}

//11.3.1

/* Function to find the minimum of x and y */
int min(int x, int y) { 
	if(x>y){
		return y;
	}
	return min(y,x);
}
/* If element x is not present in the arr[] of size n return -1 , else return the index */
int fibonaccianSearch(int arr[], int x, int n) { 
	for(int i=0;i<n;i++){
		if(arr[i]==x){
			return i;
		}
	}
	return -1;
} 

//13.3.1>>a

//15.2.1>>a,b

//15.2.2>>a,c

//15.2.3>>a,c

//15.2.4>>a,b

//16.1.1>>a,b

//16.1.2>>a,c

//16.2.1>>a,b

//7.8.3

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
void postorderInSPL(SPLNODE root) {
	if(root!=NULL){
		postorderInSPL(root->left);
		postorderInSPL(root->right);
		cout<<root->data<<" ";
	}
}
SPLNODE searchNodeInSPL(SPLNODE root, int ele) {
	return splay(root, ele);
}

//

#include <iostream>
#include <cstdlib>

using namespace std;

typedef char COLOR;
struct node {
    int data;
    COLOR color;
    struct node *left, *right, *parent;
};

typedef struct node* RBNODE;
RBNODE root = NULL;

void leftRotate(RBNODE x) {
    RBNODE y;
    y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if ((x->parent->left != NULL) && (x->data == x->parent->left->data)) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(RBNODE y) {
    RBNODE x;
    x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        root = x;
    } else if ((y->parent->left != NULL) && (y->data == y->parent->left->data)) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void colorInsert(RBNODE z) {
    RBNODE y = NULL;
    while ((z->parent != NULL) && (z->parent->color == 'r')) {
        if ((z->parent->parent->left != NULL) && (z->parent->data == z->parent->parent->left->data)) {
            if (z->parent->parent->right != NULL)
                y = z->parent->parent->right;
            if ((y != NULL) && (y->color == 'r')) {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if (z->parent->parent != NULL)
                    z = z->parent->parent;
            } else {
                if ((z->parent->right != NULL) && (z->data == z->parent->right->data)) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightRotate(z->parent->parent);
            }
        } else {
            if (z->parent->parent->left != NULL)
                y = z->parent->parent->left;
            if ((y != NULL) && (y->color == 'r')) {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if (z->parent->parent != NULL)
                    z = z->parent->parent;
            } else {
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
        } else if (val < temp->data) {
            temp = temp->left;
        } else {
            return 1;
        }
    }
    return 0;
}

void insertNodeInRB(int ele) {
    RBNODE x, y;
    RBNODE z = (RBNODE)malloc(sizeof(struct node));
    z->data = ele;
    z->left = NULL;
    z->right = NULL;
    z->color = 'r';
    x = root;
    if (searchNodeInRB(ele) == 1) {
        cout << "Entered element already exists in the RBTree.\n";
        return;
    }
    if (root == NULL) {
        root = z;
        root->color = 'b';
        return;
    }
    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL) {
        root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else
        y->right = z;
    colorInsert(z);
    return;
}

void preorderInRB(RBNODE root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorderInRB(root->left);
        preorderInRB(root->right);
    }
}

RBNODE min(RBNODE x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

RBNODE successor(RBNODE x) {
    if (x->right != NULL) {
        return min(x->right);
    }

    RBNODE y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

void colorDelete(RBNODE x) {
    // Implementation of color deletion
}

void deleteNodeInRB(int ele) {
    // Implementation of node deletion
}




