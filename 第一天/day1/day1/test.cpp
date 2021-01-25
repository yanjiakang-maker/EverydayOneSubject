#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void test() {
	printf("%s, %5.3s\n", "computer", "computer");

	int cnt = 0;
	for (int x = 0, y = 0; (y = 123) && (x < 4); x++) {
		cnt++;
	}
	cout << cnt << endl;
}


void test2() {
	vector<int> v;
	v.resize(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
}


//1. ������ˮƽֵ
void getMaxSum() {
    /**
    * ˼·: 
    *     �ȶ����ݽ�������, ������֮��ǰn����������С��, �϶�����
    *     n ~ 3n֮���2n������, ÿ����Ϊһ��, �Ӵδ�ֵ(Ҳ������ߵ�ֵ)
    *     ����, ֻҪ������������� n, n + 2 ..... 3n - 2 ����������
    */

    int n;
    //�����������
    while (cin >> n) {
        vector<int> v;
        v.resize(n * 3);
        for (int i = 0; i < n * 3; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        long long sum = 0;
        for (int i = n; i < 3 * n; i += 2) {
            sum += v[i];
        }
        cout << sum << endl;
    }
}


//2. ɾ�������ַ�
void delStr() {
    /*˼·:
        ��Ҫɾ�����ַ�ӳ�䵽һ��������
        Ȼ�������һ���ַ���,
        �����һ���ַ����е��ַ�û�г�����ӳ��������
        ����������һ��string��, ��Ϊɾ����Ч��̫��
    */
    string str1;
    string str2;
    //ʹ��getline, ��Ϊcin�����ո�ͽ�����
    getline(cin, str1);
    getline(cin, str2);

    //����һ��ӳ������
    int table[256] = { 0 };
    for (int i = 0; i < str2.size(); i++) {
        table[str2[i]]++;
    }

    //������һ���ַ���, �����ǰ�ַ�����ӳ�����, ret += ����ַ� ������
    string ret;
    for (int i = 0; i < str1.size(); i++) {
        if (table[str1[i]] == 0)
            ret += str1[i];
    }
    cout << ret << endl;
}


int main() {
	//test2();
    getMaxSum();

	return 0;
}