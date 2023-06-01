/**
  * @file <loop-functions/IcraLoopFunc.cpp>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @license MIT License
  */

#include "ToffiChLoopFunc.h"


/****************************************/
/****************************************/

ToffiChLoopFunction::ToffiChLoopFunction() {
    m_fObjectiveFunction = 0;
}

/****************************************/
/****************************************/

ToffiChLoopFunction::ToffiChLoopFunction(const ToffiChLoopFunction& orig) {
}

/****************************************/
/****************************************/

ToffiChLoopFunction::~ToffiChLoopFunction() {}

/****************************************/
/****************************************/

void ToffiChLoopFunction::Destroy() {
    m_tRobotStates.clear();
    m_tObjectStates.clear();
    RemoveArena();
   // RemoveRobots();
}

/****************************************/
/****************************************/

void ToffiChLoopFunction::Init(TConfigurationNode& t_tree) {
   TConfigurationNode cParametersNode;


    try {
      cParametersNode = GetNode(t_tree, "params");
      GetNodeAttributeOrDefault(cParametersNode, "build_arena", m_bBuildArena, (bool) false);
      GetNodeAttributeOrDefault(cParametersNode, "number_edges", m_unNumberEdges, (UInt32) 3);
      GetNodeAttributeOrDefault(cParametersNode, "number_boxes_per_edge", m_unNumberBoxes, (UInt32) 1);
      GetNodeAttributeOrDefault(cParametersNode, "length_boxes", m_fLengthBoxes, (Real) 0.25);
      GetNodeAttributeOrDefault(cParametersNode, "maximization", m_bMaximization, (bool) false);
      GetNodeAttributeOrDefault(cParametersNode, "wall_color", m_cWallColor, (UInt32) 0);
      GetNodeAttributeOrDefault(cParametersNode, "dist_radius_epuck", m_fDistributionRadiusEpuck, (Real) 0.65);
      GetNodeAttributeOrDefault(cParametersNode, "dist_radius_smart_object", m_fDistributionRadiusSmartObject, (Real) 0.55);
    } catch(std::exception e) {
    }


    if (m_bBuildArena == true) {
        m_fArenaRadius = GetArenaRadious();
        PositionArena();
    }

    CoreLoopFunctions::Init(t_tree);

    InitRobotStates();

    InitObjectStates();
    m_pcArena->SetArenaColor(CColor::BLACK);

}

/****************************************/
/****************************************/

void ToffiChLoopFunction::Reset() {
    CoreLoopFunctions::Reset();

    m_pcArena->SetArenaColor(CColor::BLACK);
    m_fObjectiveFunction = 0;

    m_tRobotStates.clear();
    m_tObjectStates.clear();

    InitRobotStates();
    InitObjectStates();
}

/****************************************/
/****************************************/

void ToffiChLoopFunction::PostStep() {
    ScoreControl();
}


/****************************************/
/****************************************/

void ToffiChLoopFunction::PostExperiment() {
    //m_fObjectiveFunction = GetScore();
    if (m_bMaximization == true){
        LOG << -m_fObjectiveFunction << std::endl;
    }
    else {
        LOG << m_fObjectiveFunction << std::endl;
    }
}


/****************************************/
/****************************************/

Real ToffiChLoopFunction::GetObjectiveFunction() {
    if (m_bMaximization == true){
        return -m_fObjectiveFunction;
    }
    else {
        return m_fObjectiveFunction;
    }
}

/****************************************/
/****************************************/


Real ToffiChLoopFunction::GetScore() {
    UpdateRobotPositions();
    UpdateObject();
    bool m_bFinalColor;
    Real unScore = 0;
    TObjectStateMap::iterator it;
    for (it = m_tObjectStates.begin(); it != m_tObjectStates.end(); ++it) {
        m_bFinalColor = IsObjectWithColor(it->second.cPosition, it->second.cColor);
        if (!m_bFinalColor){
            unScore+=1;
        }
    }

    return unScore;
}


bool ToffiChLoopFunction::IsObjectWithColor(CVector2 tObjectPosition, CColor tObjectColor) {
    if (tObjectColor == CColor::BLUE){
        return true;
    }
    return false;
}

/****************************************/
/****************************************/

void ToffiChLoopFunction::ScoreControl(){
    m_fObjectiveFunction += GetScore();
}

/****************************************/
/****************************************/

argos::CColor ToffiChLoopFunction::GetFloorColor(const argos::CVector2& c_position_on_plane) {
    return CColor::GRAY50;
}

/****************************************/
/****************************************/

