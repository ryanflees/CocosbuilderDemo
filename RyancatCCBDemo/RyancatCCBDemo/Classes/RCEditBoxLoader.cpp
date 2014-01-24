//
//  RCEditBoxLoader.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#include "RCEditBoxLoader.h"

#define PROPERTY_BACKGROUNDFRAME "backgroundFrame"
#define PROPERTY_EDITSIZE "editSize"
#define PROPERTY_MAXLENGTH "maxLength"
#define PROPERTY_STRING "string"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_INPUTMODE "inputMode"
#define PROPERTY_INPUTFLAG "inputFlag"
#define PROPERTY_TEXTCOLOR "textColor"
#define PROPERTY_RETURNTYPE "returnType"

void RCEditBoxLoader::onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_BACKGROUNDFRAME) == 0) {
        ((RCEditBox*)pNode)->setBackgroundFrame(pCCSpriteFrame);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pCCSpriteFrame, pCCBReader);
    }
}

void RCEditBoxLoader::onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_EDITSIZE) == 0) {
        ((RCEditBox*)pNode)->setContentSize(pSize);
    }
    else if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, pCCBReader);
    }

}

void RCEditBoxLoader::onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pString, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_STRING) == 0) {
        ((RCEditBox*)pNode)->setText(pString);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, pCCBReader);
    }

}

void RCEditBoxLoader::onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char* pPropertyName, const char * pFontTTF, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
        ((RCEditBox*)pNode)->setFontName(pFontTTF);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, pCCBReader);
    }
}

void RCEditBoxLoader::onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char* pPropertyName, float pFloatScale, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
        ((RCEditBox*)pNode)->setFontSize(pFloatScale);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, pCCBReader);
    }
}

void RCEditBoxLoader::onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_TEXTCOLOR) == 0) {
        ((RCEditBox*)pNode)->setFontColor(pCCColor3B);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pCCColor3B, pCCBReader);
    }
}

void RCEditBoxLoader::onHandlePropTypeIntegerLabeled(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pIntegerLabeled, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_INPUTMODE) == 0) {
        ((RCEditBox*)pNode)->setInputMode((EditBoxInputMode)pIntegerLabeled);
    }
    else if (strcmp(pPropertyName, PROPERTY_INPUTFLAG) == 0) {
        ((RCEditBox*)pNode)->setInputFlag((EditBoxInputFlag)pIntegerLabeled);
    }
    else if (strcmp(pPropertyName, PROPERTY_RETURNTYPE) == 0)
    {
        ((RCEditBox*)pNode)->setReturnType((KeyboardReturnType)pIntegerLabeled);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeIntegerLabeled(pNode, pParent, pPropertyName, pIntegerLabeled, pCCBReader);
    }
}

void RCEditBoxLoader::onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_MAXLENGTH) == 0) {
        ((RCEditBox*)pNode)->setMaxLength(pInteger);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeInteger(pNode, pParent, pPropertyName, pInteger, pCCBReader);
    }
}

void RCEditBoxLoader::onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPoint, CCBReader * pCCBReader)
{
    CCNodeLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, pCCBReader);
}
