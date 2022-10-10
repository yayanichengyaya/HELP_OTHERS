#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

void addItem();
void delItem();
void allItem();
void searchInformation();

int main()

{
    int Option;
    while (true)
    {
        cout << "欢迎使用你帮我助程序！请选择以下功能：\n";
        cout << "1.添加物品\n";
        cout << "2.删除物品\n";
        cout << "3.显示物品列表\n";
        cout << "4.查找物品信息\n" << endl;
        cin >> Option;
        cin.get();//读取回车键
        switch (Option)
        {
        case 1:addItem(); break;

        case 2:delItem(); break;

        case 3:allItem(); break;

        case 4:searchInformation(); break;
        default:cout << "您的输入不符合规范，请重新尝试。" << endl;

        }
    }
}

void addItem()
{
    string goods;
    string name;
    string phone;
    ofstream file1;
    file1.open("items.txt", ios::app);
    if (!file1.is_open())
    {
        cout << "数据文件打开失败！ " << endl;
        return;
    }
    cout << "请输入您要添加物品：\n";
    getline(cin, goods);
    file1 << goods << "\t";
    cout << "请输入您要添加物品数量：\n";
    getline(cin, goods);
    file1 << goods << "\t";
    cout << "请输入您的电话号码：\n";
    getline(cin, phone);
    file1 << phone << "\t";
    cout << "请输入您的名字：\n";
    getline(cin, name);
    file1 << name << "\t" << "\n";
    file1.close();
    cout << "添加按任意键返回主界面\n";
    return;
}

void delItem()
{
    cout << "请输入您想删除的物品:\n";
    bool find = false;
    string del_item;
    string line;//读取每一行
    int len = 0;//转换标志
    char* tmp;//读取的每一行转换成char*
    char* name_tmp;//切割出物品名称
    const char* split = "\t";//切割符号
    getline(cin, del_item);
    ifstream file1;
    ofstream file2;
    file1.open("items.txt");
    file2.open("tmp.txt", ios::out);
    if (!file1.is_open())
    {
        cout << "数据文件打开失败！ " << endl;
        return;
    }
    while (getline(file1, line))
    {
        tmp = new char[line.length()];
        len = 0;
        while (len < line.length())
        {
            tmp[len] = line[len];
            len++;
        }//将string转换成char*
        char* next_token = NULL;
        name_tmp = strtok_s(tmp, split, &next_token);
        if (name_tmp == del_item)
        {
            cout << endl << "已删除" << endl;
            find = true;
        }
        else
        {
            file2 << line << endl;
        }
        delete[]tmp;
    }

    if (!find)
    {
        cout << "未找到物品" << endl;
        file1.close();//关闭流
        file2.close();
    }
    else
    {
        file1.close();
        file2.close();
        fstream file1("items.txt", ios::out);
        fstream file2("tmp.txt", ios::in);
        while (getline(file2, line))//依次读取每一行
        {
            file1 << line << "\n";//将file1重写
        }

        file1.close();//关闭流
        file2.close();
    }
}
void allItem()
{
    ifstream file1;
    file1.open("items.txt");
    string line;
    char* tmp;
    int len = 0;
    const char* split = "\t";//切割符号
    while (getline(file1, line))
    {
        tmp = new char[line.length()];
        len = 0;
        while (len < line.length())
        {
            tmp[len] = line[len];
            len++;
        }//将string转换成char*
        char* next_token = NULL;
        char* list_item = strtok_s(tmp, split, &next_token);
        cout << list_item << "\t";
        delete[]tmp;
    }
    cout << endl;
}
void searchInformation()
{
    cout << "请输入您想查询的物品：\n";
    string goods;
    char* name_goods;
    string line;
    getline(cin, goods);
    ifstream file1;
    file1.open("items.txt");
    char* tmp;
    char* owner;
    char* phone;
    bool find = false;
    int len = 0;
    const char* split = "\t";//切割符号
    while (getline(file1, line))
    {
        tmp = new char[line.length()];
        len = 0;
        while (len < line.length())
        {
            tmp[len] = line[len];
            len++;
        }//将string转换成char*
        char* next_token = NULL;
        name_goods = strtok_s(tmp, split, &next_token);
        if (name_goods == goods)
        {
            find = true;
            cout << "物品数量是：\n";
            phone = strtok_s(NULL, split, &next_token);
            cout << phone << endl;
            cout << "联系方式是：\n";
            phone = strtok_s(NULL, split, &next_token);
            cout << phone << endl;
            cout << "捐献者称呼是：\n";
            phone = strtok_s(NULL, split, &next_token);
            cout << phone << endl;
        }

        delete[]tmp;
    }

    if (!find)
    {
        cout << "未找到物品" << endl;
        file1.close();//关闭流
    }
    else
    {
        file1.close();
    }

}
