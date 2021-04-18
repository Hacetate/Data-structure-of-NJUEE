#include "LinkList.h"

/*
Args:
* head:pointer of the head node.
Return:
* True or false.
Description:
* Create an empty linked list with a head node.
* The "next" field of the head node should point to NULL.
*/
_Bool CreateEmptyList(Node** head)
{
	Node *h;
	h = (Node*)malloc(sizeof(Node));
	h->next = NULL;
	*head = h;
	
	return true;
}


/*
Args:
* addr: pointer of an array.
* n: length of the array.
* head:pointer of the head node.
Return:
* True or false.
Description:
* Initialize a linked list with an array.
*/
_Bool CreateList(DataType *addr, unsigned int n, Node** head)
{
	
	Node* p,*q,*h;
	CreateEmptyList(&h);
	p = h;
	for (int i = 0; i < n; i++) {
		q = (Node*)malloc(sizeof(Node));
		q->data = *(addr + i);
		p->next = q;
		p = p->next;
	}
	p->next = NULL;
	*head = h;
	return true;
}


/*
Args:
* head: pointer of the head node.
Returns:
* True or false.
Description:
* Destroy the linked list.
* Release all allocated memory.
*/
_Bool DestroyList(Node *head)
{
	Node* p, * q;
	q = p = head;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the inserted data.
* data: the inserted data.
Returns:
* True or false.
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 0, 6), the linked
* list will be "head->6->3->5->2".
*/
_Bool ListInsert(Node *head, unsigned int index, DataType e)
{
	Node* new,*p;
	new = (Node*)malloc(sizeof(Node));
	new->data = e;
	p = head;
	for (int i = 0; i < index && p != NULL; i++)p = p->next;
	new->next = p->next;
	p->next = new;

	
	return true;
}


/*
Args:
* head: pointer of the head node.
* index: index of the deleted data.
* e:The deleted data.
Returns:
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 2), the linked
* list will be "head->3->5".
*/
_Bool ListDelete(Node *head, unsigned int index, DataType* e)
{
	Node* p,*q;
	p = head->next;
	q = head;
	for (int i = 0; i < index && p != NULL; i++) {
		q = p;
		p = p->next;
	}
	q->next = p->next;
	*e = p->data;
	free(p);
	

	return true;
}
