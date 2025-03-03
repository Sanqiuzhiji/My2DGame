#include <graphics.h>
#include <iostream>

void test()
{
    initgraph(800, 600);
    setbkcolor(WHITE);
    cleardevice();

    // »­Ò»¸ö°´Å¥
    int btn_x = 300, btn_y = 400, btn_w = 200, btn_h = 50;
    setfillcolor(BLUE);
    solidrectangle(btn_x, btn_y, btn_x + btn_w, btn_y + btn_h);

    std::cout << "Start detecting mouse events..." << std::endl;

    while (true)
    {
        ExMessage msg = getmessage(EM_MOUSE);
        std::cout << "Mouse: " << msg.x << ", " << msg.y << std::endl;

        if (msg.message == WM_LBUTTONDOWN)
        {
            if (msg.x >= btn_x && msg.x <= btn_x + btn_w &&
                msg.y >= btn_y && msg.y <= btn_y + btn_h)
            {
                std::cout << "Button clicked!" << std::endl;
            }
        }
    }

    closegraph();
}
