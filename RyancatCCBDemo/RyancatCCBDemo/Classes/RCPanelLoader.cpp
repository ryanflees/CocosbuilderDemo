//
//  RCPanelLoader.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-12.
//
//

#include "RCPanelLoader.h"

#define PROPERTY_BACKGROUNDSPRITEFRAME "backgroundSpriteFrame"
#define PROPERTY_PANELSIZE "panelSize"
#define PROPERTY_INSECTLEFT "insetLeft"
#define PROPERTY_INSECTRIGHT "insetRight"
#define PROPERTY_INSECTTOP "insetTop"
#define PROPERTY_INSECTBOTTOM "insetBottom"
#define PROPERTY_ENABLECLOSEBUTTON "enableCloseButton"
#define PROPERTY_CANCELBUTTONNORMALSPRITEFRAME "cancelButtonNormalSpriteFrame"
#define PROPERTY_CANCELBUTTONSELECTEDSPRITEFRAME "cancelButtonSelectedSpriteFrame"
#define PROPERTY_CLOSEBUTTONALIGNTYPE "closeButtonAlignType"
#define PROPERTY_CLOSEBUTTONALIGNGAP "closeButtonAlignGap"
#define PROPERTY_CLOSEBUTTONPOSITION "closeButtonPosition"
#define PROPERTY_CCCONTROL "ccControl"

#define PROPERY_TITLE "title"
#define PROPERY_ENABLETITLE "enableTitle"
#define PROPERY_FONTNAME "fontName"
#define PROPERY_FONTSIZE "fontSize"
#define PROPERY_TITLEPOSITION "titlePosition"
#define PROPERY_TITLECOLOR "titleColor"

void RCPanelLoader::onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME) == 0) {
        ((RCPanel*)pNode)->setPanelFrame(pCCSpriteFrame);
    }
    else if (strcmp(pPropertyName, PROPERTY_CANCELBUTTONNORMALSPRITEFRAME) == 0)
    {
        ((RCPanel*)pNode)->setNormalCloseFrame(pCCSpriteFrame);
    }
    else if (strcmp(pPropertyName, PROPERTY_CANCELBUTTONSELECTEDSPRITEFRAME) == 0)
    {
        ((RCPanel*)pNode)->setSelectedCloseFrame(pCCSpriteFrame);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pCCSpriteFrame, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_PANELSIZE) == 0) {
        ((RCPanel*)pNode)->setContentSize(pSize);
    }
    else if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeFloat(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloat, CCBReader * pCCBReader)
{
    CCNodeLoader::onHandlePropTypeFloat(pNode, pParent, pPropertyName, pFloat, pCCBReader);
}

void RCPanelLoader::onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char* pPropertyName, bool pCheck, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_ENABLECLOSEBUTTON) == 0) {
        ((RCPanel*)pNode)->setEnableCloseButton(pCheck);
    }
    else if (strcmp(pPropertyName, PROPERY_ENABLETITLE))
    {
        ((RCPanel*)pNode)->setEnableTitle(pCheck);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPoint, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_CLOSEBUTTONPOSITION) == 0) {
        ((RCPanel*)pNode)->setCloseButtonPosition(pPoint);
    }
    else if (strcmp(pPropertyName, PROPERY_TITLEPOSITION) == 0) {
        ((RCPanel*)pNode)->setTitlePosition(pPoint);
    }
    else
    {
        CCNodeLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_CCCONTROL) == 0) {
        ((RCPanel*)pNode)->setTarget(pBlockCCControlData->mTarget, (SEL_CallFuncN)pBlockCCControlData->mSELCCControlHandler);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeBlockCCControl(pNode, pParent, pPropertyName, pBlockCCControlData, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pString, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERY_TITLE) == 0) {
        ((RCPanel*)pNode)->setTitle(pString);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pFontTTF, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERY_FONTNAME) == 0) {
        ((RCPanel*)pNode)->setFontName(pFontTTF);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloatScale, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERY_FONTSIZE) == 0) {
        ((RCPanel*)pNode)->setFontSize(pFloatScale);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERY_TITLECOLOR) == 0) {
        ((RCPanel*)pNode)->setTitleColor(pCCColor3B);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pCCColor3B, pCCBReader);
    }
}

void RCPanelLoader::onHandlePropTypeIntegerLabeled(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * pCCBReader) {
    if (strcmp(pPropertyName, PROPERTY_CLOSEBUTTONALIGNTYPE) == 0) {
    }
    else
    {
        CCNodeLoader::onHandlePropTypeIntegerLabeled(pNode, pParent, pPropertyName, pIntegerLabeled, pCCBReader);
    }
}

