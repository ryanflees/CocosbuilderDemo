//
//  RCSceneManager.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-10.
//
//

#include "RCSceneManager.h"
#include "CCNodeLoaderLibrary.h"

#include "RCImageButtonLoader.h"
#include "RCCheckButtonLoader.h"
#include "RCPanelLoader.h"
#include "RCTabBarLoader.h"
#include "RCEditBoxLoader.h"
#include "RCScrollViewLoader.h"
#include "RCTableViewLoader.h"

#include "RCMainMenu.h"
#include "RCButtonScene.h"
#include "RCPanelScene.h"
#include "RCTabBarScene.h"
#include "RCScrollViewScene.h"
#include "RCTextScene.h"
#include "RCPickerViewScene.h"
#include "RCMenuContainer.h"

#include "OPStorePage.h"
#include "OPMainMenu.h"
#include "OPBattleShip.h"
#include "OPGameScene.h"
#include "OPNoticeBoard.h"
#include "OPNoticeContent.h"
#include "OPMainPage.h"
#include "OPTeamFormation.h"
#include "OPSailingList.h"
#include "OPStorePage.h"
#include "OPAdventurePage.h"
#include "OPBattleShip.h"
#include "OPLoadingScene.h"

RCSceneManager::RCSceneManager()
{

}

RCSceneManager::~RCSceneManager()
{

}

RCSceneManager* RCSceneManager::m_instanceOfSceneManager = NULL;

RCSceneManager* RCSceneManager::sharedSceneManager()
{
    if (!m_instanceOfSceneManager)
    {
        m_instanceOfSceneManager = new RCSceneManager();
    }
    return m_instanceOfSceneManager;
}

void RCSceneManager::purge()
{
    if (m_instanceOfSceneManager) {
        delete (m_instanceOfSceneManager);
    }
}

void RCSceneManager::showMainMenu()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("RCMainMenu", RCMainMenuLoader::loader());
    
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/main_menu.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->runWithScene(pScene);
}

void RCSceneManager::returnMainMenu()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("RCMainMenu", RCMainMenuLoader::loader());
    
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/main_menu.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->replaceScene(pScene);
}

void RCSceneManager::returnPreviousScene()
{
    CCDirector::sharedDirector()->popScene();
}

void RCSceneManager::switchToButtonScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    
    pLoaderLibrary->registerCCNodeLoader("RCButtonScene", RCButtonSceneLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/button_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->pushScene(pScene);
}

void RCSceneManager::switchToLabelScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    
    pLoaderLibrary->registerCCNodeLoader("RCTextScene", RCTextSceneLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/text_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->pushScene(pScene);
}

void RCSceneManager::switchToScrollViewScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    
    pLoaderLibrary->registerCCNodeLoader("RCMenuContainer", RCMenuContainerLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("RCScrollViewScene", RCScrollViewSceneLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/scrollview_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->pushScene(pScene);
}

void RCSceneManager::switchToTabBarScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    
    pLoaderLibrary->registerCCNodeLoader("RCTabBarScene", RCTabBarSceneLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/tabbar_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->pushScene(pScene);
}

void RCSceneManager::switchToPanelScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    
    pLoaderLibrary->registerCCNodeLoader("RCPanelScene", RCPanelSceneLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/panel_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->pushScene(pScene);
}

void RCSceneManager::switchToPickerViewScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    
    pLoaderLibrary->registerCCNodeLoader("RCPickerViewScene", RCPickerViewSceneLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/pickerview_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->pushScene(pScene);
}

void RCSceneManager::switchToOnePieceMainMenu()
{
//    CCScene *pScene = CCScene::create();
//    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
//    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
//    registerCustomControlsForNodeloader(pLoaderLibrary);
//    pLoaderLibrary->registerCCNodeLoader("OPStorePage", OPStorePageLoader::loader());
//    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/one_piece/store_page.ccbi");
//    ccbReader->release();
//    pScene->addChild(pNode);
//    CCDirector::sharedDirector()->pushScene(pScene);
//
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    
    pLoaderLibrary->registerCCNodeLoader("OPMainMenu", OPMainMenuLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPBattleShip", OPBattleShipLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/one_piece/main_menu.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCDirector::sharedDirector()->pushScene(pScene);
}

void RCSceneManager::switchToOnePieceLoadingScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("OPLoadingScene", OPLoadingSceneLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/one_piece/loading_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCTransitionScene *pTransScene = CCTransitionCrossFade::create(0.5f, pScene);
    CCDirector::sharedDirector()->replaceScene(pTransScene);
}

void RCSceneManager::switchToOnePieceGameScene()
{
    CCScene *pScene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    registerCustomControlsForNodeloader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("OPGameScene", OPGameSceneLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPNoticeBoard", OPNoticeBoardLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPNoticeContent", OPNoticeContentLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPMainPage", OPMainPageLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPTeamFormation", OPTeamFormationLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPSailingList", OPSailingListLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPSailingPage", OPSailingPageLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPStorePage", OPStorePageLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPAdventurePage", OPAdventurePageLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("OPBattleShip", OPBattleShipLoader::loader());
    CCNode *pNode = ccbReader->readNodeGraphFromFile("ccbi/one_piece/game_scene.ccbi");
    ccbReader->release();
    pScene->addChild(pNode);
    CCTransitionScene *pTransScene = CCTransitionCrossFade::create(0.5f, pScene);
    CCDirector::sharedDirector()->replaceScene(pTransScene);
}

void RCSceneManager::registerCustomControlsForNodeloader(CCNodeLoaderLibrary *pLoaderLibrary)
{
    pLoaderLibrary->registerCCNodeLoader("RCImageButton", RCImageButtonLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("RCCheckButton", RCCheckButtonLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("RCPanel", RCPanelLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("RCTabBar", RCTabBarLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("RCScrollView", RCScrollViewLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("RCEditBox", RCEditBoxLoader::loader());
    pLoaderLibrary->registerCCNodeLoader("RCTableView", RCTableViewLoader::loader());
}

