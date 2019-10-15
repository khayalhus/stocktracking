//Struct def of list

#include "node.h"

struct list{
	node *head;
	const char *filename;
	FILE *tracker;
	int nodecount;
	void create();
	void add_stock(int);
	void sell(int);
	void current_stock();
	void clear();
};
