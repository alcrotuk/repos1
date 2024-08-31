#include <iostream>
#include <xutility>
using namespace std;

void quicksort(int* item, int len);
void qs(int* item, int left, int right);

int main() {
	int str[10];
	bool b;
	int i, k, z;
	cout << "Enter Massive: ";
	for (int a = 0; a < 10; a++) cin >> str[a];
	quicksort(str, size(str));//вызов функции сортировки
	cout << "Sorted Massive: ";
	for (int b = 0; b < size(str); b++) cout << str[b] << " ";
	cout << "\n";
	//здесь массив отсортирован по возрастанию.
	for (i = 1; i < 10; i++) {
		b = false;
		if (str[i] == str[i - 1]) {
			b = true;
			for (k = 0; k <= i-2; k++) {
				if (str[k] == str[i]) b = false;
			}
		}
		if (b) cout << "Dublicate is: " << str[i] << "\n";
	}

	return 0;
}

void quicksort(int* item, int len) {
	qs(item, 0, len - 1);
}

void qs(int* item, int left, int right) {
	int i, j, x, y;
	i = left, j = right;
	x = item[(left + right) / 2];
	do {
		while ((item[i] < x) && (i < right)) i++;
		while ((item[j] > x) && (j > left)) j--;

		if (i <= j) {
			y = item[i];
			item[i] = item[j];
			item[j] = y;
			i++, j--;
		}
	} while (i <= j);

	if (i < right) qs(item, i, right);
	if (j > left) qs(item, left, j);
}