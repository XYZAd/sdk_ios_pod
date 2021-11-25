//
//  XMNewInterstitialAdProvider.h
//  XMAd
//
//  Created by C on 2021/11/8.
//  Copyright © 2021 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

@class XMNewInterstitialAd;

NS_ASSUME_NONNULL_BEGIN


/*
 坑爹的玩意，只支持穿山甲，具体为什么找产品
 
 */

@interface XMNewInterstitialAdProvider : NSObject<XMAdProviderProtocol>



/// 获取新插屏广告
/// @param param 参数
/// @param completion 回调
+ (void)newInterstitialAdModelWithParam:(XMAdParam *)param
                             completion:(void(^_Nonnull)(XMNewInterstitialAd * _Nullable model, XMError *_Nullable error))completion;

/// 预加载
+ (void)preloadAds:(XMAdParam *)param;


@end

NS_ASSUME_NONNULL_END
