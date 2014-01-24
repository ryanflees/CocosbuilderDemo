//
//  RCMainMenu.cpp
//  HYControls
//
//  Created by Bai Ryan on 14-1-9.
//
//

#include "RCMainMenu.h"
#include "CCNodeLoaderLibrary.h"
#include "CCCommon.h"
#include "RCSceneManager.h"

bool RCMainMenu::init()
{
    if (!CCNode::init()) {
        return false;
    }
    return true;
}

SEL_MenuHandler RCMainMenu::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler RCMainMenu::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", RCMainMenu::onButtonClicked);
    return NULL;
}

bool RCMainMenu::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}

bool RCMainMenu::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void RCMainMenu::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{

}

void RCMainMenu::onButtonClicked(cocos2d::CCObject *object)
{
    CCLog("button clicked");
    CCNode* button = (CCNode*)object;
    switch (button->getTag()) {
        case 1:
        {
            RCSceneManager::sharedSceneManager()->switchToButtonScene();
        }
            break;
        case 2:
        {
            RCSceneManager::sharedSceneManager()->switchToLabelScene();
        }
            break;
        case 3:
        {
            RCSceneManager::sharedSceneManager()->switchToScrollViewScene();
        }
            break;
        case 4:
        {
            RCSceneManager::sharedSceneManager()->switchToTabBarScene();
        }
            break;
        case 5:
        {
            RCSceneManager::sharedSceneManager()->switchToPanelScene();
        }
            break;
        case 6:
        {
            RCSceneManager::sharedSceneManager()->switchToPickerViewScene();
        }
            break;
        case 7:
        {
            RCSceneManager::sharedSceneManager()->switchToOnePieceMainMenu();
        }
            break;
        default:
            break;
    }
}

