// Library: Gas MQ2-LPG
// By: Devan Cakra M.W

#ifndef MQ2_LPG_H
#define MQ2_LPG_H

#include <Arduino.h>

class MQ2Sensor{
  public:
    void begin(int pin);
    void RL(float RL_Value);
    void m(float m_Value);
    void b(float b_Value);
    void Ro(float Ro_Value);
    void Volt(float Voltage_Value);
    void BitADC(float bitADC_Value);
    void gasCalibration();
    float readGas();

  private:
    int _pin;
    float _VRL, _Rs, _ratio, _ppm, _RL, _m, _b, _Ro, _Voltage, _bitADC, gas_read;
};

#endif