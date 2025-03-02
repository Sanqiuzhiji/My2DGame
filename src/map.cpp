#include "../include/map.h"
#include "../include/IMAGE_PR.h"

map::map(const TCHAR* path) 
{
     map_image.imageload(path);
}

map::~map()
{

}

void map::get_player_view(const player _player, int view_width, int  view_height)
{
    SetWorkingImage(&map_image.OriginImage);
    //std::cout <<map_image.OriginImage.getwidth()<<" "<<map_image.OriginImage.getheight() << std::endl;
    getimage(&player_view.OriginImage, _player.map_positionX - view_width / 2, _player.map_positionY - view_height / 2, view_width, view_height); // ´Ó img ÖÐ½ØÈ¡
    SetWorkingImage(NULL);
    //std::cout <<player_view.OriginImage.getwidth()<<" "<<player_view.OriginImage.getheight() << std::endl;
    player_view.ShowScalingImage(windowWidth, false);
}