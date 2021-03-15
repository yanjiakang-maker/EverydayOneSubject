#include<iostream>
#include<string>

using namespace std;

void program1() {
    string str;
    //获取一行数据
    while (getline(cin, str)) {
        for (auto& ch : str) {
            if (ch == ' ')
                continue;

            ch -= 5;
            if (ch < 'A') {
                ch += 26;
            }
        }

        cout << str << endl;
    }
}





int main() {
	program1();

	return 0;
}