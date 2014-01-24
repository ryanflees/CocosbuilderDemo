//
//  OPStorePage.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#ifndef __HYDemo__OPStorePage__
#define __HYDemo__OPStorePage__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCTabBar.h"
#include "RCTableView.h"
#include "OPPackTableCell.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPStorePage : public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
, public RCTabBarDelegate
, public CCTableViewDataSource
, public CCTableViewDelegate
{
public:
    OPStorePage();
    virtual ~OPStorePage();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPStorePage, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
    virtual void onTabSelected(RCTabBar* pTabbar, CCNode* pTabPage, int index);
    
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);
    
private:
    void addPackTableView();
    OPPackTableCell* createTableCell();
   
    RCTabBar* m_pTabBar;
    CCNode* m_pRecruitTabPage;
    CCNode* m_pItemTabPage;
    CCNode* m_pGiftPackPage;
    
    CCScrollView* m_pItemScrollView;
    CCTableView* m_pGiftPackTableView;
    RCTableView* m_pPackTableView;
};

class OPStorePageLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( OPStorePageLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( OPStorePage);
};


#endif /* defined(__HYDemo__OPStorePage__) */
