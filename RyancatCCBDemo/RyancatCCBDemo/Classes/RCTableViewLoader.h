//
//  RCTableViewLoader.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#ifndef __HYDemo__RCTableViewLoader__
#define __HYDemo__RCTableViewLoader__

#include "cocos2d.h"
#include "RCTableView.h"

USING_NS_CC;

class RCTableViewLoader :public CCNodeLoader
{
public:
    RCTableViewLoader();
    virtual ~RCTableViewLoader();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RCTableViewLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RCTableView);
    
    virtual void onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCSize pSize, CCBReader * pCCBReader);
    virtual void onHandlePropTypeInteger(CCNode * pNode, CCNode * pParent, const char* pPropertyName, int pInteger, CCBReader * pCCBReader);
};

#endif /* defined(__HYDemo__RCTableViewLoader__) */
