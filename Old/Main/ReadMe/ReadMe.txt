Main文件夹下主要存放的是用户自己编写的文件。
为了方便起见和保持逻辑整洁，现做出以下规定：

在Core/Src的main.h中引入SimpleMain.h即可。
具体看起来像是这样：
/* USER CODE BEGIN Includes */
////////////////////////////////////////////////////////////////
#include"SimpleMain.h"
////////////////////////////////////////////////////////////////
/* USER CODE END Includes */

在Core/Inc的main.c中仅需要修改while(1)附近的代码。
具体看起来像是这样：
/* USER CODE BEGIN WHILE */
////////////////////////////////////////////////////////////////
Main_Simple();
////////////////////////////////////////////////////////////////
while (1)
{
  /* USER CODE END WHILE */

SimpleMain.c和SimpleMain.h是为了简化配置过程而建立的。
SimpleMain.h中引用所有需要的头文件，分别是：C库文件，驱动文件等，详见其中。
SimpleMain.c中打包了一些初始化函数等，详见其中。

每个驱动文件模块需包括：Name.c和Name.h。
在Name.c中仅包含Name.h，在Name.h中仅需包含SimpleMain.h。
在Name.c中定义函数，Name.h中声明函数以及相关宏定义，和对该模块的说明。
某些较为复杂的驱动程序还包含了对应文件夹
