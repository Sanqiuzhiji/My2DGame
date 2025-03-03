#include "../include/MyIMAGE.h"

MyIMAGE::MyIMAGE(const TCHAR* path, int IMAGE_WIDTH, int IMAGE_HEIGHT, std::string _name)
{
namespace fs = std::filesystem;

    if (!fs::is_directory(path)) {
        std::wcerr << L"错误: " << path << L" 不是有效的文件夹！" << std::endl;
        return;
    }

    int i = 0;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::wstring wFilePath = entry.path().wstring();
            std::wcout << L"正在加载: " << wFilePath << std::endl;

            loadimage(MyImageSet[i], wFilePath.c_str());  // 加载图片
            i++;
        }
    }
    std::cout << "所有图片加载完成！" << std::endl;
}
MyIMAGE::~MyIMAGE()
{
	
}
