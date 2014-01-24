//
//  RCTabBarLoader.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-14.
//
//

#ifndef __HYDemo__RCTabBarLoader__
#define __HYDemo__RCTabBarLoader__

#include <iostream>

#include "CCNodeLoader.h"
#include "RCTabBar.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCTabBarLoader : public CCNodeLoader  {
public:
    ~RCTabBarLoader(){}
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCTabBarLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCTabBar);
    
    virtual void onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader);
    virtual void onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader);
    virtual void onHandlePropTypeIntegerLabeled(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * pCCBReader);
    virtual void onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader);
};

#endif /* defined(__HYDemo__RCTabBarLoader__) */
