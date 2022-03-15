//
//  XMFullScreenAd.h
//  XMAd
//
//  Created by C on 2021/8/16.
//  Copyright © 2021 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@class XMAdModel;
@class XMAdMaterialMeta;
@protocol XMFullScreenAdDelegate;

@interface XMFullScreenAd : NSObject

- (instancetype)initWithModel:(XMAdModel *)model;

@property (nonatomic, strong, readonly) XMAdModel *adModel;

/// 是否有效
@property (nonatomic, assign, readonly) BOOL effective;

/// 代理
@property (nonatomic, weak) id <XMFullScreenAdDelegate> adDelegate;

/// 广告基本信息
@property (nonatomic, strong, readonly) XMAdMaterialMeta *materialMeta;

/// 是否静音播放
@property (nonatomic, assign) BOOL videoMuted;


/// 展示全屏广告，该广告，SDK内部会持有，播放结束后会自动销毁，外部不需要持有
/// @param rootVC       根试图控制器
/// @param completion   播放结束的回调
- (BOOL)showFullScreenAdFromRootVC:(UIViewController *)rootVC
                   closeCompletion:(void (^)(BOOL success, NSString * _Nullable errMsg))completion;

@end

@protocol XMFullScreenAdDelegate <NSObject>
@optional

/// 展示失败
/// @param ad ad
/// @param error error
- (void)fullScreenAdPresentFaild:(XMFullScreenAd *)ad error:(XMError *)error;

/// 曝光回调
/// @param ad ad
- (void)fullScreenAdDidExposure:(XMFullScreenAd *)ad;

/// 点击回调
/// @param ad ad
- (void)fullScreenAdDidClick:(XMFullScreenAd *)ad;

/// 关闭
/// @param ad ad
- (void)fullScreenAdDidClose:(XMFullScreenAd *)ad;

/// 关闭详情页回调
/// @param ad ad
- (void)fullScreenAdDetailPageDidClose:(XMFullScreenAd *)ad;

@end
NS_ASSUME_NONNULL_END
