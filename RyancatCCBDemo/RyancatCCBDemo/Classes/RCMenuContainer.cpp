//
//  RCMenuContainer.cpp
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#include "RCMenuContainer.h"
#include "RCImageButton.h"

RCMenuContainer::RCMenuContainer()
{
    memset(m_pImageButtons, 0, sizeof(m_pImageButtons));
}

RCMenuContainer::~RCMenuContainer()
{

}

bool RCMenuContainer::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void RCMenuContainer::onEnter()
{
    
    CCNode::onEnter();
    
}

void RCMenuContainer::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler RCMenuContainer::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", RCMenuContainer::FUNCTION);
    return NULL;
}

SEL_CCControlHandler RCMenuContainer::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", RCMenuContainer::FUNCTION);
    return NULL;
}

bool RCMenuContainer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "imageButton_1", RCImageButton*, m_pImageButtons[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "imageButton_2", RCImageButton*, m_pImageButtons[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "imageButton_3", RCImageButton*, m_pImageButtons[2]);
    
    return false;
}

bool RCMenuContainer::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void RCMenuContainer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    for (int i=0; i<3; i++) {
        if (m_pImageButtons[i]) {
           // m_pImageButtons[i]->setTouc
        }
    }
}
