   tomerml
Tomer Maalumi,
  203284872
  
**********Description**********

The program creat a dynamic hash table by allocating memory that allows the user to decide the: 
	-the size of the table/array.
	-the length of the linked list.
	-to choose the type of data between int and *char/string.
The user can use the program function to add, remove and search data in the hash table.


**********Functions**********

-Table* createTable(int size, int dType, int listLength);
-void freeTable(Table* table);
-int add(Table* table, void* data);
-void multipleTable(Table* table);
-int removeObj(Table* table, void* data);
-Object* search(Table* table, void* data);
-void printTable(Table* table);
-Object* createObject(void* data);
-void freeObject(Object* obj, int type);
-int isEqual(int type, void* data1, void* data2);
-int intHashFun(int* key, int origSize);
-int strHashFun(char* key, int origSize);


**********Program Files**********

-GenericHashTable.c
-GenericHashTable.h
-makefile
-Readme.txt


**********How to compile**********

Add to the program the file "tester.c",
Write in the terminal 'make'.


**********How to run**********

Write in the terminal ./ex1


**********Output**********

Printing a hash table.

