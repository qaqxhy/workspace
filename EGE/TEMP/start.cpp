#include <graphics.h>
#define Window_Widit 640  //宽
#define Window_Height 480 //高
const long FPS = 60;
int main()
{
    initgraph(Window_Widit, Window_Height, INIT_RENDERMANUAL);
    setbkcolor(WHITE);
    setcolor(BLACK);

    //---------------------------------//
    for (; is_run();delay_fps(FPS))
    {

    }
    closegraph();
}