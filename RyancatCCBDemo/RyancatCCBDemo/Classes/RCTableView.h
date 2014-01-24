//
//  RCTableView.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-22.
//
//

#ifndef __HYDemo__RCTableView__
#define __HYDemo__RCTableView__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCTableViewImp.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCTableView :public CCNode
{
public:
    RCTableView();
    virtual ~RCTableView();
    virtual bool init();
    CREATE_FUNC(RCTableView);
    virtual void onEnter();
    virtual void onExit();
    
    /** 
        The CCTableView subnode can only be created once
     */
    void generateTableView(CCTableViewDataSource *dataSource);
private:
    
    CC_SYNTHESIZE(CCSize, m_tableSize, TableSize);
    CC_SYNTHESIZE(int, m_cellCount, CellCount);
    CC_SYNTHESIZE(CCSize, m_cellSize, CellSize);
    RCTableViewImp* m_pTableView;
};

#endif /* defined(__HYDemo__RCTableView__) */
