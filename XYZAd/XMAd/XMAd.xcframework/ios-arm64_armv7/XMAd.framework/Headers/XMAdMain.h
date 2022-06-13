//
//  XMAdMain.h
//  XMAd
//
//  Created by 大大东 on 2019/12/12.
//  Copyright © 2019 大大东. All rights reserved.
//


#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface XMPreInitInfo : NSObject
@property (nonatomic, copy, readonly) NSString *appId;
@property (nonatomic, copy, readonly) NSString *appKey;
@property (nonatomic, copy, readonly) NSString *productId;// sigmob的 s2s功能必填

- (instancetype)initWithAppid:(nonnull NSString *)appid appKey:(nonnull NSString *)appKey productId:(nullable NSString *)productId;

@end

/// ⚠️ 预初始化三方SDK配置 <option>  (注意 设置哪个appid就会初始化哪个三方sdk)
@interface XMPreInitSDKAppids : NSObject

/// 穿山甲appid
@property (nonatomic, copy, nullable) NSString *bu_appid;

/// 广点通appid
@property (nonatomic, copy, nullable) NSString *gdt_appid;

/// 禾赞appid
@property (nonatomic, copy, nullable) NSString *hz_appid;

/// 游可赢appid
@property (nonatomic, copy, nullable) NSString *yky_appid;

/// 快手appid
@property (nonatomic, copy, nullable) NSString *ks_appid;

/// 百度appid
@property (nonatomic, copy, nullable) NSString *bd_appid;

/// 京东广告appid
@property (nonatomic, copy, nullable) NSString *jd_appid;

/// AdColony appid
@property (nonatomic, copy, nullable) NSString *acy_appid;

/// ironsource appid
@property (nonatomic, copy, nullable) NSString *is_appid;

/// UMeng appkey
@property (nonatomic, copy, nullable) NSString *um_appKey;

/// UnityAd appid
@property (nonatomic, copy, nullable) NSString *unity_appid;

/// Vungle appid
@property (nonatomic, copy, nullable) NSString *vungle_appid;

/// MTG`s appid(坑爹的玩意)
@property (nonatomic, strong, nullable) XMPreInitInfo *mtgInfo;

/// SigMobSdk
@property (nonatomic, strong, nullable) XMPreInitInfo *smInfo;
@end



@interface XMAdConfig : NSObject

/// 获取广告配置 <required>
/// (注意 这是强引用)
@property (nonatomic, strong) id<XMAdConfigBridge> adConfigBridge;

/// 配置三方SDK提前初始化 <option>
/// 正常初始化三方SDK的时机, 是在业务发起对应请求时触发, 可能某些三方SDK会出现配置拉取慢/广告返回慢/首次无返回等问题
/// 通过此配置可选择 在XMAd初始化后 立即开始初始化指定的三方SDK 以避免上述问题
@property (nonatomic, strong, nullable) XMPreInitSDKAppids *appids;

/// 是否关闭上报启动日志和在线时长日志  YES: 关闭  NO : 开启
@property(nonatomic, assign) BOOL closeOpenLog;

@end




@interface XMAdMain : NSObject

/// 初始化方法
+ (void)admainWithConf:(XMAdConfig *)config;

/// 必须先使用上面的方法初始化后 才能访问此属性 否则throw exception
@property (nonatomic, strong, readonly, class) XMAdMain *admain;

/// 初始化配置参数
@property (nonatomic, strong, readonly) XMAdConfig *config;

/// 版本号
@property (nonatomic, copy, class, readonly) NSString *sdkVersion;



#pragma mark - 内部使用 请忽略
/// YES: 标记从后台回到APP , NO: 冷启动
@property (nonatomic, assign, readonly) BOOL hotOpenApp;

@end

NS_ASSUME_NONNULL_END
