#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include "eul.h"
#include "fun.h"
#include "other.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	Euler_1();
	Euler_2();
	Euler_3();
	Euler_4();
	Euler_5();
	Euler_6();
	Euler_7();
	Euler_8();
	Euler_9();
	Euler_10();
	Euler_11();
	Euler_12();
	//Euler_13();
	Euler_14();
	Euler_15();

	String();

	//Date();

	return 0;
}