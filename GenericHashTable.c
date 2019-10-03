
#include "GenericHashTable.h"


Table* createTable(int size, int dType, int listLength)
{
	Table *table =(Table*)malloc(sizeof(Table));					//allocating memory for the Table struct.
	if(table == NULL)
	{
		return NULL;
	}
	
	table->arr = (Object**)malloc(size*sizeof(Object*));			//allocating memory for array of Objects.
	if(table->arr == NULL)
	{
		free(table);
		return NULL;
	}

	for (int i = 0; i < size; i++)									//setting a NULL in all the indexes of the array.
	{
		table->arr[i] = NULL;
	}
																	//setting all the Table struct variables.
	table->m = size;
	table->d = 1;
	table->t = listLength;
	table->dType = dType;

	return table;
}

void freeTable(Table* table)
{
	for (int i = 0; i < table->m*table->d; i++)						//loop that goes through all the indexes in the array.
	{
		Object *obj = table->arr[i];								//creating a Objects for the previous and the current Objects in the linked list.
		Object *prev = NULL;

		while(obj != NULL)											//loop that goes through all the Objects in current index (linked list).
		{
			prev = obj;
			obj = obj->next;

			if (table->dType == INT_TYPE)
			{
				freeObject(prev, INT_TYPE);							//free the current Object from type int.
			}

			if (table->dType == STR_TYPE)							//free the current Object from type *char/string.
			{
				freeObject(prev, STR_TYPE);
			}
		}
	}

	free(table->arr);												//free the array in the Table struct.
	free(table);													//free the Table struct.
}

int add(Table* table, void* data)
{
	if (table == NULL || data == NULL)								//if there is a problem with the table or the data. 
	{
		printf("Table or Data Error\n");
		return -1;
	}

	else if (table->dType == INT_TYPE)
	{
		Object *obj = createObject(data);							//creating a new Object and insert the data inside.
		int hash = intHashFun((int*)data, table->m);				//call the hash function to know to which index the data need to found in.
		int i = hash*table->d;
		int counter, j;

		for (j = i ; j < i + table->d; j++)							//loop that goes through the indexes that match to hash function.
		{
			counter = 1;
			if (table->arr[j] == NULL)								//if the linked list is empty we insert the Object to be the first.
			{
				table->arr[j] = obj;
				return j;
			}

			Object *temp = table->arr[j];

			while (temp->next != NULL)								//loop that goes through all the Objects in current index (linked list).
			{
				temp = temp->next;
				counter++;
			}

			if (counter < table->t)									//if there is availability we insert the Object in the last place.
			{
				temp->next = obj;
				return j;
			}
		}

		if (counter >= table->t)									//if there is no availability for the Object we will multiple the table and expand it by 2x.
		{
			multipleTable(table);
			freeObject(obj, INT_TYPE);
			add(table, data);
		}
	}

	else if (table->dType == STR_TYPE)
	{
		char* str = (char*)malloc(strlen((char*)data) + 1);			//allocating memory for the data.
		if (str == NULL)
		{
			return -1;
		}

		strcpy(str,(char*)data);
		Object *obj = createObject(str);							//creating a new Object and insert the data inside.
		int hash = strHashFun((char*)data, table->m);				//call the hash function to know to which index the data need to found in.
		int i = hash*table->d;
		int counter, j;

		for (j = i; j < i+table->d; j++)							//loop that goes through the indexes that match to hash function.
		{
			counter = 1;
			if (table->arr[j] == NULL)								//if the linked list is empty we insert the Object to be the first.
			{
				table->arr[j] = obj;
				return j;
			}

			Object *temp = table->arr[j];

			while (temp->next != NULL)								//loop that goes through all the Objects in current index (linked list).
			{
				temp = temp->next;
				counter++;
			}

			if (counter < table->t)									//if there is availability we insert the Object in the last place.
			{
				temp->next = obj;
				return j;
			}
		}

		if (counter >= table->t)									//if there is no availability for the Object we will multiple the table and expand it by 2x.
		{
			multipleTable(table);
			freeObject(obj, STR_TYPE);
			add(table, data);
		}
	}
	return -1;
}

void multipleTable(Table* table)
{
	table->d = 2*table->d;											//increase the value of
	Object** tempArr = (Object**)malloc(table->m*table->d*sizeof(Object*));		//allocating memory for the new array.
	if (tempArr == NULL)
	{
		return;
	}

	for (int i = 0; i < table->m*table->d; i++)						//setting a NULL in all the indexes of the new array.
	{
		tempArr[i] = NULL;
	}

	for (int i = 0; i < table->m*(table->d/2); i++)					//move the Objects to the new array in the right place.
	{
		tempArr[i*2] = table->arr[i];
	}

	free(table->arr);												//free the allocat memory of the old array.
	table->arr = tempArr;											//set the new array in the Table struct.
}

