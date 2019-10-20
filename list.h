//Struct def of list

#include "node.h"

struct list{
	node *head;
	const char *filename;
	FILE *tracker;
	int nodecount;
	void create();
	void add_stock(int size);
	void sell(int size);
	void current_stock();
	void clear();
	void open_file();
	void read_file();
};
