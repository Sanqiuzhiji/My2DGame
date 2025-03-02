#pragma once

#include "IMAGE_PR.h"
#include "player.h"
#include "graphics.h"

class map 
{
public:
    // ���� IMAGE_PR �Ĺ��캯��
    map(const TCHAR* path);

    ~map();

    void get_player_view(const player _player, int view_width, int  view_height);

    IMAGE_PR player_view;
private:
    IMAGE_PR map_image;
    const TCHAR* map_path;
};