void ToffiChLoopFunction::UpdateRobotPositions() {
    CSpace::TMapPerType& tEpuckMap = GetSpace().GetEntitiesByType("epuck");
    CVector2 cEpuckPosition(0,0);
    for (CSpace::TMapPerType::iterator it = tEpuckMap.begin(); it != tEpuckMap.end(); ++it) {
        CEPuckEntity* pcEpuck = any_cast<CEPuckEntity*>(it->second);
        cEpuckPosition.Set(pcEpuck->GetEmbodiedEntity().GetOriginAnchor().Position.GetX(),
                           pcEpuck->GetEmbodiedEntity().GetOriginAnchor().Position.GetY());

        m_tRobotStates[pcEpuck].cLastPosition = m_tRobotStates[pcEpuck].cPosition;
        m_tRobotStates[pcEpuck].cPosition = cEpuckPosition;
    }
}

/****************************************/
/****************************************/

void ToffiChLoopFunction::UpdateObject() {
    CSpace::TMapPerType& tObjectMap = GetSpace().GetEntitiesByType("smart_object");
    CVector2 cObjectPosition(0,0);
    for (CSpace::TMapPerType::iterator it = tObjectMap.begin(); it != tObjectMap.end(); ++it) {
        CSmartObjectEntity* pcSmartObject = any_cast<CSmartObjectEntity*>(it->second);
        cObjectPosition.Set(pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetX(),
                           pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetY());

        m_tObjectStates[pcSmartObject].cLastPosition = m_tObjectStates[pcSmartObject].cPosition;
        m_tObjectStates[pcSmartObject].cColor = pcSmartObject->GetLEDEquippedEntity().GetLED(0).GetColor();
    }
   
}

/****************************************/
/****************************************/

void ToffiChLoopFunction::InitRobotStates() {

    CSpace::TMapPerType& tEpuckMap = GetSpace().GetEntitiesByType("epuck");
    CVector2 cEpuckPosition(0,0);
    for (CSpace::TMapPerType::iterator it = tEpuckMap.begin(); it != tEpuckMap.end(); ++it) {
        CEPuckEntity* pcEpuck = any_cast<CEPuckEntity*>(it->second);
        cEpuckPosition.Set(pcEpuck->GetEmbodiedEntity().GetOriginAnchor().Position.GetX(),
                           pcEpuck->GetEmbodiedEntity().GetOriginAnchor().Position.GetY());

        m_tRobotStates[pcEpuck].cLastPosition = cEpuckPosition;
        m_tRobotStates[pcEpuck].cPosition = cEpuckPosition;
        m_tRobotStates[pcEpuck].unItem = 0;
    }
}



/****************************************/
/****************************************/

void ToffiChLoopFunction::InitObjectStates() {

    CSpace::TMapPerType& tObjectMap = GetSpace().GetEntitiesByType("smart_object");
    CVector2 cObjectPosition(0,0);
    for (CSpace::TMapPerType::iterator it = tObjectMap.begin(); it != tObjectMap.end(); ++it) {
        CSmartObjectEntity* pcSmartObject = any_cast<CSmartObjectEntity*>(it->second);
        cObjectPosition.Set(pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetX(),
                           pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetY());
    //m_pcAccelerometerSensor =  GetSensor<CCI_SmartObjectAccelerometerSensor>("smart_object_accelerometer");
        m_tObjectStates[pcSmartObject].cLastPosition = cObjectPosition;
        m_tObjectStates[pcSmartObject].cPosition = cObjectPosition;
        m_tObjectStates[pcSmartObject].cColor = CColor::WHITE;
    }
}

/****************************************/
/****************************************/

CVector3 ToffiChLoopFunction::GetRandomPosition(std::string m_sType) {
  m_fDistributionRadius = (m_sType == "epuck") ? m_fDistributionRadiusEpuck : m_fDistributionRadiusSmartObject;
  Real temp;
  Real a = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
  Real b = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
  Real c = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
  Real d = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
  // If b < a, swap them
  if (b < a) {
    temp = a;
    a = b;
    b = temp;
  }
  Real fPosX = c*m_fDistributionRadius * cos(2 * CRadians::PI.GetValue() * (a/b));
  Real fPosY = d*m_fDistributionRadius * sin(2 * CRadians::PI.GetValue() * (a/b));

 
  return CVector3(fPosX, fPosY, 0);
}

/****************************************/
/****************************************/

UInt32 ToffiChLoopFunction::GetRandomTime(UInt32 unMin, UInt32 unMax) {
  UInt32 unStopAt = m_pcRng->Uniform(CRange<UInt32>(unMin, unMax));
  return unStopAt;

}

