//
//  KlevinAdSDK.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/24.
//

#import <Foundation/Foundation.h>
#import <KlevinAdSDK/KLNAdRequest.h>
#import <KlevinAdSDK/KLNSplashAd.h>
#import <KlevinAdSDK/KLNInterstitialAd.h>
#import <KlevinAdSDK/KLNRewardedAd.h>
#import <KlevinAdSDK/KLNAdReward.h>
#import <KlevinAdSDK/KLNFullScreenContentDelegate.h>
#import <KlevinAdSDK/KLNAdVideoController.h>
#import <KlevinAdSDK/KLNAdErrorCode.h>
#import <KlevinAdSDK/KLNAdsDefines.h>
#import <KlevinAdSDK/KLNAdEnumTypes.h>

NS_ASSUME_NONNULL_BEGIN

/// SDK初始化方法回调 [KlevinAdSDK startWithCompletionHandler:]
/// error为空则表示初始化成功，回调非线程安全
typedef void (^KLNAdInitializationCompletionHandler)(NSError *_Nullable error);

/// SDK初始化、设置入口类
@interface KlevinAdSDK : NSObject

/// 当前SDK版本号
+ (NSString *)sdkVersion;

/// 返回KlevinAdSDK实体（单例）
+ (KlevinAdSDK *)sharedInstance;

/// 初始化SDK，从Info.plist 读取KlevinApplicationIdentifier配置
/// 相关配置方式见文档说明：集成及初始化SDK
/// @param completionHandler 初始化结果回调 ，非线程安全
- (void)startWithCompletionHandler:(nullable KLNAdInitializationCompletionHandler)completionHandler;

/// 输出SDK调试信息
- (void)enableDebugLogout;

/// 是否允许获取定位信息，权限需由接入方获取，SDK不会主动弹框申请
/// 基于用户地理信息，系统能推荐更精准的个性化广告，提升广告收益
/// 默认为YES
- (void)enableGPS:(BOOL)enabled;

/// 初始化SDK
/// @param appId 平台注册APPID
/// @param completionHandler 初始化结果回调 ，非线程安全
- (void)startWithAppId:(NSString *)appId withCompletionHandler:(nullable KLNAdInitializationCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
