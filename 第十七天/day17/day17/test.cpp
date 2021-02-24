#include<iostream>
#include<string>
#include<vector>

using namespace std;


class A {
public:
	~A() {
		cout << "A" << endl;
	}
};

class B {
public:
	virtual ~B() {
		cout << "B" << endl;
	}
};

class C : public A, public B {
public:
	~C() {
		cout << "C" << endl;
	}
};


void test() {
	C* c = new C;
	B* b1 = dynamic_cast<B*>(c);
	A* a2 = dynamic_cast<A*>(b1);
	delete a2;
}


// 1. 杨辉三角变形
void iNOC() {
    int n;

    cin >> n;
    vector<vector<int>> v;
    v.resize(n);
    int ret = -1;
    int size = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        //开一个2n - 1的正方形数组空间
        v[i].resize(size);
        if (i == 0) {
            //第一行, 给数组中间赋值一个1
            v[i][size / 2] = 1;
        }
        //把n - 1之前的行先计算出来
        else if (i < n - 1) {
            //画个图会很明显, 每一行从n-1-i开始, 一共是2i+1个数据, 到n+i结束
            for (int j = n - 1 - i; j < n + i; j++) {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
            }
        }

        if (i == n - 1) {
            //最后一行, 记录第一个偶数的位置
            int pos = 0;
            for (; pos < n; pos++) {
                if (pos == 0)
                    v[i][pos] = v[i - 1][pos] + v[i - 1][pos + 1];
                else if (pos == n - 1)
                    v[i][pos] = v[i - 1][pos - 1] + v[i - 1][pos];
                else
                    v[i][pos] = v[i - 1][pos - 1] + v[i - 1][pos] + v[i - 1][pos + 1];

                if (v[i][pos] % 2 == 0) {
                    ret = pos + 1;
                    break;
                }
            }
        }
    }

    cout << ret << endl;
}





int main() {
	//test();
    iNOC()
        ;
	return 0;
}