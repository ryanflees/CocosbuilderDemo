//
//  OPAdventurePage.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#ifndef __HYDemo__OPAdventurePage__
#define __HYDemo__OPAdventurePage__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPAdventurePage : public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{
public:
    OPAdventurePage();
    virtual ~OPAdventurePage();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPAdventurePage, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
private:
    
};

class OPAdventurePageLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( OPAdventurePageLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( OPAdventurePage);
};


#endif /* defined(__HYDemo__OPAdventurePage__) */
