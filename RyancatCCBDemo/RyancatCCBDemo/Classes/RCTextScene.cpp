//
//  RCTextScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-15.
//
//

#include "RCTextScene.h"
#include "RCSceneManager.h"

RCTextScene::RCTextScene()
    :m_pCustomFontLabel()
    ,m_pPasswordEditBox()
    ,m_pAccountEditBox()
{
    
}

RCTextScene::~RCTextScene()
{
    
}

bool RCTextScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    return true;
}

SEL_MenuHandler  RCTextScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler  RCTextScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", RCTextScene::onButtonClicked);
    return NULL;
}

bool  RCTextScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "customFontLabel", CCLabelTTF*, m_pCustomFontLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "accountEditBox", RCEditBox*, m_pAccountEditBox);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "passwordEditBox", RCEditBox*, m_pPasswordEditBox);
    
    return false;
}

bool  RCTextScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void  RCTextScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    if (m_pCustomFontLabel) {
        m_pCustomFontLabel->setFontName("FZCuYuan-M03");
    }
    if (m_pAccountEditBox) {
        m_pAccountEditBox->setDelegate(this);
    }
    if (m_pPasswordEditBox) {
        m_pPasswordEditBox->setDelegate(this);
    }
}

void RCTextScene::editBoxReturn(CCEditBox* editBox)
{
    CCLog("edit box returned");
}

void RCTextScene::editBoxEditingDidEnd(CCEditBox* editBox)
{
    CCLog("edit box ended");
    //CCMessageBox("Edit Box Ended", "~~");
}

void  RCTextScene::onButtonClicked(CCNode* node)
{
    if (node->getTag() == 1) {
        RCSceneManager::sharedSceneManager()->returnPreviousScene();
    }
}


