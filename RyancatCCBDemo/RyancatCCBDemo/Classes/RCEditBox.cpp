//
//  RCEditBox.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-16.
//
//

#include "RCEditBox.h"
#include "CCEditBoxImpl.h"

bool RCEditBox::init()
{
    if (!CCControlButton::init()) {
        return false;
    }
    
    CCSize defaultSize = CCSizeMake(350, 70);
    m_pEditBoxImpl = __createSystemEditBox(this);
    m_pEditBoxImpl->initWithSize(defaultSize);
    
    this->setZoomOnTouchDown(false);
    this->setPreferredSize(defaultSize);
    this->setPosition(ccp(0, 0));
    this->addTargetWithActionForControlEvent(this, cccontrol_selector(CCEditBox::touchDownAction), CCControlEventTouchUpInside);
    
    return true;
}

void RCEditBox::onEnter()
{
    CCNode::onEnter();
}

void RCEditBox::onExit()
{
    CCNode::onExit();
}

void RCEditBox::setBackgroundFrame(CCSpriteFrame* frame)
{
    setBackgroundSpriteFrameForState(frame,CCControlStateNormal);
}

void RCEditBox::setTextPosition(CCPoint pos)
{
    CCSize size = getContentSize();
    CCPoint textPos = pos + getPosition() + ccp(size.width/2, 0);
    m_pEditBoxImpl->setPosition(textPos);
}

bool RCEditBox::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint point = convertToNodeSpace(pTouch->getLocation());
	if(point.x >= 0 && point.y >= 0 && m_obContentSize.width> point.x && m_obContentSize.height>point.y)
    {
        
    }
    else
    {
        if (m_pEditBoxImpl->isEditing()) {
            m_pEditBoxImpl->closeKeyboard();
            return true;
        }
    }
    return CCEditBox::ccTouchBegan(pTouch, pEvent);
}

void RCEditBox::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCEditBox::ccTouchMoved(pTouch, pEvent);
}

void RCEditBox::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCEditBox::ccTouchEnded(pTouch, pEvent);
}

void RCEditBox::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    CCEditBox::ccTouchCancelled(pTouch, pEvent);
}

void RCEditBox::keyboardWillShow(CCIMEKeyboardNotificationInfo& info)
{
    CCEditBox::keyboardWillShow(info);
}

void RCEditBox::keyboardDidShow(CCIMEKeyboardNotificationInfo& info)
{
    CCEditBox::keyboardDidShow(info);
}

void RCEditBox::keyboardWillHide(CCIMEKeyboardNotificationInfo& info)
{
    CCEditBox::keyboardWillHide(info);
}

void RCEditBox::keyboardDidHide(CCIMEKeyboardNotificationInfo& info)
{
    CCEditBox::keyboardDidHide(info);
}
