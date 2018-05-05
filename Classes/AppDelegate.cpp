#include "AppDelegate.h"
#include "MoriorGames/Scenes/LogoScene.h"
#include "MoriorGames/Screen/Resolution.h"
#include "MoriorGames/Vendor/Containers/BattleHeroesConfig.h"
#include "MoriorGames/Vendor/Entity/User.h"
#include "MoriorGames/Vendor/Repository/HeroRepository.h"
#include "MoriorGames/Vendor/Repository/SkillRepository.h"

Resolution *globalResolution = new Resolution;
BattleHeroesConfig *battleHeroesConfig = new BattleHeroesConfig;
User *playerUser = new User;
HeroRepository *heroRepo = new HeroRepository;
SkillRepository *skillRepo = new SkillRepository;

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

using namespace std;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);

static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);

static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);

static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
    Resolution resolution;

    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::createWithRect("BFA AI", resolution.getDesktopRect(), 1.0);
        director->setOpenGLView(glview);
    }

    //Prevent entering sleep mode
    cocos2d::Device::setKeepScreenOn(true);

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    auto screenSize = glview->getFrameSize();
    Resolution::DesignProperties designProperties = resolution.designPropertiesByScreen(screenSize)
        ->getDesignProperties();
    glview->setDesignResolutionSize(designProperties.width, designProperties.height, ResolutionPolicy::FIXED_WIDTH);

    register_all_packages();

    globalResolution->setScale(resolution.getScale());

    // create a scene. it's an autorelease object
    auto scene = LogoScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
