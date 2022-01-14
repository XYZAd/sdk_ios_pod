//
//  KSAdPos.h
//  KSAdSDK
//
//  Created by 徐志军 on 2019/11/14.
//  Copyright © 2019 KuaiShou. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, KSAdPosAdType) {
    KSAdPosAdTypeUnknown            =       0,
    KSAdPosAdTypeFeed               =       1,/// 信息流
    KSAdPosAdTypeRewardVideo        =       2,/// 激励视频
    KSAdPosAdTypeFullScreenVideo    =       3,/// 全屏视频
    KSAdPosAdTypeSplash             =       4,/// 开屏
    KSAdPosAdTypeDrawVideo          =       6,/// draw广告
    KSAdPosAdTypeContentEcology     =       7,/// 滑滑流draw广告
    KSAdPosAdTypeBanner             =       8,/// banner广告
    KSAdPosAdTypePaster             =       10,
    KSAdPosAdTypeReflux             =       11, /// 回流页广告
    KSAdPosAdTypeInterstitial       =       13, /// 插屏广告
    KSAdPosAdTypeAggregation        =       15, /// 推荐聚合广告
    KSAdPosAdTypeNative             =       10000, // 原生自渲染广告
};
