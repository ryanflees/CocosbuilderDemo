//
//  RCCheckButton.h
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#ifndef __RyancatCCBDemo__RCCheckButton__
#define __RyancatCCBDemo__RCCheckButton__

#include "cocos2d.h"

USING_NS_CC;

class RCCheckButton :public CCNode
,public CCTargetedTouchDelegate
{
public:
    RCCheckButton();
    virtual ~RCCheckButton();
    virtual bool init();
    CREATE_FUNC(RCCheckButton);
    virtual void onEnter();
    virtual void onExit();

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    void setTarget(CCObject* pObj,SEL_CallFuncN fun);
    
    void select();
	void unselect();
    void toggleSelected();
	
    void setTitle(const char* title);
	const char* getTitle();
    void setFontTTF(const char* font);
    void setFontSize(int fontSize);
    void setLabelColor(ccColor3B color);
    void setLabelPosition(CCPoint pos);
    void setImageScale(float scale);
    void setImageScaleX(float scaleX);
    void setImageScaleY(float scaleY);
    
private:
    void updateTextureRect();
    CCSize getNodeContentSize();
    CCRect getNodeRect();
    
    CC_PROPERTY(bool, m_selected, Selected);
    CCSprite* m_pCheckButtonSprite;
	CCLabelTTF*	m_pText;
    CCObject* m_pListener;
	SEL_CallFuncN m_pfnSelector;
    CC_SYNTHESIZE(ccColor3B, m_selectedLabelColor, SelectedLabelColor);
    ccColor3B m_normalLabelColor;
    
    CC_PROPERTY(CCSpriteFrame*, m_pNormalSpriteFrame, NormalSpriteFrame);
    CC_PROPERTY(CCSpriteFrame*, m_pSelectedSpriteFrame, SelectedSpriteFrame);
};

#endif /* defined(__RyancatCCBDemo__RCCheckButton__) */
