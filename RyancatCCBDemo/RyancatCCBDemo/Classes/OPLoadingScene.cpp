//
//  OPLoadingScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-20.
//
//

#include "OPLoadingScene.h"
#include "RCSceneManager.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

#define kLoadingDelayTime 1.0f

OPLoadingScene::OPLoadingScene()
{
}

OPLoadingScene::~OPLoadingScene()
{
    
}

bool OPLoadingScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    return true;
}

SEL_MenuHandler OPLoadingScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler OPLoadingScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool OPLoadingScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}

bool OPLoadingScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    
    return false;
}

void OPLoadingScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    
}

void OPLoadingScene::onEnter()
{
    CCNode::onEnter();
    
    CCCallFunc *loadRes = CCCallFunc::create(this, callfunc_selector(OPLoadingScene::loadResources));
    CCFiniteTimeAction *seq = CCSequence::create(CCDelayTime::create(kLoadingDelayTime),loadRes,NULL);
    runAction(seq);
}

void OPLoadingScene::onExit()
{
    CCNode::onExit();
}

static void* loadThreadFunction(void* data)
{
    CCTextureCache::sharedTextureCache()->addImageAsync("Imagesetfile/mainScene1.png", NULL, NULL);
    CCTextureCache::sharedTextureCache()->addImageAsync("Imagesetfile/mainScene2.png", NULL, NULL);
    CCTextureCache::sharedTextureCache()->addImageAsync("Imagesetfile/mainScene3.png", NULL, NULL);
    CCTextureCache::sharedTextureCache()->addImageAsync("Imagesetfile/mainScene4.png", NULL, NULL);
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("general.mp3");
    SimpleAudioEngine::sharedEngine()->preloadEffect("click.mp3");
    //SimpleAudioEngine::sharedEngine()->preloadEffect("Y_BOSS.wav");
    OPLoadingScene *loadingScene = (OPLoadingScene*)data;
    loadingScene->loadResourceFinished();
    return NULL;
}

void OPLoadingScene::loadResourceFinished()
{
    CCCallFunc *callNext = CCCallFunc::create(this, callfunc_selector(OPLoadingScene::playNextScene));
    CCFiniteTimeAction *seq = CCSequence::create(CCDelayTime::create(kLoadingDelayTime),callNext,NULL);
    runAction(seq);
}

void OPLoadingScene::loadResources()
{
    int errCode = 0;
    do {
        pthread_attr_t addr;
        errCode = pthread_attr_init(&addr);
        
        CC_BREAK_IF(errCode != 0);
        
        errCode = pthread_attr_setdetachstate(&addr, PTHREAD_CREATE_DETACHED);
        
        if (errCode != 0) {
            pthread_attr_destroy(&addr);
            break;
        }
        
        errCode = pthread_create(&threadLoadResource, &addr, loadThreadFunction, this);
    } while (0);
}

void OPLoadingScene::playNextScene()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Imagesetfile/mainScene1.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Imagesetfile/mainScene2.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Imagesetfile/mainScene3.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Imagesetfile/mainScene4.plist");
    RCSceneManager::sharedSceneManager()->switchToOnePieceGameScene();
}
