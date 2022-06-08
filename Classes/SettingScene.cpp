//
//  SettingScene.cpp
//  MagicTower
//
//  Created by 焦骜 on 2022/6/1.
//

#include "SettingScene.h"
#include "ui/CocosGUI.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* Setting::createScene()
{
    return Setting::create();
}
bool Setting::isEffect = true;

bool Setting::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //背景图片
    auto backgroundImage = Sprite::create("mota.jpg", Rect(240, 0, 550, 483));
    backgroundImage->setAnchorPoint(Vec2::ZERO);
    this->addChild(backgroundImage);
    // 开关菜单
    auto toggleSoundMenuitem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuItemSoundToggleCallback, this), MenuItemFont::create("on"), MenuItemFont::create("off"), nullptr);
    toggleSoundMenuitem->setPosition(Vec2(400, 300));

    auto soundLabel = MenuItemFont::create("音效：");
    soundLabel->setPosition(Vec2(200, 300));
    addChild(soundLabel);

    auto musicLabel = MenuItemFont::create("音乐：");
    musicLabel->setPosition(Vec2(200, 150));
    addChild(musicLabel);


    auto okMenuItem = MenuItemFont::create("完成", CC_CALLBACK_1(Setting::menuItemBack, this));
    okMenuItem->setPosition(Vec2(visibleSize.width / 2, 50));
    cocos2d::ui::Slider* slider = cocos2d::ui::Slider::create();
    slider->loadBarTexture("Slider_Back.png"); // what the slider looks like
    slider->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
    slider->loadProgressBarTexture("Slider_PressBar.png");
    slider->setMaxPercent(100);
    slider->setPercent(50);
    slider->setPosition(Vec2(400, 150));
    slider->addEventListener(CC_CALLBACK_2(Setting::onChangedSlider, this));

    addChild(slider);
    //将开关菜单和文本菜单加入menu菜单中
    Menu* menu = Menu::create(toggleSoundMenuitem, okMenuItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    addChild(menu);
    return true;
}

void Setting::onChangedSlider(Ref* PSender, cocos2d::ui::Slider::EventType type)
{
    if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
    {
        auto slider = dynamic_cast<cocos2d::ui::Slider*>(PSender);
        float percent = slider->getPercent() / 100.0f;
        AudioEngine::setVolume(0, percent);
    }
}

void Setting::menuItemSoundToggleCallback(cocos2d::Ref* PSender)
{
    auto soundToggleMenuItem = (MenuItemToggle*)PSender;
    if (isEffect)
    {
        AudioEngine::play2d("button_click.wav");
    }
    if (soundToggleMenuItem->getSelectedIndex() == 1) isEffect = false;
    else {
        isEffect = true;
        AudioEngine::play2d("button_click.wav");
    }
}

// 点击完成时，返回主界面
void Setting::menuItemBack(cocos2d::Ref* Psender)
{
    Director::getInstance()->popScene();
}
