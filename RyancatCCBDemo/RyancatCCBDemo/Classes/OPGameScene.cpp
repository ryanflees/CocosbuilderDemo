//
//  OPGameScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPGameScene.h"
#include "RCSceneManager.h"
#include "OPDataParser.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

OPGameScene::OPGameScene()
:m_pNoticeBoard()
,m_pMainPage()
,m_pTeamFormation()
,m_pBackgroundCurtain()
,m_pSailingPage()
,m_pStorePage()
,m_pNoticeMaskLayer()
,m_pAdventruePage()
{
    CCTextureCache::sharedTextureCache()->removeAllTextures();
}

OPGameScene::~OPGameScene()
{
    m_pPageArray->release();
    m_pDataParser->release();
}

bool OPGameScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    m_pPageArray = CCArray::create();
    m_pPageArray->retain();

    m_pDataParser = OPDataParser::create();
    m_pDataParser->retain();
    
    return true;
}

SEL_MenuHandler OPGameScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler OPGameScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", OPGameScene::onButtonClicked);
    return NULL;
}

bool OPGameScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "noticeBoard", OPNoticeBoard*, m_pNoticeBoard);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mainPage", OPMainPage*, m_pMainPage);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "backgroundCurtain", CCLayer*, m_pBackgroundCurtain);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "teamFormation", OPTeamFormation*, m_pTeamFormation);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sailingPage", OPSailingPage*, m_pSailingPage);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "store", OPStorePage*, m_pStorePage);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "noticeMaskLayer", CCLayer*, m_pNoticeMaskLayer);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "adventruePage", OPAdventurePage*, m_pAdventruePage);
    
    return false;
}

bool OPGameScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    
    return false;
}

void OPGameScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    if (m_pNoticeBoard) {
        m_pNoticeBoard->setDelegate(this);
    }
    if (m_pMainPage) {
        m_pMainPage->setDelegate(this);
        m_pPageArray->addObject(m_pMainPage);
    }
    if (m_pTeamFormation) {
        m_pPageArray->addObject(m_pTeamFormation);
        m_pTeamFormation->setDataParser(m_pDataParser);
    }
    if (m_pSailingPage) {
        m_pPageArray->addObject(m_pSailingPage);
    }
    if (m_pStorePage) {
        m_pPageArray->addObject(m_pStorePage);
    }
    if (m_pAdventruePage) {
        m_pPageArray->addObject(m_pAdventruePage);
    }
}

void OPGameScene::onEnter()
{
    CCNode::onEnter();
    
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("general.mp3",true);
    switchToMainPage();
    
    m_pDataParser->loadTeamData("team.plist");
    
    showNotificationBoard();
}

void OPGameScene::onExit()
{
    CCNode::onExit();
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void OPGameScene::onBoardCloseButtonClicked(OPNoticeBoard* pBoard)
{
    m_pNoticeBoard->setVisible(false);
    m_pNoticeMaskLayer->setVisible(false);
    SimpleAudioEngine::sharedEngine()->playEffect("click.mp3");
}

void OPGameScene::onMainPageButtonClicked(OPMainPage* pMainPage, int tag)
{
    SimpleAudioEngine::sharedEngine()->playEffect("click.mp3");
    CCLog("on main page clicked tag : %i",tag);
    if (tag == 1) {
    }
    else if (tag == 2)
    {
    }
    else if (tag == 3)
    {
        
    }
    else if (tag == 4)
    {
        
    }
    else if (tag == 5)
    {
        
    }
    else if (tag == 6)
    {
        
    }
    else if (tag == 7)
    {
        
    }
}

void OPGameScene::onButtonClicked(CCNode *pNode)
{
    SimpleAudioEngine::sharedEngine()->playEffect("click.mp3");
    if (pNode->getTag() == 1) {
        switchToMainPage();
    }
    else if (pNode->getTag() == 2) {
        switchToTeam();
    }
    else if (pNode->getTag() == 3) {
        switchToSailingPage();
    }
    else if (pNode->getTag() == 4) {
        switchToAdventurePage();
    }
    else if (pNode->getTag() == 5) {
        switchToStorePage();
    }
    else if (pNode->getTag() == 6) {
        RCSceneManager::sharedSceneManager()->returnMainMenu();
    }
}

void OPGameScene::hideAllPages()
{
    m_pBackgroundCurtain->setVisible(false);
    CCObject* pObject;
    CCARRAY_FOREACH(m_pPageArray, pObject)
    {
        CCNode* pNode = (CCNode*)pObject;
        pNode->setVisible(false);
    }
}

void OPGameScene::showNotificationBoard()
{
    m_pNoticeBoard->setVisible(true);
}

void OPGameScene::switchToMainPage()
{
    hideAllPages();
    m_pMainPage->setVisible(true);
    m_pBackgroundCurtain->setVisible(false);
}

void OPGameScene::switchToTeam()
{
    hideAllPages();
    m_pTeamFormation->setVisible(true);
    m_pBackgroundCurtain->setVisible(true);
    m_pTeamFormation->reloadIcons();
}

void OPGameScene::switchToSailingPage()
{
    hideAllPages();
    m_pSailingPage->setVisible(true);
    m_pBackgroundCurtain->setVisible(false);
}

void OPGameScene::switchToAdventurePage()
{
    hideAllPages();
    m_pAdventruePage->setVisible(true);
}

void OPGameScene::switchToStorePage()
{
    hideAllPages();
    m_pStorePage->setVisible(true);
    m_pBackgroundCurtain->setVisible(true);
}

