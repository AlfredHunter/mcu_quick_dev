##工程目录说明

![一级目录](http://upload-images.jianshu.io/upload_images/281893-60623dd626724f48.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- application：
放置不同的业务功能代码
- boards：
放置对应不同 PCB 板载驱动的文件
- Build：
放置工程编译生成的文件
- documents
放置开发需要用到的参考文档，比如芯片的 datasheet
- kernel
单片机 RTOS 的系统文件
- platforms
放置不同的单片机或 IDE 平台的文件和驱动代码
- projects
放置工程文件

![展开目录](http://upload-images.jianshu.io/upload_images/281893-c53a7ef6b776077b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

- applications/xxx:
不同的应用功能，对应新建不同的目录
- boards/xxx:
存放不同的 PCB 板载驱动文件
- Build/demos/xxx:
由工程配置文件把编译输出的文件设置放到此目录下
- kernel/RTOS/xxx:
以后方便扩展，可以能会用到不同的 RTOS，或不使用 RTOS 时，放置空的系统接口文件
目录 `kernel/xxx` 除了 `kernel/RTOS` 外，可能以后还会扩展 RTOS 级的其他文件
- platforms/Cortex-M3：
放置 Cortex-M3 的内核的平台文件
- platforms/MCUs/xxx:
放置不同单片机外设库文件和对应 IDE 的平台文件
- projects/STM32F1xx/demo/EWARM:
对应 IAR 的工程文件
- projects/STM32F1xx/demo/RVMDK:
对应 KEIL 的工程文件