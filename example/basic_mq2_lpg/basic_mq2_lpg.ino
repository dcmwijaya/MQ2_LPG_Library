// Library: Gas MQ2-LPG
// By: Devan Cakra M.W

#include <MQ2_LPG.h> // Library declaration.
#define SensorMQ2_Pin A0 // Sensor pin declaration.
int gas_lpg_read=0; // Variable declaration.
MQ2Sensor mySensor; // Calls the MQ2Sensor class declared as the mySensor object.

void setup() {
  // Initialize this sensor through the init method. It is accessed from the mySensor object.
  mySensor.begin(SensorMQ2_Pin); // MQ2 Sensor Pin used: 34.
}

// Gas Calibration Data.
#define RL_Value 10
#define m_Value -0.44953
#define b_Value 1.23257
#define Ro_Value 2.7
#define Voltage_Value 3.3
#define bitADC_Value 1023.0
void calibration(){
  mySensor.RL(RL_Value);
  mySensor.m(m_Value);
  mySensor.b(b_Value);
  mySensor.Ro(Ro_Value);
  mySensor.Volt(Voltage_Value);
  mySensor.BitADC(bitADC_Value);
}

void loop() {
  calibration(); // Calls calibration method.
  gas_lpg_read = mySensor.readGas(); // Calls gas LPG data through the readGas method (Float -> Integer). It is accessed from the mySensor object.
  Serial.println("Gas LPG Value: "+String(gas_lpg_read)+"ppm"); // Prints the gas LPG value.
}
