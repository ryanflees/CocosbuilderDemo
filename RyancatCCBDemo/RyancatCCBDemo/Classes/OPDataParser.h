//
//  OPDataParser.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-21.
//
//

#ifndef __HYDemo__OPDataParser__
#define __HYDemo__OPDataParser__

#include "cocos2d.h"

USING_NS_CC;

class OPDataParser :public CCNode
{
public:
    OPDataParser();
    virtual ~OPDataParser();
    virtual bool init();
    CREATE_FUNC(OPDataParser);
    virtual void onEnter();
    virtual void onExit();
    
    void loadTeamData(const char* plistFile);
    CCDictionary* getTeamMemberByID(int id);
private:
    CC_SYNTHESIZE_READONLY(CCArray*, m_pTeamData, TeamData);
};

#endif /* defined(__HYDemo__OPDataParser__) */
