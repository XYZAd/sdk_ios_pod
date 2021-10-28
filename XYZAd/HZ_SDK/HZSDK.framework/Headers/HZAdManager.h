//
//  HZAdManager.h
//  HZSDK
//
//  Created by C on 2021/3/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HZSDKLogLevel) {
    HZSDKLogLevelNone,
    HZSDKLogLevelError,
    HZSDKLogLevelDebug
};


@interface HZAdManager : NSObject



+ (void)initHZSdk;


+ (NSString *)sdkVersion;


+ (void)setSDKLogLevel:(HZSDKLogLevel)logLevel;

/**
 在播放音频时是否使用SDK内部对AVAudioSession设置的category及options，默认使用，若不使用，SDK内部不做任何处理，由调用方在展示广告时自行设置；
 SDK设置的category为AVAudioSessionCategoryAmbient，options为AVAudioSessionCategoryOptionDuckOthers
 */
+ (void)enableDefaultAudioSessionSetting:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
