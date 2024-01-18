#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int num;
	char name[21];
}monster;

int compare(const void* A, const void* B) {
	monster* a = (monster*)A;
	monster* b = (monster*)B;

	if (strcmp(a->name, b->name) > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int n, m;
	monster* list = NULL;
	monster* sorted_list = NULL;
	char op[21];

	scanf("%d %d", &n, &m);
	list = (monster*)malloc(sizeof(monster) * n);
	sorted_list = (monster*)malloc(n * sizeof(monster));

	for (int i = 0; i < n; i++) {
		scanf("%s", list[i].name);
		list[i].num = sorted_list[i].num = i + 1;
		sorted_list[i] = list[i];
	}

	qsort(sorted_list, n, sizeof(sorted_list[0]), compare);

	for (int i = 0; i < m; i++) {
		scanf("%s", op);
		if (op[0] >= '0' && op[0] <= '9') {
			int idx = atoi(op);
			printf("%s\n", list[idx - 1].name);
		}
		else {
			int left, right, mid;
			left = 0, right = n - 1;
			while (left <= right) {
				mid = (left + right) / 2;
				if (strcmp(sorted_list[mid].name, op) == 0) {
					printf("%d\n", sorted_list[mid].num);
					break;
				}
				else if (strcmp(sorted_list[mid].name, op) > 0) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
	}
}