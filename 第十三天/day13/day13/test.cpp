#include<iostream>
#include<string>
#include<vector>

using namespace std;

void test() {
	int i = 0, a = 1, b = 2, c = 3;
	i = ++a || ++b || ++c;
	cout << i << " " << a << " " << b << " " << c << endl;
}


// 1. 参数解析   (80%)
void analysis() {
    //输入一行命令
    string str;
    getline(cin, str);
    //给命令加一个空格, 以便后续处理最后一个参数
    str += ' ';

    size_t begin = 0;
    string ret[4];
    int count = 0;
    string::iterator it = str.begin();
    size_t pos = str.find(' ');

    if (pos != string::npos) {
        count++;
        //确定参数1
        ret[0].assign(it, it + pos);
        ++pos;
    }

    for (int i = 1; i <= 3; i++) {
        if (pos < str.size()) {
            // 参数有 ""
            if (str[pos] == '"') {
                begin = pos + 1;
                //从pos+1的位置找到下一个引号, 这中间的内容就是参数
                pos = str.find('"', pos + 1);
                ret[i].assign(it + begin,  it + pos);
                count++;
                pos += 2;
            }
            else {
                //没有""
                begin = pos;
                pos = str.find(' ', pos + 1);
                ret[i].assign(it + begin, it + pos);
                count++;
                pos++;
            }
            
        }
    }

    //第四个参数最后搞一下
    //ret[3].assign(str, pos, str.size());

    cout << count << endl;
    for (int i = 0; i < 4; i++) {
        cout << ret[i] << endl;
    }
}




int main() {
	//test();
    analysis();


	return 0;
}