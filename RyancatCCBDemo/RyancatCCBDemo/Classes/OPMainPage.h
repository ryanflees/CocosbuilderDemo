//
//  OPMainPage.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#ifndef __HYDemo__OPMainPage__
#define __HYDemo__OPMainPage__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPMainPage;
class OPMainPageDelegate
{
public:
    virtual void onMainPageButtonClicked(OPMainPage* pMainPage, int tag) = 0;
};

class OPMainPage :public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{
public:
    OPMainPage();
    virtual ~OPMainPage();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPMainPage, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
private:
    void onButtonClicked(CCNode* pNode);
    
    CC_SYNTHESIZE(OPMainPageDelegate*, m_delegate, Delegate);
};

class OPMainPageLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( OPMainPageLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( OPMainPage);
};


#endif /* defined(__HYDemo__OPMainPage__) */
