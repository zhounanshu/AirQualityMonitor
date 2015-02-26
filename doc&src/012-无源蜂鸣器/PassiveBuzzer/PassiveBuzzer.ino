int buzzer=8;//设置控制蜂鸣器的数字 IO 脚
void setup() 
{ 
  pinMode(buzzer,OUTPUT);//设置数字 IO 脚模式，OUTPUT 为辒出
} 
void loop() 
{ 
  unsigned char i,j;//定义变量
  while(1) 
  { 
    for(i=0;i<80;i++)//辒出一个频率的声音
    { 
      digitalWrite(buzzer,HIGH);//发声音
      delay(1);//延时 1ms 
      digitalWrite(buzzer,LOW);//不发声音
      delay(1);//延时 ms 
    } 
    for(i=0;i<100;i++)//辒出另一个频率癿声音
    { 
      digitalWrite(buzzer,HIGH);//发声音
      delay(2);//延时 2ms 
      digitalWrite(buzzer,LOW);//不发声音
      delay(2);//延时 2ms 
    } 
  } 
} 
