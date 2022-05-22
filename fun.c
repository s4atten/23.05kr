#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include "fun.h"

struct bn* MemConstruct(char* num)
{
	struct bn* object = malloc(sizeof(struct bn));
	if (!object)
		return NULL;

	int size = strlen(num);

	object->arr = malloc(size * sizeof(short));
	if (!object->arr)
	{
		perror("ERROR: NO ARRAY");
		free(object);
		return NULL;
	}

	object->size = size;

	for (int i = 0; i < object->size; i++)
		object->arr[i] = num[i] - 48;

	return object;
}

int Printbn(struct bn* object)
{
	for (int i = 0; i < object->size; i++)
	{
		printf("%hi", object->arr[i]);
	}

	printf("\n");

	return 0;
}

int Sumofbn(struct bn* object1, struct bn* object2)
{
	int len = 0;

	if (object1->size > object2->size)
		len = object1->size;
	else
		len = object2->size;

	struct bn* res = malloc(sizeof(struct bn));
	res->size = len + 1;
	res->arr = malloc(res->size * sizeof(short));

	for (int i = 0; i < res->size; ++i)
		res->arr[i] = 0;

	int temp = 0;
	int i = 0;

	for (; i < min(object1->size, object2->size); i++)
	{
		res->arr[res->size - i - 1] += temp;

		temp = 0;
		if (res->arr[res->size - i - 1] + object1->arr[object1->size - i - 1] + object2->arr[object2->size - i - 1] < 10)
			res->arr[res->size - i - 1] += object1->arr[object1->size - i - 1] + object2->arr[object2->size - i - 1];
		else
		{
			temp = 1;
			res->arr[res->size - i - 1] = (res->arr[res->size - i - 1] + object1->arr[object1->size - i - 1] + object2->arr[object2->size - i - 1]) % 10;
		}
	}

	if (temp)
		res->arr[res->size - i - 1] += temp;

	if (object1->size != object2->size)
	{
		for (int j = i; j < (max(object1->size, object2->size)); j++)
		{
			if (object1->size > object2->size)
				res->arr[res->size - j - 1] += object1->arr[object1->size - j - 1];
			else
				res->arr[res->size - j - 1] += object2->arr[object2->size - j - 1];

		}
	}

	struct bn* buf = NULL;
	if (res->arr[0] == 0)
	{
		buf = malloc(sizeof(struct bn));
		if (!buf)
			return NULL;

		buf->size = len;
		buf->arr = malloc(buf->size * sizeof(short));
		int i = 1;
		int j = 0;
		for (; i < res->size; i++, j++)
		{
			buf->arr[j] = res->arr[i];
		}
		free(res);
		return buf;
	}

	return res;
}

int Difofbn(struct bn* obj1, struct bn* obj2)
{
	return 0;
}