//
//  RCButtonScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-10.
//
//

#include "RCButtonScene.h"
#include "RCSceneManager.h"
#include "RCCheckButton.h"
#include "RCImageButton.h"

RCButtonScene::RCButtonScene()
    :m_pCheckButton()
    ,m_pSelectedCheckButtonLabel()
    ,m_pUnselectedCheckButtonLabel()
{

}

RCButtonScene::~RCButtonScene()
{

}

bool RCButtonScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    return true;
}

SEL_MenuHandler RCButtonScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler RCButtonScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", RCButtonScene::onButtonClicked);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "imageButtonClicked", RCButtonScene::onImageButtonClicked);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "checkButtonClicked", RCButtonScene::onCheckButtonClicked);
    return NULL;
}

bool RCButtonScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "checkButton", RCCheckButton*, m_pCheckButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "selecedLabel", CCLabelTTF*, m_pSelectedCheckButtonLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "unselecedLabel", CCLabelTTF*, m_pUnselectedCheckButtonLabel);
    return false;
}

bool RCButtonScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void RCButtonScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    if (m_pCheckButton) {
        CCLog("m_pCheckButton pos : %f %f",m_pCheckButton->getPositionX(),m_pCheckButton->getPositionY());
        if (m_pUnselectedCheckButtonLabel && m_pSelectedCheckButtonLabel) {
            if (m_pCheckButton->getSelected()) {
                m_pUnselectedCheckButtonLabel->setVisible(false);
                m_pSelectedCheckButtonLabel->setVisible(true);
            }
            else
            {
                m_pUnselectedCheckButtonLabel->setVisible(true);
                m_pSelectedCheckButtonLabel->setVisible(false);
            }
        }
    }
//    RCImageButton* pImageButton = RCImageButton::create();
//    CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addImage("ui/xcbutton.png");
//    CCSpriteFrame* pFrame = CCSpriteFrame::createWithTexture(pTexture, CCRectMake(0, 0, pTexture->getContentSize().width, pTexture->getContentSize().height));
//    pImageButton->setImageDisplayFrame(pFrame);
//    addChild(pImageButton);
//    pImageButton->setTag(6);
//    pImageButton->setTarget(this, callfuncN_selector(RCButtonScene::onImageButtonClicked));
//    pImageButton->setPosition(ccp(500, 200));
    
    
}

void RCButtonScene::onButtonClicked(CCObject* pObject)
{
    CCNode* pButton = (CCNode*)pObject;
    switch (pButton->getTag()) {
        case 1:
        {
            RCSceneManager::sharedSceneManager()->returnPreviousScene();
        }
            break;
        case 2:
        {
        
        }
            break;
        case 3:
        {
            
        }
            break;
        case 4:
        {
            CCMessageBox("Click Button", "Bing!");
        }
            break;
        case 5:
        {
            CCMessageBox("Click Button", "Bing!");
        }
            break;
        case 6:
        {
            CCMessageBox("Click Button", "Bing!");
        }
            break;
        default:
            break;
    }
}

void RCButtonScene::onImageButtonClicked(CCObject *pObject)
{
    CCMessageBox("Image Button Clicked!", "");
}

void RCButtonScene::onCheckButtonClicked(CCObject* pObject)
{
    CCLog("onCheckButtonClicked");
    //CCMessageBox("CheckButton Clicked!", "");
    if (m_pUnselectedCheckButtonLabel && m_pSelectedCheckButtonLabel) {
        if (m_pCheckButton->getSelected()) {
            m_pUnselectedCheckButtonLabel->setVisible(false);
            m_pSelectedCheckButtonLabel->setVisible(true);
            CCBAnimationManager* animationManager = (CCBAnimationManager*)getUserObject();
            animationManager->runAnimationsForSequenceNamed("showAlertSelectedCheckbox");
        }
        else
        {
            m_pUnselectedCheckButtonLabel->setVisible(true);
            m_pSelectedCheckButtonLabel->setVisible(false);
            CCBAnimationManager* animationManager = (CCBAnimationManager*)getUserObject();
            animationManager->runAnimationsForSequenceNamed("showAlertUnselectedCheckbox");
        }
    }
}


