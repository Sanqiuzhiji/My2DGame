#include "../include/MyIMAGE.h"

MyIMAGE::MyIMAGE(const TCHAR* path, int IMAGE_WIDTH, int IMAGE_HEIGHT, std::string _name)
{
namespace fs = std::filesystem;

    if (!fs::is_directory(path)) {
        std::wcerr << L"����: " << path << L" ������Ч���ļ��У�" << std::endl;
        return;
    }

    int i = 0;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::wstring wFilePath = entry.path().wstring();
            std::wcout << L"���ڼ���: " << wFilePath << std::endl;

            loadimage(MyImageSet[i], wFilePath.c_str());  // ����ͼƬ
            i++;
        }
    }
    std::cout << "����ͼƬ������ɣ�" << std::endl;
}
MyIMAGE::~MyIMAGE()
{
	
}
