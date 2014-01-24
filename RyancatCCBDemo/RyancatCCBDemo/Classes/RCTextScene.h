//
//  RCTextScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-15.
//
//

#ifndef __HYDemo__RCTextScene__
#define __HYDemo__RCTextScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCEditBox.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCTextScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
,public CCEditBoxDelegate
{
public:
    RCTextScene();
    ~RCTextScene();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RCTextScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void editBoxEditingDidEnd(CCEditBox* editBox);
    virtual void editBoxReturn(CCEditBox* editBox);
private:
    void onButtonClicked(CCNode* node);
    
    CCLabelTTF* m_pCustomFontLabel;
    RCEditBox* m_pAccountEditBox;
    RCEditBox* m_pPasswordEditBox;
};

class RCTextSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCTextSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCTextScene);
};

#endif /* defined(__HYDemo__RCTextScene__) */
