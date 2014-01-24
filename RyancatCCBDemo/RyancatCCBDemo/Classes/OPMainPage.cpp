//
//  OPMainPage.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPMainPage.h"

OPMainPage::OPMainPage()
:m_delegate()
{

}

OPMainPage::~OPMainPage()
{

}

bool OPMainPage::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void OPMainPage::onEnter()
{
    
    CCNode::onEnter();
    
}
void OPMainPage::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler OPMainPage::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    
    return NULL;
}

SEL_CCControlHandler OPMainPage::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", OPMainPage::onButtonClicked);
    return NULL;
}

bool OPMainPage::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    
    return false;
}

bool OPMainPage::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void OPMainPage::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    
    
}

void OPMainPage::onButtonClicked(CCNode *pNode)
{
    if (m_delegate) {
        m_delegate->onMainPageButtonClicked(this, pNode->getTag());
    }
}
