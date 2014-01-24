//
//  OPSailingPage.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-21.
//
//

#include "OPSailingPage.h"
#include "RCSceneManager.h"
#include "OPSailingList.h"

OPSailingPage::OPSailingPage()
:m_pSailingScrollView()
{

}

OPSailingPage::~OPSailingPage()
{

}

bool OPSailingPage::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}

SEL_MenuHandler OPSailingPage::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", OPSailingPage::FUNCTION);
    return NULL;
}

SEL_CCControlHandler OPSailingPage::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", OPSailingPage::FUNCTION);
    return NULL;
}

bool OPSailingPage::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sailingScrollView", RCScrollView*, m_pSailingScrollView);
    return false;
}

bool OPSailingPage::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void OPSailingPage::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    
    
}

void OPSailingPage::onEnter()
{
    CCNode::onEnter();
}
void OPSailingPage::onExit()
{
    CCNode::onExit();
}

void OPSailingPage::addScrollViewContent()
{
//    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
//    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
//    RCSceneManager::sharedSceneManager()->registerCustomControlsForNodeloader(pLoaderLibrary);
//    pLoaderLibrary->registerCCNodeLoader("OPSailingList", OPSailingListLoader::loader());
//    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/one_piece/sailing_list.ccbi");
//    ccbReader->release();
//    m_pSailingScrollView->getContainer()->addChild(pNode);
//    CCSize containerSize = CCSizeMake(m_pSailingScrollView->getContainerSize().width, 800);
//    m_pSailingScrollView->setContainerSize(containerSize);
//    pNode->setPosition(m_pSailingScrollView->getContainerSize().width/2,700);
//
}

