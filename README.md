# MarrymeRobot
说明：HC_SR04两个文件是针对超声波模块的初始化和使用，BY8001两个文件是针对语音模块的初始化和使用。

####超声波模块HC-SR04
包含两个IO，其中TRIG为输入，ECHO为输出。使用时由MCU向TRIG给一个10us或以上的高电平脉冲，在脉冲结束后，超声波模块即开始测距，并在测距完成后，在ECHO引脚输出高电平脉冲，脉冲长度即超声波从发送到接收的时长。
两个函数
- void HCSR04_Init(void)，用于初始化超声波模块，放在主函数的SystemInit()和SysTick_Initial()函数后边。
- u32 HCSR04_Measure(void)，用于测距，返回值即为测得距离。

####语音模块BY8001
主要关注6个IO，其中BUSY为输出，高电平表示播放中，低电平表示未播放；IO1~IO5为输入，分别控制播放的声音片段。
两个函数
- void BY8001_Init(void)，用于初始化，放在主函数的SystemInit()和SysTick_Initial()函数后边。
- void BY8001_Play(u8 number)，用于播放声音，输入为1~5五个数字，分别代表五段声音。
