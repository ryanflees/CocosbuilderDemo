//
//  OPTeamFormation.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-21.
//
//

#ifndef __HYDemo__OPTeamFormation__
#define __HYDemo__OPTeamFormation__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "RCScrollView.h"

USING_NS_CC;
USING_NS_CC_EXT;

class OPDataParser;

class RCImageButton;

class OPTeamFormation : public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{
public:
    OPTeamFormation();
    virtual ~OPTeamFormation();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPTeamFormation, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);

    void reloadIcons();
    void selectIcon(RCImageButton* pButton);
private:
    void onTeamIconSelected(CCNode* pNode);
    void setFrameForSprite(const char* imageFile, CCSprite* pSprite);
    void setFrameForImageButton(const char* imageFile, RCImageButton* pButton);
    void showTeamMemberByDict(CCDictionary* pDict);
    void setSpellIconBackSuspended(RCImageButton* pIcon);
    void setSpellIconBackActive(RCImageButton* pIcon);
    
    RCImageButton* m_pSelectedButton;
    RCImageButton* m_pSpellIconBack[6];
    RCImageButton* m_pSpellIcon[3];
    RCImageButton* m_pWeaponIcon;
    RCImageButton* m_pArmorIcon;
    RCImageButton* m_pTrinketIcon;
    CCSprite* m_pTeamCharacter;
    CCLabelBMFont* m_pLevelLabel;
    CCLabelBMFont* m_pReputationLabel;
    CCLabelTTF* m_pInfos[6];
    CCLabelTTF* m_pNameLabel;
    CCArray* m_pIconArray;
    CCArray* m_pIconBackArray;
    RCScrollView* m_pIconScrollView;
    CC_PROPERTY(OPDataParser*, m_pDataParser, DataParser);
};

class OPTeamFormationLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( OPTeamFormationLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( OPTeamFormation);
};


#endif /* defined(__HYDemo__OPTeamFormation__) */
