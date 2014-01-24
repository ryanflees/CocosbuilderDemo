//
//  RCTableViewImp.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#include "RCTableViewImp.h"

RCTableViewImp::RCTableViewImp()
:m_subNodeTouched()
{

}

RCTableViewImp::~RCTableViewImp()
{

}

RCTableViewImp* RCTableViewImp::create(CCTableViewDataSource* dataSource, CCSize size)
{
    return RCTableViewImp::create(dataSource, size, NULL);
}

RCTableViewImp* RCTableViewImp::create(CCTableViewDataSource* dataSource, CCSize size, CCNode *container)
{
    RCTableViewImp *table = new RCTableViewImp();
    table->initWithViewSize(size, container);
    table->autorelease();
    table->setDataSource(dataSource);
    table->_updateCellPositions();
    table->_updateContentSize();
    
    return table;
}

bool RCTableViewImp::initWithViewSize(CCSize size, CCNode* container/* = NULL*/)
{
    if (CCLayer::init())
    {
        m_pContainer = container;
        
        if (!this->m_pContainer)
        {
            m_pContainer = CCNode::create();
            this->m_pContainer->ignoreAnchorPointForPosition(false);
            this->m_pContainer->setAnchorPoint(ccp(0.0f, 0.0f));
        }
        
        this->setViewSize(size);
        
        setTouchEnabled(true);
        m_pTouches = new CCArray();
        m_pDelegate = NULL;
        m_bBounceable = true;
        m_bClippingToBounds = true;
        //m_pContainer->setContentSize(CCSizeZero);
        m_eDirection  = kCCScrollViewDirectionBoth;
        m_pContainer->setPosition(ccp(0.0f, 0.0f));
        m_fTouchLength = 0.0f;
        
        this->addChild(m_pContainer);
        m_fMinScale = m_fMaxScale = 1.0f;
        
        m_pCellsUsed      = new CCArrayForObjectSorting();
        m_pCellsFreed     = new CCArrayForObjectSorting();
        m_pIndices        = new std::set<unsigned int>();
        m_eVordering      = kCCTableViewFillBottomUp;
        this->setDirection(kCCScrollViewDirectionVertical);
        
        CCScrollView::setDelegate(this);
        return true;
    }
    return false;
}

bool RCTableViewImp::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    if(CCTableView::ccTouchBegan(pTouch, pEvent))
    {
//        if(CCNode::ccTouchBegan(pTouch,pEvent))
//        {
//            m_subNodeTouched = true;
//            return true;
//        }
        return true;
    }
    return false;
   // return CCNode::ccTouchBegan(pTouch, pEvent);
}

void RCTableViewImp::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
//    if(m_subNodeTouched)
//	{
//		m_subNodeTouched = false;
//		CCNode::ccTouchCancelled(pTouch,pEvent);
//	}
    CCTableView::ccTouchMoved(pTouch, pEvent);
}

void RCTableViewImp::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
//    if(m_subNodeTouched)
//    {
//        CCNode::ccTouchEnded(pTouch,pEvent);
//    }
    CCTableView::ccTouchEnded(pTouch, pEvent);
    m_subNodeTouched = false;
    //CCNode::ccTouchEnded(pTouch, pEvent);
}

void RCTableViewImp::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
//    if(m_subNodeTouched)
//    {
//        CCNode::ccTouchEnded(pTouch,pEvent);
//    }
    CCTableView::ccTouchCancelled(pTouch, pEvent);
    m_subNodeTouched = false;
    
    //CCNode::ccTouchCancelled(pTouch, pEvent);
}

