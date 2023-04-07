## Mencari Nilai Ro (Reverse Osmosis)

```sh
#include <MQ2_LPG.h> // Library declaration.
#define SensorMQ2_Pin A0 // Sensor pin declaration.
MQ2Sensor mySensor; // Calls the MQ2Sensor class declared as the mySensor object.

void setup() {
  Serial.begin(115200); // Baudrate : 115200
  mySensor.begin(SensorMQ2_Pin); // Initialize this sensor through the begin method. It is accessed from the mySensor object. MQ2 Sensor Pin used: A0.
}

// Gas Calibration Data.
#define RL_Value 10
#define x1_Value 0
#define x2_Value 0
#define y1_Value 0
#define y2_Value 0
#define x_Value 0
#define y_Value 0
#define Ro_Value 0
#define Voltage_Value 3.3
#define bitADC_Value 1023.0

void calibration(){
  mySensor.RL(RL_Value); // Setting Resistance Load
  mySensor.Ro(Ro_Value); // Setting Reverse Osmosis
  mySensor.Volt(Voltage_Value); // Setting voltage in sensor
  mySensor.BitADC(bitADC_Value); // Setting bit ADC board development
  mySensor.mCurve(x1_Value, x2_Value, y1_Value, y2_Value); // Setting mCurve
  mySensor.bCurve(x_Value, y_Value); // Setting bCurve
  mySensor.getDataCalibration(); // Gets data calibration
  mySensor.viewDataCalibration(); // Prints the data calibration
}

void loop() {
  calibration(); // Calls calibration method.
  delay(200); // Delay 200ms
}
```

<br/><br/>

## Mencari Titik Koordinat Yang Sesuai
