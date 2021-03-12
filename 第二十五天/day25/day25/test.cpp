#include<iostream>
#include<string>
#include<stack>

using namespace std;


//int getNum(int num) {
//    int ret = 0;
//    while (num != 0) {
//        ret += num % 10;
//        num /= 10;
//    }
//    return ret;
//}

string getNum(string num) {
    int ret = 0;
    /*
    while(num != 0) {
        ret += num % 10;
        num /= 10;
    }
    */
    for (auto& ch : num) {
        ret += (ch - '0');
    }
    //将ret转成字符串
    stack<char> st;
    while (ret != 0) {
        char tmp = ret % 10 + '0';
        st.push(tmp);
        ret /= 10;
    }
    string retStr = "";
    while (!st.empty()) {
        retStr += st.top();
        st.pop();
    }

    return retStr;
}

//数根
void program2() {
    string num;
    while (cin >> num) {
        while (num.size() >= 2) {
            num = getNum(num);
        }
        cout << num << endl;
    }
}

int main() {
	program2();
	
	return 0;
}