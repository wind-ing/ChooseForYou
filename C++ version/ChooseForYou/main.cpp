#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

const int numOfChoice = 100;//�����������ѡ����Ŀ
string strQ;//��Ҫ�������������
string choice[numOfChoice+1];//�洢���е�ѡ��
int WOfChoice[numOfChoice+1], maxn, nOfNot = 0;//ѡ���Ȩ�أ�ÿ�ξ�����ӵ�е�ѡ�񣻷��ڴ���

void show();
void init();
void question();
void answer();
void again();

int main()
{
    show();

    question();
    answer();

    //���ظ�ʹ��ģʽ��ȥ��ע�ͼ���ʹ��
    //again();

    return 0;
}
void show()
{
    //�������֣��ɲ���
    cout << "���." << endl;
    cout << "�ϵ۵�����Ϊ�����." << endl;
    cout << endl;
}
void init()
{
    //�����ݳ�ʼ��һ��
    nOfNot = 0;
    memset(WOfChoice, 0, sizeof(WOfChoice));
}
void question()
{
    //���ʹ���
    cout << "��ϣ����������������ǣ�" << endl;
    getline(cin, strQ);

    int nOfChoice = 1;
    string str;//�м����
    while(nOfChoice != 0 || nOfChoice > numOfChoice)
    {
        cout << "��ĵ� " << nOfChoice << " ��ѡ���ǣ�����������µ�ѡ������0" << endl;
        cin >> str;
        choice[nOfChoice] = str;
        if(str == "0")
        {
            maxn = nOfChoice - 1;
            nOfChoice = -1;
        }
        nOfChoice++;
    }
}
void answer()
{
    //�ش����
    srand((int)time(NULL));//����ʱ�������ͬ�����������
    int ans = 1, maxc = 1;
    for(int i=1; i<=100; i++)
    {
        ans = rand() % maxn + 1;
        WOfChoice[ans]++;
        if(WOfChoice[ans] > WOfChoice[maxc])
        {
            maxc = ans;
        }
    }

    cout << endl;
    cout << "����Ϊ " << strQ << " �����Ծ���..." << endl;
    cout << "��ӵ�� " << maxn << " ��ѡ��..." << endl;
    cout << "���õĴ��� <" << choice[maxc] << ">" << endl;
}
void again()
{
    cout << endl;
    cout << "�����Ѷ���������1" << endl;
    cout << "�������Ҳ����죬��ү����һ�Σ���������2" << endl;
    cout << "�µľ��񡪡�����3" << endl;

    string nOfAgain;
    cin >> nOfAgain;
    if(nOfAgain == "2")
    {
        nOfNot++;
        if(nOfNot > 3)
        {
            cout << "�²�����..." << endl;
        }
        else
        {
            answer();
            again();
        }

    }
    else if(nOfAgain == "3")
    {
        init();
        question();
        answer();
        again();
    }

}
