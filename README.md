BFA AI
======

BFA AI is a videogame (developed for mobile platforms mainly).
The intention of the project is to be able to combine a Strategy Game with some sort of Artificial Intelligence.
I want to create a game that learns how to play in each Match played agains a player.
 

# License

This is an open source project. You can use any of the code or assets for your personal purpose.
If you do so, I will be happy to know about your project. Email me at (moriorgames@gmail.com) with a thanks and I will be more motivated to continue this project :)


# Run on platforms

To run the project on different platforms you have to execute the next command:

```
# Platform: mac || android || ios
$ cocos run -p {platform} -j 4
$ cocos run -p android -j 4
$ cocos run -p ios -j 4
$ cocos run -p mac -j 4
$ cocos run -p android --ap android-16 -m release
$ keytool -keystore clienttmfghr -genkey -alias tmfghrmoriorgames -validity 9999
```


# Debug on Android device

To show the logs on android device you can execute this command:

```
# Android sdk manager
$ cd /usr/local/Cellar/android-sdk/24.4.1_1/tools
$ ./android
# To see android SDk installed APIS
$ android list
$ adb logcat
$ adb logcat | grep cocos2d
$ cocos run -p android && adb logcat | grep cocos2d
$ adb kill-server
$ adb start-server
$ adb devices
$ cocos run -p android --app-abi arm64-v8a
# Compile for android device
$ export JAVA_HOME=$(/usr/libexec/java_home -v 1.8) && cocos compile -p android --android-studio
# Run on android device
$ export JAVA_HOME=$(/usr/libexec/java_home -v 1.8) && cocos run -p android --android-studio
# Run with the no uninstall option if the app is not installed on the device
$ export JAVA_HOME=$(/usr/libexec/java_home -v 1.8) && cocos run -p android --android-studio --no-uninstall
```
