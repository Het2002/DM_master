#include <iostream>
#include <vector>
#include <string>
#include <direct.h>
#include <windows.h>
#include <windows.h>
#include <winnt.h>
#include <cstdio>
#include <fstream>
#include "GetRegValue.h"

using namespace std;

const LPCWSTR JDK_OLD = L"SOFTWARE\\JavaSoft\\Java Development Kit\\1.8";
const string JRE_OLD = R"(SOFTWARE\JavaSoft\Java Runtime Environment\1.8)";
const LPCWSTR JDK_NEW = L"SOFTWARE\\JavaSoft\\JDK";
const LPCWSTR JRE_NEW = L"SOFTWARE\\JavaSoft\\JRE";

bool checkJavaExist(string javaHome){
    fstream _javaExe;
    _javaExe.open(javaHome + "\\bin\\java.exe");
    cout<<"checking java runtime:"<<javaHome + "\\bin\\java.exe"<<endl;
    if(!_javaExe){
        cout<<"java runtime doesn't exist"<<endl;
        _javaExe.close();
        return false;
    }else{
        cout<<"java runtime exists"<<endl;
        _javaExe.close();
        return true;
    }
}

bool checkProgramJarExist(string jarPath){
    fstream _programFile;
    _programFile.open(jarPath);
    cout<<"checking jar file:"<<jarPath<<endl;
    if(!_programFile){
        _programFile.close();
        return false;
    }else{
        _programFile.close();
        return true;
    }
}

std::string findJavaFromReg(){
    string javaHome;
    javaHome=GetRegValue(2,JRE_OLD,"JavaHome");
    return javaHome;
}

int main(){

    char *work;
    if((work = _getcwd(NULL, 0)) == NULL){
        MessageBoxA(GetForegroundWindow(),TEXT("��������"),TEXT("��ȡ����Ŀ¼ʧ�� :("),MB_ICONQUESTION);
        //MessageBoxW(GetForegroundWindow(),TEXT("��������"),TEXT("��ȡ����Ŀ¼ʧ�� :("),MB_ICONQUESTION);
        perror("��ȡ����Ŀ¼ʧ��");
        return 1;
    }
    else{
        printf("working in��%s\n", work);
    }

    string workDir=work;
    string javaDir= workDir + R"(\runtime\java\bin)";

    string jarFile=workDir+"\\dogename.jar";

    if (!checkJavaExist(javaDir)){
        cout<<"�Ҳ���������Java���л��������Դ�ע�������Ѱ�װ��java���л�����"<<endl;
        javaDir=findJavaFromReg();
        cout<<"Got java from reg:"<<javaDir<<endl;
    } else{

        char *const args[]={"java.exe", "-jar", jarFile.c_str(), NULL};
        //const char *args[];
        javaDir=javaDir+"\\java.exe";
        execv(javaDir.data(),args);
    }

    system("pause");

    return 0;
}



