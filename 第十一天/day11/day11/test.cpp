#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>

using namespace std;



//1. 最近公共祖先   -->  100%
int getLCA(int a, int b) {
    // write code here
    if (a == b)
        return a;

    int parent1 = a / 2;
    int parent2 = b / 2;

    while (parent1 > 0 && parent2 > 0) {
        if (parent1 == parent2) {
            break;
        }

        //更新parent
        while (parent1 != 1 && parent1 > parent2)
            parent1 /= 2;

        while (parent2 != 1 && parent2 > parent1)
            parent2 /= 2;

    }
    return parent1;
}

void test() {
    int a, b;
    cin >> a >> b;
    cout << getLCA(a, b) << endl;
}


//2. 求最大连续bit数    100%
void getMax1() {
    int n;
    while (cin >> n) {
        stack<int> st; //二进制转换用到的栈
        //priority_queue<int> pq; //优先级队列, 放入1的连续数
        int count = 0; //计数器
        int max = 0; //保存最大值

        st.push(0);

        //转换成二进制, 保存在栈中
        while (n > 0) {
            int tmp = n % 2;
            st.push(tmp);
            n /= 2;
        }

        //遍历二进制数字, 记录连续1的个数
        while (!st.empty()) {
            if (st.top() == 1) {
                count++;
            }
            else {
                //当前位是0, 记录max, 计数器count归0
                //pq.push(count);
                if (count > max)
                    max = count;
                count = 0;
            }
            st.pop();
        }
        cout << max << endl;
    }
}



int main() {
	test();
    //getMax1();


	return 0;
}