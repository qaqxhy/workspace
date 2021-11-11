#include <graphics.h>
#define Window_Width 640
#define Window_Height 480
int main()
{
	initgraph(Window_Width, Window_Height, INIT_RENDERMANUAL); //初始化窗口
	setbkcolor(WHITE);										   //设置窗口背景为白色
	setcolor(BLACK);										   //设置前景色为黑色
	bool isClick;
	int xClick, yClick;
	for (; is_run(); delay_fps(60))
	{
		isClick = false;
		while (mousemsg())
		{
			mouse_msg msg = getmouse();

			//在消息处理循环中判断点击
			if (msg.is_left() && msg.is_down())
			{
				isClick = true;
				xClick = msg.x;
				yClick = msg.y;
			}
		}
		if (isClick)
		{
			//todo:
			line(xClick, 0, xClick, Window_Height);
			line(0, yClick, Window_Width, yClick);
			circle(xClick, yClick, 10);
		}
	}

	closegraph();

	return 0;
}
