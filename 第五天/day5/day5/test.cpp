#include<iostream>
#include<vector>
#include<string>

using namespace std;


void test() {
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2];
}



//1. ͳ�ƻ���

//�ж��Ƿ�Ϊ���Ĵ�
bool isPalindrome(const string& str) {
    size_t begin = 0;
    size_t end = str.size() - 1;

    while (begin < end) {
        //����в���ȵ�, ֱ�ӷ���false
        if (str[begin] != str[end])
            return false;
        begin++;
        end--;
    }
    //���������ߵ���, ˵���ǻ��Ĵ�, ����true
    return true;
}


//��ȡһ����ĸ���ԵĲ��뷽������
int getNum(string& str1, char& ch) {
    //������
    int ret = 0;
    //����ÿһ��λ��
    for (int pos = 0; pos <= str1.size(); pos++) {
        string tmp = str1;
        //�����ַ�
        tmp.insert(tmp.begin() + pos, ch);
        //�ж��Ƿ񹹳ɻ���
        if (isPalindrome(tmp))
            ret++;
    }
    return ret;
}


int getNum(string& str1, const string& str2) {
    //������
    int ret = 0;
    //����ÿһ��λ��
    for (size_t pos = 0; pos <= str1.size(); pos++) {
        string tmp = str1;
        //�����ַ���
        tmp.insert(pos, str2);
        //�ж��Ƿ񹹳ɻ���
        if (isPalindrome(tmp))
            ret++;
    }
    return ret;
}


void statistics() {
    string str1;
    string str2;
    //���������ַ���
    cin >> str1;
    cin >> str2;

    int ret = getNum(str1, str2);
    cout << ret << endl;

    //������ȫ����ɵ��...����ΪҪһ���ַ�һ���ַ�����...����˼���һ��ȫ���ȥ
    //ע�⿴�Ⱑ~
    /*
    //��������ӳ���, һ����str2����ĸ���ִ���, һ������Ӧ��ĸ����str1֮����Թ��ɻ��Ĵ��ķ�����
    int charTable[256] = {0};
    int numTable[256] = {0};

    //����str2, ��¼��ĸ���ִ���
    for(const auto& ch : str2) {
        charTable[ch]++;
    }

    int i = 0;
    //�ٴα���str2
    while (i < str2.size()) {
        //���num�������λ��Ϊ0, ˵�������ĸû�н��й��ж�
        if(numTable[str2[i]] == 0) {
            //��ȡ����ĸ������Թ��ɻ��Ĵ��ķ�����,
            int num = getNum(str1, str2[i]);
            //������num��
            numTable[str2[i]] = num;
            i++;
        }
        else {
            //���num��Ϊ0, ˵�������ĸ�Ѿ�֪���ж����ַ�����
            //�����ظ�����, ֱ������������
            i++;
            continue;
        }
    }

    //������
    int ret = 0;
    //�����ܷ�����
    for (int i = 'a'; i <= 'z'; i++) {
        ret += charTable[i] * numTable[i];
    }
    cout << ret << endl;
    */
}



//2. �������Ӵ�������
void getMaxSum() {
    int n;
    vector<int> v;
    //�����������
    while (cin >> n) {
        v.resize(n);
        //��������
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int max = v[0];
        int tmp = v[0];
        //����Ԫ�ص���һ��λ�ÿ�ʼ����
        vector<int>::iterator it = v.begin() + 1;
        while (it != v.end()) {
            tmp += *it;
            //�����Ӻ��ֵС�ڵ�ǰitָ���ֵ, ��ôֱ������, ʹ�õ�ǰitָ���ֵ��Ϊ�µ����ֵ
            if (tmp < *it)
                tmp = *it;
            //���tmp ���� max , ��tmp����max, �������ֵ
            if (tmp > max)
                max = tmp;

            it++;
        }

        cout << max << endl;
    }
}


int main() {
	//test();
    statistics();

	return 0;
}