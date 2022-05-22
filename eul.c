#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include "other.h"
#include "fun.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

/* Сумма чисел, кратных 3 и 5 до 1000*/
void Euler_1()
{
	int sum = 0;

	for (int i = 3; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;

	printf("1: %d\n", sum);
}

/* Сумма четных чисел Фиббоначи до 4млн*/
void Euler_2()
{
	int sum = 0;
	int* F = malloc(400000);
	if (!F)
	{
		printf("ERROR: !F");
		return;
	}

	F[0] = 0;
	F[1] = 1;

	for (int i = 2; F[i - 1] < 4000000; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
		if (F[i] % 2 == 0)
			sum += F[i];
	}

	printf("2: %d\n", sum);
}


/* Самый большой простой множитель 60081475143*/
void Euler_3()
{
	long long int ans = 0;
	long long int num = 600851475143;
	int Switch;

	for (int i = 2; i < sqrt(num); i++)
	{
		if (num % i == 0)
		{
			Switch = 1;
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					Switch = 0;
				}
			}

			if (Switch != 0)
				ans = i;
		}
	}

	printf("3: %lli\n", ans);
}

/* Самый большой палиндром - произведение двух трехзначных чисел*/
void Euler_4()
{
	int num = 0;
	int newnum = 0;
	int numcopy = 0;
	int count = 0;
	int largestnum = 0;

	for (int i = 999; i >= 100; i--)
	{
		for (int j = 999; j >= 100; j--)
		{
			num = i * j;
			numcopy = num;
			count = 0;
			newnum = 0;
			while (numcopy > 0)
			{
				newnum = newnum * 10;
				newnum = newnum + numcopy % 10;
				numcopy /= 10;
				count++;
			}
			if (num == newnum && largestnum < newnum)
			{
				largestnum = newnum;
			}
		}
	}

	printf("4: %d\n", largestnum);
}

/* Наименьшее число, которое делят все от 1 до 20*/
void Euler_5()
{
	int num = 20;
	int i = 2;

	while (i <= 20)
	{
		if (num % i != 0)
		{
			num++;
			i = 2;
		}
		else
			i++;
	}

	printf("5: %d\n", num);
}

/* Разность суммы квадратов и квадрата суммы первых 100 натуральных чисел*/
void Euler_6()
{
	int SumOfSqr = 0;
	int SqrOfSum = 0;

	for (int i = 1; i <= 100; i++)
	{
		SumOfSqr += i * i;
		SqrOfSum += i;
	}

	SqrOfSum *= SqrOfSum;

	printf("6: %d\n", SqrOfSum - SumOfSqr);
}

/* 10001 простое число*/
void Euler_7()
{
	int count = 0;
	int ans = 0;

	for (; count < 10001; ans++)
	{
		if (IsPrime(ans) == 1)
			count++;
	}

	printf("7: %d\n", ans - 1);
}

/* Самое большое произведение 13ти идущих подряд цифр в 1000значном числе*/
void Euler_8()
{
	unsigned long long ans = 0;
	char num[1000] = { "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450" };

	for (int i = 0; i < 987; i++)
	{
		unsigned long long curans = 0;
		curans = ((int)(num[i] - '0')) * ((int)(num[i + 1] - '0'));
		curans = curans * ((int)(num[i + 2] - '0')) * ((int)(num[i + 3] - '0'));
		curans = curans * ((int)(num[i + 4] - '0')) * ((int)(num[i + 5] - '0'));
		curans = curans * ((int)(num[i + 6] - '0')) * ((int)(num[i + 7] - '0'));
		curans = curans * ((int)(num[i + 8] - '0')) * ((int)(num[i + 9] - '0'));
		curans = curans * ((int)(num[i + 10] - '0')) * ((int)(num[i + 11] - '0')) * ((int)(num[i + 12] - '0'));
		ans = max(curans, ans);
	}

	printf("8: %llu\n", ans);
}

