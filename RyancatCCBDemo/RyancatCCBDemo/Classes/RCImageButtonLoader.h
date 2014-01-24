//
//  RCImageButtonLoader.h
//  HYGame
//
//  Created by Bai Ryan on 14-1-9.
//
//

#ifndef __HYGame__RCImageButtonLoader__
#define __HYGame__RCImageButtonLoader__

#include <iostream>
#include "RCImageButton.h"
#include "CCNodeLoader.h"

USING_NS_CC_EXT;

class RCImageButtonLoader : public CCNodeLoader
{
public:
    virtual ~RCImageButtonLoader(){}
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCImageButtonLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCImageButton);
    virtual void onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader);
    virtual void onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader);
    virtual void onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader);
    virtual void onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader);
};


#endif /* defined(__HYGame__RCImageButtonLoader__) */
