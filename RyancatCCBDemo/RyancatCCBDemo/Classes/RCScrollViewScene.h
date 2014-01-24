//
//  RCScrollViewScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-15.
//
//

#ifndef __HYDemo__RCScrollViewScene__
#define __HYDemo__RCScrollViewScene__

#include <iostream>

#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCScrollView.h"

enum
{
    kScrollViewShowLeft,
    kScrollViewShowRight,
    kScrollViewScrolling
};

USING_NS_CC;
USING_NS_CC_EXT;

class RCScrollViewScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
{
public:
    RCScrollViewScene();
    ~RCScrollViewScene();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RCScrollViewScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
private:
    void onButtonClicked(CCNode* node);
    void showRightScrollFinished();
    void showLeftScrollFinished();
    
    int m_sceneStatus;
    
    RCScrollView* m_pScrollView;
};

class RCScrollViewSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCScrollViewSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCScrollViewScene);
};

#endif /* defined(__HYDemo__RCScrollViewScene__) */
