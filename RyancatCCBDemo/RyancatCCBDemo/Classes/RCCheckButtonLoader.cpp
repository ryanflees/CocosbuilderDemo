//
//  RCCheckButtonLoader.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-10.
//
//

#include "RCCheckButtonLoader.h"

#define PROPERTY_SELECTED "selected"
#define PROPERTY_STRING "string"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_LABELPOSITION "labelPosition"
#define PROPERTY_LABELCOLOR "labelColor"
#define PROPERTY_SELECTEDLABELCOLOR "selectedLabelColor"
#define PROPERTY_NORMALSPRITEFRAME "normalSpriteFrame"
#define PROPERTY_SELECTEDSPRITEFRAME "selectedSpriteFrame"
#define PROPERTY_CCCONTROL "ccControl"
#define PROPERTY_IMAGESCALE "imageScale"

void RCCheckButtonLoader::onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPoint, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_LABELPOSITION) == 0) {
        ((RCCheckButton*)pNode)->setLabelPosition(pPoint);
    }
    else {
        CCNodeLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_NORMALSPRITEFRAME) == 0) {
        ((RCCheckButton*)pNode)->setNormalSpriteFrame(pCCSpriteFrame);
    }
    else if (strcmp(pPropertyName, PROPERTY_SELECTEDSPRITEFRAME) == 0) {
        ((RCCheckButton*)pNode)->setSelectedSpriteFrame(pCCSpriteFrame);
    }
    else {
        CCNodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pCCSpriteFrame, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader)
{
    if(strcmp(pPropertyName, PROPERTY_CCCONTROL) == 0) {
        ((RCCheckButton *)pNode)->setTarget(pBlockCCControlData->mTarget, (SEL_CallFuncN)pBlockCCControlData->mSELCCControlHandler);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeBlockCCControl(pNode, pParent, pPropertyName, pBlockCCControlData, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeScaleLock(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float * pScaleLock, CCBReader * pCCBReader)
{
    if(strcmp(pPropertyName, PROPERTY_SCALE) == 0) {
        pNode->setScaleX(pScaleLock[0]);
        pNode->setScaleY(pScaleLock[1]);
    }
    else if(strcmp(pPropertyName, PROPERTY_IMAGESCALE) == 0)
    {
        ((RCCheckButton*)pNode)->setImageScaleX(pScaleLock[0]);
        ((RCCheckButton*)pNode)->setImageScaleY(pScaleLock[1]);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeScaleLock(pNode, pParent, pPropertyName, pScaleLock, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloatScale, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
        ((RCCheckButton*)pNode)->setFontSize(pFloatScale);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_LABELCOLOR) == 0) {
        ((RCCheckButton*)pNode)->setLabelColor(pCCColor3B);
    }
    else if (strcmp(pPropertyName, PROPERTY_SELECTEDLABELCOLOR) == 0)
    {
        ((RCCheckButton*)pNode)->setSelectedLabelColor(pCCColor3B);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pCCColor3B, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pString, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_STRING) == 0) {
        ((RCCheckButton*)pNode)->setTitle(pString);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pFontTTF, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
        ((RCCheckButton*)pNode)->setFontTTF(pFontTTF);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, pCCBReader);
    }
}

void RCCheckButtonLoader::onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char* pPropertyName, bool pCheck, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_SELECTED) == 0) {
        ((RCCheckButton*)pNode)->setSelected(pCheck);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, pCCBReader);
    }
}

