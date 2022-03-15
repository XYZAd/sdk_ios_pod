//
//  JHAdConst.h
//  JHAd
//
//  Created by Liujingjie on 2019/11/7.
//  Copyright © 2019 ljj. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, JHLogLevel){
    JHLogLevel_Debug,
    JHLogLevel_Release,
};

/**广告类型*/
typedef NS_ENUM(NSInteger,JHAdSlotType) {
    /**横幅*/
    JHAdType_Banner = 1,
    /**开屏*/
    JHAdType_Splash = 2,
    /**插屏*/
    JHAdType_Insert = 3,
    /**图文信息流*/
    JHAdType_InfoFlow = 4,
    /**激励视频*/
    JHAdType_Video = 5,
    /**激励视频下载(安卓端)*/
    JHAdType_Video_Download = 6,
    /**混合信息流*/
    JHAdType_BlendFlow = 7,
    JHAdSlotType_8 = 8,//视频信息流
    JHAdSlotType_9 = 9,//模板信息流
    JHAdSlotType_11 = 11,//web固定块
    JHAdSlotType_12 = 12,//web右下炫富
    JHAdSlotType_13 = 13,//web对联
    JHAdSlotType_14 = 14,//wap固定块
    JHAdSlotType_15 = 15,//web底部悬浮
    JHAdSlotType_20 = 20,//搜索
    UnkownSoltType  = 99,//未知
};
/**
 *  视频播放器状态
 *
 *  播放器只可能处于以下状态中的一种
 *
 */
typedef NS_ENUM(NSUInteger, JHMediaPlayerStatus) {
    JHMediaPlayerStatusInitial = 0,         // 初始状态
    JHMediaPlayerStatusLoading = 1,         // 加载中
    JHMediaPlayerStatusStarted = 2,         // 开始播放
    JHMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    JHMediaPlayerStatusError = 4,           // 播放出错
    JHMediaPlayerStatusStoped = 5,          // 播放停止
};


typedef NS_ENUM(NSUInteger, JHVideoPlayPolicy) {
    JHVideoPlayPolicyUnknow = 0, // 默认值，未设置
    JHVideoPlayPolicyAuto = 1,   // 用户角度看起来是自动播放
    JHVideoPlayPolicyManual = 2  // 用户角度看起来是手动播放或点击后播放
};

typedef NS_ENUM(NSUInteger, JHVideoRenderType) {
    JHVideoRenderTypeUnknow = 0,
    JHVideoRenderTypeSDK = 1,
    JHVideoRenderTypeDeveloper = 2
};

typedef NS_ENUM(NSInteger, JHVideoAutoPlayPolicy) {
    JHVideoAutoPlayPolicyWIFI = 0, // WIFI 下自动播放
    JHVideoAutoPlayPolicyAlways = 1, // 总是自动播放，无论网络条件
    JHVideoAutoPlayPolicyNever = 2, // 从不自动播放，无论网络条件
};


typedef NS_ENUM(NSInteger, JHAdBiddingLossReason) {
    JHAdBiddingLossReasonLowPrice          = 1,        // 竞争力不足
    JHAdBiddingLossReasonLoadTimeout       = 2,        // 返回超时
    JHAdBiddingLossReasonNoAd              = 3,        // 无广告回包
    JHAdBiddingLossReasonAdDataError       = 4,        // 回包不合法
    JHAdBiddingLossReasonOther             = 10001     // 其他
};


NS_ASSUME_NONNULL_BEGIN

@interface JHAdConst : NSObject

@end

NS_ASSUME_NONNULL_END
