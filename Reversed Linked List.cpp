#include<bits/stdc++.h>
using namespace std;

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

/*
Method 1: Using Vector and Indexing */

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Node;

void linkedlistTraversal(struct Node* head)
{
	struct Node* ptr = head;
	while(ptr != NULL)
	{
		cout<<ptr->data<<' ';
		ptr = ptr->next;
	}
	cout<<endl;
}

struct Node* createNode(int val)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = val;
	n->next = NULL;
	return n;
}




Node* ReverseList(Node* head)
{

	Node* ptr = head;
	vector<int> v1;
	
	while(ptr->next != NULL)
	{
		v1.push_back(ptr->data);
		ptr = ptr->next;
	}
	v1.push_back(ptr->data);
	int i=v1.size()-1;
	ptr = head;
	while(i>=0 && ptr->next != NULL)
	{
		ptr->data = v1[i];
		ptr = ptr->next;
		i--;
	}
	ptr->data = v1[0];
	ptr = head; 
	return ptr;
}



int main()
{
	// Creation of Linked list
	Node* head = createNode(1);							//Creation of head node that is must needed to reverse the string
	Node* first = createNode(2);						
	Node* second = createNode(3);
	Node* third = createNode(4);
	Node* fourth = createNode(5);
	head->next = first;									// Chaining of nodes
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	linkedlistTraversal(head); 							// Linked List traversal before reversing
	head = ReverseList(head);							// Reverse function called
	linkedlistTraversal(head); 							// Linked List after Traversing
	return 0;
}
