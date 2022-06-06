#include "MusicController.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
using namespace ui;

#include "AudioEngine.h"


SoundPlayer::SoundPlayer() {
	//������ʼ��
	_audioID = AudioEngine::INVALID_AUDIO_ID;//���ֵΪAudioEngine�е�һ����ʼֵ��Ϊ-1
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


	//��ǰ���Ա�ǩ����
	auto test_label = Label::createWithSystemFont("Sound Player", "Arial Black", 40);
	test_label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - test_label->getContentSize().height));
	this->addChild(test_label);

	//Play
	auto Play_Item = MenuItemFont::create("Play", [&](Ref* sender) {
		if (_audioID == AudioEngine::INVALID_AUDIO_ID) {
			_audioID = AudioEngine::play2d("bgm.mp3", _loop);//���������ļ�
		}
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::setFinishCallback(_audioID, [&](int id, const std::string& filePath) {
				_audioID = AudioEngine::INVALID_AUDIO_ID; //�������ʱ���ٴγ�ʼ�������ļ�ID
				});
		}

		});
	Play_Item->setPosition(Vec2(-visibleSize.width / 4, visibleSize.height / 4-30));
	Play_Item->setFontNameObj("Arial Black");


	//Stop
	auto Stop_Item = MenuItemFont::create("Stop", [&](Ref* sender) {
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::stop(_audioID);//ֹͣ���������ļ�
			_audioID = AudioEngine::INVALID_AUDIO_ID;
		}

		});
	Stop_Item->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 4-30));
	Stop_Item->setFontNameObj("Arial Black");

	//Pause
	auto Pause_Item = MenuItemFont::create("Pause", [&](Ref* sender) {
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::pause(_audioID);//��ͣ���������ļ�
		}

		});
	Pause_Item->setPosition(Vec2(-visibleSize.width / 4, 0));
	Pause_Item->setFontNameObj("Arial Black");
	
	//Resume
	auto Resume_Item = MenuItemFont::create("Resume", [&](Ref* sender) {
		if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
			AudioEngine::resume(_audioID);//�ָ����������ļ�
		}

		});
	Resume_Item->setPosition(Vec2(visibleSize.width / 4, 0));
	Resume_Item->setFontNameObj("Arial Black");

	auto menu = Menu::create(Play_Item, Stop_Item, Pause_Item, Resume_Item, NULL);
	addChild(menu, 10);

	//��ʼ�����������Ļ�����
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
				auto volum = 1.0f * s->getPercent() / s->getMaxPercent();//����������ֵ��������ֵӦΪ��0~1֮��
				if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
					AudioEngine::setVolume(_audioID, volum);
				}
		});
	this->addChild(slider);

	return true;
}

void SoundPlayer::onEnter() {
	Layer::onEnter();

	//���������ʼ��
	AudioEngine::lazyInit();

	//���������ļ�
	AudioEngine::preload("music/background.mp3");

	//��ӡ������Ϣ
	CCLOG("OnEnter....");
}
void SoundPlayer::onExit() {
	if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
		AudioEngine::uncache("music/background.mp3");//��������ļ��Ļ���
	}
	Layer::onExit();
}

