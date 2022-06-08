#pragma once
//
//  SettingScene.h
//  MagicTower
//
//  Created by ½¹æñ on 2022/6/1.
//

#ifndef _SETTING_SCENE_H_
#define _SETTING_SCENE_H_

#include "ui/CocosGUI.h"
#include "cocos2d.h"

class Setting :public cocos2d::Scene
{
public:
    static bool isEffect;
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuItemSoundToggleCallback(cocos2d::Ref* PSender);
    void menuItemBack(cocos2d::Ref* Psender);
    void onChangedSlider(Ref* PSender, cocos2d::ui::Slider::EventType type);
    CREATE_FUNC(Setting);
};

#endif // !_SETTING_SCENE_H_