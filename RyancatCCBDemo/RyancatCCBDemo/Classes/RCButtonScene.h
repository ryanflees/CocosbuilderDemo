//
//  RCButtonScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-10.
//
//

#ifndef __HYDemo__RCButtonScene__
#define __HYDemo__RCButtonScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCCheckButton;

class RCButtonScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
{
public:
    RCButtonScene();
    ~RCButtonScene();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RCButtonScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
private:
    void onButtonClicked(CCObject* pObject);
    void onImageButtonClicked(CCObject* pObject);
    void onCheckButtonClicked(CCObject* pObject);
    
    RCCheckButton* m_pCheckButton;
    CCLabelTTF* m_pSelectedCheckButtonLabel;
    CCLabelTTF* m_pUnselectedCheckButtonLabel;
};

class RCButtonSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCButtonSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCButtonScene);
};

#endif /* defined(__HYDemo__RCButtonScene__) */
