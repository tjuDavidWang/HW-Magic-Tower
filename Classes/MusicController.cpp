#include "MusicController.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
using namespace ui;

#include "AudioEngine.h"


SoundPlayer::SoundPlayer() {
	//变量初始化
	_audioID = AudioEngine::INVALID_AUDIO_ID;//这个值为AudioEngine中的一个初始值，为-1
	_loop = false;

}
Scene* SoundPlayer::createScene() {
	auto scene = Scene::create();
	auto layer = SoundPlayer::create();
	scene->addChild(layer);
	return scene;
}
bool SoundPlayer::init() {
	if (!Layer::init()) {
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();


	//当前测试标签描述
	auto test_label = Label::createWithSystemFont("Sound Player", "Arial Black", 40);
	test_label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - test_label->getContentSize().height));
	this->addChild(test_label);

	//Play
	auto Play_Item = MenuItemFont::create("Play", [&](Ref* sender) {
		if (_audioID == AudioEngine::INVALID_AUDIO_ID) {
			_audioID = AudioEngine::play2d("bgm.mp3", _loop);//播放音乐文件
		}
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::setFinishCallback(_audioID, [&](int id, const std::string& filePath) {
				_audioID = AudioEngine::INVALID_AUDIO_ID; //播放完成时，再次初始化声音文件ID
				});
		}

		});
	Play_Item->setPosition(Vec2(-visibleSize.width / 4, visibleSize.height / 4-30));
	Play_Item->setFontNameObj("Arial Black");


	//Stop
	auto Stop_Item = MenuItemFont::create("Stop", [&](Ref* sender) {
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::stop(_audioID);//停止播放音乐文件
			_audioID = AudioEngine::INVALID_AUDIO_ID;
		}

		});
	Stop_Item->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 4-30));
	Stop_Item->setFontNameObj("Arial Black");

	//Pause
	auto Pause_Item = MenuItemFont::create("Pause", [&](Ref* sender) {
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::pause(_audioID);//暂停播放音乐文件
		}

		});
	Pause_Item->setPosition(Vec2(-visibleSize.width / 4, 0));
	Pause_Item->setFontNameObj("Arial Black");
	
	//Resume
	auto Resume_Item = MenuItemFont::create("Resume", [&](Ref* sender) {
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::resume(_audioID);//恢复播放音乐文件
		}

		});
	Resume_Item->setPosition(Vec2(visibleSize.width / 4, 0));
	Resume_Item->setFontNameObj("Arial Black");

	auto menu = Menu::create(Play_Item, Stop_Item, Pause_Item, Resume_Item, NULL);
	addChild(menu, 10);

	//初始化控制音量的滑动条
	Slider* slider = Slider::create();
	slider->loadBarTexture("Slider_Back.png"); // what the slider looks like
	slider->loadSlidBallTextures("SliderNode_Normal.png", "SliderNode_Press.png", "SliderNode_Disable.png");
	slider->loadProgressBarTexture("Slider_PressBar.png");
	slider->setPosition(Vec2(visibleSize.width / 2, 100));
	slider->setScale(1.5f);
	slider->setPercent(100);

	slider->addEventListener([&](Ref* sender, Slider::EventType type)
		{
				auto s = dynamic_cast<Slider*>(sender);
				auto volum = 1.0f * s->getPercent() / s->getMaxPercent();//计算音量的值，音量的值应为：0~1之间
				if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
					AudioEngine::setVolume(_audioID, volum);
				}
		});
	this->addChild(slider);

	return true;
}

void SoundPlayer::onEnter() {
	Layer::onEnter();

	//声音引擎初始化
	AudioEngine::lazyInit();

	//加载声音文件
	AudioEngine::preload("music/background.mp3");

	//打印加载信息
	CCLOG("OnEnter....");
}
void SoundPlayer::onExit() {
	if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
		AudioEngine::uncache("music/background.mp3");//清除音乐文件的缓存
	}
	Layer::onExit();
}

