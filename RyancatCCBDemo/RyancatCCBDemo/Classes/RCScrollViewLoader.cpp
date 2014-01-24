//
//  RCScrollViewLoader.cpp
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#include "RCScrollViewLoader.h"

#define PROPERTY_PAGEMODE "pageMode"
#define PROPERTY_CONTAINER "container"

RCScrollViewLoader::RCScrollViewLoader()
{

}

RCScrollViewLoader::~RCScrollViewLoader()
{

}

void RCScrollViewLoader::onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char * pPropertyName, bool pCheck, CCBReader * pCCBReader)
{
    if (strcmp(pPropertyName, PROPERTY_PAGEMODE) == 0) {
        ((RCScrollView*)pNode)->setPageMode(pCheck);
    }
    else
    {
        CCScrollViewLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, pCCBReader);
    }
}
