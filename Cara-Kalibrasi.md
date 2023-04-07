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

<p align="justify">Setelah data Ro didapatkan, maka langkah selanjutnya yaitu memasukkan data Ro tersebut ke bagian #define lalu upload program.</p>

<br/><br/>

## Mencari Titik Koordinat Yang Sesuai

<p align="justify">Bukalah link berikut: https://automeris.io/WebPlotDigitizer/ , lalu klik "Launch Now!". Kemudian klik "Load Image". Hal tersebut dapat anda ketahui selengkapnya di bawah ini.</p>
<img src="https://user-images.githubusercontent.com/54527592/230691437-6e734c51-a1a1-499b-ab66-c18921d6f26b.jpg"/>
<p align="justify">Upload gambar sesuai dengan link yang telah disediakan: https://lihat.in/api/MQ2CalibrationPicture.</p><br/>
<p align="justify">Kemudian memilih tipe plot: 2D (X-Y) Plot. Selanjutnya klik "Align Axes" → "Proceed".</p>
<img src="https://user-images.githubusercontent.com/54527592/230691665-0cfe7167-42a9-4b24-8cde-1571c080a7e2.jpg"/><br/>
<p align="justify">Selanjutnya, anda harus memberikan batas nilai, mulai dari X1 → X2 → Y1 → Y2. Selanjutnya klik "Complete!" untuk mengatur X-Axis dan Y-Axis. Jangan lupa untuk mencentang bagian "Log Scale" → "OK".</p>
<img src="https://user-images.githubusercontent.com/54527592/230692139-07392ab0-8119-4a60-ba9e-daa5cfeb4a01.jpg"/><br/>
<p align="justify">Langkah berikutnya, klik "Add Point (A)", lalu pilih kurva yang diinginkan (dalam hal ini hanya menggunakan LPG dan Propane). Jangan lupa cari titik koordinat yang saling berhimpitan satu sama lain seperti yang ditampilkan pada gambar berikut.</p>
<img src="https://user-images.githubusercontent.com/54527592/230692688-5fdb713c-d8e0-41e0-88d8-cb930f8af38b.jpg"/><br/>
<p align="justify">Kemudian, klik "View Data" untuk mengetahui nilai dari titik koordinat yang telah dipilih tadi. Misalnya seperti yang terlihat pada gambar di bawah ini.</p>
<img src="https://user-images.githubusercontent.com/54527592/230692817-40d2f148-5cd2-4255-9fd3-49a02a9cd3c9.jpg"/><br/>
<p align="justify">Langkah terakhir, data koordinat diatas kemudian dimasukkan kedalam kode yang ada di Arduino IDE bagian #define.</p>

```sh
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
#define Ro_Value 2.7
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
  air_quality_detection = mySensor.readGas(); // Calls gas LPG data through the readGas method. It is accessed from the mySensor object.
  Serial.println("Air Quality Value: "+String(air_quality_detection)+"ppm\n"); // Prints the air quality value.
  delay(200); // Delay 200ms
}
```

<br/>
<p align="justify">SELESAI, selamat mencoba.</p>
