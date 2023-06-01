#ifndef SMARTOBJECT_DAO_H
#define SMARTOBJECT_DAO_H

#include <vector>
#include <deque>

#include <argos3/core/utility/math/rng.h>
#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/plugins/robots/smart-object/control_interface/ci_smartobject_accelerometer_sensor.h>
#include <argos3/plugins/robots/smart-object/control_interface/ci_smartobject_ground_sensor.h>
#include <argos3/plugins/robots/smart-object/control_interface/ci_smartobject_leds_actuator.h>

namespace argos {
	class SmartObjectDAO {
		public:

			virtual ~SmartObjectDAO();

			/*
			 * Reset function.
			 */
			virtual void Reset() = 0;

			/*
			 * Setter for the robot idientifier.
			 */
			void SetRobotIdentifier(const UInt32& un_robot_id);

			/*
			 * Setter for the velocity.
			 */
			void SetVelocity(const Real& c_velocity_vector);

			/*
			 * Getter for the robot identifier.
			 */
			const UInt32& GetRobotIdentifier() const;

			/*
			 * Getter for the random number generetor.
			 */
			CRandom::CRNG* GetRandomNumberGenerator() const;


			void setMovingState(UInt8 state) {
				movingState = state;
			}

			UInt8 getMovingState() {
				return movingState;
			}


	/*******************/
	/* Virtual classes */
	/*******************/

			
			virtual CCI_SmartObjectAccelerometerSensor::SReading GetAccelerometerReading() {					// RM 1.2
				return CCI_SmartObjectAccelerometerSensor::SReading();
			};

			/*
			 * Getter for the proximity input.
			 */

			virtual Real GetGroundReading() {
				return 0.0f;
			};
			/*
			 * Setter for the ground input.
			 */
			virtual void SetGroundReading(Real s_ground_input) {};

				/*
			 * Setter for the ground input.
			 */
			virtual void SetAccelerometerReading(CCI_SmartObjectAccelerometerSensor::SReading s_accelerometer_reading) {};


			virtual void SetVelocityReading(Real c_velocity) {};
			virtual void GetVelocityReading(Real* velocities) {
				for (UInt16 i=0; i<20; i++) {
					velocities[i] = 0;
				}
			};




      /*
       * Setter for the RGB LEDs color.
       */
      virtual void SetLEDsColor(const CColor& c_color) {};

      /*
       * Getter for the RGB LEDs color.
       */
      virtual const CColor& GetLEDsColor() const {
          CColor& ccEmptyVariable = CColor::BLACK;
          return ccEmptyVariable;

      }


	  /*	virtual Real GetVelocity() {return 0.0f;};*/


		protected:

			/*
			 * The robot identifier.
			 */
			UInt32 m_unRobotIdentifier;

			/*
			 * Pointer to the random number generator.
			 */
			CRandom::CRNG* m_pcRng;

			UInt8 movingState;

	};
}


#endif
