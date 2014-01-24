//
//  RCTabBarScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-13.
//
//

#ifndef __HYDemo__RCTabBarScene__
#define __HYDemo__RCTabBarScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCTabBar.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCTabBarScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
,public RCTabBarDelegate
{
public:
    RCTabBarScene();
    ~RCTabBarScene();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RCTabBarScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void onTabSelected(RCTabBar* pTabbar, CCNode* pTabPage, int index);
private:
    void onButtonClicked(CCNode* node);
    
    RCTabBar* m_pTabBar;
};

class RCTabBarSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCTabBarSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCTabBarScene);
};

#endif /* defined(__HYDemo__RCTabBarScene__) */
