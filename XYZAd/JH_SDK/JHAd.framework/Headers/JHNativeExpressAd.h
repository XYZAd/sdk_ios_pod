//
//  JHNativeExpressAd.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/8.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


@class JHNativeExpressAdView;
@class JHNativeExpressAd;

@protocol JHNativeExpressAdDelegete <NSObject>

@optional
/**
 * 拉取原生模板广告成功
 */
- (void)jh_nativeExpressAdSuccessToLoad:(JHNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof JHNativeExpressAdView *> *)views;

/**
 * 拉取原生模板广告失败
 */
- (void)jh_nativeExpressAdFailToLoad:(JHNativeExpressAd *)nativeExpressAd error:(NSError *)error;

/**
 * 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 */
- (void)jh_nativeExpressAdViewRenderSuccess:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告渲染失败
 */
- (void)jh_nativeExpressAdViewRenderFail:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告曝光回调
 */
- (void)jh_nativeExpressAdViewExposure:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告点击回调
 */
- (void)jh_nativeExpressAdViewClicked:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板广告被关闭
 */
- (void)jh_nativeExpressAdViewClosed:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 点击原生模板广告以后即将弹出全屏广告页
 */
- (void)jh_nativeExpressAdViewWillPresentScreen:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 点击原生模板广告以后弹出全屏广告页
 */
- (void)jh_nativeExpressAdViewDidPresentScreen:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 全屏广告页将要关闭
 */
- (void)jh_nativeExpressAdViewWillDissmissScreen:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 全屏广告页关闭
 */
- (void)jh_nativeExpressAdViewDidDissmissScreen:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 详解:当点击应用下载或者广告调用系统程序打开时调用
 */
- (void)jh_nativeExpressAdViewApplicationWillEnterBackground:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生模板视频广告 player 播放状态更新回调
 */
- (void)jh_nativeExpressAdView:(JHNativeExpressAdView *)nativeExpressAdView playerStatusChanged:(JHMediaPlayerStatus)status;

/**
 * 原生视频模板详情页 WillPresent 回调
 */
- (void)jh_nativeExpressAdViewWillPresentVideoVC:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生视频模板详情页 DidPresent 回调
 */
- (void)jh_nativeExpressAdViewDidPresentVideoVC:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生视频模板详情页 WillDismiss 回调
 */
- (void)jh_nativeExpressAdViewWillDismissVideoVC:(JHNativeExpressAdView *)nativeExpressAdView;

/**
 * 原生视频模板详情页 DidDismiss 回调
 */
- (void)jh_nativeExpressAdViewDidDismissVideoVC:(JHNativeExpressAdView *)nativeExpressAdView;

@end


@interface JHNativeExpressAd : NSObject

/**
 *  委托对象
 */
@property (nonatomic, weak) id<JHNativeExpressAdDelegete> delegate;


/**
 *  非 WiFi 网络，是否自动播放。默认 NO。loadAd 前设置。
 */

@property (nonatomic, assign) BOOL videoAutoPlayOnWWAN;

/**
 *  自动播放时，是否静音。默认 YES。loadAd 前设置。
 */
@property (nonatomic, assign) BOOL videoMuted;

/**
 请求视频的时长上限，有效值范围为[5,60]。
 */
@property (nonatomic) NSInteger maxVideoDuration;


/**
 *  构造方法
 *  详解：placementId - 广告位 ID
 *       adSize - 广告展示的宽高
 *       viewController - 视图控制器
 */

- (instancetype)initWithPlacementId:(NSString *)placementId adSize:(CGSize)size viewController:(UIViewController *)viewController listView:(UIView *)listView;

              

/**加载广告,返回的数量可能比请求加载的数量少*/
- (void)loadAd:(NSInteger)count;

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
