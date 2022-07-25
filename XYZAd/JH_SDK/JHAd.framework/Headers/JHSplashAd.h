//
//  JHSplashAd.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/7.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class JHSplashAd;

@protocol JHSplashAdDelegate <NSObject>

@optional
/**
 *  开屏广告成功展示
 */
- (void)jh_splashAdSuccessPresentScreen:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告素材加载成功
 */
- (void)jh_splashAdDidLoad:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告展示失败
 */
- (void)jh_splashAdFailToPresent:(JHSplashAd * __nullable)splashAd withError:(NSError *)error;

/**
 *  应用进入后台时回调
 *  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
 */
- (void)jh_splashAdApplicationWillEnterBackground:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告曝光回调
 */
- (void)jh_splashAdExposured:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告点击回调
 */
- (void)jh_splashAdClicked:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告将要关闭回调
 */
- (void)jh_splashAdWillClosed:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告关闭回调
 */
- (void)jh_splashAdClosed:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告点击以后即将弹出全屏广告页
 */
- (void)jh_splashAdWillPresentFullScreenModal:(JHSplashAd * __nullable)splashAd;

/**
 *  开屏广告点击以后弹出全屏广告页
 */
- (void)jh_splashAdDidPresentFullScreenModal:(JHSplashAd * __nullable)splashAd;

/**
 *  点击以后全屏广告页将要关闭
 */
- (void)jh_splashAdWillDismissFullScreenModal:(JHSplashAd * __nullable)splashAd;

/**
 *  点击以后全屏广告页已经关闭
 */
- (void)jh_splashAdDidDismissFullScreenModal:(JHSplashAd * __nullable)splashAd;

/**
 * 开屏广告剩余时间回调
 */
- (void)jh_splashAdLifeTime:(NSUInteger)time splashAd:(JHSplashAd *__nullable)splashAd;


/**
 开屏激励回调 (只有开屏激励广告位才会有此回调)
 @param splashAd  JHSplashAd 实例
 @param info 包含此次广告行为的一些信息，例如 @{@"JH_TRANS_ID":@"930f1fc8ac59983bbdf4548ee40ac353"}, 通过@“GDT_TRANS_ID”可获取此次广告行为的交易id
 */
- (void)jh_splashAdDidRewardEffective:(JHSplashAd *)splashAd info:(NSDictionary *)info;

@end





@interface JHSplashAd : NSObject

/**
 *  委托对象
 */
@property (nonatomic, weak) id<JHSplashAdDelegate> delegate;

/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) NSInteger fetchDelay;

/**
 *  开屏广告的背景图片
 *  可以设置背景图片作为开屏加载时的默认背景
 */
@property (nonatomic, strong) UIImage *backgroundImage;

/**
 *  开屏广告的背景色
 *  可以设置开屏图片来作为开屏加载时的默认图片
 */
@property (nonatomic, copy) UIColor *backgroundColor;

/**
 * 跳过按钮的位置
 */
@property (nonatomic, assign) CGPoint skipButtonCenter;

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
 *  构造方法
 *  详解：placementId - 广告位 ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;
/**
 * 返回广告是否可展示
 * @return 当广告已经加载完成且未曝光时，为YES，否则为NO
 */
- (BOOL)isAdValid;

/**
 *  广告发起请求并展示在Window中
 *  详解：[可选]发起拉取广告请求,并将获取的广告以全屏形式展示在传入的Window参数中
 *  提示: Splash广告只支持竖屏
 *  @param window 展示全屏开屏的容器
 */
- (void)loadAdAndShowInWindow:(UIWindow *)window;

/**
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面或是自定义View
 *  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *       请注意1.bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。2.Splash广告只支持竖屏
 *  @param window 展示开屏的容器
 *         bottomView 自定义底部View，可以在此View中设置应用Logo
 */
- (void)loadAdAndShowInWindow:(UIWindow *)window withBottomView:(UIView *__nullable)bottomView;

/**
 *  加载并渲染广告
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面或是自定义View,skipView是自定义的“跳过”样式
 *  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *       请注意1.bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。2.Splash广告只支持竖屏
 *  skipView
 *  @param window 展示开屏的容器
 *         bottomView 自定义底部View，可以在此View中设置应用Logo
           skipView 自定义”跳过“View.
 */
- (void)loadAdAndShowInWindow:(UIWindow *)window withBottomView:(UIView *__nullable)bottomView skipView:(UIView *__nullable)skipView;

/**
 *  加载广告数据
 */
-(void)loadAd;

/**
 *  渲染广告
 *  广告发起请求并展示在Window中, 同时在屏幕底部设置应用自身的Logo页面或是自定义View,skipView是自定义的“跳过”样式
 *  详解：[可选]发起拉取广告请求,并将获取的广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *       请注意1.bottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%。2.Splash广告只支持竖屏
 *  skipView
 *  @param window 展示开屏的容器
 *         bottomView 自定义底部View，可以在此View中设置应用Logo
          skipView 自定义”跳过“View.
*/
-(void)showInWindow:(UIWindow *)window withBottomView:(UIView *)bottomView skipView:(UIView *__nullable)skipView;



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
