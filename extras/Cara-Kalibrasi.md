## Mencari Nilai Ro (Reverse Osmosis)

```ino
#include "MQ2_LPG.h" // library declaration
#define MQ2PIN A0 // mq2 pin declaration

MQ2Sensor mq2(MQ2PIN); // create a new object with the name mq2 to hold the MQ2Sensor class

void setup() {
  Serial.begin(9600); // default baudrate for the Arduino board
  mq2.begin(); // initiate mq2 sensor
}

// gas calibration data
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
  mq2.RL(RL_Value); // setting resistance load
  mq2.Ro(Ro_Value); // setting reverse osmosis
  mq2.Volt(Voltage_Value); // setting voltage in sensor
  mq2.BitADC(bitADC_Value); // setting bit ADC board development
  mq2.mCurve(x1_Value, x2_Value, y1_Value, y2_Value); // setting mCurve
  mq2.bCurve(x_Value, y_Value); // setting bCurve
  mq2.getDataCalibration(); // gets data calibration
  mq2.viewDataCalibration(); // print to serial monitor: data calibration
}

void loop() {
  calibration(); // calls calibration method
  delay(3000); // delay for 3 seconds
}
```

<p align="justify">Setelah data Ro didapatkan, maka langkah selanjutnya yaitu memasukkan data Ro tersebut ke bagian #define lalu upload program.</p>

<br/><br/>

## Mencari Titik Koordinat Yang Sesuai

<p align="justify">Bukalah link berikut: https://automeris.io/WebPlotDigitizer/ , lalu klik "Launch Now!". Kemudian klik "Load Image". Hal tersebut dapat anda ketahui selengkapnya di bawah ini.</p>
<img src="https://user-images.githubusercontent.com/54527592/230691437-6e734c51-a1a1-499b-ab66-c18921d6f26b.jpg"/>
<p align="justify">Upload gambar sesuai dengan link yang telah disediakan: <a href="https://github.com/devancakra/MQ2_LPG_Library/assets/54527592/ed1eb989-1353-4678-97be-7fc626425aa6">Klik disini</a>.</p><br/>
<p align="justify">Kemudian memilih tipe plot: 2D (X-Y) Plot. Selanjutnya klik "Align Axes" → "Proceed".</p>
<img src="https://user-images.githubusercontent.com/54527592/230691665-0cfe7167-42a9-4b24-8cde-1571c080a7e2.jpg"/><br/>
<p align="justify">Selanjutnya, anda harus memberikan batas nilai, mulai dari X1 → X2 → Y1 → Y2. Selanjutnya klik "Complete!" untuk mengatur X-Axis dan Y-Axis. Jangan lupa untuk mencentang bagian "Log Scale" → "OK".</p>
<img src="https://user-images.githubusercontent.com/54527592/230692139-07392ab0-8119-4a60-ba9e-daa5cfeb4a01.jpg"/><br/>
<p align="justify">Langkah berikutnya, klik "Add Point (A)", lalu pilih kurva yang diinginkan (dalam hal ini hanya menggunakan LPG dan Propane). Jangan lupa cari titik koordinat yang saling berhimpitan satu sama lain seperti yang ditampilkan pada gambar berikut.</p>
<img src="https://user-images.githubusercontent.com/54527592/230692688-5fdb713c-d8e0-41e0-88d8-cb930f8af38b.jpg"/><br/>
<p align="justify">Kemudian, klik "View Data" untuk mengetahui nilai dari titik koordinat yang telah dipilih tadi. Misalnya seperti yang terlihat pada gambar di bawah ini.</p>
<img src="https://user-images.githubusercontent.com/54527592/230692817-40d2f148-5cd2-4255-9fd3-49a02a9cd3c9.jpg"/><br/>
<p align="justify">Langkah terakhir, data koordinat diatas kemudian dimasukkan kedalam kode yang ada di Arduino IDE bagian #define.</p>
