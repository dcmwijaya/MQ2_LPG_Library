// Library: Gas MQ2-LPG
// By: Devan Cakra M.W

#include <MQ2_LPG.h> // Library declaration.
#define SensorMQ2_Pin A0 // Sensor pin declaration.
int air_quality_detection = 0; // Variable declaration.

MQ2Sensor mySensor; // Calls the MQ2Sensor class declared as the mySensor object.

void setup() {
  Serial.begin(115200); // Baudrate : 115200
  mySensor.begin(SensorMQ2_Pin); // Initialize this sensor through the begin method. It is accessed from the mySensor object. MQ2 Sensor Pin used: A0.
}

// Gas Calibration Data.
#define RL_Value 10
#define x1_Value 199.150007852152
#define x2_Value 797.3322752256328
#define y1_Value 1.664988323698715
#define y2_Value 0.8990240080541785
#define x_Value 497.4177875376839
#define y_Value 1.0876679972710004
#define Ro_Value 2.45
#define Voltage_Value 3.3
#define bitADC_Value 1023.0

void calibration(){
  mySensor.RL(RL_Value);
  mySensor.Ro(Ro_Value);
  mySensor.Volt(Voltage_Value);
  mySensor.BitADC(bitADC_Value);
  mySensor.mCurve(x1_Value, x2_Value, y1_Value, y2_Value);
  mySensor.bCurve(x_Value, y_Value);
  mySensor.getDataCalibration();
}

void loop() {
  calibration(); // Calls calibration method.
  air_quality_detection = mySensor.readGas(); // Calls gas LPG data through the readGas method. It is accessed from the mySensor object.
  Serial.println("Air Quality Value: "+String(air_quality_detection)+"ppm\n"); // Prints the air quality value.
  delay(200); // Delay 200ms
}
