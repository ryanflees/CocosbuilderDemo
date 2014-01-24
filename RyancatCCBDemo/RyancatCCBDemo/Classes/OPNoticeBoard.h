//
//  OPNoticeBoard.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#ifndef __HYDemo__OPNoticeBoard__
#define __HYDemo__OPNoticeBoard__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCTableView.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPNoticeContent;

class OPNoticeBoard;

class OPNoticeBoardDelegate
{
public:
    virtual void onBoardCloseButtonClicked(OPNoticeBoard* pBoard) = 0;
};

class OPNoticeBoard : public CCNode
,public CCBSelectorResolver
,public CCBMemberVariableAssigner
,public CCNodeLoaderListener
,public CCTableViewDataSource
,public CCTableViewDelegate
{
public:
    OPNoticeBoard();
    ~OPNoticeBoard();
    virtual bool init();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPNoticeBoard, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);
    
private:
    void onCloseButtonClicked(CCNode* pNode);
    OPNoticeContent* createNoticeContent();
    
    RCTableView* m_pTableView;
    CC_SYNTHESIZE(OPNoticeBoardDelegate*, m_delegate, Delegate);
};

class OPNoticeBoardLoader :public CCNodeLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OPNoticeBoardLoader, loader);
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(OPNoticeBoard);
};


#endif /* defined(__HYDemo__OPNoticeBoard__) */
