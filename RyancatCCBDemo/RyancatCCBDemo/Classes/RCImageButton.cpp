//
//  RCImageButton.cpp
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#include "RCImageButton.h"

#define RYANCAT_IMAGEBUTTON_SELECTED_COLOR ccc3(0xc0,0xc0,0xc0)
#define RYANCAT_IMAGEBUTTON_NORMAL_COLOR ccc3(0xff,0xff,0xff)
#define RYANCAT_DEFAULT_TOUCHUPOUT_DELAY 400

RCImageButton::RCImageButton()
:m_pListener()
,m_pfnSelector()
,m_isTouched()
,m_touchTimer()
,m_touchUpOutDelay()
{

}

RCImageButton::~RCImageButton()
{

}

bool RCImageButton::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    m_normalColor = RYANCAT_IMAGEBUTTON_NORMAL_COLOR;
    m_selectedColor = RYANCAT_IMAGEBUTTON_SELECTED_COLOR;
    m_touchUpOutDelay = RYANCAT_DEFAULT_TOUCHUPOUT_DELAY;
    m_pButtonSprite = CCSprite::create();
	addChild(m_pButtonSprite);
    return true;
}

void RCImageButton::onEnter()
{
    CCNode::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

void RCImageButton::onExit()
{
    CCNode::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

void RCImageButton::visit(void)
{
    CCNode::visit();
}

void RCImageButton::setImageDisplayFrame(CCSpriteFrame* frame)
{
    if (!frame) {
        return;
    }
    m_pButtonSprite->setDisplayFrame(frame);
    CCSize size = m_pButtonSprite->getContentSize();
	m_pButtonSprite->setAnchorPoint(ccp(0,0));
    setContentSize(size);
	setAnchorPoint(ccp(0.5,0.5));
	updateTextureRect();
}

void RCImageButton::setTarget(CCObject* pObj,SEL_CallFuncN fun)
{
	m_pListener = pObj;
	m_pfnSelector = fun;
}

bool RCImageButton::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!isVisible() || !getParent()->isVisible()) {
        return false;
    }
    CCPoint realitivePoint = convertToNodeSpace(pTouch->getLocation());
	if(realitivePoint.x >= 0 && realitivePoint.y >= 0 && m_obContentSize.width> realitivePoint.x && m_obContentSize.height>realitivePoint.y)
	{
        struct cc_timeval now;
        CCTime::gettimeofdayCocos2d(&now, NULL);
        m_touchTimer = now.tv_sec * 1000 + now.tv_usec / 1000;
        m_isTouched = true;
		updateTextureRect();
		return true;
	}
	return false;
}

void RCImageButton::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!m_isTouched) {
        return;
    }
    
    CCPoint realitivePoint = convertToNodeSpace(pTouch->getLocation());
	if(realitivePoint.x >= 0 && realitivePoint.y >= 0 && m_obContentSize.width> realitivePoint.x && m_obContentSize.height>realitivePoint.y)
	{
		m_isTouched = true;
	}
	else
	{
		m_isTouched = false;
	}
	updateTextureRect();
}

void RCImageButton::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint realitivePoint = convertToNodeSpace(pTouch->getLocation());
	if(realitivePoint.x >= 0 && realitivePoint.y >= 0 && m_obContentSize.width> realitivePoint.x && m_obContentSize.height>realitivePoint.y)
	{
		m_isTouched = false;
		updateTextureRect();
		if(m_pListener && m_pfnSelector)
		{
			(m_pListener->*m_pfnSelector)(this);
		}
	}
    else
    {
        struct cc_timeval now;
        CCTime::gettimeofdayCocos2d(&now, NULL);
        long timeNow = now.tv_sec * 1000 + now.tv_usec / 1000;
        if (timeNow - m_touchTimer < m_touchUpOutDelay) {
            if (m_pListener && m_pfnSelector) {
                (m_pListener->*m_pfnSelector)(this);
            }
        }
    }
    if (m_isTouched) {
        m_isTouched = false;
        updateTextureRect();
    }
}

void RCImageButton::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    m_isTouched = false;
	updateTextureRect();
}

void RCImageButton::updateTextureRect(void)
{
	m_pButtonSprite->setColor(m_isTouched?m_selectedColor:m_normalColor);
}
