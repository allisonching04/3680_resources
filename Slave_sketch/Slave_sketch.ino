/***********************************************************
  BLE CC41A Bluetooth Master setup sketch
  This is a clone of the HM10 BLE board
  In the Serial Monitor ensure that 'Both NL and CR' is selected
  Select a Baud Rate of 9600
  enter the following commands into the MASTER unit
  AT - should return OK
  AT+RENEW - restores to factory settings
  AT+RESET - software reset
  AT+ROLE1 - sets to Master
  AT+INQ - searches for nearby Slave units
  AT+CONN1 - connects to Slave Unit 1
************************************************************/
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(4, 5); // Setup for RX, TX
void setup()
{
  // Start the hardware serial port
  Serial.begin(9600);
  pinMode(13, OUTPUT); // onboard LED
  digitalWrite(13, LOW); // switch OFF LED
  bluetooth.begin(9600);

  pinMode(11, OUTPUT);
}
void loop()
{
  bluetooth.listen();
  // while there is data coming in, read it
  // and send to the hardware serial port:
  if (bluetooth.available())
  {
    int inByte = bluetooth.read() - '0'; //Subtract ASCII 0 char to convert bytes
    int LED = inByte;
    Serial.println(LED);
    if (LED == 1)
    {
      digitalWrite(11, HIGH);
    }

    if (LED == 0)
    {
      digitalWrite(11, LOW);
    }
  }
  //S
}
