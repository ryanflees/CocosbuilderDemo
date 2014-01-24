//
//  RCCheckButtonLoader.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-10.
//
//

#ifndef __HYDemo__RCCheckButtonLoader__
#define __HYDemo__RCCheckButtonLoader__

#include <iostream>
#include "RCCheckButton.h"
#include "CCNodeLoader.h"

USING_NS_CC_EXT;

class RCCheckButtonLoader : public CCNodeLoader  {
public:
    ~RCCheckButtonLoader(){}
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCCheckButtonLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCCheckButton);
    
    virtual void onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPoint, CCBReader * pCCBReader);
    virtual void onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader);
    virtual void onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader);
    virtual void onHandlePropTypeScaleLock(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float * pScaleLock, CCBReader * pCCBReader);
    virtual void onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloatScale, CCBReader * pCCBReader);
    virtual void onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader);
    virtual void onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pString, CCBReader * pCCBReader);
    virtual void onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pFontTTF, CCBReader * pCCBReader);
    virtual void onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char* pPropertyName, bool pCheck, CCBReader * pCCBReader);
};

#endif /* defined(__HYDemo__RCCheckButtonLoader__) */
