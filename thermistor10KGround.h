#ifndef Thermistor10KGround_H
#define Thermistor10KGround_H

#include <Arduino.h>
#include <log.h>


class Thermistor10KGround {
    public:
        Thermistor10KGround(double& _beta, double& _r25): beta(_beta), r25(_r25) {
            
        }
        double getTemp(double rThermistor) {
            const double  A_0  = 1.0 / refTemp;
            const double  A_1  = 1.0 / beta;
            double tKelvin = 1.0 / (A_0 + A_1 * log(rThermistor / r25));
            double tCelsius = tKelvin - 273.15;  // convert kelvin to celsius
            return tCelsius;
        }
    private:
        double& beta; // B25/85(K)
        double& r25; // resistance at 25C Kohms
        const double refTemp = 298.15; // 25C
};

#endif

