//
//  XMBannerAdProvider.h
//  XMAd
//
//  Created by 大大东 on 2019/12/24.
//  Copyright © 2019 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

@class XMError,XMBannerAd;

NS_ASSUME_NONNULL_BEGIN


@interface XMBannerAdProvider : NSObject <XMAdProviderProtocol>


/*
 
 注意，获取的广告model，sdk内部将不在持有，需要外部持有引用，防止释放
 
 */

/// 获取banner
/// @param param 参数
/// @param completion 回调
+ (void)bannerAdModelWithParam:(XMAdBannerParam *)param
                    completion:(void (^)(XMBannerAd * _Nullable, XMError * _Nullable))completion;

/// 预加载
+ (void)preloadAds:(XMAdBannerParam *)param;

@end

NS_ASSUME_NONNULL_END
