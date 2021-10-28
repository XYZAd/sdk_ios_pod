//
//  KLNAdRequest.h
//  KlevinAdSDK
//
//  Copyright © 2021 Tencent. All rights reserved.
//  Created by Klevin on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 请求对象基类，请勿直接使用
@interface KLNAdRequest : NSObject

/// 广告位ID
@property (nonatomic, copy, readonly) NSString *posId;

/// 请求ID
@property (nonatomic, copy, readonly) NSString *requestId;

- (instancetype)initWithPosId:(NSString *)posId;

@end

/// 开屏广告请求对象
@interface KLNSplashAdRequest : KLNAdRequest
/// 超时时长
@property (nonatomic) NSUInteger timeout;
@end

/// 插屏广告请求对象
@interface KLNInterstitialAdRequest : KLNAdRequest
@end

/// 激励视频请求对象
@interface KLNRewardedAdRequest : KLNAdRequest

/// 激励视频播放是否自动静音
/// @discussion 不设置，默认NO，非静音播放
@property (nonatomic) BOOL autoMute;

/// 触发的激励类型，1：复活；2：签到；3：道具；4：虚拟货币；5：其他
/// @discussion 不设置，则默认为5
@property (nonatomic) NSUInteger rewardTrigger;

/// 激励卡秒时长
/// @discussion 默认为视频时长/赋值大于视频时长或者为非正数时，SDK以视频时长为准
@property (nonatomic) NSUInteger rewardTime;

@end


/// 原生模版广告请求对象
@interface KLNUnifiedNativeAdRequest : KLNAdRequest

/// 一次请求自渲染广告个数，推荐请求1-3个，一次最多请求10个。
@property (nonatomic, assign) NSUInteger adCount;

@end

NS_ASSUME_NONNULL_END
