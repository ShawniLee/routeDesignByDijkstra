#include "HX711.h"
#include  "Fade.h"
float Weight = 0;
float LastWeight=0;
float Change=0;
int situation=1;
int led1=9;
int led2=10;
int led3=11;
int motor1=5;
int motor2=6;
int motor3=13;
void setup()
{
  Init_Hx711();       //初始化HX711模块连接的IO设置

  Serial.begin(9600);
  //Serial.print("Welcome to use!\n");

  delay(3000);
  Get_Maopi();    //获取毛皮
  delay(1000);
}

void loop()
{
  //准备阶段
  while(1){
    situation=1;
    Weight = Get_Weight();  //计算放在传感器上的重物重量
    Change=Weight-LastWeight;//计算重量差值
    // 差值小于3时（无重量变化）
    if(Change<3){
      delay(1000);        //延时1s
      continue;
    }
    else if(Change>4&&Change<8&&situation==1){
      fade(led1);
      delay(1000);        //延时1s
      situation=2;
      continue;
    }
    else if(Change>900&&Change<1100&&situation==2){
      fade(led2);
      delay(1000);        //延时1s
      continue;
      situation=3;
    }
    else if(Change>4&&Change<8&&situation==3){
      fade(led3);
      delay(1000);        //延时1s
      break;
    }
  }

  //正式开始游戏
  while(1)
  {
    situation=1;
    Weight = Get_Weight();  //计算放在传感器上的重物重量
    Change=Weight-LastWeight;//计算重量差值 单位为g
    //第一秒
    if(Change>=900&&Change<=1100&&situation==1){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      situation=2;
      continue;
    }
    //第二秒
    if(Change>=1800&&Change<=2200&&situation==2){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      analogWrite(led2,200);
      analogWrite(motor2,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(led2,0);
      analogWrite(motor2,0);
      situation=3;
      continue;
    }
    //第三秒
    if(Change>=1800&&Change<=2200&&situation==3){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      analogWrite(led3,200);
      analogWrite(motor3,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(led3,0);
      analogWrite(motor3,0);
      situation=4;
      continue;
    }
    //第四秒
    if(Change>=1800&&Change<=2200&&situation==4){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      analogWrite(led2,200);
      analogWrite(motor2,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(led2,0);
      analogWrite(motor2,0);
      situation=5;
      continue;
    }
    //第五秒
    if(Change>=900&&Change<=1100&&situation==5){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      situation=6;
      continue;
    }
    //第六秒
    if(Change>=2700&&Change<=3300&&situation==6){
      analogWrite(led1,200);
      analogWrite(motor1 ,200);
      analogWrite(motor2,200);
      analogWrite(led2,200);
      analogWrite(motor3,200);
      analogWrite(led3,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(motor2,0);
      analogWrite(led2,0);
      analogWrite(motor3,0);
      analogWrite(led3,0);
      situation=7;
      continue;
    }
    //第七秒
    if(Change>=900&&Change<=1100&&situation==7){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      situation=8;
      continue;
    }
    //第八秒
    if(Change>=1800&&Change<=2200&&situation==8){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      analogWrite(led2,200);
      analogWrite(motor2,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(led2,0);
      analogWrite(motor2,0);
      situation=9;
      continue;
    }
    //第九秒
    if(Change>=1800&&Change<=2200&&situation==9){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      analogWrite(led3,200);
      analogWrite(motor3,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(led3,0);
      analogWrite(motor3,0);
      situation=10;
      continue;
    }
    //第十秒
    if(Change>=1800&&Change<=2200&&situation==10){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      analogWrite(led2,200);
      analogWrite(motor2,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(led2,0);
      analogWrite(motor2,0);
      situation=11;
      continue;
    }
    //第十一秒
    if(Change>=900&&Change<=1100&&situation==11){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      delay(2000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      situation=12;
      continue;
    }
    //第十二秒
    if(Change>=2700&&Change<=3300&&situation==12){
      analogWrite(led1,200);
      analogWrite(motor1,200);
      analogWrite(motor2,200);
      analogWrite(led2,200);
      analogWrite(motor3,200);
      analogWrite(led3,200);
      delay(30000);
      analogWrite(led1,0);
      analogWrite(motor1,0);
      analogWrite(motor2,0);
      analogWrite(led2,0);
      analogWrite(motor3,0);
      analogWrite(led3,0);
      situation=1;
      continue;
    }
  }
}
