#include "StdFunctions.h"

using namespace std;
int main(int argc, char** argv) {
	Node* H = NULL;

	if (argc == 1) {
		H = ReadFile("file.txt");
	} else {
		H = ReadFile(argv[1]);
	}

	Sort(H);
	DisplayList(H);
	H = HuffmanTree(H);
	for (char c = 'a'; c <= 'z'; c++) {
		Node*  res = SearchTree(H, string(1,c));
		DisplayTree(H, res);
	}

	cout << "Press Any Key to Continue ..." << endl;
	getchar();
}
