/**
  * @file <loop-functions/IcraLoopFunc.cpp>
  *
  * @author Antoine Ligot - <aligot@ulb.ac.be>
  *
  * @license MIT License
  */

#include "ToffiFrLoopFunc.h"

/****************************************/
/****************************************/

ToffiFrLoopFunction::ToffiFrLoopFunction() {
    m_fObjectiveFunction = 0;
}

/****************************************/
/****************************************/

ToffiFrLoopFunction::ToffiFrLoopFunction(const ToffiFrLoopFunction& orig) {
}

/****************************************/
/****************************************/

ToffiFrLoopFunction::~ToffiFrLoopFunction() {}

/****************************************/
/****************************************/

void ToffiFrLoopFunction::Destroy() {

    m_tRobotStates.clear();
    RemoveArena();
}

/****************************************/
/****************************************/

void ToffiFrLoopFunction::Init(TConfigurationNode& t_tree) {

    TConfigurationNode cParametersNode;


    try {
      cParametersNode = GetNode(t_tree, "params");
      GetNodeAttributeOrDefault(cParametersNode, "build_arena", m_bBuildArena, (bool) false);
      GetNodeAttributeOrDefault(cParametersNode, "number_edges", m_unNumberEdges, (UInt32) 3);
      GetNodeAttributeOrDefault(cParametersNode, "number_boxes_per_edge", m_unNumberBoxes, (UInt32) 1);
      GetNodeAttributeOrDefault(cParametersNode, "length_boxes", m_fLengthBoxes, (Real) 0.25);
      GetNodeAttributeOrDefault(cParametersNode, "maximization", m_bMaximization, (bool) false);
      GetNodeAttributeOrDefault(cParametersNode, "dist_radius_epuck", m_fDistributionRadiusEpuck, (Real) 0.3);
    } catch(std::exception e) {
    }


    if (m_bBuildArena == true) {
        m_fArenaRadius = GetArenaRadious();
        m_fDistributionRadiusEpuck = m_fArenaRadius - m_fDistributionRadiusEpuck;
        m_fDistributionRadiusSmartObject = m_fArenaRadius - m_fDistributionRadiusSmartObject;
        PositionArena();
    }

    CoreLoopFunctions::Init(t_tree, false);

    InitRobotStates();

    InitObjectStates();
    m_pcArena->SetArenaColor(CColor::BLACK);
    m_pcArena->SetWallColor(5, CColor::RED);
    m_pcArena->SetWallColor(7, CColor::RED);
    m_pcArena->SetWallColor(4, CColor::RED);


}

/****************************************/
/****************************************/

void ToffiFrLoopFunction::Reset() {
    CoreLoopFunctions::Reset();

    m_fObjectiveFunction = 0;

    m_tRobotStates.clear();
    m_tObjectStates.clear();

    InitRobotStates();
    InitObjectStates();
}

/****************************************/
/****************************************/

void ToffiFrLoopFunction::PostExperiment() {
    m_fObjectiveFunction = GetRobotsInZone();
    if (m_bMaximization == true){
        LOG << -m_fObjectiveFunction << std::endl;
    }
    else {
        LOG << m_fObjectiveFunction << std::endl;
    }
}

/****************************************/
/****************************************/



UInt32 ToffiFrLoopFunction::GetRobotsInZone() {
    UpdateRobotPositions();
    UInt32 unScore = 0;
    TRobotStateMap::iterator it;

    for (it = m_tRobotStates.begin(); it != m_tRobotStates.end(); ++it) {
        if (it->second.cPosition.GetX() > 0.5) {
            unScore++;
        }
    }
    return unScore;
}

/****************************************/
/****************************************/

Real ToffiFrLoopFunction::GetObjectiveFunction() {
    if (m_bMaximization == true){
        return -m_fObjectiveFunction;
    }
    else {
        return m_fObjectiveFunction;
    }
}



/****************************************/
/****************************************/

argos::CColor ToffiFrLoopFunction::GetFloorColor(const argos::CVector2& c_position_on_plane) {
    if(c_position_on_plane.GetX() > 0.0){
        return CColor::WHITE;
    }
    return CColor::GRAY50;
}

/****************************************/
/****************************************/

