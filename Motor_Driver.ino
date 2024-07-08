#include <OzIDManager.h>
#include <OzDCMotorControllerL298N.h>
 
OzIDManager* manager;
OzDCMotorControllerL298N* dcMotorController;
 
const DCMotorMode motorMode = DCMotorMode::PWM;  //Default value: PWM
const DCMotorUnit motorUnit = DCMotorUnit::BOTH;  //Default value: MOTOR_B
const int inPin1 = 14;  //Default value: 14
const int inPin2 = 15;  //Default value: 15
const int inPin3 = 16;  //Default value: 16
const int inPin4 = 17;  //Default value: 17
const int ENA = 9;
const int ENB = 10;
 
void setup()
{
  Serial.begin(115200);
 
  manager = new OzIDManager;
  manager->_sendACK = true;
  manager->_checksum = true;
 
  OzCommunication::setIDManager(manager);
 
  dcMotorController =
    new OzDCMotorControllerL298N(motorMode, inPin1, inPin2, inPin3, inPin4, ENA, ENB);
   
  int x=1;
  manager->sendLinkSetup();
  manager->PrintWelcomeLine(dcMotorController, x++, "MyDCMotors");
}
 
void loop()
{
    OzCommunication::communicate();
    dcMotorController->ownLoop();
}