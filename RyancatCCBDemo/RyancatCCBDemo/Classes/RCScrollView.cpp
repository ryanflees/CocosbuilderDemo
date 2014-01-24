//
//  RCScrollView.cpp
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#include "RCScrollView.h"

#define SCROLL_DEACCEL_RATE  0.95f
#define SCROLL_DEACCEL_DIST  1.0f
#define BOUNCE_DURATION      0.15f
#define INSET_RATIO          0.2f
#define MOVE_INCH            7.0f/160.0f

RCScrollView::RCScrollView()
:m_pageMode()
{

}

RCScrollView::~RCScrollView()
{

}

bool RCScrollView::init()
{
    if (!CCScrollView::init())
    {
        return false;
    }
    m_currentPageIndex = 0;
    return true;
}

void RCScrollView::onEnter()
{
    CCScrollView::onEnter();
    
    if (m_pageMode) {
        float sizeMultiple = 0;
        if (m_eDirection == kCCScrollViewDirectionHorizontal) {
            CCAssert(getContainer()->getContentSize().width > 0, "container contentsize must be larger than 0");
            sizeMultiple = getContainer()->getContentSize().width/getViewSize().width;
        }
        else if (m_eDirection == kCCScrollViewDirectionVertical)
        {
            CCAssert(getContainer()->getContentSize().height > 0, "container contentsize must be larger than 0");
            sizeMultiple = getContainer()->getContentSize().height/getViewSize().height;
        }
        if (sizeMultiple > (int)sizeMultiple) {
            m_pageCount = sizeMultiple + 1;
        }
        else
        {
            m_pageCount = sizeMultiple;
        }
    }
}

void RCScrollView::onExit()
{
    CCScrollView::onExit();
}

bool RCScrollView::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return CCScrollView::ccTouchBegan(pTouch, pEvent);
}

void RCScrollView::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCScrollView::ccTouchMoved(pTouch, pEvent);
    CCObject* pObject;
    CCARRAY_FOREACH(getContainer()->getChildren(), pObject)
    {
        CCTargetedTouchDelegate* pTouchableNode = dynamic_cast<CCTargetedTouchDelegate*>(pObject);
        if (pTouchableNode) {
            pTouchableNode->ccTouchCancelled(pTouch, pEvent);
        }
    }
}

void RCScrollView::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!this->isVisible())
    {
        return;
    }
    if (m_pTouches->containsObject(pTouch))
    {
        if (m_pTouches->count() == 1 && m_bTouchMoved)
        {
            if (m_pageMode) {
                relocateContainer(true);
            }
            else
            {
                this->schedule(schedule_selector(RCScrollView::deaccelerateScrolling));
            }
        }
        m_pTouches->removeObject(pTouch);
    }
    
    if (m_pTouches->count() == 0)
    {
        m_bDragging = false;
        m_bTouchMoved = false;
    }
  //  CCScrollView::ccTouchEnded(pTouch, pEvent);
}

void RCScrollView::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
}

void RCScrollView::relocateContainer(bool animated)
{
    CCPoint oldPoint, min, max;
    float newX, newY;
    
    min = this->minContainerOffset();
    max = this->maxContainerOffset();
    
    oldPoint = m_pContainer->getPosition();
    
    newX     = oldPoint.x;
    newY     = oldPoint.y;
    if (m_eDirection == kCCScrollViewDirectionBoth || m_eDirection == kCCScrollViewDirectionHorizontal)
    {
        newX     = MAX(newX, min.x);
        newX     = MIN(newX, max.x);
    }
    
    if (m_eDirection == kCCScrollViewDirectionBoth || m_eDirection == kCCScrollViewDirectionVertical)
    {
        newY     = MIN(newY, max.y);
        newY     = MAX(newY, min.y);
    }
    
    if (!m_pageMode) {
        if (newY != oldPoint.y || newX != oldPoint.x)
        {
            this->setContentOffset(ccp(newX, newY), animated);
        }
    }
    else
    {
        if(oldPoint.x <= min.x || oldPoint.x >= max.x)
        {
            this->setContentOffset(ccp(newX, newY), animated);
        }
        else
        {
            
            float leftOffset = oldPoint.x;
            int criticalLeft = m_currentPageIndex*getViewSize().width*(-1) - 100;
            int criticalRight = m_currentPageIndex*getViewSize().width*(-1) + 100;
            if(leftOffset < criticalLeft)
            {
                m_currentPageIndex ++;
                if(m_currentPageIndex >= m_pageCount)
                    m_currentPageIndex = m_pageCount -1;
            }
            else if(leftOffset > criticalRight)
            {
                m_currentPageIndex --;
                if(m_currentPageIndex <= 0)
                    m_currentPageIndex = 0;
            }
            setContentOffsetByItemIndex(m_currentPageIndex);
        }
    }
}

void RCScrollView::setContentOffsetByItemIndex(int i)
{
    CCPoint newPosition;
    if (m_eDirection == kCCScrollViewDirectionVertical) {
        newPosition = ccp(m_pContainer->getPosition().y, (-1)*i*getViewSize().height);
    }
    else if (m_eDirection == kCCScrollViewDirectionHorizontal)
    {
        newPosition = ccp((-1)*i*getViewSize().width, m_pContainer->getPosition().y);
    }
    this->setContentOffsetInDuration(newPosition, 0.2f);
}

void RCScrollView::deaccelerateScrolling(float dt)
{
    if (m_bDragging)
    {
        this->unschedule(schedule_selector(RCScrollView::deaccelerateScrolling));
        return;
    }
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
    m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = this->maxContainerOffset();
        minInset = this->minContainerOffset();
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
    
    newX = m_pContainer->getPosition().x;
    newY = m_pContainer->getPosition().y;
    
    m_tScrollDistance     = ccpSub(m_tScrollDistance, ccp(newX - m_pContainer->getPosition().x, newY - m_pContainer->getPosition().y));
    m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
    this->setContentOffset(ccp(newX,newY));
    
    if ((fabsf(m_tScrollDistance.x) <= SCROLL_DEACCEL_DIST &&
         fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST) ||
        newY > maxInset.y || newY < minInset.y ||
        newX > maxInset.x || newX < minInset.x ||
        newX == maxInset.x || newX == minInset.x ||
        newY == maxInset.y || newY == minInset.y)
    {
        this->unschedule(schedule_selector(RCScrollView::deaccelerateScrolling));
        this->relocateContainer(true);
    }
}
