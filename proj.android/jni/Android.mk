LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libBFAI

LOCAL_SRC_FILES := projectbfai/main.cpp \
                   ../../Classes/MoriorGames/Scenes/BattleScene.cpp \
                   ../../Classes/MoriorGames/Scenes/LogoScene.cpp \
                   ../../Classes/MoriorGames/Scenes/MainMenuScene.cpp \
                   ../../Classes/MoriorGames/Scenes/SplashScene.cpp \
                   ../../Classes/MoriorGames/Screen/Position.cpp \
                   ../../Classes/MoriorGames/Screen/Resolution.cpp \
                   ../../Classes/MoriorGames/Screen/ScreenProperties.cpp \
                   ../../Classes/MoriorGames/Services/FontCreator.cpp \
                   ../../Classes/MoriorGames/Services/SoundPlayer.cpp \
                   ../../Classes/MoriorGames/Services/SpriteAnimator.cpp \
                   ../../Classes/MoriorGames/Services/SpritesInitializer.cpp \
                   ../../Classes/MoriorGames/View/Buttons/BattleButton.cpp \
                   ../../Classes/MoriorGames/View/BackgroundView.cpp \
                   ../../Classes/MoriorGames/View/BattleBackgroundView.cpp \
                   ../../Classes/MoriorGames/View/LoadingView.cpp \
                   ../../Classes/MoriorGames/View/LogoView.cpp \
                   ../../Classes/MoriorGames/View/SplashView.cpp \
                   ../../Classes/MoriorGames/View/ViewHelper.cpp \
                   ../../Classes/MoriorGames/View/WorldView.cpp \
                   ../../Classes/AppDelegate.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
