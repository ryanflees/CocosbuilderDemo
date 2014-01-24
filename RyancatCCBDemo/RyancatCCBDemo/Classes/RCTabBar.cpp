//
//  RCTabbar.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-13.
//
//

#include "RCTabBar.h"

RCTabBar::RCTabBar()
    :m_pDelegate()
    ,m_pButtonNormalFrame()
    ,m_pButtonSelectedFrame()
    ,m_tabBarDirection()
    ,m_curTabIndex()
    ,m_firstTabButtonSpace()
    ,m_tabButtonSpace()
    ,m_tabPanelSpace()
    ,m_pSelectedTabButton()
    ,m_pTouchedTabButton()
{
    
}

RCTabBar::~RCTabBar()
{
    m_pTabButtonArray->release();
    m_pTabPageArray->release();
    
    CC_SAFE_RELEASE(m_pButtonNormalFrame);
    CC_SAFE_RELEASE(m_pButtonSelectedFrame);
}

bool RCTabBar::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    m_pTabButtonArray = CCArray::create();
    m_pTabButtonArray->retain();
    m_pTabPageArray = CCArray::create();
    m_pTabPageArray->retain();
    
    m_pBackgroundImage = CCScale9Sprite::create();
    addChild(m_pBackgroundImage);
    m_pBackgroundImage->setAnchorPoint(CCPointZero);
    m_pBackgroundImage->setPosition(CCPointZero);
    
    return true;
}

