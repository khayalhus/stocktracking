//Struct def of list

#include "node.h" // include implementation of the node struct

struct list{
	node *head; // pointer to the shoe node with smallest size
	FILE *tracker;
	const char *filename;
	int nodecount; // count of currently available nodes
	void create(); // creates stock list
	void add_stock(int size); // adds a pair of shoe to the stock list
	void sell(int size); // sells a pair of shoe
	void current_stock(); // prints the current stock list
	void clear(); // deletes all of the nodes
	void open_file();
	void read_file();
};
