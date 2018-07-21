LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libBFAI

LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   ../../../Classes/MoriorGames/Containers/BattleContainer.cpp \
                   ../../../Classes/MoriorGames/Containers/GridContainer.cpp \
                   ../../../Classes/MoriorGames/EventListeners/BattleEventListener.cpp \
                   ../../../Classes/MoriorGames/EventListeners/BattleEventOfflinePublisher.cpp \
                   ../../../Classes/MoriorGames/EventListeners/BattleEventOnlinePublisher.cpp \
                   ../../../Classes/MoriorGames/Factories/BattleEventPublisherFactory.cpp \
                   ../../../Classes/MoriorGames/Grid/GridHD.cpp \
                   ../../../Classes/MoriorGames/Grid/GridHDR.cpp \
                   ../../../Classes/MoriorGames/Grid/GridSD.cpp \
                   ../../../Classes/MoriorGames/Http/Client.cpp \
                   ../../../Classes/MoriorGames/Scenes/BattleScene.cpp \
                   ../../../Classes/MoriorGames/Scenes/HeroesConfigScene.cpp \
                   ../../../Classes/MoriorGames/Scenes/LogoScene.cpp \
                   ../../../Classes/MoriorGames/Scenes/MainMenuScene.cpp \
                   ../../../Classes/MoriorGames/Scenes/MatchMakerScene.cpp \
                   ../../../Classes/MoriorGames/Scenes/SplashScene.cpp \
                   ../../../Classes/MoriorGames/Screen/ClosestCoordinate.cpp \
                   ../../../Classes/MoriorGames/Screen/Coordinate2Screen.cpp \
                   ../../../Classes/MoriorGames/Screen/Position.cpp \
                   ../../../Classes/MoriorGames/Screen/Resolution.cpp \
                   ../../../Classes/MoriorGames/Screen/ResolutionChecker.cpp \
                   ../../../Classes/MoriorGames/Screen/ScreenProperties.cpp \
                   ../../../Classes/MoriorGames/Services/FontCreator.cpp \
                   ../../../Classes/MoriorGames/Services/HeroesConfigProcessor.cpp \
                   ../../../Classes/MoriorGames/Services/HeroesConfigPublisher.cpp \
                   ../../../Classes/MoriorGames/Services/SoundPlayer.cpp \
                   ../../../Classes/MoriorGames/Services/SpriteAnimator.cpp \
                   ../../../Classes/MoriorGames/Services/SpritesInitializer.cpp \
                   ../../../Classes/MoriorGames/Services/StringFileReader.cpp \
                   ../../../Classes/MoriorGames/Services/TeamSight.cpp \
                   ../../../Classes/MoriorGames/Services/Translator.cpp \
                   ../../../Classes/MoriorGames/Transformers/BattleAction2Json.cpp \
                   ../../../Classes/MoriorGames/Transformers/CampaignEditor.cpp \
                   ../../../Classes/MoriorGames/Transformers/HeroesConfig2Json.cpp \
                   ../../../Classes/MoriorGames/Vendor/Config/StaticBushConfig.cpp \
                   ../../../Classes/MoriorGames/Vendor/Containers/HeroesConfig.cpp \
                   ../../../Classes/MoriorGames/Vendor/Dtos/HeroConfigPayload.cpp \
                   ../../../Classes/MoriorGames/Vendor/Entity/Battle.cpp \
                   ../../../Classes/MoriorGames/Vendor/Entity/BattleAction.cpp \
                   ../../../Classes/MoriorGames/Vendor/Entity/BattleHero.cpp \
                   ../../../Classes/MoriorGames/Vendor/Entity/Hero.cpp \
                   ../../../Classes/MoriorGames/Vendor/Entity/Skill.cpp \
                   ../../../Classes/MoriorGames/Vendor/Entity/SkillHero.cpp \
                   ../../../Classes/MoriorGames/Vendor/Entity/User.cpp \
                   ../../../Classes/MoriorGames/Vendor/Factories/BattleFactory.cpp \
                   ../../../Classes/MoriorGames/Vendor/Factories/BattleHeroInitializer.cpp \
                   ../../../Classes/MoriorGames/Vendor/Factories/PathBuilder.cpp \
                   ../../../Classes/MoriorGames/Vendor/Grid/Grid.cpp \
                   ../../../Classes/MoriorGames/Vendor/Parsers/BattleActionParser.cpp \
                   ../../../Classes/MoriorGames/Vendor/Parsers/BattleParser.cpp \
                   ../../../Classes/MoriorGames/Vendor/Parsers/HeroParser.cpp \
                   ../../../Classes/MoriorGames/Vendor/Parsers/JsonParser.cpp \
                   ../../../Classes/MoriorGames/Vendor/Parsers/SkillHeroParser.cpp \
                   ../../../Classes/MoriorGames/Vendor/Parsers/SkillParser.cpp \
                   ../../../Classes/MoriorGames/Vendor/Parsers/UserParser.cpp \
                   ../../../Classes/MoriorGames/Vendor/Repository/HeroRepository.cpp \
                   ../../../Classes/MoriorGames/Vendor/Repository/SkillHeroRepository.cpp \
                   ../../../Classes/MoriorGames/Vendor/Repository/SkillRepository.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/AI.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/BattleActionChecker.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/BattleHeroSpawner.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/BattleProcessor.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/FitnessCalculator.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/MotionEngine.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/PathFinder.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/PathFinderArea.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/PathFinderShot.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/PlayerSide.cpp \
                   ../../../Classes/MoriorGames/Vendor/Services/Randomizer.cpp \
                   ../../../Classes/MoriorGames/Vendor/ValueObjects/Coordinate.cpp \
                   ../../../Classes/MoriorGames/View/Battle/BattleBackgroundView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/BattleView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/BushView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/EndOfBattle.cpp \
                   ../../../Classes/MoriorGames/View/Battle/GridView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/HeroAnimator.cpp \
                   ../../../Classes/MoriorGames/View/Battle/HeroHitPointsView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/HeroView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/PortraitsView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/SkillsView.cpp \
                   ../../../Classes/MoriorGames/View/Battle/TileDrawer.cpp \
                   ../../../Classes/MoriorGames/View/Buttons/BattleButton.cpp \
                   ../../../Classes/MoriorGames/View/Buttons/BattleHeroesButton.cpp \
                   ../../../Classes/MoriorGames/View/Buttons/MainMenuButton.cpp \
                   ../../../Classes/MoriorGames/View/Buttons/TrainingButton.cpp \
                   ../../../Classes/MoriorGames/View/Custom/BattleInitCustomActions.cpp \
                   ../../../Classes/MoriorGames/View/Custom/PopupBattleHero.cpp \
                   ../../../Classes/MoriorGames/View/HeroesConfig/AbstractFrame.cpp \
                   ../../../Classes/MoriorGames/View/HeroesConfig/HeroesConfigView.cpp \
                   ../../../Classes/MoriorGames/View/HeroesConfig/LeftFrame.cpp \
                   ../../../Classes/MoriorGames/View/HeroesConfig/RightFrame.cpp \
                   ../../../Classes/MoriorGames/View/HeroesConfig/TopHud.cpp \
                   ../../../Classes/MoriorGames/View/BackgroundView.cpp \
                   ../../../Classes/MoriorGames/View/LoadingTitleView.cpp \
                   ../../../Classes/MoriorGames/View/LoadingView.cpp \
                   ../../../Classes/MoriorGames/View/LogoView.cpp \
                   ../../../Classes/MoriorGames/View/MatchMakerView.cpp \
                   ../../../Classes/MoriorGames/View/SplashView.cpp \
                   ../../../Classes/MoriorGames/View/ViewHelper.cpp \
                   ../../../Classes/MoriorGames/View/WorldView.cpp \
                   ../../../Classes/AppDelegate.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
