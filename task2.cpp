#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	char ch;
	if (argc != 4) {
		cout << "Usage: <file1> <file2> <file3>";
		return 1;
	}
	ifstream f1(argv[1], ios::in | ios::binary);
	if (!f1.is_open()) {
		cout << "cannot open file1";
		return 1;
	}
	ifstream f2(argv[2], ios::in | ios::binary);
	if (!f2.is_open()) {
		cout << "cannot open file2";
		return 1;
	}
	ofstream fout(argv[3], ios::out | ios::binary);
	if (!fout.is_open()) {
		cout << "cannot open file3";
		return 1;
	}
	while (f1.get(ch))
	{
		fout.put(ch);
	}
	while (f2.get(ch)) {
		fout.put(ch);
	}
	f1.close();
	f2.close();
	fout.close();
	return 0;
}