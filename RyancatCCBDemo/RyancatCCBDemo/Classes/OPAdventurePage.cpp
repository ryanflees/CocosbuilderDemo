//
//  OPAdventurePage.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#include "OPAdventurePage.h"

OPAdventurePage::OPAdventurePage()
{

}

OPAdventurePage::~OPAdventurePage()
{

}

bool OPAdventurePage::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void OPAdventurePage::onEnter()
{
    
    CCNode::onEnter();
    
}
void OPAdventurePage::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler OPAdventurePage::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", OPAdventurePage::FUNCTION);
    return NULL;
}

SEL_CCControlHandler OPAdventurePage::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", OPAdventurePage::FUNCTION);
    return NULL;
}

bool OPAdventurePage::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NAME", TYPE,VALUE);
    return false;
}

bool OPAdventurePage::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void OPAdventurePage::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    
    
}
