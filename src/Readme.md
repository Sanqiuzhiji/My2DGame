MyGameProject/
├── MyGameProject.sln          # Visual Studio 解决方案文件
├── MyGameProject/             # 项目文件夹
│   ├── MyGameProject.vcxproj  # 项目文件
│   ├── src/                   # 源代码文件夹
│   │   ├── main.cpp           # 主程序入口
│   │   ├── Game.h             # 游戏主类头文件
│   │   ├── Game.cpp           # 游戏主类实现文件
│   │   ├── Player.h           # 玩家类头文件
│   │   ├── Player.cpp         # 玩家类实现文件
│   │   ├── Enemy.h            # 敌人类头文件
│   │   ├── Enemy.cpp          # 敌人类实现文件
│   │   ├── Bullet.h           # 子弹类头文件
│   │   ├── Bullet.cpp         # 子弹类实现文件
│   │   └── ...                # 其他游戏相关类
│   ├── include/               # 第三方库头文件
│   │   └── easyx.h            # EasyX 头文件
│   ├── resources/             # 资源文件夹
│   │   ├── images/            # 图片资源
│   │   ├── sounds/            # 音效资源
│   │   └── fonts/             # 字体资源
│   ├── lib/                   # 第三方库文件
│   │   └── easyx.lib          # EasyX 库文件
│   └── CMakeLists.txt         # CMake 配置文件（可选）
└── README.md                  # 项目说明文件