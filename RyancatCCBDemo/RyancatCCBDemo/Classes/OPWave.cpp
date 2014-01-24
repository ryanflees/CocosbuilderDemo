//
//  OPWave.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPWave.h"

OPWave::OPWave()
{

}

OPWave::~OPWave()
{

}

bool OPWave::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    return true;
}

SEL_MenuHandler OPWave::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler OPWave::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool OPWave::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return true;
}

bool OPWave::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return true;
}

void OPWave::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{

}
