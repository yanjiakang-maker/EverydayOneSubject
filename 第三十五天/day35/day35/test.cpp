#include<iostream>
#include<string>

using namespace std;


void program1() {
    string str, name;
    while (getline(cin, str)) {
        getline(cin, name);

        int flag = 0; //标记, 0代表str中没有出现, 1代表出现
        for (int i = 0; i < str.size(); i++) {
            string tmp;
            if (str[i] == '"') {
                i++;
                //处理引号中的内容
                while (i < str.size() && str[i] != '"') {
                    tmp += str[i];
                    i++;
                }
                if (tmp == name) {
                    //tmp就是引号中的内容, 如果等于name, 则置flag为1
                    flag = 1;
                    break;
                }
            }
            else if (str[str[i] != ',']) {
                //处理非引号的内容
                while (i < str.size() && str[i] != ',') {
                    tmp += str[i];
                    i++;
                }
                if (tmp == name) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1)
            cout << "Ignore" << endl;
        else
            cout << "Important!" << endl;
    }
}


int main() {
    program1();
    // "Letendre, Bruce",Joe,"Quan, William"
    // Joe,Kewell,Leon

    return 0;
}
