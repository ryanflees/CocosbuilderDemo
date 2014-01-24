//
//  RCImageButton.h
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#ifndef __RyancatCCBDemo__RCImageButton__
#define __RyancatCCBDemo__RCImageButton__

#include "cocos2d.h"

USING_NS_CC;

class RCImageButton :public CCNode
,public CCTargetedTouchDelegate
{
public:
    RCImageButton();
    virtual ~RCImageButton();
    virtual bool init();
    CREATE_FUNC(RCImageButton);
    virtual void onEnter();
    virtual void onExit();
    
    virtual void visit(void);
    
    void setImageDisplayFrame(CCSpriteFrame* frame);
    
    void setTarget(CCObject* pObj,SEL_CallFuncN fun);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
private:
    void updateTextureRect(void);

    bool m_isTouched;
    long m_touchTimer;
    CC_SYNTHESIZE(int, m_touchUpOutDelay, TouchUpOutDelay);
    CCObject* m_pListener;
	SEL_CallFuncN m_pfnSelector;
    CCSprite* m_pButtonSprite;
    CC_SYNTHESIZE(ccColor3B, m_selectedColor, SelectedColor);
    ccColor3B m_normalColor;
};

#endif /* defined(__RyancatCCBDemo__RCImageButton__) */
