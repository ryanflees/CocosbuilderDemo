//
//  OPGameScene.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#ifndef __HYDemo__OPGameScene__
#define __HYDemo__OPGameScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "OPNoticeBoard.h"
#include "OPMainPage.h"
#include "OPTeamFormation.h"
#include "OPSailingPage.h"
#include "OPStorePage.h"
#include "OPAdventurePage.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPDataParser;

class OPGameScene : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
,public OPNoticeBoardDelegate
,public OPMainPageDelegate
{
public:
    OPGameScene();
    ~OPGameScene();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPGameScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void onEnter();
    virtual void onExit();
    
    // OPNoticeBoardDelegate
    virtual void onBoardCloseButtonClicked(OPNoticeBoard* pBoard);
    
    // OPMainPageDelegate
    virtual void onMainPageButtonClicked(OPMainPage* pMainPage, int tag);
private:
    void onButtonClicked(CCNode* pNode);
    
    void hideAllPages();
    void showNotificationBoard();
    void switchToMainPage();
    void switchToTeam();
    void switchToSailingPage();
    void switchToAdventurePage();
    void switchToStorePage();
    
    CCLayer* m_pNoticeMaskLayer;
    OPDataParser* m_pDataParser;
    CCArray* m_pPageArray;
    CCLayer* m_pBackgroundCurtain;
    OPNoticeBoard* m_pNoticeBoard;
    OPMainPage* m_pMainPage;
    OPStorePage* m_pStorePage;
    OPTeamFormation* m_pTeamFormation;
    OPSailingPage* m_pSailingPage;
    OPAdventurePage* m_pAdventruePage;
};

class OPGameSceneLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OPGameSceneLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(OPGameScene);
};


#endif /* defined(__HYDemo__OPGameScene__) */
