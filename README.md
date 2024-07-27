# STM32Simpler
  STM32Simpler基于HAL库和CUBEIDE，旨在为STM初学者提供一个易于上手，易于移植的尽可能完善的底层驱动库。

  这个项目目前还处于筹备状态，相关使用说明还没有完成编写，请酌情使用。欢迎合作交流，欢迎改进斧正。

前言：
  为什么推荐初学者使用CUDEIDE+HAL库来开发？CUBEIDE和HAL库是ST公司最新推出的官方编译器和官方库，同时也是ST公司的主推，是未来主流开发环境大势所趋。
  CUBEIDE可以在ST官网免费下载使用，并且无需多余配置，开箱即用，内置默认HAL库。对于入门的学习者来说，这种方案也是最易上手，学习成本最低的路径。
  最原始的寄存器开发，最为底层也最为高效，但对开发者提出了较高的要求，需要有强大的查阅芯片手册的能力，且具有较低的移植效率（换芯片之后需要重新查阅手册以及配置寄存器）。
  传统的标准库开发，标准库是HAL库的前身，同样是由ST公司开发，但由于种种原因，被新出的HAL库所替代，逐渐被弃用。
  传统的Keil+CUBEMX的开发方式，Keil软件环境配置繁杂，极易出现版本不兼容等情况，一旦出现报错仅凭入门者很难解决，ST公式也正在减少对CUBEMX转Keil的支持力度和维护，转而主推CUBEIDE。
  
目的：
  开源这个驱动库的目的有两个：
  1.帮助基于CUBEIDE的STM项目的快速实现和移植。（实际上也可用于传统Keil开发）
  2.作为已经基本完善的历程，也为各位初学者学习独立完成驱动的编写，提供一个可供参考的蓝本。

敬告：
  我鼓励初学者学习并熟悉硬件功能实现的底层原理，事实上这也是作为一名合格的嵌入式/硬件方向工程师的必修课。
  即使这个驱动库可能为你解决了大部分学习中可能遇到的困难和不便，也并不意味着你可以完全不了解任何的硬件底层原理、通信时序规则等基本功。
  如果你只是出于兴趣爱好接触STM32系列，我很高兴看到你在使用这个库实现你想要达到的效果的同时，还能去了解一些相关的底层知识，在保持这份热爱的同时学到知识。
  但如果你计划尝试相关的竞赛，或者打算在将来从事相关工作，只是一味的依赖别人已经造好的轮子，却不深入了解各个功能的实现过程，甚至从来没有尝试亲自写过驱动程序，如此下去只会是对自己的不负责任。
  我们提升自己的动力应是为了让这个世界更美好，而不是为了通过贬低他人而获得廉价的优越感。闻道有先后，术业有专攻；人外有人，天外有天。永远保持一颗谦虚、低调的求学之心。

其他：
  作者是一名大一学生，是c语言初学者，也是STM32系列单片机的初学者。
  实际上整个驱动库的编写过程，一定程度上也是作者自学c语言的过程，
  考虑到很多初学者都不具备扎实的c语言功底，也不了解驱动程序运行的基本逻辑，该驱动库目前也并未涉及一些c语言的进阶语法，同时没有按照行业惯例的命名方法（通常使用大量省略的短变量名，不利于理解阅读），而是使用了通俗易懂的英文直译（看不懂的英文译成中文就能看懂了），方便大家理解、参考和学习。
  这个库目前只在Github上开源，谢绝任何向其他平台的搬运，这种行为会被认为是侵权。
  其中MPU6050部分，SingTownAI部分，某些内容基于官方历程进行修改，如果你是版权方，并认为自己的权利收到了侵害，请联系作者删除相应代码。
  对于其他部分，除特别标明以外，否则100%由作者一人原创，如果任何人有任何异议，请拿出证据。
  对于通信协议之类的逻辑代码，有雷同之处是非常正常的，这是由通信协议的硬性规定决定的，不接受以此为借口的质疑。