void RCTabBar::onEnter()
{
    CCNode::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void RCTabBar::onExit()
{
    CCNode::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

void RCTabBar::setBackgroundFrame(CCSpriteFrame* frame)
{
    if (m_pBackgroundImage) {
        m_pBackgroundImage->removeFromParent();
        m_pBackgroundImage = NULL;
    }
    m_pBackgroundImage = CCScale9Sprite::createWithSpriteFrame(frame);
    addChild(m_pBackgroundImage);
 }

void RCTabBar::setTabButtonNormalFrame(CCSpriteFrame* frame)
{
    CC_SAFE_RELEASE(m_pButtonNormalFrame);
    m_pButtonNormalFrame = NULL;
    if (frame) {
        m_pButtonNormalFrame = frame;
        m_pButtonNormalFrame->retain();
    }
    
    CCObject* pObject;
    CCARRAY_FOREACH(m_pTabButtonArray, pObject)
    {
        CCScale9Sprite* pButton = (CCScale9Sprite*)pObject;
        pButton->setSpriteFrame(m_pButtonNormalFrame);
        pButton->setContentSize(m_tabButtonSize);
    }
}

void RCTabBar::setTabButtonSelectedFrame(CCSpriteFrame* frame)
{
    CC_SAFE_RELEASE(m_pButtonSelectedFrame);
    m_pButtonSelectedFrame = NULL;
    if (frame) {
        m_pButtonSelectedFrame = frame;
        m_pButtonSelectedFrame->retain();
    }
}

void RCTabBar::setTabButtonSize(const CCSize& size)
{
    m_tabButtonSize = size;
    updateLayout();
}

const CCSize& RCTabBar::getTabButtonSize(void)
{
    return m_tabButtonSize;
}

void RCTabBar::setBackgroundSize(const CCSize& size)
{
    if (!m_pBackgroundImage)
    {
        return;
    }
    m_pBackgroundImage->setContentSize(size);
    m_pBackgroundImage->setPosition(ccp(size.width/2, size.height/2));
    updateLayout();
}

void RCTabBar::setTabButtonCount(int count)
{
    CCObject* pObject;
    CCARRAY_FOREACH(m_pTabButtonArray, pObject)
    {
        CCNode* node = (CCNode*)pObject;
        node->removeFromParent();
    }
    m_pTabButtonArray->removeAllObjects();
    
    for (int i=0; i<count; i++) {
        CCScale9Sprite* pButton;
        if (m_pButtonNormalFrame)
        {
            pButton = CCScale9Sprite::createWithSpriteFrame(m_pButtonNormalFrame);
        }
        else
        {
            pButton = CCScale9Sprite::create();
        }
        pButton->setTag(i);
        addChild(pButton);
        m_pTabButtonArray->addObject(pButton);
    }
    updateLayout();
}

int RCTabBar::getTabButtonCount()
{
    return m_pTabButtonArray->count();
}

void RCTabBar::setTabPanelSpace(int var)
{
    m_tabPanelSpace = var;
}

int RCTabBar::getTabPanelSpace()
{
    return m_tabPanelSpace;
}

void RCTabBar::setTabButtonSpace(int var)
{
    m_tabButtonSpace = var;
    updateLayout();
}

int RCTabBar::getTabButtonSpace()
{
    return m_tabButtonSpace;
}

void RCTabBar::setFirstTabButtonSpace(int var)
{
    m_firstTabButtonSpace = var;
    updateLayout();
}

int RCTabBar::getFirstTabButtonSpace()
{
    return m_firstTabButtonSpace;
}

void RCTabBar::setTabBarDirection(int var)
{
    if (var != kTabBarDirectionTop && var != kTabBarDirectionLeft &&
        var != kTabBarDirectionBottom && var != kTabBarDirectionRight)
    {
        m_tabBarDirection = kTabBarDirectionTop;
    }
    else
    {
        m_tabBarDirection = var;
    }
    updateLayout();
}

int RCTabBar::getTabBarDirection()
{
    return m_tabBarDirection;
}

void RCTabBar::setCurTabIndex(int var)
{
    m_curTabIndex = var;
    switchToPage(m_curTabIndex);
}

int RCTabBar::getCurTabIndex()
{
    return m_curTabIndex;
}

void RCTabBar::onTabPageChanged()
{

}

void RCTabBar::updateTabState()
{
}

void RCTabBar::updateLayout()
{
    CCObject* pObject;
    CCARRAY_FOREACH(m_pTabButtonArray, pObject)
    {
        CCScale9Sprite* pButton = (CCScale9Sprite*) pObject;
        pButton->setContentSize(m_tabButtonSize);
    }
    
    if (m_tabBarDirection == kTabBarDirectionTop)
    {
        CCSize backSize = m_pBackgroundImage->getContentSize();
        m_pBackgroundImage->setPosition(ccp(backSize.width/2,backSize.height/2));
        int i = 0;
        CCObject* pObject;
        CCARRAY_FOREACH(m_pTabButtonArray, pObject)
        {
            CCNode* pNode = (CCNode*)pObject;
            CCPoint pos = ccp(m_firstTabButtonSpace + pNode->getContentSize().width/2 + (pNode->getContentSize().width + m_tabButtonSpace)*i
                              , backSize.height + pNode->getContentSize().height/2);
            pNode->setPosition(pos);
            i++;
        }
        CCSize totalSize = backSize;
        totalSize.height += m_tabButtonSize.height;
        setContentSize(totalSize);
    }
    else if (m_tabBarDirection == kTabBarDirectionLeft)
    {
        CCSize backSize = m_pBackgroundImage->getContentSize();
        m_pBackgroundImage->setPosition(ccp(backSize.width/2 + m_tabButtonSize.width,backSize.height/2));
        int i = 0;
        CCObject* pObject;
        CCARRAY_FOREACH(m_pTabButtonArray, pObject)
        {
            CCNode* pNode = (CCNode*)pObject;
            float distanceFromTop = m_firstTabButtonSpace + pNode->getContentSize().height/2 + (pNode->getContentSize().height + m_tabButtonSpace)*i;
            CCPoint pos = ccp(pNode->getContentSize().width/2,
                backSize.height - distanceFromTop);
            pNode->setPosition(pos);
            i++;
        }
        CCSize totalSize = backSize;
        totalSize.width += m_tabButtonSize.width;
        setContentSize(totalSize);
    }
    else if (m_tabBarDirection == kTabBarDirectionBottom)
    {
        CCSize backSize = m_pBackgroundImage->getContentSize();
        m_pBackgroundImage->setPosition(ccp(backSize.width/2,backSize.height/2 + m_tabButtonSize.height));
        int i = 0;
        CCObject* pObject;
        CCARRAY_FOREACH(m_pTabButtonArray, pObject)
        {
            CCNode* pNode = (CCNode*)pObject;
            CCPoint pos = ccp(m_firstTabButtonSpace + pNode->getContentSize().width/2 + (pNode->getContentSize().width + m_tabButtonSpace)*i
                              , pNode->getContentSize().height/2);
            pNode->setPosition(pos);
            i++;
        }
        CCSize totalSize = backSize;
        totalSize.height += m_tabButtonSize.height;
        setContentSize(totalSize);
      
    }
    else if (m_tabBarDirection == kTabBarDirectionRight)
    {
        CCSize backSize = m_pBackgroundImage->getContentSize();
        m_pBackgroundImage->setPosition(ccp(backSize.width/2, backSize.height/2));
        int i = 0;
        CCObject* pObject;
        CCARRAY_FOREACH(m_pTabButtonArray, pObject)
        {
            CCNode* pNode = (CCNode*)pObject;
            float distanceFromTop = m_firstTabButtonSpace + pNode->getContentSize().height/2 + (pNode->getContentSize().height + m_tabButtonSpace)*i;
            CCPoint pos = ccp(pNode->getContentSize().width/2 + backSize.width,
                              backSize.height - distanceFromTop);
            pNode->setPosition(pos);
            i++;
        }
        CCSize totalSize = backSize;
        totalSize.width += m_tabButtonSize.width;
        setContentSize(totalSize);
    }
    
    switchToPage(m_curTabIndex);
}

bool RCTabBar::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint touchPoint = pTouch->getLocation();
    touchPoint = convertToNodeSpace(touchPoint);
    CCObject* pObject;
    CCARRAY_FOREACH(m_pTabButtonArray, pObject)
    {
        CCScale9Sprite* pButton = (CCScale9Sprite*)pObject;
        
        if (m_pSelectedTabButton == pButton) {
            continue;
        }
        CCRect buttonRect = CCRectMake(pButton->getPositionX() - pButton->getContentSize().width/2
                                            , pButton->getPositionY() - pButton->getContentSize().height/2
                                            , pButton->getContentSize().width
                                            , pButton->getContentSize().height);
        if (buttonRect.containsPoint(touchPoint)) {
            m_pTouchedTabButton = pButton;
            pButton->setSpriteFrame(m_pButtonSelectedFrame);
            pButton->setContentSize(m_tabButtonSize);
            return true;
        }
    }
    return false;
}

void RCTabBar::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint touchPoint = pTouch->getLocation();
    touchPoint = convertToNodeSpace(touchPoint);
    if (m_pTouchedTabButton && m_pTouchedTabButton != m_pSelectedTabButton) {
        CCRect buttonRect = CCRectMake(m_pTouchedTabButton->getPositionX() - m_pTouchedTabButton->getContentSize().width/2
                                       , m_pTouchedTabButton->getPositionY() - m_pTouchedTabButton->getContentSize().height/2
                                       , m_pTouchedTabButton->getContentSize().width
                                       , m_pTouchedTabButton->getContentSize().height);
        if (!buttonRect.containsPoint(touchPoint)) {
            m_pTouchedTabButton->setSpriteFrame(m_pButtonNormalFrame);
            m_pTouchedTabButton->setContentSize(m_tabButtonSize);
            m_pTouchedTabButton = NULL;
            return;
        }
    }
}

