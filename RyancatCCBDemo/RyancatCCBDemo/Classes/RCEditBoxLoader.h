//
//  RCEditBoxLoader.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#ifndef __HYDemo__RCEditBoxLoader__
#define __HYDemo__RCEditBoxLoader__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCEditBox.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCEditBoxLoader : public CCNodeLoader{
public:
    ~RCEditBoxLoader(){}
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCEditBoxLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCEditBox);
    
    virtual void onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader);
    virtual void onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader);
    virtual void onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pString, CCBReader * pCCBReader);
    virtual void onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pFontTTF, CCBReader * pCCBReader);
    virtual void onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloatScale, CCBReader * pCCBReader);
    virtual void onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader);
    virtual void onHandlePropTypeIntegerLabeled(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * pCCBReader);
    virtual void onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader);
    virtual void onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPoint, CCBReader * pCCBReader);
};


#endif /* defined(__HYDemo__RCEditBoxLoader__) */
