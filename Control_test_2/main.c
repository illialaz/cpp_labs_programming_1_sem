#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Gift {
	int num;
	char gift[15];
};

struct Name {
  char name[15];
};

int gift_num (int x) {
	int result = 0;
	while(x != 0) {
		result += (x % 10);
		x /= 10;
	}
	/* Ассемблерная вставка
		  xor ebx, ebx
			xor edx, edx
			mov eax, x
			mov ecx, 10
	m1: div ecx
			add ebx, edx
			xor edx, edx
			cmp eax, 0
			jg m1
			mov eax, ebx*/
	if(result >= 10) {
		return gift_num(result);
	}
	else return result;
}


int name_num(char* str) {
	int i = 0;
	int result = 0;
	while (str[i] != '\0') {
		result += (((str[i] - 'A') % 9) + 1);
		i++;
	}
	return result;
}

int compare(const void* pa, const void* pb) {
	return (gift_num(name_num(((struct Name*)pa)->name)) -  gift_num(name_num(((struct Name*)pb)->name)));
}

int main(void) {
	FILE* gifts = fopen("gifts.txt", "r");
	int i = 0;
	char str[100];
	char* pch;
	char seps[] = " !?:;,.\n";
	struct Gift* gift = (struct Gift*)malloc(9 * sizeof(struct Gift));
	while(fgets(str, 100, gifts)) {
		pch = strtok(str, seps);
		while(pch != NULL) {
			strcpy(gift[i].gift, pch);
			gift[i].num = i;
			i++;
			pch = strtok(NULL, seps);
		}
	}
	fclose(gifts);

	FILE* names = fopen("name.txt", "r");
	if (!names) {
		printf("Create file\n");
		return 0;
	}
	struct Name name[100];
	i = 0;
	while (fgets(str, 100, names)) {
		pch = strtok(str, seps);
		while (pch != NULL) {
			strcpy(name[i].name, pch);
			i++;
			pch = strtok(NULL, seps);
		}
	}
	fclose(names);
	
	FILE* result = fopen("result.txt", "w");
	for(int j = 0; j < i; j++) {
		fprintf(result, "%s ", name[j].name);
	}
	
	for(int j = 0; j < i; j++) {
		int num_of_name = name_num(name[j].name);
		int num_of_gift = gift_num(num_of_name);
		fprintf(result, "\n%s, %d, %d, %s", name[j].name, num_of_name, num_of_gift, gift[num_of_gift - 1].gift);
	}

	qsort(name, i, sizeof(struct Name), compare);

	for(int j = 0; j < i; j++) {
		int num_of_name = name_num(name[j].name);
		int num_of_gift = gift_num(num_of_name);
		fprintf(result, "\n%d, %s, %s", num_of_gift, gift[num_of_gift - 1].gift, name[j].name);
	}

	fprintf(result, "\n\nLaziuk Illia, 7 group\n");
	fclose(result);
	return 0;
}
