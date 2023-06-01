
#include "SmartObjectDAO.h"

namespace argos {

	SmartObjectDAO::~SmartObjectDAO() {}

	/****************************************/
	/****************************************/

	void SmartObjectDAO::SetRobotIdentifier(const UInt32& un_robot_id) {
		m_unRobotIdentifier = un_robot_id;
	}

	/****************************************/
	/****************************************/

	const UInt32& SmartObjectDAO::GetRobotIdentifier() const{
		return m_unRobotIdentifier;
	}

	/****************************************/
	/****************************************/

	CRandom::CRNG* SmartObjectDAO::GetRandomNumberGenerator() const {
		return m_pcRng;
	}




}