void ToffiFrLoopFunction::UpdateRobotPositions() {
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

void ToffiFrLoopFunction::InitRobotStates() {

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

void ToffiFrLoopFunction::UpdateObject() {
    CSpace::TMapPerType& tObjectMap = GetSpace().GetEntitiesByType("smart_object");
    CVector2 cObjectPosition(0,0);
    for (CSpace::TMapPerType::iterator it = tObjectMap.begin(); it != tObjectMap.end(); ++it) {
        CSmartObjectEntity* pcSmartObject = any_cast<CSmartObjectEntity*>(it->second);
        cObjectPosition.Set(pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetX(),
                           pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetY());


     //  std::cout << "color: " << m_tObjectStates[pcSmartObject].cColor << std::endl;
       // std::cout << "current color: " <<  pcSmartObject->GetLEDEquippedEntity().GetLED(0).GetColor() << std::endl;

        m_tObjectStates[pcSmartObject].cLastPosition = m_tObjectStates[pcSmartObject].cPosition;
        m_tObjectStates[pcSmartObject].cLastColor = m_tObjectStates[pcSmartObject].cColor;
        m_tObjectStates[pcSmartObject].cColor = pcSmartObject->GetLEDEquippedEntity().GetLED(0).GetColor();
    }
   
}


/****************************************/
/****************************************/

void ToffiFrLoopFunction::InitObjectStates() {
    try{
        CSpace::TMapPerType& tObjectMap = GetSpace().GetEntitiesByType("smart_object");   
        CVector2 cObjectPosition(0,0);
        for (CSpace::TMapPerType::iterator it = tObjectMap.begin(); it != tObjectMap.end(); ++it) {
            CSmartObjectEntity* pcSmartObject = any_cast<CSmartObjectEntity*>(it->second);
            cObjectPosition.Set(pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetX(),
                            pcSmartObject->GetEmbodiedEntity().GetOriginAnchor().Position.GetY());

            m_tObjectStates[pcSmartObject].cLastPosition = cObjectPosition;
            m_tObjectStates[pcSmartObject].cPosition = cObjectPosition;
            m_tObjectStates[pcSmartObject].cColor = CColor::BLACK;
            m_tObjectStates[pcSmartObject].unItem = 0;
        }  

    }catch(std::exception &e){
        std::cout << "No smart-object present in the arena!" << std::endl;
    }

}


/****************************************/
/****************************************/

CVector3 ToffiFrLoopFunction::GetRandomPosition(std::string m_sType) {
  m_fDistributionRadius = m_fDistributionRadiusEpuck;
  Real temp;
  Real a = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
  Real b = m_pcRng->Uniform(CRange<Real>(0.0f, 1.0f));
  Real c = m_pcRng->Uniform(CRange<Real>(-1.0f, 1.0f));
  Real d = m_pcRng->Uniform(CRange<Real>(-1.0f, 1.0f));
  // If b < a, swap them
  if (b < a) {
    temp = a;
    a = b;
    b = temp;
  }
  //m_fDistributionRadius = m_fRadius;
  Real fPosX = -0.35f + c*m_fDistributionRadius/2 * cos(2 * CRadians::PI.GetValue() * (a/b));
  Real fPosY = d*m_fDistributionRadius * sin(2 * CRadians::PI.GetValue() * (a/b));

  return CVector3(fPosX, fPosY, 0);
}

/****************************************/
/****************************************/

void ToffiFrLoopFunction::PositionArena() {
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

void ToffiFrLoopFunction::RemoveArena() {
    std::ostringstream id;
    id << "arena";
    RemoveEntity(id.str().c_str());
}

/****************************************/
/****************************************/

Real ToffiFrLoopFunction::GetArenaRadious() {

    Real fRadious;
    fRadious =  (m_fLengthBoxes*m_unNumberBoxes) / (2 * Tan(CRadians::PI / m_unNumberEdges));
    //fRadious = fRadious - 0.10; // Avoids to place robots close the walls.
    //fRadious = fRadious - 0.65; // Reduced cluster at the begining

    return fRadious;
}

/****************************************/
/****************************************/

bool ToffiFrLoopFunction::IsEven(UInt32 unNumber) {
    bool even;
    if((unNumber%2)==0)
       even = true;
    else
       even = false;

    return even;
}

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(ToffiFrLoopFunction, "Toffi_ps_loop_function");
