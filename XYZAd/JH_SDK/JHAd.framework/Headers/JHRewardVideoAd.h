//
//  JHRewardVideoAd.h
//  JHAd
//
//  Created by L66J99E33 on 2019/11/27.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class JHRewardVideoAd;

@protocol JHRewardedVideoAdDelegate <NSObject>

@optional


/**
 广告数据加载成功回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdDidLoad:(JHRewardVideoAd *)rewardedVideoAd;

/**
 视频数据下载成功回调，已经下载过的视频会直接回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdVideoDidLoad:(JHRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页即将展示回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdWillVisible:(JHRewardVideoAd *)rewardedVideoAd;

/**
 视频广告曝光回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdDidExposed:(JHRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdDidClose:(JHRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdDidClicked:(JHRewardVideoAd *)rewardedVideoAd;

/**
 视频广告各种错误信息回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)jh_rewardVideoAd:(JHRewardVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;

/**
 视频广告播放达到激励条件回调

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdDidRewardEffective:(JHRewardVideoAd *)rewardedVideoAd;

/**
 视频广告视频播放完成

 @param rewardedVideoAd JHRewardVideoAd 实例
 */
- (void)jh_rewardVideoAdDidPlayFinish:(JHRewardVideoAd *)rewardedVideoAd;

@end

@interface JHRewardVideoAd : NSObject

@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;
@property (nonatomic, assign, readonly) NSInteger expiredTimestamp;
@property (nonatomic, weak) id <JHRewardedVideoAdDelegate> delegate;

/**
 构造方法

 @param placementId 广告位ID
 @return JHRewardVideoAd 实例
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 加载广告方法 支持 iOS8.1 及以上系统
 */
- (void)loadAd;
/**
 展示广告方法

 @param rootViewController 用于 present 激励视频 VC
 @return 是否展示成功
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
@property (nonatomic, readonly) NSInteger eCPM;

/**
 返回广告的eCPM等级
 
 @return 成功返回一个包含数字的string，@""或nil表示无权限或后台异常
 */
@property (nonatomic, readonly) NSString *eCPMLevel;


/**
 返回广告平台名称

 @return 当使用 google 补余功能时，用于区分广告平台
 */
- (NSString *)adNetworkName;

/**
 *  竞胜之后调用, 需要在调用广告 show 之前调用
 *  @param price - 竞胜价格 (单位: 分)
 */
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/**
 *  竞败之后调用
 *  @param price - 竞胜价格 (单位: 分)
 *  @param reason - 优量汇广告竞败原因
 *  @param adnID - adnID
 */
- (void)sendLossNotificationWithWinnerPrice:(NSInteger)price lossReason:(JHAdBiddingLossReason)reason winnerAdnID:(NSString *)adnID;

@end

NS_ASSUME_NONNULL_END
