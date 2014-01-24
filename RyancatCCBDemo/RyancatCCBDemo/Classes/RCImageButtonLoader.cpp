//
//  RCImageButtonLoader.cpp
//  HYGame
//
//  Created by Bai Ryan on 14-1-9.
//
//

#include "RCImageButtonLoader.h"

#define PROPERTY_IMAGEDISPLAYFRAME "imageDisplayFrame"
#define PROPERTY_CCCONTROL "ccControl"
#define PROPERTY_SELECTEDCOLOR "selectedColor"
#define PROPERTY_DELAY "delay"

void RCImageButtonLoader::onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader) {
    if (strcmp(pPropertyName, PROPERTY_IMAGEDISPLAYFRAME) == 0) {
        ((RCImageButton*)pNode)->setImageDisplayFrame(pCCSpriteFrame);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pCCSpriteFrame, pCCBReader);
    }
}

void RCImageButtonLoader::onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader)
{
    if(strcmp(pPropertyName, PROPERTY_CCCONTROL) == 0) {
        ((RCImageButton *)pNode)->setTarget(pBlockCCControlData->mTarget, (SEL_CallFuncN)pBlockCCControlData->mSELCCControlHandler);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeBlockCCControl(pNode, pParent, pPropertyName, pBlockCCControlData, pCCBReader);
    }
}

void RCImageButtonLoader::onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_SELECTEDCOLOR) == 0) {
        ((RCImageButton*)pNode)->setSelectedColor(pCCColor3B);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pCCColor3B, pCCBReader);
    }
}

void RCImageButtonLoader::onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_DELAY) == 0) {
        ((RCImageButton*)pNode)->setTouchUpOutDelay(pInteger);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeInteger(pNode, pParent, pPropertyName, pInteger, pCCBReader);
    }
}



