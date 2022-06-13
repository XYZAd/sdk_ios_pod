//
//  JHUnifiedNativeAdView.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/26.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JHAd/JHLogoView.h>
#import <JHAd/JHMediaView.h>
#import <JHAd/JHUnifiedNativeAdDataObject.h>

NS_ASSUME_NONNULL_BEGIN

@class JHUnifiedNativeAdView;

//视频广告时长 abKey
//extern NSString* const kJHUnifiedNativeAdKeyVideoDuration;

@protocol JHUnifiedNativeAdViewDelegate <NSObject>

@optional
/**
 广告曝光回调

 @param unifiedNativeAdView JHUnifiedNativeAdView 实例
 */
- (void)jh_unifiedNativeAdViewWillExpose:(JHUnifiedNativeAdView *)unifiedNativeAdView;


/**
 广告点击回调

 @param unifiedNativeAdView JHUnifiedNativeAdView 实例
 */
- (void)jh_unifiedNativeAdViewDidClick:(JHUnifiedNativeAdView *)unifiedNativeAdView;


/**
 广告详情页关闭回调

 @param unifiedNativeAdView JHUnifiedNativeAdView 实例
 */
- (void)jh_unifiedNativeAdDetailViewClosed:(JHUnifiedNativeAdView *)unifiedNativeAdView;


/**
 当点击应用下载或者广告调用系统程序打开时调用
 
 @param unifiedNativeAdView JHUnifiedNativeAdView 实例
 */
- (void)jh_unifiedNativeAdViewApplicationWillEnterBackground:(JHUnifiedNativeAdView *)unifiedNativeAdView;


/**
 广告详情页面即将展示回调

 @param unifiedNativeAdView JHUnifiedNativeAdView 实例
 */
- (void)jh_unifiedNativeAdDetailViewWillPresentScreen:(JHUnifiedNativeAdView *)unifiedNativeAdView;


/**
 视频广告播放状态更改回调

 @param unifiedNativeAdView 实例
 @param status 视频广告播放状态
 @param userInfo 视频广告信息
 */
- (void)jh_unifiedNativeAdView:(JHUnifiedNativeAdView *)unifiedNativeAdView playerStatusChanged:(JHMediaPlayerStatus)status userInfo:(NSDictionary *)userInfo;
@end



@interface JHUnifiedNativeAdView:UIView

/**
 绑定的数据对象
 */
@property (nonatomic, strong, readonly) JHUnifiedNativeAdDataObject *dataObject;

/**
 视频广告的媒体View，绑定数据对象后自动生成，可自定义布局
 */
@property (nonatomic, strong, readonly) JHMediaView *mediaView;

/**
 腾讯广告 LogoView，自动生成，可自定义布局
 */
@property (nonatomic, strong, readonly) JHLogoView *logoView;

/**
 广告 View 时间回调对象
 */
@property (nonatomic, weak) id<JHUnifiedNativeAdViewDelegate> delegate;

/*
 *  viewControllerForPresentingModalView
 *  详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;

/**
 删除控件 媒体额外添加的删除控件 
 */
@property (nonatomic, weak) UIView *deleteView;

/**
 自渲染2.0视图注册方法
 
 @param dataObject 数据对象，必传字段
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
  注意：如果是视频信息流，请注意传给clickableViews的view不要重叠，否则会造成视频详情页上方视频播放部分黑屏，
       如果不确定clickableViews是否重叠，请直接调用没有clickableViews参数的注册方法
 */
- (void)registerDataObject:(JHUnifiedNativeAdDataObject *)dataObject
            clickableViews:(NSArray<UIView *> *)clickableViews;

/**
 自渲染2.0视图注册方法
 
 @param dataObject 数据对象，必传字段
 */
- (void)registerDataObject:(JHUnifiedNativeAdDataObject *)dataObject;



/**
 注册可点击的callToAction视图的方法
 建议开发者使用JHUnifiedNativeAdDataObject中的callToAction字段来创建视图，并取代自定义的下载或打开等button,
 调用此方法之前必须先调用registerDataObject:clickableViews
 @param callToActionView CTA视图, 系统自动处理点击事件
 */
- (void)registerClickableCallToActionView:(UIView *)callToActionView;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 JHUnifiedNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 JHUnifiedNativeAdView 解绑，具体可参考示例 demo 的 UnifiedNativeAdBaseTableViewCell 类
 */
- (void)unregisterDataObject;

@end

NS_ASSUME_NONNULL_END
