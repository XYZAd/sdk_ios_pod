//
//  JHInterstitialAd.h
//  JHAd
//
//  Created by Liujingjie on 2020/2/8.
//  Copyright © 2020 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@class JHInterstitialAd;
@protocol JHInterstitialDelegate <NSObject>

@optional

/**
 *  广告预加载成功回调
 *  详解:当接收服务器返回的广告数据成功且预加载后调用该函数
 */
- (void)jh_interstitialSuccessToLoadAd:(JHInterstitialAd *)interstitialAd;

/**
 *  广告预加载失败回调
 *  详解:当接收服务器返回的广告数据失败后调用该函数
 */
- (void)jh_interstitialFailToLoadAd:(JHInterstitialAd *)interstitialAd error:(NSError *)error;

/**
 *  插屏广告将要展示回调
 *  详解: 插屏广告即将展示回调该函数
 */
- (void)jh_interstitialWillPresentScreen:(JHInterstitialAd *)interstitialAd;

/**
 *  插屏广告视图展示成功回调
 *  详解: 插屏广告展示成功回调该函数
 */
- (void)jh_interstitialDidPresentScreen:(JHInterstitialAd *)interstitialAd;
/**
 * 插屏广告视图展示失败回调
 * 详解：插屏广告展示失败回调该函数
 */
- (void)jh_interstitialFailToPresent:(JHInterstitialAd *)interstitialAd error:(NSError *)error;
/**
 *  插屏广告展示结束回调
 *  详解: 插屏广告展示结束回调该函数
 */
- (void)jh_interstitialDidDismissScreen:(JHInterstitialAd *)interstitialAd;

/**
 *  详解:当点击应用下载或者广告调用系统程序打开时调用
 */
- (void)jh_interstitialApplicationWillEnterBackground:(JHInterstitialAd *)interstitialAd;

/**
 *  插屏广告曝光回调
 */
- (void)jh_interstitialWillExposure:(JHInterstitialAd *)interstitialAd;

/**
 *  插屏广告点击回调
 */
- (void)jh_interstitialClicked:(JHInterstitialAd *)interstitialAd;

/**
 *  点击插屏广告以后即将弹出全屏广告页
 */
- (void)jh_interstitialAdWillPresentFullScreenModal:(JHInterstitialAd *)interstitialAd;

/**
 *  点击插屏广告以后弹出全屏广告页
 */
- (void)jh_interstitialAdDidPresentFullScreenModal:(JHInterstitialAd *)interstitialAd;

/**
 *  全屏广告页将要关闭
 */
- (void)jh_interstitialAdWillDismissFullScreenModal:(JHInterstitialAd *)interstitialAd;

/**
 *  全屏广告页被关闭
 */
- (void)jh_interstitialAdDidDismissFullScreenModal:(JHInterstitialAd *)interstitialAd;

/**
 * 插屏2.0视频广告 player 播放状态更新回调
 */
- (void)jh_interstitialAd:(JHInterstitialAd *)interstitialAd playerStatusChanged:(JHMediaPlayerStatus)status;

/**
 * 插屏2.0视频广告详情页 WillPresent 回调
 */
- (void)jh_interstitialAdViewWillPresentVideoVC:(JHInterstitialAd *)interstitialAd;

/**
 * 插屏2.0视频广告详情页 DidPresent 回调
 */
- (void)jh_interstitialAdViewDidPresentVideoVC:(JHInterstitialAd *)interstitialAd;

/**
 * 插屏2.0视频广告详情页 WillDismiss 回调
 */
- (void)jh_interstitialAdViewWillDismissVideoVC:(JHInterstitialAd *)interstitialAd;

/**
 * 插屏2.0视频广告详情页 DidDismiss 回调
 */
- (void)jh_interstitialAdViewDidDismissVideoVC:(JHInterstitialAd *)interstitialAd;


@end

@interface JHInterstitialAd : NSObject


/**
 *  委托对象
 */
@property (nonatomic, weak) id<JHInterstitialDelegate> delegate;


/**
 *  非 WiFi 网络，是否自动播放。默认 NO。loadAd 前设置。
 */

@property (nonatomic, assign) BOOL videoAutoPlayOnWWAN;

/**
 *  自动播放时，是否静音。默认 YES。loadAd 前设置。
 */
@property (nonatomic, assign) BOOL videoMuted;


/**
 *  视频详情页播放时是否静音。默认NO。loadAd 前设置。
 */
@property (nonatomic, assign) BOOL detailPageVideoMuted;

/**
 请求视频的时长下限，视频时长有效值范围为[5,60]。
 以下两种情况会使用系统默认的最小值设置，1:不设置  2:minVideoDuration大于maxVideoDuration
*/
@property (nonatomic) NSInteger minVideoDuration;

/**
 请求视频的时长上限，视频时长有效值范围为[5,60]。
 */
@property (nonatomic) NSInteger maxVideoDuration;

/**
 * 是否是视频插屏2.0广告
 */
@property (nonatomic, assign, readonly) BOOL isVideoAd;

/**
 *  插屏广告预加载是否完成
 */
@property (nonatomic, readonly) BOOL isAdValid;

/**
 * 视频插屏2.0广告时长，单位 ms
 */
- (CGFloat)videoDuration;

/**
 * 视频插屏广告已播放时长，单位 ms
 */
- (CGFloat)videoPlayTime;

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
 构造方法

 @param placementId 广告位ID
 @return JHInterstitialAd 实例
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 *  广告发起请求方法
 *  详解：[必选]发起拉取广告请求
 */
- (void)loadAd;

/**
 *  广告展示方法
 *  详解：[必选]发起展示广告请求, 必须传入用于显示插播广告的UIViewController
 */
- (void)presentFromRootViewController:(UIViewController *)rootViewController;

/**
 *  全屏视频广告发起请求方法
 *  详解：[必选]发起拉取广告请求
 */
- (void)loadFullScreenAd;

/**
 *  全屏视频广告展示方法
 *  详解：[必选]发起展示广告请求, 必须传入用于显示插播广告的UIViewController
 */
- (void)presentFullScreenAdFromRootViewController:(UIViewController *)rootViewController;

/**
 * 加载自定义大小的插屏,必须大于100*150
 */
- (void)loadUsingSize:(CGRect)rect;

/**
 * 展示自定义大小的插屏
 */
- (void)presentFromView:(UIView *)view;

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
