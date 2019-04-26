#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Table Table;

struct Table {
	int  key;
	int  val;
	Table *next;
};

Table* TableSearch(Table *p, int key) {
	for (; p != NULL; p = p->next) {
		if (p->key == key) {
			printf("key: %d\t value: %d\n", p->key, p->val);
			return p;
		}
	}
	return NULL;
}

void PrintTable(Table *p) {
	if (!p) printf("Empty!\n");
	while (p) {
		printf("key: %d\t value: %d\n", p->key, p->val);
		p = p->next;
	}
}

void AddTable(Table **l, int key, int val) {
	Table *newElem = (Table*)malloc(sizeof(Table));
	newElem->next = *l;
	newElem->key = key;
	newElem->val = val;
	*l = newElem;
}


int main()
{
	Table *table = NULL;
	int keyr, maxkey = 0, valr, num;
	printf("Enter number of entrys: ");
	scanf_s("%d", &num);
	printf("\n");
	int i;
	srand(time(NULL));
	for (i = 0; i < num; ++i) {
		keyr = rand() % 10;
		valr = rand() % 100;
		AddTable(&table, keyr, valr);
		if (keyr > maxkey) maxkey = keyr;
	}
	PrintTable(table);
	printf("\nMax key: \n");
	TableSearch(table, maxkey);
}
