//
//  RCPanelLoader.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-12.
//
//

#ifndef __HYDemo__RCPanelLoader__
#define __HYDemo__RCPanelLoader__

#include <iostream>

#include <iostream>
#include "RCPanel.h"
#include "CCNodeLoader.h"

USING_NS_CC_EXT;

class RCPanelLoader : public CCNodeLoader  {
public:
    ~RCPanelLoader(){}
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCPanelLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCPanel);
    
    virtual void onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader);
    virtual void onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader);
    virtual void onHandlePropTypeFloat(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloat, CCBReader * pCCBReader);
    virtual void onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char* pPropertyName, bool pCheck, CCBReader * pCCBReader);
    virtual void onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPoint, CCBReader * pCCBReader);
    virtual void onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader);
    virtual void onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pString, CCBReader * pCCBReader);
    virtual void onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pFontTTF, CCBReader * pCCBReader);
    virtual void onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloatScale, CCBReader * pCCBReader);
    virtual void onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader);
    virtual void onHandlePropTypeIntegerLabeled(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * pCCBReader);
};

#endif /* defined(__HYDemo__RCPanelLoader__) */
