//
//  RCPickerViewImpIOS.m
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//
#include "RCPickerViewImpIOS.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#import "AppController.h"
#import "EAGLView.h"

@implementation UIPickerViewImpIOS
@synthesize pickerView;
@synthesize delegate;
@synthesize pickerViewImpCpp;

-(id) init
{
    if (([super init])) {
        pickerView = [[UIPickerView alloc] init];
        pickerView.delegate = self;
        pickerView.dataSource = self;
        pickerView.showsSelectionIndicator = YES;
       
//        UIImage* image = [UIImage imageNamed:@"ui/RCpanel.png"];
//        UIImageView* imageView = [[UIImageView alloc] initWithImage:image];
//        // [pickerView addSubview:imageView];
//        [[[pickerView subviews] objectAtIndex:2] addSubview:imageView];
//
        delegate = nil;
        pickerViewImpCpp = nil;
    }
    return self;
}

-(void) dealloc
{
    [super dealloc];
   // [datePicker release];
}

-(void) setPickerRect:(CGRect)rect
{
    pickerView.frame = rect;
}

-(int) getSelectedRow:(int)component
{
    if (pickerView) {
        return [pickerView selectedRowInComponent:component];
    }
    return -1;
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    if (delegate) {
        return delegate->numberOfComponentsInPickerView(pickerViewImpCpp);
    }
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    if (delegate) {
        return delegate->numberOfRowsInComponent(pickerViewImpCpp, component);
    }
    return 10;
}

- (CGFloat)pickerView:(UIPickerView *)pickerView widthForComponent:(NSInteger)component
{
    if (delegate) {
        return delegate->widthForComponent(pickerViewImpCpp, component);
    }
    return 400;
}
- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component
{
    if (delegate) {
        return delegate->rowHeightForComponent(pickerViewImpCpp, component);
    }
    return 30;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    if (delegate) {
       return [NSString stringWithUTF8String:delegate->titleForRow(pickerViewImpCpp, row, component)];
    }
    NSString* result = [NSString stringWithFormat:@"row for %i",row];
    return result;
}

//- (UIView*)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view
//{
//    UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 100, 40)];
//    label.backgroundColor = [UIColor lightGrayColor];
//    label.textColor = [UIColor blackColor];
//    label.font = [UIFont fontWithName:@"HelveticaNeue-Bold" size:18];
//    if (delegate) {
//        label.text = [NSString stringWithUTF8String:delegate->titleForRow(pickerViewImpCpp, row, component)];
//    }
//    return label;
//}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    if (delegate) {
        delegate->didSelectRow(pickerViewImpCpp, row, component);
    }
}

@end

RCPickerViewImpIOS::RCPickerViewImpIOS()
{
    m_bInRetinaMode = [[EAGLView sharedEGLView] contentScaleFactor] == 2.0f ? true : false;
}

RCPickerViewImpIOS::~RCPickerViewImpIOS()
{
    [m_systemControl.pickerView removeFromSuperview];
    [m_systemControl release];
}

bool RCPickerViewImpIOS::init()
{
    if (!RCPickerViewImp::init()) {
        return false;
    }
    
    m_systemControl = [[UIPickerViewImpIOS alloc] init];
    [[EAGLView sharedEGLView] addSubview:m_systemControl.pickerView];
    m_systemControl.pickerViewImpCpp = this;
    
    //NSDate *now = [NSDate date];
    //[m_systemControl.datePicker setBackgroundColor:[UIColor brownColor]];
    //[m_systemControl.datePicker setDate:now animated:YES];
    //m_systemControl.datePicker.center =((UIView*)[EAGLView sharedEGLView]).center;
    return true;
}

void RCPickerViewImpIOS::setPickerRect(const CCRect& rect)
{
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    CGRect newRect = CGRectMake(rect.origin.x,  screenSize.height - rect.origin.y - rect.size.height, rect.size.width, rect.size.height);
    if (m_bInRetinaMode) {
        newRect.origin.x *= 0.5f;
        newRect.origin.y *= 0.5f;
        newRect.size.width *= 0.5f;
        newRect.size.height *= 0.5f;
    }
    [m_systemControl setPickerRect:newRect];
}

void RCPickerViewImpIOS::setDelegate(RCPickerViewImpDelegate* delegate)
{
    m_systemControl.delegate = delegate;
}

int RCPickerViewImpIOS::getSelectedRow(int component)
{
    return [m_systemControl getSelectedRow:component];
}

RCPickerViewImp* __createSystemPickerView()
{
    return (RCPickerViewImp*)RCPickerViewImpIOS::create();
}

#endif
