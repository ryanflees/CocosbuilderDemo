//
//  RCPickerViewScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#ifndef __HYDemo__RCPickerViewScene__
#define __HYDemo__RCPickerViewScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCPickerViewImp.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCPickerView;

class RCPickerViewScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
,public RCPickerViewImpDelegate
{
public:
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RCPickerViewScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual int numberOfComponentsInPickerView(RCPickerViewImp *pickerView);
    virtual int numberOfRowsInComponent(RCPickerViewImp *pickerView, int component);
    virtual const char* titleForRow(RCPickerViewImp *pickerView, int row, int component);
    virtual void didSelectRow(RCPickerViewImp *pickerView, int row, int component);
    virtual float rowHeightForComponent(RCPickerViewImp *pickerView, int component);
    virtual float widthForComponent(RCPickerViewImp *pickerView, int component);
private:
    void onButtonClicked(CCNode* node);
    
    RCPickerView* m_pPickerView;
};

class RCPickerViewSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCPickerViewSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCPickerViewScene);
};


#endif /* defined(__HYDemo__RCPickerViewScene__) */