/* Пифагорова тройка, для которой a+b+c=1000*/
void Euler_9()
{
	for (int i = 1; i <= 995; i++)
		for (int j = i + 1; j <= 996; j++)
			for (int k = j + 1; k <= 997; k++)
				if ((i * i + j * j == k * k) && (i + j + k == 1000))
					printf("9: %d\n", i * j * k);
}

/* Сумма простых чисел до 2млн*/
void Euler_10()
{
	long long sum = 0;

	for (int i = 2; i < 2000000; i++)
		if (IsPrime(i) == 1)
			sum += i;

	printf("10: %lli\n", sum);
}

/* Самое большое произведение четырех соседних чисел в матрице*/
void Euler_11()
{
	int matrix[20][20] = { 8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8,
		 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0,
		 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65,
		 52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91,
		 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
		 24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
		 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
		 67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
		 24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
		 21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95,
		 78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92,
		 16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57,
		 86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
		 19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40,
		 4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
		 88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
		 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
		 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16,
		 20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54 };

	int ans = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			int column = 0;
			int string = 0;
			int uptodown = 0;
			int	downtoup = 0;
			if (j < 17)
			{
				string = matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3];
			}
			if (i < 17)
			{
				column = matrix[i][j] * matrix[i + 1][j] * matrix[i + 2][j] * matrix[i + 3][j];
			}
			if ((i < 17) && (j < 17))
			{
				downtoup = matrix[i][j] * matrix[i + 1][j + 1] * matrix[i + 2][j + 2] * matrix[i + 3][j + 3];
			}
			if ((i > 3) && (i < 17) && (j > 3))
			{
				uptodown = matrix[i][j] * matrix[i + 1][j - 1] * matrix[i + 2][j - 2] * matrix[i + 3][j - 3];
			}
			ans = max(ans, max(string, max(column, max(downtoup, uptodown))));
		}
	}

	printf("11: %d\n", ans);
}

/* Значение первого треугольного числа с более чем 500а телителями*/
void Euler_12()
{
	unsigned int triungle = 0;
	int count = 1;
	int lim;

	for (int i = 1; count <= 500; i++)
	{
		count = 1;
		triungle += i;
		lim = sqrt(triungle);
		for (int j = 2; j <= lim; j++)
			if (triungle % j == 0)
				if (j == lim)
					count++;
				else
					count += 2;
	}

	printf("12: %d\n", triungle);
}

/* Первые десять цифр суммы 100а 50тизначных чисел из text.txt*/
void Euler_13()
{
	FILE* F;
	F = fopen("text.txt", "r");
	if (!F)
		return;

	char num[51] = "";
	struct bn* x = MemConstruct("0");
	struct bn* y = NULL;

	for (int i = 0; i < 100; i++)
	{
		fscanf_s(F, "%s", num, 51);
		y = MemConstruct(num);
		x = Sumofbn(x, y);
	}

	printf("13: ");
	Printbn(x);
	printf("\n");
}

/* Число меньше 1млн, образующее самую большую последовательность Коллаца*/
void Euler_14()
{
	long long n = 0;
	long long count = 0;
	long long max = 0;
	int N = 0;
	for (int i = 1000000; i > 1; --i)
	{
		n = i;
		count = 1;
		while (n > 1)
		{
			if (n % 2 == 0)
			{
				n /= 2;
				++count;
			}
			else
			{
				n = (n * 3) + 1;
				++count;
			}
		}
		if (count >= max)
		{
			max = count;
			N = i;
		}
	}
	printf("14: %d\n", N);
}

/* Количество маршрутов в сетке 20*20*/
void Euler_15()
{
	long long int arr[21][21] = { 0 };
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
		{
			if (i == 0 && j == 0)
				arr[i][j] = 0;
			else
				if (i == 0 || j == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	printf("15: %lli\n", arr[20][20]);
}