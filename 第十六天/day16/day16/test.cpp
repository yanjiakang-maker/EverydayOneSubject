#include<iostream>
#include<string>
#include<vector>

using namespace std;


void print(char* s) {
	if (*s) {
		print(++s);
		printf("%c", *s);
	}
}

void test() {
	char str[] = "Geneius";
	print(str);
}



int main() {
	test();


	return 0;
}