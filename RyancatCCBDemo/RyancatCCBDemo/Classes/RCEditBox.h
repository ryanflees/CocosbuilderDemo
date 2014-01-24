//
//  RCEditBox.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-16.
//
//

#ifndef __HYDemo__RCEditBox__
#define __HYDemo__RCEditBox__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCEditBox : public CCEditBox
{
public:
    virtual bool init();
    CREATE_FUNC(RCEditBox);
    virtual void onEnter();
    virtual void onExit();
    
    void setBackgroundFrame(CCSpriteFrame* frame);
    void setTextPosition(CCPoint pos);
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual void keyboardWillShow(CCIMEKeyboardNotificationInfo& info);
    virtual void keyboardDidShow(CCIMEKeyboardNotificationInfo& info);
    virtual void keyboardWillHide(CCIMEKeyboardNotificationInfo& info);
    virtual void keyboardDidHide(CCIMEKeyboardNotificationInfo& info);
    
};

#endif /* defined(__HYDemo__RCEditBox__) */
