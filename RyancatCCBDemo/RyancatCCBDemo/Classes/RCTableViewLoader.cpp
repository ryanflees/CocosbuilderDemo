//
//  RCTableViewLoader.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#include "RCTableViewLoader.h"

#define PROPERTY_CELLSIZE "cellSize"
#define PROPERTY_CELLCOUNT "cellCount"
#define PROPERTY_CELLTEMPLATE "cellTemplate"

RCTableViewLoader::RCTableViewLoader()
{

}

RCTableViewLoader::~RCTableViewLoader()
{

}

void RCTableViewLoader::onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_CELLSIZE) == 0) {
        ((RCTableView*)pNode)->setCellSize(pSize);
    }
    else if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
        pNode->setContentSize(pSize);
        ((RCTableView*)pNode)->setTableSize(pSize);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, pCCBReader);
    }
}

void RCTableViewLoader::onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_CELLCOUNT) == 0) {
        ((RCTableView*)pNode)->setCellCount(pInteger);
    }
    else
    {
        CCNodeLoader::onHandlePropTypeInteger(pNode, pParent, pPropertyName, pInteger, pCCBReader);
    }
}