/****************************************/
/****************************************/

void ToffiChLoopFunction::PositionArena() {
  CArenaEntity* pcArena;
  /*
    pcArena = new CArenaEntity("arena",
                               CVector3(0,0,0),
                               CQuaternion().FromEulerAngles(CRadians::ZERO,CRadians::ZERO,CRadians::ZERO), // TODO
                               CVector3(0.01,m_fLenghtBoxes,0.1),
                               "leds",
                               m_unNumberBoxes,
                               m_unNumberEdges,
                               0.017f,
                               1.0f);   */ // arena with 12 leds per block

   pcArena = new CArenaEntity("arena",
                             CVector3(0,0,0),
                             CQuaternion().FromEulerAngles(CRadians::ZERO,CRadians::ZERO,CRadians::ZERO), // TODO
                             CVector3(0.01,m_fLengthBoxes,0.1),
                             "leds",
                             m_unNumberBoxes,
                             m_unNumberEdges,
                             0.125f,
                             1.0f);

   CWallEntity* wall_0 = new CWallEntity(pcArena, "wall_0",
                                     CVector3(0.7134,0.7134,0),
                             CQuaternion().FromEulerAngles(-3*CRadians::PI_OVER_FOUR,CRadians::ZERO,CRadians::ZERO), // TODO
                             CVector3(0.01,0.25,0.1),
                             "leds",
                             1,
                             0.125f,
                             1.0f);

   CWallEntity* wall_1 = new CWallEntity(pcArena, "wall_1",
                                     CVector3(-0.7134,0.7134,0),
                             CQuaternion().FromEulerAngles(-CRadians::PI_OVER_FOUR,CRadians::ZERO,CRadians::ZERO), // TODO
                             CVector3(0.01,0.25,0.1),
                             "leds",
                             1,
                             0.125f,
                             1.0f);

    CWallEntity* wall_2 = new CWallEntity(pcArena, "wall_2",
                                     CVector3(0.7134,-0.7134,0),
                             CQuaternion().FromEulerAngles(-5*CRadians::PI_OVER_FOUR,CRadians::ZERO,CRadians::ZERO), // TODO
                             CVector3(0.01,0.25,0.1),
                             "leds",
                             1,
                             0.125f,
                             1.0f);   

    CWallEntity* wall_3 = new CWallEntity(pcArena, "wall_3",
                                     CVector3(-0.7134,-0.7134,0),
                             CQuaternion().FromEulerAngles(CRadians::PI_OVER_FOUR,CRadians::ZERO,CRadians::ZERO), // TODO
                             CVector3(0.01,0.25,0.1),
                             "leds",
                             1,
                             0.125f,
                             1.0f);                      

     pcArena->AddWall(*wall_0);       
     pcArena->AddWall(*wall_1);  
     pcArena->AddWall(*wall_2);  
     pcArena->AddWall(*wall_3);  
     
     AddEntity(*pcArena);
     m_pcArena = pcArena;
}

/****************************************/
/****************************************/

void ToffiChLoopFunction::RemoveArena() {
    std::ostringstream id;
    id << "arena";
    RemoveEntity(id.str().c_str());
}

/****************************************/
/****************************************/

Real ToffiChLoopFunction::GetArenaRadious() {

    Real fRadious;
    fRadious =  (m_fLengthBoxes*m_unNumberBoxes) / (2 * Tan(CRadians::PI / m_unNumberEdges));
    //fRadious = fRadious - 0.10; // Avoids to place robots close the walls.
    //fRadious = fRadious - 0.65; // Reduced cluster at the begining
    //std::cout << "ARENA RADIUS: " << fRadious << std::endl;

    return fRadious;
}

/****************************************/
/****************************************/

bool ToffiChLoopFunction::IsEven(UInt32 unNumber) {
    bool even;
    if((unNumber%2)==0)
       even = true;
    else
       even = false;

    return even;
}
/****************************************/
/****************************************/

void ToffiChLoopFunction::SetWallColor() {
    CColor wall_color;

    switch (m_cWallColor) {
    case 1:
        wall_color = CColor::MAGENTA;
        cFinalColor = CColor::RED;
        break;
    case 2:
        wall_color = CColor::CYAN;
        cFinalColor = CColor::BLUE;
        break;
    case 3:
        wall_color = CColor::YELLOW;
        cFinalColor = CColor::GREEN;
        break;
    default:
        wall_color = CColor::BLACK;
        break;
    }
    m_pcArena->SetArenaColor(wall_color);

}


/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(ToffiChLoopFunction, "toffi_ch_loop_function");
