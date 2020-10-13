#include<iostream>
using namespace std;
void i_n()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
*************STACK - ARRAY REPRESENTATION ************************
class stack {
	int *p;
	int top;
	int maxsize;
public :
	stack(int defaultsize = 5) {
		this->maxsize = defaultsize;
		this->p = new int[maxsize];
		this->top = -1;
	}
	void push(int data) {
		if (top == maxsize - 1) {
			cout << "Overflow" << endl;
			return;
		}
		this->p[++top] = data;
	}
	void pop() {
		if (top == -1) {
			cout << "Underflow" << endl;
			return;
		}
		this->top--;
	}
	int size() {
		return this->top + 1;
	}
	bool isempty() {
		return this->size() == 0;
	}
	int gettop() {

		return this->p[top];
	}
};

int main() {
	i_n();
	stack s(3);
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.isempty() << endl;;
	cout << s.size() << endl;
	cout << s.gettop() << endl;
}


*************STACK - LINKED LIST REPRESENTATION ************************


class node {
public :

	int data;
	node* next;

	node(int data) {
		this->data = data;
		next = nullptr;
	}

};
void removeduplicates(node *&head)
{
	node* temp1;
	node* temp2;
	node* remove;
	temp1 = head;

	while (temp1 && temp1->next)
	{
		temp2 = temp1;
		while (temp2->next)
		{
			if (temp1->data == temp2->next->data)
			{
				remove = temp2->next;
				temp2->next = temp2->next->next;
				delete(remove);
			}
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}


void push(node* &head, int ndata) {
	node *n = new node(ndata);
	n->next = head;
	head = n;
}
int pop(node *&head) {
	if (!head) {
		cout << "Underflow" << endl;
		return -1;
	}
	node *n = head;
	head = head ->next;
	delete n;
}
int traverse(node* head) {
	if (head == nullptr) {
		return -1;
	} else {
		return head->data;
	}
}
bool empty(node *head) {
	return head == nullptr;
}
void clear(node* &head) {
	if (!head) {
		return;
	}
	node* temp = head;
	while (temp) {
		node* n = temp;
		temp = temp->next;
		delete n;
	}
}
int main() {
	i_n();
node* s = nullptr;
pop(s);
push(s, 1);
cout << traverse(s) << endl;
push(s, 2);
push(s, 3);
push(s, 1);
// cout << empty(s) << endl;;
// cout << s.size() << endl;
cout << traverse(s) << endl;

removeduplicates(s);
cout << traverse(s) << endl;


}


*************QUEUE - ARRAY REPRESENTATION ************************


class queue {
	int *arr;
	int front, rear;
	int maxsize;
public :
	queue(int defaultsize = 3) {
		front = 0;
		rear = -1;
		this->maxsize = defaultsize;
		this->arr = new int[maxsize];
	}
	void push(int data) {
		if (rear == maxsize - 1) {
			cout << "Overflow" << endl;
			return;
		}
		this -> arr[++rear] = data;
	}
	void pop() {
		if (front > rear) {
			cout << "Underflow" << endl;
			return;
		}
		front++;
	}
	int getfront() {
		if (front > rear) {
			return -1;
		}
		return this->arr[front];
	}
};
int main() {
	i_n();
	queue q;
	q.pop();
	cout << q.getfront() << endl;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.getfront() << endl;
	q.pop();
	q.pop();
	cout << q.getfront() << endl;
	q.pop();
	q.pop();

}


*************QUEUE - LINKEDLIST REPRESENTATION ************************

#include <bits/stdc++.h>
using namespace std;
class node {
public :
	int data;
	node* next;
	node(int data) {
		this->data = data;
		next = nullptr;
	}
};

class Queue {
	node *front, *rear;

public :
	Queue() {
		front = nullptr;
		rear = nullptr;
	}
	void push(int data) {
		node* n = new node(data);
		if (front == nullptr) {
			front = rear = n;
			return;
		}
		rear->next = n;
		rear = n;
	}
	void pop() {
		if (front == nullptr) {
			cout << "Underflow" << endl;
			return;
		}
		node* n = front;
		front = front->next;
		if (front == nullptr) rear = nullptr;
		delete n;
	}
	int getfront() {
		if (front == nullptr) {
			return -1;
		}
		return front->data;
	}
};

int main() {
	Queue Q;
	Q.pop();
	cout << Q.getfront() << endl;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	cout << Q.getfront() << endl;
	Q.pop();
	Q.pop();
	cout << Q.getfront() << endl;
	Q.pop();
	Q.pop();
}


*************CIRCULAR QUEUE - ARRAY REPRESENTATION ************************




class queue
{
	int *arr;
	int front, rear, maxsize;
	int currsize;
public:
	queue(int defaultsize = 3) {
		this->maxsize = defaultsize;
		this->arr = new int[maxsize];
		this->front = 0;
		this->rear = -1;
		this->currsize = 0;
	}
	void push(int data) {
		if (this->currsize == this->maxsize) {
			cout << "Overflow" << endl;
			return;
		}
		this->rear = (this->rear + 1) % this->maxsize;
		this->arr[rear] = data;
		this->currsize++;
	}
	void pop() {
		if (this->currsize == 0) {
			cout << "Underflow" << endl;
			return;
		}
		this->front = (this->front + 1) % this->maxsize;
		this->currsize--;
	}
	int getfront() {
		if (this->currsize == 0) {
			return -1;
		}
		return this-> arr[this->front];
	}
	bool isempty() {
		return this->currsize == 0;
	}
	int size() {
		return this->currsize;
	}
};

int main() {
	i_n();
	queue q;
	q.pop();
	q.push(1);
	q.push(2);
	cout << q.getfront() << endl;
	q.push(3);
	q.push(4);
	q.pop();
	q.pop();
	cout << q.size() << endl;
	q.push(4);
	q.push(5);
	q.pop();
	cout << q.getfront() << endl;
	q.push(6);
	q.pop();
	cout << q.size() << endl;
	cout << q.isempty() << endl;
}



********************** LINKEDLIST IMPLEMENTATION ****************


class node {
public :
	int data;
	node* next;
	node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

void insertathead(node* &head, int data) {
	node* n = new node(data);
	n->next = head;
	head = n;
}
void insertrattail(node* &head, int data) {
	if (head == nullptr) {
		insertathead(head, data);
		return;
	}
	node* temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	node* n = new node(data);
	temp->next = n;
}
void insertaftergivenindex(node* &head, int positon, int data) {
	// if user gives position greater than the length of list then
	// either don't insert or insert at the end

	// here, i am not inserting
	// 1 based indexing (0 position not allowed)
	node* temp = head;
	for (int i = 1; i < positon; i++) {
		temp = temp->next;
		if (temp == nullptr) {
			return;
		}
	}
	node *n = new node(data);
	n->next = temp->next;
	temp->next = n;
}
void insertbeforegivenindex(node* &head, int position, int data) {
	if (position == 1) {
		insertathead(head, data);
		return;
	}

	node* temp = head;
	for (int i = 1; i < position - 1; i++) {
		temp = temp->next;
		if (temp == nullptr) {
			return;
		}
	}
	node *n = new node(data);
	n->next = temp->next;
	temp->next = n;
}

void display(node *head) {
	node* temp = head;
	while (temp) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}
void deleteathead(node* &head){
	if(node == nullptr) {
		cout << "Underflow" << endl;
	}
	node* temp = head;
	head = head->next;
	delete temp;
}
void deleteattail(node* &head) {
	node* temp = head;

	while(temp->next->next!=nullptr){
		temp = temp->next;
	}

	node* toBeDeleted = temp->next;
	temp->next = NULL;
	delete toBeDeleted;
}
void deletebeforegivenindex(node *head, int position, int data) {
	if(position == 1) {
		cout << "Underflow" << endl;
		return;
	}

}
void deleteaftergivenindex(node *head, int position, int data) {

}
int main() {
	i_n();
	node* head = nullptr;
	insertrattail(head, 1);
	insertathead(head, 2);
	insertathead(head, 3);
	insertrattail(head, 4);
	display(head);
	insertbeforegivenindex(head, 1, 5);
	insertbeforegivenindex(head, 5, 6);
	display(head);
	insertaftergivenindex(head, 1, 7);
	insertaftergivenindex(head, 7, 8);
	display(head);

}

class node{
	public :
	int data;
	node* next;
	node* prev;
	node(data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
}
void insertathead(node * &head, int data) {
	node* n = new node(data);
	n ->next = head;
	if(head) head->prev = n;
	head = n;
}
void insertattail(node * &head, int data) {
	if(!head) {
		insertathead(head, data);
		return;
	}
	node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	node *n = new node(data);
	temp->next = n;
	n->prev = temp;
}
void deleteathead(node* & head) {
	if(!head) {
		cout << "Underflow" << endl;
		return;
 	}
 	node* n = head;
 	head = head->next;
 	head ->prev = nullptr;
 	delete n;
}
void deleteattail(node* &head) {
	if(!head) {
		cout << "Underflow" << endl;
		return;
 	}
 	if(!temp->next){
 		head = nullptr;
 	}
 	while(temp->next->next){
 		temp = temp->next;
 	}
 	node* n = temp->next;
 	temp->next = nullptr;
 	delete n;
}

class node
{
	int data;
	node* next;
public:
	node(int data){
		this->data = data;
		this->next = nullptr;
	}

};
void insertathead(node* &head, int data) {
	node* n = new node(data);
	if(!head) {
		return;
	}

}
