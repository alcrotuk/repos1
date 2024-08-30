#include <iostream>
#include <cstring>
using namespace std;

template <class QStype> void quicksort(QStype* item,int len);
template <class QStype> void qs(QStype* item, int left, int right);

int main() {
	int nums[] = { 1,13,2,7,4,3 };
	char str[] = "alknfofwghgwlfmnwblaf";
	quicksort(nums, size(nums));
	quicksort(str, strlen(str));
	for (int i = 0; i < size(nums); i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
	cout << str;
	return 0;
}

template <class QStype> void quicksort(QStype* item, int len) {
	qs(item, 0, len - 1);
}

template <class QStype> void qs(QStype* item, int left, int right) {
	QStype x;
	int i, j;
	i = left; j = right;
	x = item[(left + right) / 2];
	do {
		while (item[i] < x && (i < right)) i++;
		while (item[j] > x && (j > left)) j--;

		if (i <= j) {
			QStype obj;
			obj = item[i];
			item[i] = item[j];
			item[j] = obj;
			i++; j--;
		}
	} while (i <= j);

	if (i < right) qs(item, i, right);
	if (j > left) qs(item, left, j);
}