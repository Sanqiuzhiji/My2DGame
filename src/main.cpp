
#include "main.h"


int main() {
    // 初始化图形窗口
    initgraph(640, 480);

    // 绘制开始页面并等待点击
    drawStartPage();

    while (true) {};
    // 关闭图形窗口
    closegraph();
    return 0;
}
