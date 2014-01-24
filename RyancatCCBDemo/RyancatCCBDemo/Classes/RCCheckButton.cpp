//
//  RCCheckButton.cpp
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#include "RCCheckButton.h"

#define DEFAULT_FONT_SIZE 40

RCCheckButton::RCCheckButton()
:m_selected()
,m_pListener()
,m_pfnSelector()
,m_pNormalSpriteFrame()
,m_pSelectedSpriteFrame()
{

}

RCCheckButton::~RCCheckButton()
{

}

bool RCCheckButton::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    
    m_pCheckButtonSprite = CCSprite::create();
	m_pText = CCLabelTTF::create("","", DEFAULT_FONT_SIZE);
	addChild(m_pCheckButtonSprite);
	addChild(m_pText);
	setSelected(false);
    
    return true;
}

void RCCheckButton::onEnter()
{
    CCNode::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void RCCheckButton::onExit()
{
    CCNode::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool RCCheckButton::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    bool bRet = false;
	CCRect checkBtnRect = getNodeRect();
	if(checkBtnRect.containsPoint(convertToNodeSpace(pTouch->getLocation())))
	{
		m_pText->setColor(m_selectedLabelColor);
		bRet = true;
	}
	return bRet;
}

void RCCheckButton::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCRect checkBtnRect = getNodeRect();
	if(checkBtnRect.containsPoint(convertToNodeSpace(pTouch->getLocation())))
	{
		m_pText->setColor(m_selectedLabelColor);
	}
	else
	{
		m_pText->setColor(m_normalLabelColor);
	}
}

void RCCheckButton::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCRect checkBtnRect = getNodeRect();
	if(checkBtnRect.containsPoint(convertToNodeSpace(pTouch->getLocation())))
	{
        toggleSelected();
        if(m_pListener && m_pfnSelector)
        {
            (m_pListener->*m_pfnSelector)(this);
        }
	}
	m_pText->setColor(m_normalLabelColor);
}

void RCCheckButton::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
}

void RCCheckButton::setTarget(CCObject* pObj,SEL_CallFuncN fun)
{
	m_pListener = pObj;
	m_pfnSelector = fun;
}

void RCCheckButton::select(void)
{
    setSelected(true);
}

void RCCheckButton::unselect(void)
{
    setSelected(false);
}

void RCCheckButton::toggleSelected()
{
    setSelected(!m_selected);
}

void RCCheckButton::setTitle(const char* title)
{
    m_pText->setString(title);
}

const char* RCCheckButton::getTitle(void)
{
	return m_pText->getString();
}

void RCCheckButton::setFontTTF(const char* font)
{
    m_pText->setFontName(font);
}

void RCCheckButton::setFontSize(int fontSize)
{
	m_pText->setFontSize(fontSize);
}

void RCCheckButton::setLabelColor(ccColor3B color)
{
    m_normalLabelColor = color;
    m_pText->setColor(color);
}

void RCCheckButton::setLabelPosition(CCPoint pos)
{
    m_pText->setPosition(pos);
}

void RCCheckButton::setImageScale(float scale)
{
    m_pCheckButtonSprite->setScale(scale);
}

void RCCheckButton::setImageScaleX(float scaleX)
{
    m_pCheckButtonSprite->setScaleX(scaleX);
}

void RCCheckButton::setImageScaleY(float scaleY)
{
    m_pCheckButtonSprite->setScaleY(scaleY);
}

void RCCheckButton::updateTextureRect(void)
{
	if(m_selected)
	{
	    if (m_pSelectedSpriteFrame) {
            m_pCheckButtonSprite->setDisplayFrame(m_pSelectedSpriteFrame);
        }
    }
	else
	{
	    if (m_pNormalSpriteFrame) {
            m_pCheckButtonSprite->setDisplayFrame(m_pNormalSpriteFrame);
        }
    }
}

CCSize RCCheckButton::getNodeContentSize()
{
    CCSize imageSize = m_pCheckButtonSprite->getContentSize();
    CCSize labelSize = m_pText->getContentSize();
    float height = imageSize.height > labelSize.height ? imageSize.height : labelSize.height;
    CCSize contentSize = CCSizeMake(imageSize.width/2 + m_pText->getPositionX() + labelSize.width/2, height);
    return contentSize;
}

CCRect RCCheckButton::getNodeRect()
{
    CCSize contentSize = getNodeContentSize();
    CCRect rect = CCRectMake(-m_pCheckButtonSprite->getContentSize().width/2,
                             -m_pCheckButtonSprite->getContentSize().height/2,
                             contentSize.width, contentSize.height);
    return rect;
}

void RCCheckButton::setSelected(bool var)
{
    m_selected = var;
	updateTextureRect();
}

bool RCCheckButton::getSelected()
{
    return m_selected;
}

void RCCheckButton::setNormalSpriteFrame(CCSpriteFrame* frame)
{
    CC_SAFE_RELEASE(m_pNormalSpriteFrame);
    m_pNormalSpriteFrame = NULL;
    if (frame) {
        m_pNormalSpriteFrame = frame;
        m_pNormalSpriteFrame->retain();
        if (!getSelected()) {
            m_pCheckButtonSprite->setDisplayFrame(frame);
        }
    }
}

void RCCheckButton::setSelectedSpriteFrame(CCSpriteFrame* frame)
{
    CC_SAFE_RELEASE(m_pSelectedSpriteFrame);
    m_pSelectedSpriteFrame = NULL;
    if (frame) {
        m_pSelectedSpriteFrame = frame;
        m_pSelectedSpriteFrame->retain();
        if (getSelected()) {
            m_pCheckButtonSprite->setDisplayFrame(frame);
        }
    }
}

CCSpriteFrame* RCCheckButton::getNormalSpriteFrame()
{
    return m_pNormalSpriteFrame;
}

CCSpriteFrame* RCCheckButton::getSelectedSpriteFrame()
{
    return m_pSelectedSpriteFrame;
}



