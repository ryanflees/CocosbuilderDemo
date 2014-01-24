//
//  RCTabBarScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-13.
//
//

#include "RCTabBarScene.h"
#include "RCSceneManager.h"

RCTabBarScene::RCTabBarScene()
    :m_pTabBar()
{

}

RCTabBarScene::~RCTabBarScene()
{

}

bool RCTabBarScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    return true;
}

SEL_MenuHandler RCTabBarScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler RCTabBarScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", RCTabBarScene::onButtonClicked);
    return NULL;
}

bool RCTabBarScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName,CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "tabBar", RCTabBar*, m_pTabBar);
    
    return false;
}

bool RCTabBarScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void RCTabBarScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    if (m_pTabBar) {
        m_pTabBar->setDelegate(this);
    }
}

void RCTabBarScene::onButtonClicked(CCNode *node)
{
    if (node->getTag() == 1) {
        RCSceneManager::sharedSceneManager()->returnPreviousScene();
    }
    else if(node->getTag() == 2)
    {
        if (m_pTabBar) {
            int direction = m_pTabBar->getTabBarDirection();
            direction ++;
            if (direction > kTabBarDirectionBottom) {
                direction = kTabBarDirectionTop;
            }
            m_pTabBar->setTabBarDirection(direction);
        }
    }
}

void RCTabBarScene::onTabSelected(RCTabBar* pTabbar, CCNode* pTabPage, int index)
{
    CCLog("touched on tab %i",index);
}
