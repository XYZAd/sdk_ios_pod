//
//  JHUnifiedNativeAd.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/26.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHUnifiedNativeAdDataObject.h"
#import "JHUnifiedNativeAdView.h"

NS_ASSUME_NONNULL_BEGIN

@class JHUnifiedNativeAd;

@protocol JHUnifiedNativeAdDelegate <NSObject>
/**
 广告数据回调

 @param unifiedNativeAdDataObjects 广告数据数组
 @param error 错误信息
 */
- (void)jh_unifiedNativeAdLoaded:(NSArray<JHUnifiedNativeAdDataObject *> * _Nullable)unifiedNativeAdDataObjects unifiedNativeAd:(JHUnifiedNativeAd *)unifiedNativeAd error:(NSError * _Nullable)error;


@end



@interface JHUnifiedNativeAd : NSObject

@property (nonatomic, weak) id<JHUnifiedNativeAdDelegate> delegate;

/**
 请求视频的最大时长，有效值范围为[5,60]。
 */
@property (nonatomic) NSInteger maxVideoDuration;

/**
 可选属性，设置本次拉取的视频广告从用户角度看到的视频播放CL00E9。
 
 “用户角度”特指用户看到的情况，并非SDK是否自动播放，与自动播放CL00E9 GDTVideoAutoPlayPolicy 的取值并非一一对应
 
 例如开发者设置了 JHVideoAutoPlayPolicyNever 表示 SDK 不自动播放视频，但是开发者通过 GDTMediaView 的 play 方法播放视频，这在用户看来仍然是自动播放的。
 
 准确的设置 GDTVideoPlayPolicy 有助于提高视频广告的eCPM值，如果广告位仅支持图文广告，则无需调用。
 
 需要在 loadAd 前设置此属性。
 */
@property (nonatomic, assign) JHVideoPlayPolicy videoPlayPolicy;

/**
 可选属性，设置本次拉取的视频广告封面是由SDK渲染还是开发者自行渲染。
 
 SDK 渲染，指视频广告 containerView 直接在 feed 流等场景展示，用户可以直接看到渲染的视频广告。Demo 工程中的 “视频Feed” 就是 SDK 渲染。
 
 开发者自行渲染，指开发者获取到广告对象后，先用封面图字段在 feed 流中先渲染出一个封面图入口，用户点击封面图，再进入一个有 conainterView 的详细页，播放视频。Demo 工程中的 "竖版 Feed 视频" 就是开发者渲染的场景。
 */
@property (nonatomic, assign) JHVideoRenderType videoRenderType;



/**
 加载广告

 @param adCount 加载条数
 */
- (void)loadAdWithAdCount:(NSInteger)adCount;

/**
 返回广告平台名称
 
 @return 当使用流量分配功能时，用于区分广告平台；未使用时为空字符串
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
