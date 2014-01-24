//
//  OPNoticeContent.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPNoticeContent.h"

OPNoticeContent::OPNoticeContent()
{
}

OPNoticeContent::~OPNoticeContent()
{
    
}

bool OPNoticeContent::init()
{
    if (!CCNode::init()) {
        return false;
    }
    return true;
}

SEL_MenuHandler OPNoticeContent::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler OPNoticeContent::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool OPNoticeContent::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}

bool OPNoticeContent::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    
    return false;
}

void OPNoticeContent::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    
}

void OPNoticeContent::onEnter()
{
    CCNode::onEnter();
}

void OPNoticeContent::onExit()
{
    CCNode::onExit();
}

