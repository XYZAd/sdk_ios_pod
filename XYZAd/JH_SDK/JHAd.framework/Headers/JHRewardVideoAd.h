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
 *
 *  @param winInfo 字典类型，支持的key有
 *  JH_M_W_E_COST_PRICE：竞胜价格 (单位: 分)，值类型为NSNumber *
 *  JH_M_W_H_LOSS_PRICE：最高失败出价，值类型为NSNumber  *
 *
 */
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;

/**
 *  竞败之后调用
 *
 *  @pararm lossInfo 竞败信息，字典类型，支持的key有
 *  JH_M_L_WIN_PRICE ：竞胜价格 (单位: 分)，值类型为NSNumber *
 *  JH_M_L_LOSS_REASON ：优量汇广告竞败原因，竞败原因参考枚举JHAdBiddingLossReason中的定义，值类型为NSNumber *
 *  JH_M_ADNID  ：竞胜方渠道ID，值类型为NSString *
 */
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
