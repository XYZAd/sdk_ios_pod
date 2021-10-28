//
//  HZRewardVideoAd.h
//  HZSDK
//
//  Created by C on 2021/3/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol HZRewardedVideoAdDelegate;

@interface HZRewardVideoAd : NSObject

@property (nonatomic, assign, readonly) BOOL adValid;
@property (nonatomic, assign) BOOL videoMuted;
@property (nonatomic, weak) id <HZRewardedVideoAdDelegate> delegate;
@property (nonatomic, copy, readonly) NSString *placementId;
@property (nonatomic, copy, readonly) NSString *appId;


/**
 构造方法
 @param appId - 媒体 ID
 @param placementId - 广告位 ID
 @return HZRewardVideoAd 实例
 */
- (instancetype)initWithAppId:(NSString *)appId placementId:(NSString *)placementId;


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
 返回广告的eCPM等级
 
 @return 成功返回一个包含数字的string，@""或nil表示无权限或后台异常
 */
- (NSString *)eCPMLevel;


@end

@protocol HZRewardedVideoAdDelegate <NSObject>

@optional


/**
 广告数据加载成功回调

 @param rewardedVideoAd HZRewardVideoAd 实例
 */
- (void)hz_rewardVideoAdDidLoad:(HZRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页即将展示回调

 @param rewardedVideoAd HZRewardVideoAd 实例
 */
- (void)hz_rewardVideoAdWillVisible:(HZRewardVideoAd *)rewardedVideoAd;
/**
 视频广告曝光回调

 @param rewardedVideoAd HZRewardVideoAd 实例
 */
- (void)hz_rewardVideoAdDidExposed:(HZRewardVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭回调

 @param rewardedVideoAd HZRewardVideoAd 实例
 */
- (void)hz_rewardVideoAdDidClose:(HZRewardVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击回调

 @param rewardedVideoAd HZRewardVideoAd 实例
 */
- (void)hz_rewardVideoAdDidClicked:(HZRewardVideoAd *)rewardedVideoAd;

/**
 视频广告各种错误信息回调

 @param rewardedVideoAd HZRewardVideoAd 实例
 @param error 具体错误信息
 */
- (void)hz_rewardVideoAd:(HZRewardVideoAd *)rewardedVideoAd didFailWithError:(HZError *)error;


/**
 视频广告视频播放完成

 @param rewardedVideoAd HZRewardVideoAd 实例
 */
- (void)hz_rewardVideoAdDidPlayFinish:(HZRewardVideoAd *)rewardedVideoAd;

@end

NS_ASSUME_NONNULL_END
