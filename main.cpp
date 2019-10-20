#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

using namespace std;

list stock;

void open_file();
void read_file();
void search_stock();

int main () {
	stock.create();
	open_file();
	read_file();
	stock.clear();
	return EXIT_SUCCESS;
}

void list::create() {
	head = NULL;
	nodecount = 0;
}

void open_file () {
	stock.tracker = fopen("input.txt", "r+");
	if(!stock.tracker){
		cerr << "Error: Unable to read file" << endl;
		exit(EXIT_FAILURE);
	}
}

void read_file () {
	int k;
	fseek(stock.tracker, 0, SEEK_SET);
	while (!feof(stock.tracker)) {
		fscanf(stock.tracker, " %d", &k);
		if(feof(stock.tracker)) break;
		if(k == 0) {
			//current_stock();
		} else if (k > 0) {
			//add_stock(k);
		} else {
			//sell(-k);
		}
	}
	fclose(stock.tracker);
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
