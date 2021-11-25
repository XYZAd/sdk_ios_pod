//
//  XMNewInterstitialAd.h
//  XMAd
//
//  Created by C on 2021/11/8.
//  Copyright © 2021 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>


@class XMAdModel;
@class XMAdMaterialMeta;
@protocol XMNewIntersititialAdDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface XMNewInterstitialAd : NSObject


- (instancetype)initWithModel:(XMAdModel *)model;

@property (nonatomic, strong, readonly) XMAdModel *adModel;

/// 是否有效
@property (nonatomic, assign, readonly) BOOL effective;

/// 插屏代理
@property (nonatomic, weak) id <XMNewIntersititialAdDelegate> adDelegate;

/// 广告基本信息
@property (nonatomic, strong, readonly) XMAdMaterialMeta *materialMeta;


/// 展示新插屏
/// @param rootVC  根试图控制器
/// @param completion      播放结束的回调
- (BOOL)showNewIntersititialAdFromRootVC:(UIViewController *)rootVC
                         closeCompletion:(void (^)(void))completion;

@end

@protocol XMNewIntersititialAdDelegate <NSObject>
@optional
/// 曝光回调
- (void)newIntersititialAdDidExposure:(XMNewInterstitialAd *)ad;

/// 点击回调
- (void)newIntersititialAdDidClick:(XMNewInterstitialAd *)ad;

/// 关闭
- (void)newIntersititialAdDidClose:(XMNewInterstitialAd *)ad;

/// 关闭详情页回调
- (void)newIntersititialAdDetailPageDidClose:(XMNewInterstitialAd *)ad;

@end


NS_ASSUME_NONNULL_END
