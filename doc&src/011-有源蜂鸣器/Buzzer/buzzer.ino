int buzzer=11;//设置控制蜂鸣器的数字IO脚
void setup()
{
 pinMode(buzzer,OUTPUT);//设置数字IO脚模式，OUTPUT为输出
}
void loop()
{
  digitalWrite(buzzer,HIGH);//发声音
} 
