//
//  RCMainMenu.h
//  HYControls
//
//  Created by Bai Ryan on 14-1-9.
//
//

#ifndef __HYControls__RCMainMenu__
#define __HYControls__RCMainMenu__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCMainMenu : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
{
public:
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RCMainMenu, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
private:
    void onButtonClicked(CCObject* object);
};

class RCMainMenuLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCMainMenuLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCMainMenu);
};


#endif /* defined(__HYControls__RCMainMenu__) */
