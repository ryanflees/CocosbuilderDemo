//
//  OPDataParser.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-21.
//
//

#include "OPDataParser.h"

OPDataParser::OPDataParser()
:m_pTeamData()
{

}

OPDataParser::~OPDataParser()
{
    CC_SAFE_RELEASE(m_pTeamData);
}

bool OPDataParser::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    
    return true;
}
void OPDataParser::onEnter()
{
    
    CCNode::onEnter();
    
}
void OPDataParser::onExit()
{
    CCNode::onExit();
}

void OPDataParser::loadTeamData(const char* plistFile)
{
    CC_SAFE_RELEASE(m_pTeamData);
    m_pTeamData = NULL;
    
    CCDictionary* pDict = CCDictionary::createWithContentsOfFile(plistFile);
    m_pTeamData= (CCArray*)pDict->objectForKey("team");
    m_pTeamData->retain();
}

CCDictionary* OPDataParser::getTeamMemberByID(int id)
{
    if (!m_pTeamData) {
        return NULL;
    }
    CCObject* pObject;
    CCARRAY_FOREACH(m_pTeamData, pObject)
    {
        CCDictionary* pDict = (CCDictionary*)pObject;
        int memberID = pDict->valueForKey("id")->intValue();
        if (memberID == id) {
            return pDict;
        }
    }
    return NULL;
}
