//
//  RCPickerView.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#include "RCPickerView.h"
#include "RCPickerViewImp.h"

RCPickerView::~RCPickerView()
{
}

bool RCPickerView::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
    m_pPickerViewImp = __createSystemPickerView();
    addChild(m_pPickerViewImp);
    
    return true;
}

void RCPickerView::setPickerRect(const CCRect &rect)
{
    m_pPickerViewImp->setPickerRect(rect);
}

void RCPickerView::setDelegate(RCPickerViewImpDelegate* delegate)
{
    m_pPickerViewImp->setDelegate(delegate);
}

int RCPickerView::getSelectedRow(int component)
{
    return m_pPickerViewImp->getSelectedRow(component);
}
