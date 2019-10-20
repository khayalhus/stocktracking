#include <iostream> // needed for input and output operations
#include <stdlib.h> // needed for EXIT_SUCCESS and EXIT_FAILURE macros
#include <stdio.h> // needed for file operation functions

#include "list.h" // includes List struct

using namespace std;

list stock; //create a Linked List called stock

int main () {
	stock.create(); // initialize some variables
	stock.open_file(); // opens file
	stock.read_file(); // reads and closes file
	stock.clear(); // deletes all of the nodes of the list
	return EXIT_SUCCESS;
}

void list::create() {
	head = NULL;
	nodecount = 0;
}

void list::open_file () {
	tracker = fopen("input.txt", "r+");
	if(!tracker){
		cerr << "Error: Unable to read file" << endl;
		exit(EXIT_FAILURE);
	}
}

void list::read_file () {
	int k;
	while (!feof(tracker)) {
		fscanf(tracker, " %d", &k);
		if(k == 0) {
			current_stock();
		} else if (k > 0) {
			add_stock(k);
		} else {
			sell(-k);
		}
	}
	fclose(tracker);
}

void list::add_stock(int size){	
	if(head){
		node *traverse, *tail;
		tail = NULL;
		traverse = head;
		while(traverse){
			if (traverse->size == size) {
				traverse->quant++; // increase quantity by 1 of a shoe that is already in stock
				return;
			} else if (traverse->size > size) {
				node *newnode = new node; // add a node for a shoe that is not available in stock
				newnode->size = size;
				newnode->quant = 1;
				if(tail) {
					tail->next = newnode; // if tail points to something, make it point to recently inserted node
				} else {
					head = newnode; // if tail is NULL, then this node is the smallest shoe size
				}
				newnode->next = traverse;
				nodecount++;
				return;
			}
			tail = traverse;
			traverse = traverse->next;
		}
		node *newnode = new node; // add a node at the end of the list, if the shoe size is the biggest in stock
		newnode->size = size;
		newnode->quant = 1;
		newnode->next = NULL;
		tail->next = newnode;
		nodecount++;
	} else {
		node* newnode = new node; // add the first node as the head node
		newnode->size = size;
		newnode->quant = 1;
		newnode->next = NULL;
		head = newnode;
		nodecount++;
	}
}

void list::current_stock(){
	if(head){
		node *traverse;
		traverse = head;
		while(traverse) {
			cout << traverse->size << ":" << traverse->quant << endl;
			traverse = traverse->next;
		}
	}
}

void list::sell(int size){
	if(head){
		node *traverse, *tail;
		traverse = head;
		tail = NULL;
		while(traverse) {
			if(traverse->size == size){
				if (traverse->quant == 1) { // delete node if the sold shoe was the last one left
					if (tail) {
						tail->next = traverse->next; // link the previous node with the next node
						delete traverse;
						return;
					} else {
						head = traverse->next; // make the second node the head if the deleted node is head node
						delete traverse;
						return;
					}
				} else {
					traverse->quant -= 1; // decrease by 1 if stock has more than one pair of the shoe
					return;
				}
			}
			tail = traverse;
			traverse = traverse->next;
		}
	}
	cout << "NO_STOCK" << endl; // print NO_STOCK if function did not terminate before this line
}

void list::clear(){
	node *tmpptr;
	while (head){
		tmpptr = head;
		head = head->next;
		delete tmpptr;
	}
	nodecount = 0;
}
