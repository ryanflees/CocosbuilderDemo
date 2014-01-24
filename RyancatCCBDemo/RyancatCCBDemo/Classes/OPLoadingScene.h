//
//  OPLoadingScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#ifndef __HYDemo__OPLoadingScene__
#define __HYDemo__OPLoadingScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPLoadingScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
{
public:
    OPLoadingScene();
    ~OPLoadingScene();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPLoadingScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void onEnter();
    virtual void onExit();

    void loadResourceFinished();
private:
    void loadResources();
    void playNextScene();
    pthread_t threadLoadResource;
};

class OPLoadingSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OPLoadingSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(OPLoadingScene);
};


#endif /* defined(__HYDemo__OPLoadingScene__) */