int removeObj(Table* table, void* data)
{
	Object *found = search(table, data);							//calling to the search function to know if the Object is exist.

	if (found == NULL)
	{
		return -1;
	}

	else if (table->dType == INT_TYPE)
	{
		int hash = intHashFun(data, table->m);						//call the hash function to know to which index the data need to found in.
		int i = hash*table->d;

		for (int j = i; j < i + table->d; j++)						//loop that goes through the indexes that match to hash function.
		{
			Object *obj = table->arr[j];							//creating a Objects for the previous and the current Objects in the linked list.
			Object *prev = NULL;

			while (obj != NULL)										//loop that goes through all the Objects in current index (linked list).
			{
				if (isEqual(INT_TYPE, obj->data, data) == 0)		//checking if this the Object.
				{
					if (prev == NULL)								//if the Object is first in the linked list.
					{
						table->arr[j] = obj->next;
						freeObject(obj, INT_TYPE);					//remove/deleting the Object.
						return j;
					}

					else											//if the Object is not in the linked list(in the middle or last).
					{
						prev->next = obj->next;
						freeObject(obj, INT_TYPE);					//remove/deleting the Object.
						return j;
					}
				}

				prev = obj;
				obj = obj->next;
			}
		}
	}

	else if (table->dType == STR_TYPE)
	{
		int hash = strHashFun(data, table->m);						//call the hash function to know to which index the data need to found in.
		int i = hash*table->d;

		for (int j = i; j < i + table->d; j++)						//loop that goes through the indexes that match to hash function.
		{
			Object *obj = table->arr[j];							//creating a Objects for the previous and the current Objects in the linked list.
			Object *prev = NULL;

			while (obj != NULL)										//loop that goes through all the Objects in current index (linked list).
			{
				if (isEqual(STR_TYPE, obj->data, data) == 0)		//checking if this the Object.
				{
					if (prev == NULL)								//if the Object is first in the linked list.
					{
						table->arr[j] = obj->next;
						freeObject(obj, STR_TYPE);					//remove/deleting the Object.
						return j;
					}

					else											//if the Object is not in the linked list(in the middle or last).
					{
						prev->next = obj->next;
						freeObject(obj, STR_TYPE);					//remove/deleting the Object.
						return j;
					}
				}

				prev = obj;
				obj = obj->next;
			}
		}
	}
	return -1;
}

Object* search(Table* table, void* data)
{
	if (table == NULL)
	{
		printf("Table Error\n");
		return NULL;
	}

	else if (table->dType == INT_TYPE)
	{
		int hash = intHashFun((int*)data, table->m);				//call the hash function to know to which index the data need to found in.
		int i = hash*table->d;

		for (int j = i; j < i + table->d; j++)						//loop that goes through the indexes that match to hash function.
		{
			Object *obj = table->arr[j];

			while (obj != NULL)										//loop that goes through all the Objects in current index (linked list).
			{
				int found = isEqual(INT_TYPE, obj->data, data);		//call to function that check if the datas are equal.

				if (found == 0)
				{
					return obj;										//if the data are equal we found the Object and returning it.
				}

				obj = obj->next;
			}
		}
		return NULL;
	}

	else if (table->dType == STR_TYPE)
	{
		int hash = strHashFun((char*)data, table->m);				//call the hash function to know to which index the data need to found in.
		int i = hash*table->d;

		for (int j = i; j < i + table->d; j++)						//loop that goes through the indexes that match to hash function.
		{
			Object *obj = table->arr[j];

			while (obj != NULL)										//loop that goes through all the Objects in current index (linked list).
			{
				int found = isEqual(STR_TYPE, obj->data, data);		//call to function that check if the datas are equal.

				if (found == 0)
				{
					return obj;										//if the data are equal we found the Object and returning it.
				}

				obj = obj->next;
			}
		}
		return NULL;
	}
	return NULL;
}

void printTable(Table* table)
{
	Object *obj;

	for (int i = 0; i < table->m*table->d; i++)						//loop that goes through all the indexes in the array.
	{
		printf("[%d]:\t ", i);										//printing the index number.
		obj = table->arr[i];

		while(obj != NULL)											//loop that goes through all the Objects in current index and printing the data in the Object.
		{
			if (table->dType == STR_TYPE)
			{
				printf("%s\t-->", (char*)obj->data);
			}
			if (table->dType == INT_TYPE)
			{
				printf("%d\t-->", *(int*)obj->data);	
			}

			obj = obj->next;
		}
		printf("\n");
	}
}

Object* createObject(void* data)
{
	Object *obj = (Object*)malloc(sizeof(Object));					//allocating memory for the Object struct.
	if (obj == NULL)
	{
		return NULL;
	}

	obj->data = data;												//setting the data of Object struct.
	obj->next = NULL;												//setting the next Object in the linked list to NULL.
	return obj;
}

void freeObject(Object* obj, int type)
{
	if (type == STR_TYPE)											//if the type is *char/string free the allocation for the data.
	{
		free(obj->data);
	}
	free(obj);														//freeing the Object struct.
}

int isEqual(int type, void* data1, void* data2)
{
	if (type == INT_TYPE)											//if the type of datas is int.
	{
		if (data1 == data2)											//if the datas are equal return 0, else return -1.
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	else if (type == STR_TYPE)										//if the type of datas is *char/string. 
	{
		if (strcmp(data1, data2) == 0)								//if the datas are equal return 0, else return -1.
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	return -1;
}

int intHashFun(int* key, int origSize)
{
	int hash = *key % origSize;										//calculate the sum modulo original size of array.
	return hash;
}

int strHashFun(char* key, int origSize)
{
	int asciiSum = 0;

	for (int i = 0; i < strlen(key); i++)							//loop that goes all string length by each letter.
	{
		asciiSum+= (int)key[i];										//sum each letter by ASCII value.
	}

	int hash = asciiSum % origSize;									//calculate the sum modulo original size of array.
	return hash;
}
