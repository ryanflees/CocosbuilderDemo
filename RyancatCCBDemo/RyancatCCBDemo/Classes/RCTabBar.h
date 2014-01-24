//
//  RCTabbar.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-13.
//
//

#ifndef __HYDemo__RCTabbar__
#define __HYDemo__RCTabbar__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

enum
{
    kTabBarDirectionTop = 0,
    kTabBarDirectionLeft = 1,
    kTabBarDirectionRight = 2,
    kTabBarDirectionBottom = 3,
};

class RCTabBar;

class RCTabBarDelegate
{
public:
    virtual void onTabSelected(RCTabBar* pTabbar, CCNode* pTabPage, int index) = 0;
};

class RCTabBar : public CCNode
,public CCTargetedTouchDelegate
{
public:
    RCTabBar();
    ~RCTabBar();
    virtual bool init();
    CREATE_FUNC(RCTabBar);
    virtual void onEnter();
    virtual void onExit();
    
    void setBackgroundFrame(CCSpriteFrame* frame);
    void setTabButtonNormalFrame(CCSpriteFrame* frame);
    void setTabButtonSelectedFrame(CCSpriteFrame* frame);
    
    void setBackgroundSize(const CCSize& size);
    
    void setTabButtonCount(int count);
    int getTabButtonCount();
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

protected:
    void onTabPageChanged();
    void updateTabState();
    void updateLayout();
private:
    void switchToPage(int index);
    void selectTab(CCScale9Sprite* pButton);
    
    CC_SYNTHESIZE(RCTabBarDelegate*, m_pDelegate, Delegate);

    CC_PROPERTY(int, m_firstTabButtonSpace, FirstTabButtonSpace);
    CC_PROPERTY(int, m_tabButtonSpace, TabButtonSpace);
    CC_PROPERTY(int, m_tabBarDirection, TabBarDirection);
    CC_PROPERTY(int, m_tabPanelSpace, TabPanelSpace);
    CC_PROPERTY_PASS_BY_REF(CCSize, m_tabButtonSize, TabButtonSize);
    CC_PROPERTY(int, m_curTabIndex, CurTabIndex);
    CCSpriteFrame* m_pButtonNormalFrame;
    CCSpriteFrame* m_pButtonSelectedFrame;
    CCScale9Sprite* m_pBackgroundImage;
    CCScale9Sprite* m_pSelectedTabButton;
    CCScale9Sprite* m_pTouchedTabButton;
    CCArray* m_pTabButtonArray;
    CCArray* m_pTabPageArray;
};

#endif /* defined(__HYDemo__RCTabbar__) */
