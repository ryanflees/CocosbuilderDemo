//
//  RCScrollViewScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-15.
//
//

#include "RCScrollViewScene.h"
#include "RCSceneManager.h"
#include "RCScrollView.h"

RCScrollViewScene::RCScrollViewScene()
:m_pScrollView()
{

}

 RCScrollViewScene::~RCScrollViewScene()
{

}

bool RCScrollViewScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    return true;
}

SEL_MenuHandler  RCScrollViewScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler  RCScrollViewScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", RCScrollViewScene::onButtonClicked);
    return NULL;
}

bool  RCScrollViewScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "scrollView", RCScrollView*, m_pScrollView);

    
    return false;
}

bool  RCScrollViewScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void  RCScrollViewScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
//    if (m_pScrollView) {
//        m_pScrollView->setPageMode(true);
//        m_pScrollView->setPageCount(3);
//    }
}

void  RCScrollViewScene::onButtonClicked(CCNode* node)
{
    if (node->getTag() == 1) {
        RCSceneManager::sharedSceneManager()->returnPreviousScene();
    }
    else if(node->getTag() == 2)
    {
    }
}

void RCScrollViewScene::showRightScrollFinished()
{
    
}

void RCScrollViewScene::showLeftScrollFinished()
{
}

