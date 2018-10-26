/* Dynamixel Basic Position Control Example
 
 Turns left the dynamixel , then turn right for one second,
 repeatedly.
 
                   Compatibility
 CM900                  O
 OpenCM9.04             O
 
                  Dynamixel Compatibility
               AX    MX      RX    XL-320    Pro
 CM900          O      O      O        O      X
 OpenCM9.04     O      O      O        O      X
 **** OpenCM 485 EXP board is needed to use 4 pin Dynamixel and Pro Series ****
 
 created 16 Nov 2012
 by ROBOTIS CO,.LTD.
 */
/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define ID_NUM_3 1
#define ID_NUM_4 2
/* Control table defines */
#define GOAL_POSITION 30

Dynamixel Dxl(DXL_BUS_SERIAL3);

void setup() {
  
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  Dxl.jointMode(ID_NUM_3); //jointMode() is to use position mode
  Dxl.jointMode(ID_NUM_4);
}

void loop() {  
  //Turn dynamixel ID 1 to position 0  
  Dxl.writeWord(ID_NUM_3, GOAL_POSITION, 200); //Compatible with all dynamixel serise
  // Wait for 1 second (1000 milliseconds)
  delay(10);
  Dxl.writeWord(ID_NUM_4, GOAL_POSITION, 200); 
  delay(300);         

  //Turn dynamixel ID 1 to position 300
  Dxl.writeWord(ID_NUM_3, GOAL_POSITION, 800);
  delay(10);
  Dxl.writeWord(ID_NUM_4, GOAL_POSITION, 800);
  // Wait for 1 second (1000 milliseconds)
  delay(300);              
}
