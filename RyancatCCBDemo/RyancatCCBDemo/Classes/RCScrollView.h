//
//  RCScrollView.h
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#ifndef __RyancatCCBDemo__RCScrollView__
#define __RyancatCCBDemo__RCScrollView__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCScrollView :public CCScrollView
{
public:
    RCScrollView();
    virtual ~RCScrollView();
    virtual bool init();
    CREATE_FUNC(RCScrollView);
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
private:
    void relocateContainer(bool animated);
    void deaccelerateScrolling(float dt);
    void setContentOffsetByItemIndex(int i);

    CC_SYNTHESIZE(bool, m_pageMode, PageMode);
    CC_SYNTHESIZE_READONLY(int, m_pageCount, PageCount);
    int getCurrentPageIndex();
    int m_currentPageIndex;
};

#endif /* defined(__RyancatCCBDemo__RCScrollView__) */
