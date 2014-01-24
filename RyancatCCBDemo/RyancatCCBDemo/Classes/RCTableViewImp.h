//
//  RCTableViewImp.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#ifndef __HYDemo__RCTableViewImp__
#define __HYDemo__RCTableViewImp__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCTableViewImp :public CCTableView
{
public:
    RCTableViewImp();
    virtual ~RCTableViewImp();
    
    static RCTableViewImp* create(CCTableViewDataSource* dataSource, CCSize size);
    static RCTableViewImp* create(CCTableViewDataSource* dataSource, CCSize size, CCNode *container);
    bool initWithViewSize(CCSize size, CCNode* container = NULL);
    
    CREATE_FUNC(RCTableViewImp);
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

private:
    bool m_subNodeTouched;
};

#endif /* defined(__HYDemo__RCTableViewImp__) */
