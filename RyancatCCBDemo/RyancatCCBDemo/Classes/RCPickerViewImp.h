//
//  RCPickerViewImp.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#ifndef HYDemo_RCPickerViewImp_h
#define HYDemo_RCPickerViewImp_h

#include "cocos2d.h"

USING_NS_CC;

class RCPickerViewImp;

class RCPickerViewImpDelegate
{
public:
    virtual ~RCPickerViewImpDelegate(){}
    virtual int numberOfComponentsInPickerView(RCPickerViewImp *pickerView) = 0;
    virtual int numberOfRowsInComponent(RCPickerViewImp *pickerView, int component) = 0;
    virtual const char* titleForRow(RCPickerViewImp *pickerView, int row, int component) = 0;
    virtual void didSelectRow(RCPickerViewImp *pickerView, int row, int component) = 0;
    virtual float rowHeightForComponent(RCPickerViewImp *pickerView, int component) = 0;
    virtual float widthForComponent(RCPickerViewImp *pickerView, int component) = 0;
};

class RCPickerViewImp : public CCNode{
public:
    RCPickerViewImp() {}
    virtual ~RCPickerViewImp() {}
    
    virtual bool init()
    {
        if (!CCNode::init()) {
            return false;
        }
        return true;
    }
    
    virtual void setPickerRect(const CCRect& rect){}
    CREATE_FUNC(RCPickerViewImp);
    
    virtual void setDelegate(RCPickerViewImpDelegate* delegate){}
    
    virtual int getSelectedRow(int component){return -1;}
};

// This method must be implemented at each subclass of CCEditBoxImpl.
extern RCPickerViewImp* __createSystemPickerView();

#endif
