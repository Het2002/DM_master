#include <iostream>
#include <vector>
#include <string>
#include <direct.h>
#include <windows.h>
#include <windows.h>
#include <winnt.h>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{

    char *work;
    if((work = _getcwd(NULL, 0)) == NULL)
    {
        MessageBoxA(GetForegroundWindow(),TEXT("��������"),TEXT("��ȡ����Ŀ¼ʧ�� :("),MB_ICONQUESTION);
        //MessageBoxW(GetForegroundWindow(),TEXT("��������"),TEXT("��ȡ����Ŀ¼ʧ�� :("),MB_ICONQUESTION);
        perror("��ȡ����Ŀ¼ʧ��");

    }
    else
    {
        printf("working in��%s\n", work);
    }

    string workDir=work;

    string program=workDir+"\\java\\bin\\java.exe";
    string jarFile=workDir+"\\dogename.jar";

    fstream _javaexe;
    _javaexe.open(program);
    if (!_javaexe){
        cout<<"java���л�����ʧ�����Դ�ע�������Ѱ�װ��java���л�����"<<endl;
    } else{
        const char *args[]={"java.exe","-jar",jarFile.data(),NULL};
    }

    system("pause");
    //execv(program.data(),args);

    return 0;
}