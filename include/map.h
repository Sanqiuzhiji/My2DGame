#pragma once

#include "IMAGE_PR.h"
#include "player.h"
#include "graphics.h"

class map 
{
public:
    // 调用 IMAGE_PR 的构造函数
    map(const TCHAR* path);

    ~map();

    void get_player_view(const player _player, int view_width, int  view_height);

    IMAGE_PR player_view;
private:
    IMAGE_PR map_image;
    const TCHAR* map_path;
};