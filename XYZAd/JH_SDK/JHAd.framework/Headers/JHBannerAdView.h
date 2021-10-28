//
//  JHBannerAd.h
//  JHAd
//
//  Created by Liujingjie on 2020/2/8.
//  Copyright © 2020 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  聚合广告推荐尺寸,开发者在嵌入Banner条时，可以手动设置Banner条的宽度用来满足场景需求，
 *  而高度的话广点通侧不建议更改，否则显示效果会有影响
 */
#define JH_AD_SUGGEST_SIZE_320x50    CGSizeMake(320, 50) //For iPhone
#define JH_AD_SUGGEST_SIZE_468x60    CGSizeMake(468, 60) //For iPad
#define JH_AD_SUGGEST_SIZE_728x90    CGSizeMake(728, 90) //For iPad

@class JHBannerAdView;

@protocol JHBannerViewDelegate <NSObject>

@optional

/**
 *  请求广告条数据成功后调用
 *  当接收服务器返回的广告数据成功后调用该函数
 */
- (void)jh_bannerViewDidLoad:(JHBannerAdView *)bannerView;
/**
 *  请求广告条数据失败后调用
 *  当接收服务器返回的广告数据失败后调用该函数
 */
- (void)jh_bannerViewFailedToLoad:(JHBannerAdView *)bannerView error:(NSError *)error;

/**
 *  banner2.0曝光回调
 */
- (void)jh_bannerViewWillExpose:(JHBannerAdView *)bannerView;

/**
 *  banner2.0点击回调
 */
- (void)jh_bannerViewClicked:(JHBannerAdView *)bannerView;

/**
 *  banner2.0广告点击以后即将弹出全屏广告页
 */
- (void)jh_bannerViewWillPresentFullScreenModal:(JHBannerAdView *)bannerView;

/**
 *  banner2.0广告点击以后弹出全屏广告页完毕
 */
- (void)jh_bannerViewDidPresentFullScreenModal:(JHBannerAdView *)bannerView;

/**
 *  全屏广告页即将被关闭
 */
- (void)jh_bannerViewWillDismissFullScreenModal:(JHBannerAdView *)bannerView;

/**
 *  全屏广告页已经被关闭
 */
- (void)jh_bannerViewDidDismissFullScreenModal:(JHBannerAdView *)bannerView;

/**
 *  当点击应用下载或者广告调用系统程序打开
 */
- (void)jh_bannerViewWillLeaveApplication:(JHBannerAdView *)bannerView;

/**
 *  banner2.0被用户关闭时调用
 */
- (void)jh_bannerViewWillClose:(JHBannerAdView *)bannerView;


@end

@interface JHBannerAdView : UIView


/**
 *  委托 [可选]
 */
@property(nonatomic, weak) id<JHBannerViewDelegate> delegate;

/**
 *  Banner展现和轮播时的动画效果开关，默认打开
 */
@property (nonatomic) BOOL animated;

/**
 *  广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。 [可选]
 */
@property (nonatomic) int autoSwitchInterval;

/**
 返回广告的eCPM等级
 
 @return 成功返回一个包含数字的string，@""或nil表示无权限或后台异常
 */
- (NSString *)eCPMLevel;

/**
 *  拉取并展示广告
 */
- (void)loadAdAndShow;

@end

NS_ASSUME_NONNULL_END
