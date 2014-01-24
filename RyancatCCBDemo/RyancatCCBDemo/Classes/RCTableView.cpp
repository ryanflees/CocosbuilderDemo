//
//  RCTableView.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#include "RCTableView.h"

RCTableView::RCTableView()
:m_pTableView()
{

}

RCTableView::~RCTableView()
{
}

bool RCTableView::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    
    return true;
}
void RCTableView::onEnter()
{
    CCNode::onEnter();
    
}
void RCTableView::onExit()
{
    CCNode::onExit();
}

void RCTableView::generateTableView(CCTableViewDataSource *dataSource)
{
    if (!m_pTableView) {
        m_pTableView = RCTableViewImp::create(dataSource, m_tableSize);
        addChild(m_pTableView);
    }
}
