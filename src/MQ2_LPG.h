// Library: Gas MQ2-LPG
// By: Devan Cakra M.W

#ifndef MQ2_LPG_H
#define MQ2_LPG_H

#include <Arduino.h>

class MQ2Sensor{
  public:
    void begin(int pin);
    void RL(float RL_Value);
    void Ro(float Ro_Value);
    void Volt(float Voltage_Value);
    void BitADC(float bitADC_Value);
    void VRL();
    void getDataCalibration();
    float roCheck();
    float ratioCheck();
    double mCurve(double x1, double x2, double y1, double y2);
    double bCurve(double x, double y);
    float readGas();

  private:
    int _pin;
    float _RL, _Ro, _Voltage, _bitADC;
    float _VRL, _Rs, _Reverseosmosis; 
    float _getDataRo, _getDataRatio, _m, _b;
    float _ratio, _ppm;
};

#endif