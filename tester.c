
#include "GenericHashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


int main(int argc, char const *argv[])
{
/*	
	Table *table = createTable(4, INT_TYPE, 2);
	int x = 4;
	int y = 8;
	int z = 12;
	int t = 16;
	int w = 20;

	add(table, &x);
	add(table, &y);
	add(table, &z);
	add(table, &t);
	add(table, &w);

	printTable(table);

	printf("++++++++++++++++++++++++++++++++\n");

	removeObj(table, &x);
	removeObj(table, &y);
	removeObj(table, &z);
	removeObj(table, &t);
	removeObj(table, &w);
	removeObj(table, &w);

	printTable(table);

//////////////////////////////////////////////////////////////////////

	Table *table = createTable(4, STR_TYPE, 2);

	char a[] = "shir";
	char b[] = "daniel";
	char c[] = "ori";
	char d[] = "or";
	char e[] = "yarin";
	char f[] = "dassa";
	char j[] = "barak";
	char h[] = "adi";
	char i[] = "haim";

	add(table, &a);
	add(table, &b);
	add(table, &c);
	add(table, &d);
	add(table, &e);
	add(table, &f);
	add(table, &j);
	add(table, &h);
	add(table, &i);

	printTable(table);

	removeObj(table, &j);
	removeObj(table, &c);
	removeObj(table, &e);

	printTable(table);

	Object *x = search(table, &a);
	printf("the data is: %s\n", (char*)x->data);

	freeTable(table);
*/

/////////////// Ori Ben Shitrit ///////////////////////////////

	Table * tb= createTable(2, 1, 2);
    

    char * a = "a";//1
    char * b="b";//0
    char * c="c";//1
    char * d = "d";//0
    char * e="e";//1
    char * f="f";//0
    char * g ="g";//1
    char * h="h";//0
    char * i="i";//1
    char * j ="j";//0
    char * k="k";//1
    char * l="l";//0
    char * m ="m";//1
    char * n="n";//0
    char * o="o";//1
    char * p ="p";//0
    char * q="q";//1
    char * r="r";//0
    char * s ="s";//1
    char * t="t";//0
    char * u="u";//1
    
    add(tb,a);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,b);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,c);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,d);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,e);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,f);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,g);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,h);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,i);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,j);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,k);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,l);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,m);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,n);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,o);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,p);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,q);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,r);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,s);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,t);
    printf("\nThe Table:\n");
    printTable(tb);
    add(tb,u);
    printf("\nThe Table:\n");
    printTable(tb);
    printf("index of remove value: %d \n",removeObj(tb,a)); //10
    printf("index of remove value: %d \n",removeObj(tb,b)); //10
    printf("index of remove value: %d \n",removeObj(tb, c)); //10
    printf("index of remove value: %d \n",removeObj(tb, d)); //10
    printf("index of remove value: %d \n",removeObj(tb, e)); //10
    printf("index of remove value: %d \n",removeObj(tb, f)); //10
    printf("index of remove value: %d \n",removeObj(tb, g)); //10
    printf("index of remove value: %d \n",removeObj(tb, h)); //10
    printf("index of remove value: %d \n",removeObj(tb, i)); //10
    printf("index of remove value: %d \n",removeObj(tb, j)); //10
    printTable(tb);


    Object *ob= search(tb, a);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, b);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, c);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, d);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, e);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, f);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, g);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, h);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, i);
    if(ob==NULL)
        printf("ob is null \n");
    //printf("%s \n",(char*)(ob->data));
    ob= search(tb, j);
    if(ob==NULL)
        printf("ob is null \n");
    ob=search(tb, k);
    printf("%s \n",(char*)(ob->data));
    ob=search(tb, l);
    printf("%s \n",(char*)(ob->data));
    ob=search(tb, m);
    printf("%s \n",(char*)(ob->data));
    ob=search(tb, n);
    printf("%s \n",(char*)(ob->data));
    ob=search(tb, o);
    printf("%s \n",(char*)(ob->data));

    freeTable(tb);
/*    
    Table* myTable = createTable(4,0,2);
    int x4 = 4; //0
    int x8 = 8; //0
    int x10 = 10;//2
    int x12 = 12;//0
    int x16 = 16;//0
    int x18 = 18;//2
    int x22 = 22;//2
    int x1 = 1;//1
    //int x4 = 4;//0
    int x45=45;
    
    add(myTable,&x4);
    add(myTable,&x8);
    add(myTable,&x10);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x12);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x16);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x18);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    
    add(myTable,&x22);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    
    add(myTable,&x4);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x12);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x1);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x1);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x16);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x4);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x8);
    printf("\nThe Table:\n");
    printTable(myTable);
    
    add(myTable,&x45);
    printf("\nThe Table:\n");
    printTable(myTable);
    printf("index of remove value: %d \n",removeObj(myTable, &x4)); //10
    printTable(myTable);
    printf("index of remove value: %d \n",removeObj(myTable, &x8));//18
    printTable(myTable);
    printf("index of remove value: %d \n",removeObj(myTable, &x10)); //10
    printTable(myTable);
    printf("index of remove value: %d \n",removeObj(myTable, &x12));//18
    printTable(myTable);
    printf("index of remove value: %d \n",removeObj(myTable, &x16));//18
    printTable(myTable);
    printf("index of remove value: %d \n",removeObj(myTable, &x18));//18
    printTable(myTable);

    freeTable(myTable);
*/

	return 0;
}
