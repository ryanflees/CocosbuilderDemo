//
//  RCSceneManager.h
//  HYDemo
//
//  Created by Bai Ryan on 14-1-10.
//
//

#ifndef __HYDemo__RCSceneManager__
#define __HYDemo__RCSceneManager__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class RCSceneManager
{
public:
    RCSceneManager();
    ~RCSceneManager();
    
    static RCSceneManager* m_instanceOfSceneManager;
    static RCSceneManager* sharedSceneManager();
    static void purge();
  
    void showMainMenu();
    void returnMainMenu();
    void returnPreviousScene();
    void switchToButtonScene();
    void switchToLabelScene();
    void switchToScrollViewScene();
    void switchToTabBarScene();
    void switchToPanelScene();
    void switchToPickerViewScene();
    void switchToOnePieceMainMenu();
    void switchToOnePieceLoadingScene();
    void switchToOnePieceGameScene();
    
    void registerCustomControlsForNodeloader(CCNodeLoaderLibrary *pLoaderLibrary);
private:
    
};

#endif /* defined(__HYDemo__RCSceneManager__) */
