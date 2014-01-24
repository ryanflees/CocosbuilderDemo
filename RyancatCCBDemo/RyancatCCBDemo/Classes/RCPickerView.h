//
//  RCPickerView.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#ifndef __HYDemo__RCPickerView__
#define __HYDemo__RCPickerView__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class RCPickerViewImp;

class RCPickerViewImpDelegate;

class RCPickerView : public CCNode
{
public:
    ~RCPickerView();
    virtual bool init();
    CREATE_FUNC(RCPickerView);
    void setPickerRect(const CCRect& rect);
    void setDelegate(RCPickerViewImpDelegate* delegate);
    int getSelectedRow(int component);
private:
    CC_SYNTHESIZE_READONLY(RCPickerViewImp*, m_pPickerViewImp, PickViewImp);
};

#endif /* defined(__HYDemo__RCPickerView__) */
