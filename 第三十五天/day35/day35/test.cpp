#include<iostream>
#include<string>

using namespace std;


void program1() {
    string str, name;
    while (getline(cin, str)) {
        getline(cin, name);

        int flag = 0; //���, 0����str��û�г���, 1�������
        for (int i = 0; i < str.size(); i++) {
            string tmp;
            if (str[i] == '"') {
                i++;
                //���������е�����
                while (i < str.size() && str[i] != '"') {
                    tmp += str[i];
                    i++;
                }
                if (tmp == name) {
                    //tmp���������е�����, �������name, ����flagΪ1
                    flag = 1;
                    break;
                }
            }
            else if (str[str[i] != ',']) {
                //��������ŵ�����
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
