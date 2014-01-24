//
//  RCScrollViewLoader.h
//  RyancatCCBDemo
//
//  Created by Bai Ryan on 14-1-23.
//
//

#ifndef __RyancatCCBDemo__RCScrollViewLoader__
#define __RyancatCCBDemo__RCScrollViewLoader__

#include "cocos2d.h"
#include "CCNodeLoader.h"
#include "RCScrollView.h"

USING_NS_CC_EXT;
USING_NS_CC;

class RCScrollViewLoader :public CCScrollViewLoader
{
public:
    RCScrollViewLoader();
    virtual ~RCScrollViewLoader();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCScrollViewLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCScrollView);
    
    virtual void onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char * pPropertyName, bool pCheck, CCBReader * pCCBReader);
};

#endif /* defined(__RyancatCCBDemo__RCScrollViewLoader__) */
