//
//  RCPanelScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-11.
//
//

#ifndef __HYDemo__RCPanelScene__
#define __HYDemo__RCPanelScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCPanelScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
{
public:
    RCPanelScene();
    ~RCPanelScene();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RCPanelScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
private:
    void onClosePanelClicked(CCNode* node);
    void onButtonClicked(CCNode* node);
    
    void switchNode();
    
    CCNode* m_pSinglePanelNode;
    CCNode* m_pMultiPanelNode;
};

class RCPanelSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCPanelSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCPanelScene);
};

#endif /* defined(__HYDemo__RCPanelScene__) */
