#ifndef SOREFERENCE_MODEL_1_1_H
#define SOREFERENCE_MODEL_1_1_H

#include "SmartObjectDAO.h"

using namespace argos;

class SOReferenceModel1Dot1: public SmartObjectDAO {
  public:
    /*
     *  Class constructor.
     */
    SOReferenceModel1Dot1();

    /*
     * Class destructor.
     */
    virtual ~SOReferenceModel1Dot1();

    /*
     * Reset function.
     */
    virtual void Reset();
    
     /*
     * Getter for the proximity input.
     */
    	CCI_SmartObjectAccelerometerSensor::SReading GetAccelerometerReading();


    /*
     * Getter for the ground input.
     */
     Real GetGroundReading();

    /*
     * Setter for the ground input.
     */
    void SetGroundReading(Real s_ground_input);

     /*
     * Setter for the accelerometer reading.
     */
    void SetAccelerometerReading(CCI_SmartObjectAccelerometerSensor::SReading s_accelerometer_reading);

    /*
     * Setter for the RGB LEDs color.
     */
    void SetLEDsColor(const CColor& c_color);

    /*
     * Getter for the RGB LEDs color.
     */
    const CColor& GetLEDsColor() const;

    void GetVelocityReading(Real* velocities);

    void SetVelocityReading(Real c_velocity);


  private:


    /*
    * The velocity input.
    */
    std::deque<Real> m_deqVelocityInput;

    /*
     * The ground sensors input.
     */
    CCI_SmartObjectAccelerometerSensor::SReading m_sAccelerometerInput;

    /*
     * The ground sensors input.
     */
    std::deque<Real> m_deqGroundInput;

    /*
     * The ground sensors input.
     */
    Real m_sGroundInput;

    /*
     * The color of RGB LEDs  (output variable).
     */
    CColor m_cLEDsColor;

    


};

#endif
