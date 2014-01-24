//
//  RCTabBarLoader.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-14.
//
//

#include "RCTabBarLoader.h"

#define PROPERTY_BACKGROUNDFRAME "backgroundFrame"
#define PROPERTY_BACKGROUNDSIZE "backgroundSize"
#define PROPERTY_DIRECTION "direction"
#define PROPERTY_TABBUTTONSIZE "tabButtonSize"
#define PROPERTY_TABBUTTONNORMALFRAME "tabButtonNormalFrame"
#define PROPERTY_TABBUTTONSELECTEDFRAME "tabButtonSelectedFrame"
#define PROPERTY_TABBUTTONCOUNT "tabButtonCount"
#define PROPERTY_FIRSTTABBUTTONSPACE "firstTabButtonSpace"
#define PROPERTY_TABBUTTONSPACE "tabButtonSpace"

void RCTabBarLoader::onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_BACKGROUNDFRAME) == 0) {
        ((RCTabBar*)pNode)->setBackgroundFrame(pCCSpriteFrame);
    }
    else if (strcmp(pPropertyName, PROPERTY_TABBUTTONNORMALFRAME) == 0) {
        ((RCTabBar*)pNode)->setTabButtonNormalFrame(pCCSpriteFrame);
    }
    else if (strcmp(pPropertyName, PROPERTY_TABBUTTONSELECTEDFRAME) == 0) {
        ((RCTabBar*)pNode)->setTabButtonSelectedFrame(pCCSpriteFrame);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pCCSpriteFrame, pCCBReader);
    }
}

void RCTabBarLoader::onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_BACKGROUNDSIZE) == 0) {
        ((RCTabBar*)pNode)->setBackgroundSize(pSize);
    }
    else if (strcmp(pPropertyName, PROPERTY_TABBUTTONSIZE) == 0) {
        ((RCTabBar*)pNode)->setTabButtonSize(pSize);
    }
    else if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, pCCBReader);
    }
}

void RCTabBarLoader::onHandlePropTypeIntegerLabeled(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_DIRECTION) == 0) {
        ((RCTabBar*)pNode)->setTabBarDirection(pIntegerLabeled);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeIntegerLabeled(pNode, pParent, pPropertyName, pIntegerLabeled, pCCBReader);
    }
}

void RCTabBarLoader::onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_TABBUTTONCOUNT) == 0) {
        ((RCTabBar*)pNode)->setTabButtonCount(pInteger);
    }
    else if (strcmp(pPropertyName, PROPERTY_FIRSTTABBUTTONSPACE) == 0) {
        ((RCTabBar*)pNode)->setFirstTabButtonSpace(pInteger);
    }
    else if (strcmp(pPropertyName, PROPERTY_TABBUTTONSPACE) == 0) {
        ((RCTabBar*)pNode)->setTabButtonSpace(pInteger);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeInteger(pNode, pParent, pPropertyName, pInteger, pCCBReader);
    }
}
