#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

const int numOfChoice = 100;//最多可以输入的选择数目
string strQ;//需要做出抉择的事情
string choice[numOfChoice+1];//存储所有的选择
int WOfChoice[numOfChoice+1], maxn, nOfNot = 0;//选择的权重；每次抉择所拥有的选择；反悔次数

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

    //可重复使用模式，去掉注释即可使用
    //again();

    return 0;
}
void show()
{
    //引导部分，可补充
    cout << "你好." << endl;
    cout << "上帝的骰子为你服务." << endl;
    cout << endl;
}
void init()
{
    //将数据初始化一下
    nOfNot = 0;
    memset(WOfChoice, 0, sizeof(WOfChoice));
}
void question()
{
    //提问过程
    cout << "你希望做出抉择的事情是？" << endl;
    cin >> strQ;

    int nOfChoice = 1;
    string str;//中间变量
    while(nOfChoice != 0 || nOfChoice > numOfChoice)
    {
        cout << "你的第 " << nOfChoice << " 个选择是？如果不再有新的选择，输入0" << endl;
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
    //回答过程
    srand((int)time(NULL));//根据时间产生不同的随机数种子
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
    cout << "你在为 " << strQ << " 而难以抉择..." << endl;
    cout << "你拥有 " << maxn << " 个选择..." << endl;
    cout << "你获得的答案是 <" << choice[maxc] << ">" << endl;
}
void again()
{
    cout << endl;
    cout << "抉择已定——输入1" << endl;
    cout << "我命由我不由天，给爷再掷一次！——输入2" << endl;
    cout << "新的抉择——输入3" << endl;

    string nOfAgain;
    cin >> nOfAgain;
    if(nOfAgain == "2")
    {
        nOfNot++;
        if(nOfNot > 3)
        {
            cout << "事不过三..." << endl;
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
