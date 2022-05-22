#pragma once

struct bn
{
	short* arr;
	int size;
};

struct bn* MemConstruct(char* num);

int Printbn(struct bn* object);

int Sumofbn(struct bn* object1, struct bn* object2);

int Difofbn(struct bn* object1, struct bn* object2);