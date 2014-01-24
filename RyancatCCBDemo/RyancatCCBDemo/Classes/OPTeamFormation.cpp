//
//  OPTeamFormation.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-21.
//
//

#include "OPTeamFormation.h"
#include "OPDataParser.h"
#include "RCImageButton.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

OPTeamFormation::OPTeamFormation()
:m_pIconScrollView()
,m_pDataParser()
,m_pSelectedButton()
,m_pTeamCharacter()
,m_pLevelLabel()
,m_pReputationLabel()
,m_pNameLabel()
,m_pSpellIcon()
,m_pTrinketIcon()
,m_pArmorIcon()
,m_pWeaponIcon()
{
    memset(m_pInfos, 0, sizeof(m_pInfos));
    memset(m_pSpellIcon, 0, sizeof(m_pSpellIcon));
    memset(m_pSpellIconBack, 0, sizeof(m_pSpellIconBack));
}

OPTeamFormation::~OPTeamFormation()
{
    m_pIconBackArray->release();
    m_pIconArray->release();
}

bool OPTeamFormation::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    m_pIconArray = CCArray::create();
    m_pIconArray->retain();
    
    m_pIconBackArray = CCArray::create();
    m_pIconBackArray->retain();
    return true;
}
void OPTeamFormation::onEnter()
{
    
    CCNode::onEnter();
    
}
void OPTeamFormation::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler OPTeamFormation::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", OPTeamFormation::FUNCTION);
    return NULL;
}

SEL_CCControlHandler OPTeamFormation::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", OPTeamFormation::FUNCTION);
    return NULL;
}

