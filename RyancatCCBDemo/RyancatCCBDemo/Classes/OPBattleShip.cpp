//
//  OPBattleShip.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPBattleShip.h"

OPBattleShip::OPBattleShip()
:m_pFlag_01()
,m_pFlag_02()
{
    
}

OPBattleShip::~OPBattleShip()
{
    
}

bool OPBattleShip::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    return true;
}

SEL_MenuHandler OPBattleShip::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler OPBattleShip::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool OPBattleShip::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "flag_01", CCSprite*, m_pFlag_01);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "flag_02", CCSprite*, m_pFlag_02);
    return true;
}

bool OPBattleShip::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return true;
}

void OPBattleShip::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    CCAnimation* animation = CCAnimation::create();
    
    for (int i=1; i<=3; i++) {
        CCString* imageName = CCString::createWithFormat("loadingScene/u_qi%i.png",i);
        CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(imageName->getCString());
        CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(texture, CCRectMake(0, 0, texture->getContentSize().width, texture->getContentSize().height));
        animation->addSpriteFrame(frame);
        animation->setLoops(-1);
        animation->setDelayPerUnit(0.1f);
    }
    if (m_pFlag_01) {
        CCAnimate* animate = CCAnimate::create(animation);
        m_pFlag_01->runAction(animate);
    }
    if (m_pFlag_02) {
        CCAnimate* animate = CCAnimate::create(animation);
        m_pFlag_02->runAction(animate);
    }
}

