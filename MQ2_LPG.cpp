// Library: Gas MQ2-LPG
// By: Devan Cakra M.W

#include <MQ2_LPG.h>

void MQ2Sensor::begin(int pin) {
  _pin = pin;
}

void MQ2Sensor::RL(float RL_Value){
  _RL = RL_Value;
}

void MQ2Sensor::m(float m_Value){
  _m = m_Value;
}

void MQ2Sensor::b(float b_Value){
  _b = b_Value;
}

void MQ2Sensor::Ro(float Ro_Value){
  _Ro = Ro_Value;
}

void MQ2Sensor::Volt(float Voltage_Value){
  _Voltage = Voltage_Value;
}

void MQ2Sensor::BitADC(float bitADC_Value){
  _bitADC = bitADC_Value;
}

void MQ2Sensor::gasCalibration(){
  _VRL = analogRead(_pin)*(_Voltage/(_bitADC));
  _Rs = ((_Voltage*(_RL))/(_VRL))-(_RL);
  _ratio = ((_Rs)/(_Ro));
  _ppm = pow(10, ((log10(_ratio)-(_b))/(_m)));
}

float MQ2Sensor::readGas() {
  return gas_read = _ppm;
}