void RCTabBar::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint touchPoint = pTouch->getLocation();
    touchPoint = convertToNodeSpace(touchPoint);
    if (m_pTouchedTabButton && m_pTouchedTabButton != m_pSelectedTabButton) {
        CCRect buttonRect = CCRectMake(m_pTouchedTabButton->getPositionX() - m_pTouchedTabButton->getContentSize().width/2
                                       , m_pTouchedTabButton->getPositionY() - m_pTouchedTabButton->getContentSize().height/2
                                       , m_pTouchedTabButton->getContentSize().width
                                       , m_pTouchedTabButton->getContentSize().height);
        if (buttonRect.containsPoint(touchPoint)) {
            m_pTouchedTabButton->setSpriteFrame(m_pButtonNormalFrame);
            m_pTouchedTabButton->setContentSize(m_tabButtonSize);
            switchToPage(m_pTouchedTabButton->getTag());
            if (m_pDelegate) {
                m_pDelegate->onTabSelected(this, NULL, m_pTouchedTabButton->getTag());
            }
            m_pTouchedTabButton = NULL;
            return;
        }
        else
        {
            m_pTouchedTabButton->setSpriteFrame(m_pButtonNormalFrame);
            m_pTouchedTabButton->setContentSize(m_tabButtonSize);
            m_pTouchedTabButton = NULL;
            return;
        }
    }
}

void RCTabBar::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint touchPoint = pTouch->getLocation();
    touchPoint = convertToNodeSpace(touchPoint);
    if (m_pTouchedTabButton && m_pTouchedTabButton != m_pSelectedTabButton) {
        CCRect buttonRect = CCRectMake(m_pTouchedTabButton->getPositionX() - m_pTouchedTabButton->getContentSize().width/2
                                       , m_pTouchedTabButton->getPositionY() - m_pTouchedTabButton->getContentSize().height/2
                                       , m_pTouchedTabButton->getContentSize().width
                                       , m_pTouchedTabButton->getContentSize().height);
        if (buttonRect.containsPoint(touchPoint)) {
            m_pTouchedTabButton->setSpriteFrame(m_pButtonNormalFrame);
            m_pTouchedTabButton->setContentSize(m_tabButtonSize);
            m_pTouchedTabButton = NULL;
            return;
        }
        else
        {
            m_pTouchedTabButton->setSpriteFrame(m_pButtonNormalFrame);
            m_pTouchedTabButton->setContentSize(m_tabButtonSize);
            m_pTouchedTabButton = NULL;
            return;
        }
    }
}

void RCTabBar::switchToPage(int index)
{
    CCObject* pObject;
    CCARRAY_FOREACH(m_pTabButtonArray, pObject)
    {
        CCScale9Sprite* pButton = (CCScale9Sprite*)pObject;
        if (index == pButton->getTag()) {
            selectTab(pButton);
        }
    }
}

void RCTabBar::selectTab(CCScale9Sprite *pButton)
{
    if (!pButton) {
        return;
    }
    
    if (m_pSelectedTabButton == pButton) {
        return;
    }
    if (m_pSelectedTabButton) {
        m_pSelectedTabButton->setSpriteFrame(m_pButtonNormalFrame);
        m_pSelectedTabButton->setContentSize(m_tabButtonSize);
    }
    m_pSelectedTabButton = pButton;
    m_curTabIndex = m_pSelectedTabButton->getTag();
    m_pSelectedTabButton->setSpriteFrame(m_pButtonSelectedFrame);
    m_pSelectedTabButton->setContentSize(m_tabButtonSize);
}