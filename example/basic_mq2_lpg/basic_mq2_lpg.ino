// Library: Gas MQ2-LPG
// By: Devan Cakra M.W

#include "MQ2_LPG.h" // library declaration
#define MQ2PIN A0 // mq2 pin declaration

MQ2Sensor mq2(MQ2PIN); // create a new object with the name mq2 to hold the MQ2Sensor class

void setup() {
  Serial.begin(9600); // default baudrate for the Arduino board
  mq2.begin(); // initiate mq2 sensor
}

// gas calibration data
#define RL_Value 50
#define x1_Value 199.150007852152
#define x2_Value 797.3322752256328
#define y1_Value 1.664988323698715
#define y2_Value 0.8990240080541785
#define x_Value 497.4177875376839
#define y_Value 1.0876679972710004
#define Ro_Value 4.26
#define Voltage_Value 5.0
#define bitADC_Value 1023.0

void calibration(){
  mq2.RL(RL_Value); // setting resistance load
  mq2.Ro(Ro_Value); // setting reverse osmosis
  mq2.Volt(Voltage_Value); // setting voltage in sensor
  mq2.BitADC(bitADC_Value); // setting bit ADC board development
  mq2.mCurve(x1_Value, x2_Value, y1_Value, y2_Value); // setting mCurve
  mq2.bCurve(x_Value, y_Value); // setting bCurve
  mq2.getCalibrationData(); // gets calibration data
  mq2.viewCalibrationData(); // print to serial monitor: calibration data
}

void loop() {
  calibration(); // calls calibration method
  mq2.readGas(); // reading mq2 sensor data
  mq2.viewGasData(); // print to serial monitor: gas value & status
  delay(3000); // delay for 3 seconds
}
