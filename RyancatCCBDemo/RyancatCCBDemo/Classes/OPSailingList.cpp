//
//  OPSailingList.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-21.
//
//

#include "OPSailingList.h"

OPSailingList::OPSailingList()
{

}

OPSailingList::~OPSailingList()
{

}

bool OPSailingList::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void OPSailingList::onEnter()
{
    
    CCNode::onEnter();
    
}
void OPSailingList::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler OPSailingList::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", OPSailingList::FUNCTION);
    return NULL;
}

SEL_CCControlHandler OPSailingList::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", OPSailingList::FUNCTION);
    return NULL;
}

bool OPSailingList::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NAME", TYPE,VALUE);
    return false;
}

bool OPSailingList::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void OPSailingList::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    
    
}