bool OPTeamFormation::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "teamIconScrollView", RCScrollView*, m_pIconScrollView);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "info_1", CCLabelTTF*, m_pInfos[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "info_2", CCLabelTTF*, m_pInfos[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "info_3", CCLabelTTF*, m_pInfos[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "info_4", CCLabelTTF*, m_pInfos[3]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "info_5", CCLabelTTF*, m_pInfos[4]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "info_6", CCLabelTTF*, m_pInfos[5]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "teamCharacter", CCSprite*, m_pTeamCharacter);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "levelLabel", CCLabelBMFont*, m_pLevelLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "reputationLabel", CCLabelBMFont*, m_pReputationLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "nameLabel", CCLabelTTF*, m_pNameLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "icon_spell_1", RCImageButton*, m_pSpellIcon[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "icon_spell_2", RCImageButton*, m_pSpellIcon[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "icon_spell_3", RCImageButton*, m_pSpellIcon[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "icon_weapon", RCImageButton*, m_pWeaponIcon);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "icon_armor", RCImageButton*, m_pArmorIcon);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "icon_trinket", RCImageButton*, m_pTrinketIcon);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "iconBackground_1", RCImageButton*, m_pSpellIconBack[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "iconBackground_2", RCImageButton*, m_pSpellIconBack[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "iconBackground_3", RCImageButton*, m_pSpellIconBack[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "iconBackground_4", RCImageButton*, m_pSpellIconBack[3]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "iconBackground_5", RCImageButton*, m_pSpellIconBack[4]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "iconBackground_6", RCImageButton*, m_pSpellIconBack[5]);
 
    return false;
}

bool OPTeamFormation::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void OPTeamFormation::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    if (m_pIconScrollView) {
        CCNode* pNode = CCNode::create();
        m_pIconScrollView->setContainer(pNode);
        pNode->setContentSize(m_pIconScrollView->getViewSize());
    }
    for (int i=0; i<3; i++) {
        if (m_pSpellIcon[i]) {
            m_pSpellIcon[i]->setUserData(m_pSpellIconBack[i]);
            m_pSpellIcon[i]->setScale(0.3f);
        }
    }
    if (m_pWeaponIcon) {
        m_pWeaponIcon->setScale(0.3f);
        m_pWeaponIcon->setUserData(m_pSpellIconBack[3]);
    }
    if (m_pArmorIcon) {
        m_pArmorIcon->setUserData(m_pSpellIconBack[4]);
    }
    if (m_pTrinketIcon) {
        m_pTrinketIcon->setScale(0.3f);
        m_pTrinketIcon->setUserData(m_pSpellIconBack[5]);
    }
}

void OPTeamFormation::setDataParser(OPDataParser *var)
{
    m_pDataParser = var;
}

OPDataParser* OPTeamFormation::getDataParser()
{
    return m_pDataParser;
}

void OPTeamFormation::reloadIcons()
{
    m_pSelectedButton = NULL;
    m_pIconScrollView->getContainer()->removeAllChildren();
    CCAssert(m_pIconScrollView, "m_pIconScrollView is NULL");
    if (!m_pDataParser) {
        return;
    }
    CCArray* pTeamMemberArray = m_pDataParser->getTeamData();
    CCObject* pObject;
    m_pIconArray->removeAllObjects();
    m_pIconBackArray->removeAllObjects();
    CCARRAY_FOREACH(pTeamMemberArray, pObject)
    {
        CCDictionary* pDict = (CCDictionary*)pObject;
        int memberID = pDict->valueForKey("id")->intValue();
        const CCString* iconFile = pDict->valueForKey("icon");
        RCImageButton* pButton = RCImageButton::create();
        CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addImage(iconFile->getCString());
        CCSpriteFrame* pFrame = CCSpriteFrame::createWithTexture(pTexture, CCRectMake(0, 0, pTexture->getContentSize().width, pTexture->getContentSize().height));
        pButton->setImageDisplayFrame(pFrame);
        pButton->setTag(memberID);
        
        CCSpriteFrame* pIconBackgroundFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("u_icobg02.png");
        CCSprite* pIconBack = CCSprite::createWithSpriteFrame(pIconBackgroundFrame);
        pButton->setUserData(pIconBack);
        m_pIconScrollView->getContainer()->addChild(pIconBack);
        m_pIconBackArray->addObject(pIconBack);
        m_pIconScrollView->getContainer()->addChild(pButton);
        m_pIconArray->addObject(pButton);
        pButton->setTarget(this, callfuncN_selector(OPTeamFormation::onTeamIconSelected));
    }
    
    int i =0;
    CCARRAY_FOREACH(m_pIconArray, pObject)
    {
        CCSprite* pIconBack = (CCSprite*)m_pIconBackArray->objectAtIndex(i);
        RCImageButton* pButton = (RCImageButton*)pObject;
        CCPoint pos = ccp(m_pIconScrollView->getContentSize().width/2,
            m_pIconScrollView->getViewSize().height
            - (i+1)*pButton->getContentSize().height*1.2f);
        pButton->setPosition(pos);
        pIconBack->setPosition(pos);
        i++;
    }
    
    if (m_pIconArray->count() > 0) {
        RCImageButton* pButton = (RCImageButton*)m_pIconArray->objectAtIndex(0);
        selectIcon(pButton);
    }
}

void OPTeamFormation::selectIcon(RCImageButton* pButton)
{
    if (m_pSelectedButton) {
        CCSpriteFrame* pSelectorFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("u_icobg02.png");
        CCSprite* pIconBack = (CCSprite*)m_pSelectedButton->getUserData();
        pIconBack->setDisplayFrame(pSelectorFrame);
    }
    
    m_pSelectedButton= pButton;
    CCSpriteFrame* pSelectorFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("u_icobg06.png");
    CCSprite* pIconBack = (CCSprite*)pButton->getUserData();
    pIconBack->setDisplayFrame(pSelectorFrame);
    
    int id = pButton->getTag();
    CCDictionary* pDict =  m_pDataParser->getTeamMemberByID(id);
    showTeamMemberByDict(pDict);
}

void OPTeamFormation::onTeamIconSelected(CCNode* pNode)
{
    RCImageButton* pButton = (RCImageButton*)pNode;
    if (m_pSelectedButton != pButton) {
        SimpleAudioEngine::sharedEngine()->playEffect("click.mp3");
        selectIcon(pButton);
    }
}

void OPTeamFormation::setFrameForSprite(const char* imageFile, CCSprite* pSprite)
{
    CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addImage(imageFile);
    if (pTexture) {
        CCSpriteFrame* pFrame = CCSpriteFrame::createWithTexture(pTexture, CCRectMake(0, 0, pTexture->getContentSize().width, pTexture->getContentSize().height));
        if (pSprite) {
            pSprite->setDisplayFrame(pFrame);
        }
    }
}

void OPTeamFormation::setFrameForImageButton(const char* imageFile, RCImageButton* pButton)
{
    CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addImage(imageFile);
    if (pTexture) {
        CCSpriteFrame* pFrame = CCSpriteFrame::createWithTexture(pTexture, CCRectMake(0, 0, pTexture->getContentSize().width, pTexture->getContentSize().height));
        if (pButton) {
            pButton->setImageDisplayFrame(pFrame);
        }
    }
    else
    {
        CCSpriteFrame* pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(imageFile);
        if (pFrame && pButton) {
            pButton->setImageDisplayFrame(pFrame);
        }
    }
}

void OPTeamFormation::showTeamMemberByDict(CCDictionary* pDict)
{
    const CCString* pName = pDict->valueForKey("name");
    if (m_pNameLabel) {
        m_pNameLabel->setString(pName->getCString());
    }
    
    int level = pDict->valueForKey("level")->intValue();
    CCString* pLevelString = CCString::createWithFormat("M%i",level);
    if (m_pLevelLabel) {
        m_pLevelLabel->setString(pLevelString->getCString());
    }
    
    int reputation = pDict->valueForKey("reputation")->intValue();
    CCString* pRepString = CCString::createWithFormat("%i",reputation);
    if (m_pReputationLabel) {
        m_pReputationLabel->setString(pRepString->getCString());
    }
    
    const CCString* pPortraitFile = pDict->valueForKey("portrait");
    setFrameForSprite(pPortraitFile->getCString(), m_pTeamCharacter);
    
    for (int i=0; i<6; i++) {
        if (m_pInfos[i]) {
            m_pInfos[i]->setString("");
        }
    }
    
    CCArray* pInfoArray = (CCArray*)pDict->objectForKey("info");
    for (unsigned int i=0; i<pInfoArray->count(); i++) {
        CCString* pInfo = (CCString*)pInfoArray->objectAtIndex(i);
        if (i<6 && m_pInfos[i]) {
            m_pInfos[i]->setString(pInfo->getCString());
        }
    }
    
    for (int i=0; i<3; i++) {
        if (m_pSpellIcon[i]) {
            m_pSpellIcon[i]->setVisible(false);
        }
    }
    m_pWeaponIcon->setVisible(false);
    m_pArmorIcon->setVisible(false);
    m_pTrinketIcon->setVisible(false);
    
    CCDictionary* pWeaponDict = (CCDictionary*)pDict->objectForKey("weapon");
    if (pWeaponDict) {
        const CCString* pIconFile = pWeaponDict->valueForKey("icon");
        setFrameForImageButton(pIconFile->getCString(), m_pWeaponIcon);
        m_pWeaponIcon->setVisible(true);
        setSpellIconBackSuspended(m_pWeaponIcon);
    }
    else
    {
        setSpellIconBackActive(m_pWeaponIcon);
    }
    
    CCDictionary* pArmorDict = (CCDictionary*)pDict->objectForKey("armor");
    if (pArmorDict) {
        const CCString* pIconFile = pArmorDict->valueForKey("icon");
        setFrameForImageButton(pIconFile->getCString(), m_pArmorIcon);
        m_pArmorIcon->setVisible(true);
        setSpellIconBackSuspended(m_pArmorIcon);
    }
    else
    {
        setSpellIconBackActive(m_pArmorIcon);
    }
    
    CCDictionary* pTrinketDict = (CCDictionary*)pDict->objectForKey("trinket");
    if (pTrinketDict) {
        const CCString* pIconFile = pTrinketDict->valueForKey("icon");
        setFrameForImageButton(pIconFile->getCString(), m_pTrinketIcon);
        m_pTrinketIcon->setVisible(true);
        setSpellIconBackSuspended(m_pTrinketIcon);
    }
    else
    {
        setSpellIconBackActive(m_pTrinketIcon);
    }
    
    CCArray* pSpellArray = (CCArray*)pDict->objectForKey("spell");
    if (pSpellArray) {
        for (unsigned int i=0;i<3 ; i++) {
            if (i<pSpellArray->count()) {
                CCDictionary* pSpellDict = (CCDictionary*)pSpellArray->objectAtIndex(i);
                const CCString* pIconFile = pSpellDict->valueForKey("icon");
                setFrameForImageButton(pIconFile->getCString(), m_pSpellIcon[i]);
                m_pSpellIcon[i]->setVisible(true);
                setSpellIconBackSuspended(m_pSpellIcon[i]);
            }
            else
            {
                setSpellIconBackActive(m_pSpellIcon[i]);
            }
        }

    }
}

void OPTeamFormation::setSpellIconBackSuspended(RCImageButton* pIcon)
{
    RCImageButton* pIconBack = (RCImageButton*)pIcon->getUserData();
    if (pIconBack) {
        setFrameForImageButton("u_icobg02.png", pIconBack);
    }
}

void OPTeamFormation::setSpellIconBackActive(RCImageButton* pIcon)
{
    RCImageButton* pIconBack = (RCImageButton*)pIcon->getUserData();
    if (pIconBack) {
        setFrameForImageButton("u_icobg01.png", pIconBack);
    }
}
