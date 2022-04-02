//
//  XMUniversalAd.h
//  XMAd
//
//  Created by C on 2022/2/22.
//  Copyright © 2022 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>
@class XMImgTextAd;
@class XMVideoAd;
@class XMIntersititialAd;
@class XMFullScreenAd;
@class XMBannerAd;
@class XMSplashAdProvider;

NS_ASSUME_NONNULL_BEGIN

@interface XMUniversalAd : NSObject

/**
 *
 *  具体类型API，请详见具体广告模型
 *
 *
 *
 *
 */

/// 广告类型，返回什么类型的广告，请根据该字段展示相对应的广告
@property (nonatomic, assign, readonly) XMAdPositionAdType positionAdType;


/// 图文广告，当positionAdType为0-4时，有值
@property (nonatomic, strong, readonly, nullable) XMImgTextAd *imgTextAd;

/// 激励视频广告，当positionAdType为6时，有值
@property (nonatomic, strong, readonly, nullable) XMVideoAd *rewardVideoAd;

/// 全屏视频广告，当positionAdType为7时，有值
@property (nonatomic, strong, readonly, nullable) XMFullScreenAd *fullScreenAd;

/// 插屏广告，当positionAdType为8-9时，有值
@property (nonatomic, strong, readonly, nullable) XMIntersititialAd *intersititialAd;

/// 模版banner广告，当positionAdType为5时，有值
@property (nonatomic, strong, readonly, nullable) XMBannerAd *bannerAd;

/// 开屏广告，当positionAdType为10时，有值
@property (nonatomic, weak, readonly, nullable) XMSplashAdProvider *splashProvider;





@end

NS_ASSUME_NONNULL_END
