#include "SOReferenceModel1Dot1.h"

/****************************************/
/****************************************/

SOReferenceModel1Dot1::SOReferenceModel1Dot1() {
  m_pcRng = CRandom::CreateRNG("argos");
  movingState = 0;
}

/****************************************/
/****************************************/

SOReferenceModel1Dot1::~SOReferenceModel1Dot1() {}

/****************************************/
/****************************************/

void SOReferenceModel1Dot1::Reset() {
  m_cLEDsColor = CColor::BLACK;
  m_deqGroundInput.clear();
  m_deqVelocityInput.clear();
}
/****************************************/
/****************************************/

CCI_SmartObjectAccelerometerSensor::SReading SOReferenceModel1Dot1::GetAccelerometerReading() {
  return m_sAccelerometerInput;
}


/****************************************/
/****************************************/

Real SOReferenceModel1Dot1::GetGroundReading() {
  std::deque<Real>::iterator it;
  UInt32 unBlackWhiteCounter[2] = {0,0};  //unBlackWhiteCounter[0] -> Black; unBlackWhiteCounter[1] -> White.
  float fBlackThreshold = 0.03;  //0.03
  float fWhiteThreshold = 0.85;  //0.85
  for (it = m_deqGroundInput.begin(); it != m_deqGroundInput.end(); it++) {
    if (*it < fBlackThreshold) {
      unBlackWhiteCounter[0] += 1;
    } else if (*it > fWhiteThreshold) {
      unBlackWhiteCounter[1] += 1;
    }
  }

  if (unBlackWhiteCounter[0] > 2) {
    return 0.0f;
  }
  else if (unBlackWhiteCounter[1] > 2) {
    return 1.0f;
  }
  else {
    return 0.5f;
  }
}

/****************************************/
/****************************************/

void SOReferenceModel1Dot1::SetGroundReading(Real s_ground_input) {
  m_deqGroundInput.push_back(s_ground_input);
  if (m_deqGroundInput.size() > 5) {
    m_deqGroundInput.pop_front();
  }
}

/****************************************/
/****************************************/

void SOReferenceModel1Dot1::SetAccelerometerReading(CCI_SmartObjectAccelerometerSensor::SReading s_accelerometer_reading) {
  m_sAccelerometerInput = s_accelerometer_reading;
}

/****************************************/
/****************************************/

void SOReferenceModel1Dot1::SetLEDsColor(const CColor& c_color) {
    m_cLEDsColor = c_color;
}

/****************************************/
/****************************************/

const CColor& SOReferenceModel1Dot1::GetLEDsColor() const {
    return m_cLEDsColor;
}

void SOReferenceModel1Dot1::GetVelocityReading(Real* velocities) {
  std::deque<Real>::iterator it;
  UInt16 i = 0;
  for (it = m_deqVelocityInput.begin(); it != m_deqVelocityInput.end(); it++) {
    velocities[i] = *it;
    i++;
  }
}

void SOReferenceModel1Dot1::SetVelocityReading(Real c_velocity) {
    m_deqVelocityInput.push_back(c_velocity);
    if (m_deqVelocityInput.size() > 4) {
      m_deqVelocityInput.pop_front();
    }
}
