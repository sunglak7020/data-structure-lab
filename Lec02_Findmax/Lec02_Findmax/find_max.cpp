#include <cstdio>

int findArrayMax(int score[], int n)
{
	int tmp = score[0];
	for (int i = 1; i < n; i++) {
		if (score[i] > tmp) {
			tmp = score[i];
		}
	}
	return tmp;
}

void main()
{
	int score[5] = { 1, 10, 11, 21, 9 };
	int out;
	out = findArrayMax(score, 5);
	printf("result = %d", out);
}