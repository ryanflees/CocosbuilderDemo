//
//  RCPickerViewImpIOS.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#import <Foundation/Foundation.h>
#include "cocos2d.h"
#include "RCPickerViewImp.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

@interface UIPickerViewImpIOS : UIView <UIPickerViewDataSource, UIPickerViewDelegate>
{
}

//@property (nonatomic, readonly) UIDatePicker* datePicker;
@property (nonatomic, readonly) UIPickerView* pickerView;
@property (nonatomic, assign) RCPickerViewImpDelegate* delegate;
@property (nonatomic, assign) RCPickerViewImp* pickerViewImpCpp;

-(id) init;
-(void) setPickerRect:(CGRect) rect;
-(int) getSelectedRow:(int) component;

@end

class RCPickerViewImpIOS : public RCPickerViewImp
{
public:
    RCPickerViewImpIOS();
    virtual ~RCPickerViewImpIOS();
    
    virtual bool init();
    CREATE_FUNC(RCPickerViewImpIOS);
    
    virtual void setPickerRect(const CCRect& rect);
    virtual void setDelegate(RCPickerViewImpDelegate* delegate);
    virtual int getSelectedRow(int component);
private:
    UIPickerViewImpIOS* m_systemControl;
    bool            m_bInRetinaMode;
};

#endif
