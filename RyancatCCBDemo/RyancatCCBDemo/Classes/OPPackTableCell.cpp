//
//  OPPackTableCell.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#include "OPPackTableCell.h"

OPPackTableCell::OPPackTableCell()
{

}

OPPackTableCell::~OPPackTableCell()
{

}

bool OPPackTableCell::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void OPPackTableCell::onEnter()
{
    
    CCNode::onEnter();
    
}
void OPPackTableCell::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler OPPackTableCell::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", OPPackTableCell::FUNCTION);
    return NULL;
}

SEL_CCControlHandler OPPackTableCell::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", OPPackTableCell::FUNCTION);
    return NULL;
}

bool OPPackTableCell::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NAME", TYPE,VALUE);
    return false;
}

bool OPPackTableCell::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void OPPackTableCell::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    
    
}
