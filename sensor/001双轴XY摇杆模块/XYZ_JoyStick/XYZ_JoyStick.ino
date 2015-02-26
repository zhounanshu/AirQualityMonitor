/****************************************************************************************************************/
/*                                   XYZ_JoyStick 测试程序                                                      */
/*              +5  ：连接Arduino MEGA 2560   +5V电源IO接口                                                     */
/*		GND ：连接Arduino MEGA 2560   GND接地IO接口                                                     */
/*              VRX ：按程序设计连接到Arduino MEGA 2560 模拟IO接口（A0~A15）                                    */
/*		VRY ：按程序设计连接到Arduino MEGA 2560 模拟IO接口（A0~A15）                                    */
/*              SW  ：按程序设计连接到Arduino MEGA 2560 数字IO接口（D0~D53）                                    */                                                                                                     
/*                                                                                                              */
/*                                                                                                              */
/****************************************************************************************************************/


/****************************************************************************************************************/
//传感器端口设置
int JoyStick_X = 0;			 //设置端口名JoyStick_X和对应的端口标号”0”
int JoyStick_Y = 1;			 //设置端口名JoyStick_Y和对应的端口标号”1”
int JoyStick_Z = 3; 			 //设置端口名JoyStick_Z和对应的端口标号”3” 
/****************************************************************************************************************/



/****************************************************************************************************************/
//初始化变量、管脚模式、调用函数库等
void setup() { 
	pinMode(JoyStick_X, INPUT);      //将JoyStick_X端口设置成输入端口（此处输入指传感器输入到Arduino 板子）
	pinMode(JoyStick_Y, INPUT); 
	pinMode(JoyStick_Z, INPUT); 
	Serial.begin(9600);             //使用Arduino串口监视器，设置传输速率（默认9600即可） 
} 
/****************************************************************************************************************/



/****************************************************************************************************************/
//连续执行函数loop函数内的功能语句
void loop() { 
		int x,y,z;                           //设置变量
                x=analogRead(JoyStick_X);            //读取标号为JoyStick_X的端口模拟信号，并存入变量x 中
		y=analogRead(JoyStick_Y); 
	        z=digitalRead(JoyStick_Z);           //读取标号为JoyStick_X的端口模拟信号，并存入变量x 中
                Serial.print("x:");                 //在串口监视器中显示“x:”
		Serial.print(x ,DEC);               //在串口监视器中显示变量x 的值
		Serial.print(",  "); 
                Serial.print("y:"); 
		Serial.print(y ,DEC); 
		Serial.print(",  ");
                Serial.print("z:"); 
		Serial.println(z ,DEC); 
		delay(1000);                          // 延时100*1ms
}

