#include <windows.h>
 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
 
HINSTANCE hInst;
 
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,
    int iCmdShow
){
    static TCHAR szClassName[] = TEXT("Win32Demo");  //��������
    HWND     hwnd;  //���ھ��
    MSG      msg;  //��Ϣ
    WNDCLASS wndclass;  //������
 
    hInst = hInstance;
 
    /**********�ڢٲ���ע�ᴰ����**********/
    //Ϊ������ĸ����ֶθ�ֵ
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��
    wndclass.lpfnWndProc  = WndProc;  //���ڹ���
    wndclass.cbClsExtra   = 0;  //��ʱ����Ҫ����
    wndclass.cbWndExtra   = 0;  //��ʱ����Ҫ����
    wndclass.hInstance    = hInstance;  //��ǰ���ھ��
    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //����ͼ��
    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //�����ʽ
    wndclass.hbrBackground= (HBRUSH) GetStockObject (WHITE_BRUSH);;  //���ڱ�����ˢ����ɫ��
    wndclass.lpszMenuName = NULL ;  //���ڲ˵�
    wndclass.lpszClassName= szClassName;  //��������
    //ע�ᴰ��
    RegisterClass(&wndclass);
 
    /*****�ڢڲ�����������(���ô�����ʾ����)*****/
    hwnd = CreateWindow(
        szClassName,  //��������
        TEXT("Welcome"),  //���ڱ��⣨�����ڱ�������
        WS_OVERLAPPEDWINDOW,  //���ڷ��
        CW_USEDEFAULT,  //��ʼ��ʱx���λ��
        CW_USEDEFAULT,  //��ʼ��ʱy���λ��
        500,  //���ڿ���
        300,  //���ڸ߶�
        NULL,  //�����ھ��
        NULL,  //���ڲ˵����
        hInstance,  //��ǰ���ڵľ��
        NULL  //��ʹ�ø�ֵ
    );
 
    //��ʾ����
    ShowWindow (hwnd, iCmdShow);
    //���£����ƣ�����
    UpdateWindow (hwnd);
 
    /**********�ڢ۲�����Ϣѭ��**********/
    while( GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);  //������Ϣ
        DispatchMessage (&msg);  //������Ϣ
    }
 
    return msg.wParam;
}
 
//���ڹ���
LRESULT CALLBACK WndProc(
    HWND hWnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam
){
    PAINTSTRUCT ps;
    HDC hdc;
    //���뱻����Ϊ��̬����
    static int iClick = 0;  //��굥������
    static TCHAR szTextBuf[20];  //static �ؼ��ı�
    static HWND hStatic;  //static �ؼ����
 
    switch (message){
        case  WM_CREATE:
            hStatic = CreateWindow(
                L"static", //��̬�ı��������
                L"C����������",  //�ؼ����ı�
                WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | WS_BORDER /*���߿�*/| SS_CENTER /*ˮƽ����*/ | SS_CENTERIMAGE /*��ֱ����*/,
                20 /*X����*/, 20 /*Y����*/, 200 /*����*/, 100 /*�߶�*/,
                hWnd,  //�����ھ��
                (HMENU)1,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                hInst,  //��ǰ����ʵ�����
                NULL
            );
            break;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            // TODO:  �ڴ����������ͼ����...
            EndPaint(hWnd, &ps);
            break;
        case WM_LBUTTONDOWN:
            iClick++;
            wsprintf(szTextBuf, TEXT("��걻����%d��"), iClick);
            SetWindowText(hStatic, szTextBuf);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam) ;
}