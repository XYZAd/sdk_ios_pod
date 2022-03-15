//
//  XMVideoAd.h
//  XMAd
//
//  Created by 大大东 on 2019/12/26.
//  Copyright © 2019 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMVideoExtraProtocol.h>


@class XMAdModel;
@class XMAdMaterialMeta;
@class XMError;
NS_ASSUME_NONNULL_BEGIN

@protocol XMVideoAdDelegate;

@interface XMVideoAd : NSObject <XMVideoExtraDelegate>

- (instancetype)initWithModel:(XMAdModel *)model;

@property (nonatomic, strong, readonly) XMAdModel *adModel;

/// 是否有效
@property (nonatomic, assign, readonly) BOOL effective;

/// 播放代理
@property (nonatomic, weak) id <XMVideoAdDelegate> adDelegate;

/// 是否静音播放
@property (nonatomic, assign) BOOL videoMuted;

/// 是否是在看一次的奖励（穿山甲才有），默认是false，没有在看一次
@property (nonatomic, assign, readonly) BOOL againVideoReward;

/// 广告基本信息
@property (nonatomic, strong, readonly) XMAdMaterialMeta *materialMeta;

/// 播放激励视频，该广告，SDK内部会持有，播放结束后会自动销毁，外部不需要持有
/// @param viewController  使用这个vc进行模态
/// @param completion      播放结束的回调, 如果errmsg存在，可以toust提示
- (BOOL)playAdFromVC:(UIViewController *)viewController
      playCompletion:(void (^)(BOOL success, NSString * _Nullable errMsg))completion;

@end

@protocol XMVideoAdDelegate <NSObject>
@optional

/// 展示失败
/// @param ad ad
/// @param error error
- (void)videoAdPresentFaild:(XMVideoAd *)ad error:(XMError *)error;

/// 曝光回调
/// @param ad ad
- (void)videoAdDidExposure:(XMVideoAd *)ad;

/// 点击回调
/// @param ad ad
- (void)videoAdDidClick:(XMVideoAd *)ad;

/// 关闭
/// @param ad ad
- (void)videoAdDidClose:(XMVideoAd *)ad;

/// 视频播放结束回调
/// @param finished 是否播放结束
/// @param error 如果播放失败，会有error信息抛出，若没有，则是成功
- (void)videoAdPlayFinished:(BOOL)finished
                      error:(XMError *)error;

/// 视频上方自定义额外的试图，例如vip充值可跳过广告(慎用),注意：UnityAd、AdColony、IronSource广告不支持下面功能（- (void)videoAdCustomExtraView:,- (BOOL)videoAdCustomExtraViewAlwaysOnContainer:,- (void)videoAdExtraViewDidClick: controller:）
/// @param ad ad
- (UIView *)videoAdCustomExtraView:(XMVideoAd *)ad;

/// 自定义试图是否常驻激励视频（无论是播放时，还是播放结束），默认false
/// @param ad ad
- (BOOL)videoAdCustomExtraViewAlwaysOnContainer:(XMVideoAd *)ad;

/// 额外的视频被点击
/// @param ad ad
/// @param vc 用来presenter的vc
- (void)videoAdExtraViewDidClick:(XMVideoAd *)ad
                      controller:(UIViewController *)vc;

@end


NS_ASSUME_NONNULL_END
