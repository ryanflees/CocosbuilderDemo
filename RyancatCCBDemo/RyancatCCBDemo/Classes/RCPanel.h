//
//  RCPanel.h
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#ifndef __RyancatCCBDemo__RCPanel__
#define __RyancatCCBDemo__RCPanel__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCPanel : public CCNode
,public CCTargetedTouchDelegate
{
public:
    RCPanel();
    virtual ~RCPanel();
    virtual bool init();
    CREATE_FUNC(RCPanel);
    virtual void onEnter();
    virtual void onExit();
    
    void setTitle(const char* title);
	const char* getTitle(void);
    
    virtual void setContentSize(const CCSize& size);
    
    void setPanelFrame(CCSpriteFrame* frame);
    
    void setInsect(float left, float bottom, float right, float top);
    
    void setCloseButtonPosition(CCPoint pos);
    
    void setFontName(const char* fontName);
    void setFontSize(float fontSize);
    void setEnableTitle(bool var);
    void setTitlePosition(CCPoint pos);
    void setTitleColor(ccColor3B color3);
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
	void setTarget(CCObject* pObj,SEL_CallFuncN fun);
private:
	CCScale9Sprite* m_pBGImage;
	CCLabelTTF* m_pTitle;
	CCSprite* m_pCloseButton;
    
    CC_PROPERTY(CCSpriteFrame*, m_pNormalCloseFrame, NormalCloseFrame);
    CC_PROPERTY(CCSpriteFrame*, m_pSelectedCloseFrame, SelectedCloseFrame);
    CC_PROPERTY(bool, m_enableCloseButton, EnableCloseButton);
    CC_SYNTHESIZE(int, m_touchUpOutDelay, TouchUpOutDelay);
    
    bool    m_closeButtonSelected;
    long   m_touchTimer;
	CCObject*     m_pListener;
	SEL_CallFuncN  m_pfnSelector;
};

#endif /* defined(__RyancatCCBDemo__RCPanel__) */
