//
//  OPMainMenu.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPMainMenu.h"
#include "RCSceneManager.h"
#include "OPWave.h"
#include "OPLoadingScene.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

OPMainMenu::OPMainMenu()
{
    memset(m_pWave, 0, sizeof(m_pWave));
    memset(m_pSpinDrift, 0, sizeof(m_pSpinDrift));
}

OPMainMenu::~OPMainMenu()
{

}

bool OPMainMenu::init()
{
    if (!CCNode::init()) {
        return false;
    }
    return true;
}

SEL_MenuHandler OPMainMenu::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler OPMainMenu::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", OPMainMenu::onButtonClicked);
    return NULL;
}

bool OPMainMenu::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "wave_01", CCNode*, m_pWave[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "wave_02", CCNode*, m_pWave[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "wave_03", CCNode*, m_pWave[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "wave_04", CCNode*, m_pWave[3]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "spindrift_01", CCNode*, m_pSpinDrift[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "spindrift_02", CCNode*, m_pSpinDrift[1]);
    return false;
}

bool OPMainMenu::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    
    return false;
}

void OPMainMenu::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
 
}

void OPMainMenu::onButtonClicked(CCObject* object)
{
    CCNode* pButton = (CCNode*)object;
    if (pButton->getTag() == 1) {
        RCSceneManager::sharedSceneManager()->switchToOnePieceLoadingScene();
    }
    else if (pButton->getTag() == 2)
    {
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
        RCSceneManager::sharedSceneManager()->returnPreviousScene();
    }
}

void OPMainMenu::onEnter()
{
    CCNode::onEnter();
    
    
    for (int i=0; i<4; i++) {
        if (m_pWave[i]) {
            CCBAnimationManager* animationManager = (CCBAnimationManager*)m_pWave[i]->getUserObject();
            CCString* actionName = CCString::createWithFormat("wave_%.02i",i+1);
            animationManager->runAnimationsForSequenceNamed(actionName->getCString());
        }
    }
    
    if (m_pSpinDrift[0]) {
        CCBAnimationManager* animationManager = (CCBAnimationManager*)m_pSpinDrift[0]->getUserObject();
        animationManager->runAnimationsForSequenceNamed("showSpindrift_1");
    }
    if (m_pSpinDrift[1]) {
        CCBAnimationManager* animationManager = (CCBAnimationManager*)m_pSpinDrift[1]->getUserObject();
        animationManager->runAnimationsForSequenceNamed("showSpindrift_2");
    }

  //  SimpleAudioEngine::sharedEngine()->playBackgroundMusic("loadingMusic.mp3", true);
    //SimpleAudioEngine::sharedEngine()->playBackgroundMusic("click.mp3", true);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("loadingMusic.mp3");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("loadingMusic.mp3",true);
    //animationManager->runAnimationsForSequenceNamed("wave_01");
    //animationManager->runAnimationsForSequenceNamed("wave_02");
  //  animationManager->runAnimationsForSequenceNamed("wave_03");
  //  animationManager->runAnimationsForSequenceNamed("wave_04");
}

void OPMainMenu::onExit()
{
    CCNode::onExit();
}
