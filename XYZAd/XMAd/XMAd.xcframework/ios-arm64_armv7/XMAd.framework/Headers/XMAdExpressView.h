//
//  XMAdExpressView.h
//  XMAd
//
//  Created by C on 2022/1/25.
//  Copyright © 2022 XMAd. All rights reserved.
//

#import <UIKit/UIKit.h>

@class XMVideoConfig;
@class XMExpressAttributed;

NS_ASSUME_NONNULL_BEGIN

/// 该枚举只针对海外SDK，即FBSDK、GADSDK有效
typedef NS_ENUM(NSInteger, XMExpressImgAdViewRenderSize) {
    XMExpressImgAdViewRenderSize_Small        ,///小尺寸
    XMExpressImgAdViewRenderSize_Medium       ,///中尺寸
};

@interface XMAdExpressView : UIView

/// 下面两个属性共存，渲染尺寸类型，只针对于FBSDK、GADSDK，若不接谷歌和脸书，则忽略
@property (nonatomic, assign) XMExpressImgAdViewRenderSize renderSize;
@property (nonatomic, strong) XMExpressAttributed *attributed;

/**
 * 视频配置（default is null）
 */
@property (nonatomic, strong) XMVideoConfig *videoConfig;


/*
 required.
 Root view controller for handling ad actions.
 */
@property (nonatomic, weak) UIViewController * rootViewController;

/**
 是否是视频广告（MTG不返回类型，无法判别，默认false）

 */
@property (nonatomic, assign, readonly) BOOL isVideo;


/**
 当前播放时长（注意，只有穿山甲、广点通、百度贴片、万裕有该参数，其他获取为0）

 @return 视频播放时长
 */
- (NSTimeInterval)currentTime;


/**
 视频总时长（注意，只有穿山甲、广点通、百度、万裕有该参数，其他获取为0）

 @return 视频总时长
 */
- (NSTimeInterval)duration;


/**
 开始渲染广告
 
 */
- (void)renderAdIfNeed;

/**
 移除广告渲染
 
 */
- (void)unRender;


/**
 * @brief 重新布局.动画式变化,例如根据触发时目前新尺寸，用于横竖屏切换（主要是百度广告用）
 *
 * @param duration 动画时长
 * @param frame 目标的尺寸
 */
- (void)reSizeInAnimateDuration:(double)duration
                    targetFrame:(CGRect)frame;


@end

NS_ASSUME_NONNULL_END
