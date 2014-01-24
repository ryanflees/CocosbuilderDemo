//
//  RCPanelScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-11.
//
//

#include "RCPanelScene.h"
#include "RCPanel.h"
#include "RCSceneManager.h"

RCPanelScene::RCPanelScene()
    :m_pSinglePanelNode()
    ,m_pMultiPanelNode()
{

}

RCPanelScene::~RCPanelScene()
{

}

bool RCPanelScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    return true;
}

SEL_MenuHandler RCPanelScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler RCPanelScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "closeButtonClicked", RCPanelScene::onClosePanelClicked);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", RCPanelScene::onButtonClicked);
    return NULL;
}

bool RCPanelScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "singlePanelNode", CCNode*, m_pSinglePanelNode);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "multiPanelNode", CCNode*, m_pMultiPanelNode);
    return false;
}

bool RCPanelScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void RCPanelScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
//    XCWidgetPanel *panel = XCWidgetPanel::create();
//    addChild(panel);
//    panel->setPosition(ccp(480, 320));
//    CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("ui/RCPanel.png");
//    CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(texture, CCRectMake(0, 0, texture->getContentSize().width, texture->getContentSize().height));
//    panel->setPanelFrame(frame);
//    panel->setContentSize(CCSizeMake(700, 500));
}

void RCPanelScene::onClosePanelClicked(CCNode* node)
{
    CCMessageBox("onClosePanelClicked", "!");
}

void RCPanelScene::onButtonClicked(cocos2d::CCNode *node)
{
    if (node->getTag() == 1) {
        RCSceneManager::sharedSceneManager()->returnPreviousScene();
    }
    else if(node->getTag() == 2)
    {
        switchNode();
    }
}

void RCPanelScene::switchNode()
{
    if (m_pSinglePanelNode->isVisible()) {
        m_pSinglePanelNode->setVisible(false);
        m_pMultiPanelNode->setVisible(true);
    }
    else
    {
        m_pSinglePanelNode->setVisible(true);
        m_pMultiPanelNode->setVisible(false);
    }
}
