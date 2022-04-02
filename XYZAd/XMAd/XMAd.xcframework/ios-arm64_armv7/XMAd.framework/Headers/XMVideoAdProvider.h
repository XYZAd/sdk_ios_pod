//
//  XMVideoAdProvider.h
//  XMAd
//
//  Created by 大大东 on 2019/12/12.
//  Copyright © 2019 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

@class XMVideoAd;

NS_ASSUME_NONNULL_BEGIN


/// 用于请求激励视频的Provider
@interface XMVideoAdProvider : NSObject <XMAdProviderProtocol>


/// 获取激励视频广告
/// @param param 参数
/// @param completion 回调
+ (void)videoAdModelWithParam:(XMAdParam *)param
                   completion:(void(^_Nonnull)(XMVideoAd * _Nullable model, XMError *_Nullable error))completion;


/// 预加载
/// @param param param
+ (void)preloadAds:(XMAdParam *)param;



/// 从缓存中获取广告，不会触发广告请求，获取的广告可能为nil
/// @param param param
/// @param error 错误信息
+ (XMVideoAd *)fetchVideoAdFromCache:(XMAdParam *)param
                               error:(XMError *_Nullable*_Nullable)error;

@end

NS_ASSUME_NONNULL_END
