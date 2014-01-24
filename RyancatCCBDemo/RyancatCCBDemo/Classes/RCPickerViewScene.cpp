//
//  RCPickerViewScene.cpp
//  HYDemo
//
//  Created by Bai Ryan on 14-1-17.
//
//

#include "RCPickerViewScene.h"
#include "RCPickerView.h"
#include "RCSceneManager.h"

const char* pickerRows[] =
{
    "Rogue",
    "Mage",
    "Hunder",
    "Warrior",
    "Warlock",
    "Priest",
    "Paladin",
    "Monk",
    "Death Knight",
    "Druid",
    "Shaman"
};

bool RCPickerViewScene::init()
{
    if (!CCNode::init()) {
        return false;
    }
    
//    CCLayerColor* layer = CCLayerColor::create(ccc4(255, 255, 255, 255));
//    addChild(layer);
//    
//    m_pPicker = RCPickerView::create();
//    addChild(m_pPicker);
//    m_pPicker->setContentSize(CCSizeMake(480, 320));
//    
    return true;
}

SEL_MenuHandler RCPickerViewScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler RCPickerViewScene::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "buttonClicked", RCPickerViewScene::onButtonClicked);
    return NULL;
}

bool RCPickerViewScene::onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode)
{
    return false;
}

bool RCPickerViewScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void RCPickerViewScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader)
{
    m_pPickerView = RCPickerView::create();
    if (m_pPickerView->getPickViewImp()) {
        addChild(m_pPickerView);
        CCRect rect = CCRectMake(200, 100, 600, 500);
        m_pPickerView->setPickerRect(rect);
        m_pPickerView->setDelegate(this);
    }
}

void RCPickerViewScene::onButtonClicked(CCNode* node)
{
    if (node->getTag() == 1) {
        RCSceneManager::sharedSceneManager()->returnPreviousScene();
    }
    else if (node->getTag() == 2)
    {
        int pickerIndex = m_pPickerView->getSelectedRow(0);
        if (pickerIndex >= 0) {
            CCMessageBox(CCString::createWithFormat("You have selected %s",pickerRows[pickerIndex])->getCString(), "Select Class");
        }
    }
}


int RCPickerViewScene::numberOfComponentsInPickerView(RCPickerViewImp *pickerView)
{
    return 1;
}

int RCPickerViewScene::numberOfRowsInComponent(RCPickerViewImp *pickerView, int component)
{
    return sizeof(pickerRows)/4;
}

const char* RCPickerViewScene::titleForRow(RCPickerViewImp *pickerView, int row, int component)
{
    return pickerRows[row];
}

void RCPickerViewScene::didSelectRow(RCPickerViewImp *pickerView, int row, int component)
{
    CCLog("selected row %i",row);
}

float RCPickerViewScene::rowHeightForComponent(RCPickerViewImp *pickerView, int component)
{
    return 40;
}

float RCPickerViewScene::widthForComponent(RCPickerViewImp *pickerView, int component)
{
    return 200;
}

