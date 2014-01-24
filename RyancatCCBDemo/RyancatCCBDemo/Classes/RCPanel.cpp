//
//  RCPanel.cpp
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#include "RCPanel.h"

RCPanel::RCPanel(void)
:m_pBGImage()
,m_pTitle()
,m_pListener()
,m_pfnSelector()
,m_pNormalCloseFrame()
,m_pSelectedCloseFrame()
,m_touchUpOutDelay()
,m_closeButtonSelected()
{
}

RCPanel::~RCPanel(void)
{
    CC_SAFE_RELEASE(m_pNormalCloseFrame);
    CC_SAFE_RELEASE(m_pSelectedCloseFrame);
}

bool RCPanel::init(void)
{
    if (!CCNode::init()) {
        return false;
    }
    
    m_touchUpOutDelay = 400;
    
    m_pBGImage = CCScale9Sprite::create();
    addChild(m_pBGImage);
    
    m_pCloseButton = CCSprite::create();
    addChild(m_pCloseButton);
    
    m_pTitle = CCLabelTTF::create();
    addChild(m_pTitle);
    
    return true;
}

void RCPanel::onEnter()
{
    CCNode::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void RCPanel::onExit()
{
    CCNode::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool RCPanel::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!m_pCloseButton->isVisible()) {
        return false;
    }
    CCPoint touchPoint = pTouch->getLocation();
    touchPoint = convertToNodeSpace(touchPoint);
    CCRect closeButtonRect = CCRectMake(m_pCloseButton->getPositionX() - m_pCloseButton->getContentSize().width/2
                                        , m_pCloseButton->getPositionY() - m_pCloseButton->getContentSize().height/2
                                        , m_pCloseButton->getContentSize().width
                                        , m_pCloseButton->getContentSize().height);
    if (closeButtonRect.containsPoint(touchPoint)) {
        m_pCloseButton->setDisplayFrame(m_pSelectedCloseFrame);
        m_closeButtonSelected = true;
        struct cc_timeval now;
        CCTime::gettimeofdayCocos2d(&now, NULL);
        m_touchTimer = now.tv_sec * 1000 + now.tv_usec / 1000;
        return true;
    }
    return false;
}

void RCPanel::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!m_pCloseButton->isVisible()) {
        return;
    }
    if (m_closeButtonSelected) {
        CCPoint touchPoint = pTouch->getLocation();
        touchPoint = convertToNodeSpace(touchPoint);
        CCRect closeButtonRect = CCRectMake(m_pCloseButton->getPositionX() - m_pCloseButton->getContentSize().width/2
                                            , m_pCloseButton->getPositionY() - m_pCloseButton->getContentSize().height/2
                                            , m_pCloseButton->getContentSize().width
                                            , m_pCloseButton->getContentSize().height);
        if (!closeButtonRect.containsPoint(touchPoint)) {
            m_pCloseButton->setDisplayFrame(m_pNormalCloseFrame);
        }
    }
}

void RCPanel::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    m_pCloseButton->setDisplayFrame(m_pNormalCloseFrame);
    m_closeButtonSelected = false;
    CCPoint touchPoint = pTouch->getLocation();
    touchPoint = convertToNodeSpace(touchPoint);
    CCRect closeButtonRect = CCRectMake(m_pCloseButton->getPositionX() - m_pCloseButton->getContentSize().width/2
                                        , m_pCloseButton->getPositionY() - m_pCloseButton->getContentSize().height/2
                                        , m_pCloseButton->getContentSize().width
                                        , m_pCloseButton->getContentSize().height);
    if (closeButtonRect.containsPoint(touchPoint)) {
        if (m_pListener && m_pfnSelector) {
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
}

void RCPanel::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    m_pCloseButton->setDisplayFrame(m_pNormalCloseFrame);
    m_closeButtonSelected = false;
}

void RCPanel::setTitle(const char* title)
{
	m_pTitle->setString(title);
}

const char* RCPanel::getTitle(void)
{
	return m_pTitle->getString();
}

void RCPanel::setContentSize(const CCSize& size)
{
    CCNode::setContentSize(size);
    if (m_pBGImage) {
        m_pBGImage->setContentSize(size);
    }
}

void RCPanel::setPanelFrame(CCSpriteFrame* frame)
{
    m_pBGImage->setSpriteFrame(frame);
    m_pBGImage->setAnchorPoint(CCPointZero);
    m_pBGImage->setPosition(CCPointZero);
}

void RCPanel::setInsect(float left, float bottom, float right, float top)
{
    m_pBGImage->setInsetLeft(left);
    m_pBGImage->setInsetBottom(bottom);
    m_pBGImage->setInsetRight(right);
    m_pBGImage->setInsetTop(top);
}

void RCPanel::setCloseButtonPosition(CCPoint pos)
{
    CCSize size = getContentSize();
    m_pCloseButton->setPosition(pos);
}

void RCPanel::setFontName(const char* fontName)
{
    m_pTitle->setFontName(fontName);
}

void RCPanel::setFontSize(float fontSize)
{
    m_pTitle->setFontSize(fontSize);
}

void RCPanel::setEnableTitle(bool var)
{
    m_pTitle->setVisible(var);
}

void RCPanel::setTitlePosition(CCPoint pos)
{
    m_pTitle->setPosition(pos);
}

void RCPanel::setTitleColor(ccColor3B color3)
{
    m_pTitle->setColor(color3);
}

void RCPanel::setTarget(CCObject* pObj,SEL_CallFuncN fun)
{
	m_pListener = pObj;
	m_pfnSelector = fun;
}

void RCPanel::setEnableCloseButton(bool var)
{
    m_enableCloseButton = var;
    m_pCloseButton->setVisible(m_enableCloseButton);
}

bool RCPanel::getEnableCloseButton()
{
    return m_enableCloseButton;
}

void RCPanel::setNormalCloseFrame(CCSpriteFrame *var)
{
    CC_SAFE_RELEASE(m_pNormalCloseFrame);
    m_pNormalCloseFrame = NULL;
    if (var) {
        m_pNormalCloseFrame = var;
        m_pNormalCloseFrame->retain();
        m_pCloseButton->setDisplayFrame(m_pNormalCloseFrame);
    }
}

void RCPanel::setSelectedCloseFrame(CCSpriteFrame *var)
{
    CC_SAFE_RELEASE(m_pSelectedCloseFrame);
    m_pSelectedCloseFrame = NULL;
    if (var) {
        m_pSelectedCloseFrame = var;
        m_pSelectedCloseFrame->retain();
    }
}

CCSpriteFrame* RCPanel::getNormalCloseFrame()
{
    return m_pNormalCloseFrame;
}

CCSpriteFrame* RCPanel::getSelectedCloseFrame()
{
    return m_pSelectedCloseFrame;
}

