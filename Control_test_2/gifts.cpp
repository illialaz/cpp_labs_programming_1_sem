#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gifts.h"

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
