#include <SPI.h>
#include <mcp2515.h>

#define POT A1

double lastAvg = 0.0;

struct can_frame canMsg1;
MCP2515 mcp2515(10);

void setup(){
  canMsg1.can_id  = 0x036;
  canMsg1.can_dlc = 1;

//  canMsg1.data[1] = 2;
//  canMsg1.data[2] = 3;
//  canMsg1.data[3] = 4;
//  canMsg1.data[4] = 5;
//  canMsg1.data[5] = 6;
//  canMsg1.data[6] = 7;
//  canMsg1.data[7] = 8;
//
//  while (!Serial);
  Serial.begin(9600);
  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop(){
  int pot_value = 0;
  int i = 0;
  int cur_avg = 0;
  pot_value = analogRead(POT);
  cur_avg = (pot_value*0.1) + ((0)*(1-0.1))-19;
  //int potensio = map(pot_value,0,1023,0,255);
  Serial.print("POT : ");
  Serial.println(cur_avg);
  lastAvg = cur_avg;

  canMsg1.data[0] = cur_avg;
  
  mcp2515.sendMessage(&canMsg1);

  delay(100);
}
