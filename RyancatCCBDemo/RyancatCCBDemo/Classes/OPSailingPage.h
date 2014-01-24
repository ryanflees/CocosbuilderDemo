//
//  OPSailingPage.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-21.
//
//

#ifndef __HYDemo__OPSailingPage__
#define __HYDemo__OPSailingPage__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCScrollView.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPSailingPage : public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{
public:
    OPSailingPage();
    virtual ~OPSailingPage();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPSailingPage, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
private:
    void addScrollViewContent();
    RCScrollView* m_pSailingScrollView;
};

class OPSailingPageLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( OPSailingPageLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( OPSailingPage);
};


#endif /* defined(__HYDemo__OPSailingPage__) */
