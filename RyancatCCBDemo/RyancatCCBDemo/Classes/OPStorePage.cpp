//
//  OPStorePage.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#include "OPStorePage.h"
#include "RCSceneManager.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

OPStorePage::OPStorePage()
:m_pRecruitTabPage()
,m_pItemTabPage()
,m_pTabBar()
,m_pItemScrollView()
,m_pGiftPackTableView()
,m_pGiftPackPage()
,m_pPackTableView()
{

}

OPStorePage::~OPStorePage()
{

}

bool OPStorePage::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void OPStorePage::onEnter()
{
    
    CCNode::onEnter();
    
}
void OPStorePage::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler OPStorePage::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", OPStorePage::FUNCTION);
    return NULL;
}

SEL_CCControlHandler OPStorePage::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", OPStorePage::FUNCTION);
    return NULL;
}

bool OPStorePage::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NAME", TYPE,VALUE);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "recruitTabPage", CCNode*,m_pRecruitTabPage);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "itemTabPage", CCNode*,m_pItemTabPage);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "tabBar", RCTabBar*,m_pTabBar);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "itemScrollView", CCScrollView*,m_pItemScrollView);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "giftPackPage", CCNode*,m_pGiftPackPage);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "packTableView", RCTableView*,m_pPackTableView);
    
    return false;
}

bool OPStorePage::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void OPStorePage::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    if (m_pTabBar) {
        m_pTabBar->setDelegate(this);
    }
    if (m_pRecruitTabPage && m_pItemTabPage) {
        m_pRecruitTabPage->setVisible(true);
        m_pItemTabPage->setVisible(false);
    }
    if (m_pItemScrollView) {
        CCSize size = m_pItemScrollView->getContainer()->getContentSize();
        CCPoint offset = ccp(0, -(size.height - m_pItemScrollView->getViewSize().height));
        m_pItemScrollView->setContentOffset(offset);
    }
    if (m_pGiftPackPage) {
        m_pGiftPackPage->setVisible(false);
    }
    if (m_pPackTableView) {
        m_pPackTableView->generateTableView(this);
    }
}

void OPStorePage::onTabSelected(RCTabBar* pTabbar, CCNode* pTabPage, int index)
{
    SimpleAudioEngine::sharedEngine()->playEffect("click.mp3");
    if (index == 0) {
        m_pRecruitTabPage->setVisible(true);
        m_pItemTabPage->setVisible(false);
        m_pGiftPackPage->setVisible(false);
    }
    else if(index == 1)
    {
        m_pRecruitTabPage->setVisible(false);
        m_pItemTabPage->setVisible(true);
        m_pGiftPackPage->setVisible(false);
    }
    else if(index == 2)
    {
        m_pRecruitTabPage->setVisible(false);
        m_pItemTabPage->setVisible(false);
        m_pGiftPackPage->setVisible(true);
    }
}

void OPStorePage::addPackTableView()
{
    m_pGiftPackTableView = CCTableView::create(this, CCSizeMake(660, 450));
    m_pGiftPackPage->addChild(m_pGiftPackTableView);
}

void OPStorePage::scrollViewDidScroll(CCScrollView* view)
{

}

void OPStorePage::scrollViewDidZoom(CCScrollView* view)
{

}

void OPStorePage::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{

}

OPPackTableCell* OPStorePage::createTableCell()
{
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    RCSceneManager::sharedSceneManager()->registerCustomControlsForNodeloader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("OPPackTableCell", OPPackTableCellLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/one_piece/table_cell.ccbi");
    ccbReader->release();
    return (OPPackTableCell*)pNode;
}

CCTableViewCell* OPStorePage::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();
        cell->autorelease();
        
        OPPackTableCell* pCellNode = createTableCell();
        pCellNode->setPosition(ccp(m_pPackTableView->getCellSize().width/2, m_pPackTableView->getCellSize().height/2));
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

unsigned int OPStorePage::numberOfCellsInTableView(CCTableView *table)
{
    if (m_pPackTableView) {
        return m_pPackTableView->getCellCount();
    }
    return 2;
}

CCSize OPStorePage::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    if (m_pPackTableView) {
        return m_pPackTableView->getCellSize();
    }
    return CCSizeMake(660, 70);
}


