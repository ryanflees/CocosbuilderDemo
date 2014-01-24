//
//  OPNoticeBoard.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPNoticeBoard.h"
#include "RCSceneManager.h"
#include "OPNoticeContent.h"
#include "RCScrollView.h"

OPNoticeBoard::OPNoticeBoard()
:m_pTableView()
,m_delegate()
{
}

OPNoticeBoard::~OPNoticeBoard()
{
    
}

bool OPNoticeBoard::init()
{
    if (!CCNode::init()) {
        return false;
    }
    return true;
}

SEL_MenuHandler OPNoticeBoard::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler OPNoticeBoard::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "closeButtonClicked", OPNoticeBoard::onCloseButtonClicked);
    return NULL;
}

bool OPNoticeBoard::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "tableView", RCTableView*, m_pTableView);
    return false;
}

bool OPNoticeBoard::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    
    return false;
}

void OPNoticeBoard::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    if (m_pTableView) {
        m_pTableView->generateTableView(this);
    }
}

void OPNoticeBoard::onEnter()
{
    CCNode::onEnter();
    //CCCallFunc* callback = CCCallFunc::create(this, callfunc_selector(OPNoticeBoard::addNoticeContent));
    //runAction(callback);
}

void OPNoticeBoard::onExit()
{
    CCNode::onExit();
}

void OPNoticeBoard::onCloseButtonClicked(CCNode* pNode)
{
    if (m_delegate) {
        m_delegate->onBoardCloseButtonClicked(this);
    }
}

OPNoticeContent* OPNoticeBoard::createNoticeContent()
{
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    RCSceneManager::sharedSceneManager()->registerCustomControlsForNodeloader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("OPNoticeContent", OPNoticeContentLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/one_piece/notification.ccbi");
    ccbReader->release();
    return (OPNoticeContent*)pNode;
}

void OPNoticeBoard::scrollViewDidScroll(CCScrollView* view)
{

}

void OPNoticeBoard::scrollViewDidZoom(CCScrollView* view)
{

}

void OPNoticeBoard::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{

}

CCTableViewCell* OPNoticeBoard::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
        
        CCNode* pCellNode = createNoticeContent();
        pCellNode->setPosition(ccp(0, 0));
        pCellNode->setTag(1);
        cell->addChild(pCellNode);
    }
    else
    {
        //    CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
        //    label->setString(string->getCString());
    }
    
    return cell;
}

unsigned int OPNoticeBoard::numberOfCellsInTableView(CCTableView *table)
{
    if (m_pTableView) {
        return m_pTableView->getCellCount();
    }
    return 2;
}

CCSize OPNoticeBoard::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    if (m_pTableView) {
        return m_pTableView->getCellSize();
    }
    return CCSizeMake(0, 0);
}

