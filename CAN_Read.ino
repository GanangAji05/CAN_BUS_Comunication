#include <SPI.h>
#include <mcp2515.h>

#define CS PB6

struct can_frame canMsg;
MCP2515 mcp2515(CS);

void setup(){
  Serial.begin(9600);

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop(){
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK){
//    Serial.print("ID: ");
//    Serial.print(canMsg.can_id,HEX);
//    Serial.println();
//    Serial.print("DLC: ");
//    Serial.print(canMsg.can_dlc);
//    Serial.println();
     Serial.print("POT: ");
    
    for (int i = 0 ; i <= canMsg.can_dlc; i++){
      Serial.print(canMsg.data[0]);
      Serial.print(" ");
      Serial.println();
  }
 }
}
