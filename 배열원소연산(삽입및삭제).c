#include <stdio.h>

void outputArray(int a[], int size);
int insertArray(int a[], int num, int index, int size);
int deleteArray(int a[], int index, int size);

int main() {
	int a[10], size = 0;
	size = insertArray(a, 10, 0, size);
	size = insertArray(a, 20, 1, size);
	size = insertArray(a, 30, 2, size);
	size = insertArray(a, 50, 2, size);
	outputArray(a, size);
	size = deleteArray(a, 1, size);
	outputArray(a, size);
	return 0;
}

void outputArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int insertArray(int a[], int num, int index, int size) {
	if (size >= 10) {
		printf("Array is full. Insertion failed.\n");
	} else if (index < 0 || index > size) {
		printf("Invalid index for insertion.\n");
	} else {
		for (int i = size; i > index; i--) {
			a[i] = a[i - 1]; // Shift elements to the right
		}
		a[index] = num;
		size++;
	}
	return size;
}

int deleteArray(int a[], int index, int size) {
	if (size <= 0 || index < 0 || index >= size) {
		printf("Invalid index for deletion.\n");
	} else {
		for (int i = index; i < size - 1; i++) {
			a[i] = a[i + 1]; // Shift elements to the left
		}
		size--;
	}
	return size;
}