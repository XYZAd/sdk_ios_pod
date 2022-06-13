//
//  XMSplashAdProvider.h
//  XMAd
//
//  Created by 大大东 on 2020/3/19.
//  Copyright © 2020 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XMError;

NS_ASSUME_NONNULL_BEGIN

@protocol XMSplashAdDelegate;

/// 用于请求开盘的Provider
@interface XMSplashAdProvider : NSObject

/// 非全屏开屏广告底部填充试图
@property (nonatomic, strong, nullable) UIView *customSplashBottomView;

/// 开屏代理
@property (nonatomic, weak) id <XMSplashAdDelegate> adDelegate;

/// 广告基本信息
@property (nonatomic, strong, readonly) XMAdMaterialMeta *materialMeta;

/// 是否死等最高价(bidding逻辑才有效)
@property (nonatomic, assign) BOOL splashWaitEcpmHight;

/// 请求开屏广告 （立即展示假的启动图<依次取LaunchStoryboard、LaunchImage>），带block简介版本
/// @param param 广告位 （不可更改，如果广告位不同，请实例化多个本类对象）
/// @param size size (一般为 宽等于屏幕宽 高为屏幕高*0.84, 不能低于屏幕的75%)
/// @param time 最大等待时长（会限制在 2 - 8s）
/// @param completion 回调
- (void)adWithParam:(nonnull XMAdParam *)param
             adsize:(CGSize)size
          totalTime:(CGFloat)time
         completion:(void(^_Nonnull)(BOOL success, XMError *_Nullable error))completion;



/// 展示 (请在广告请求成功后 调用， 否则无效)，带block简介版本
/// @param closeCallback 关闭回调，如果是通过delegate监听，block可不实现
- (void)presentWithCloseHandle:(void(^)(void))closeCallback;


/// 请求开屏广告 （立即展示假的启动图<依次取LaunchStoryboard、LaunchImage>）(纯走delegate)
/// @param param 广告位 （不可更改，如果广告位不同，请实例化多个本类对象）
/// @param size size (一般为 宽等于屏幕宽 高为屏幕高*0.84, 不能低于屏幕的75%),这里注意一下，游可赢的开屏只能是全屏广告，不能自定义size，如果有硬性要求，必须自定义size，则不要配置游可赢云控
/// @param time 最大等待时长（会限制在 2 - 8s）
- (void)loadSplashAdWithParam:(nonnull XMAdParam *)param
                       adsize:(CGSize)size
                    totalTime:(CGFloat)time;


/// 展示广告，在广告请求成功后 调用， 否则无效
- (void)showSplashAd;

/// 取消当前广告加载
- (void)cancel;

/// 广告云控是否有效
- (BOOL)adClouldValidWithPosition:(nullable XMAdPageType *)position;


@end


@protocol XMSplashAdDelegate <NSObject>
@optional

/// 开屏已经加载成功
/// @param provider provider
- (void)splashAdDidLoad:(XMSplashAdProvider *)provider;

/// 开屏失败,一系列失败原因都在该代理中抛出
/// @param provider provider
/// @param error error
- (void)splashAdPresent:(XMSplashAdProvider *)provider
                  error:(XMError *)error;

/// 曝光回调
/// @param provider provider
- (void)splashAdDidExposure:(XMSplashAdProvider *)provider;

/// 点击回调
/// @param provider provider
- (void)splashAdDidClick:(XMSplashAdProvider *)provider;

/// 即将关闭
/// @param provider provider
- (void)splashAdWillClose:(XMSplashAdProvider *)provider;

/// 关闭
/// @param provider provider
- (void)splashAdDidClose:(XMSplashAdProvider *)provider;

/// 关闭详情页回调
/// @param provider provider
- (void)splashAdDetailPageDidClose:(XMSplashAdProvider *)provider;


/// 开屏领取奖励
/// @param provider provider
- (void)splashAdDidRewardEffective:(XMSplashAdProvider *)provider;

@end

NS_ASSUME_NONNULL_END
