//
//  XMDrawVideoAdProvider.h
//  XMAd
//
//  Created by C on 2020/7/3.
//  Copyright © 2020 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdProviderProtocol.h>

@class XMError;
@class XMDrawVideoAd;

NS_ASSUME_NONNULL_BEGIN

@interface XMDrawVideoAdProvider : NSObject <XMAdProviderProtocol>

/*
 
 注意，获取的广告model，sdk内部将不在持有，需要外部持有引用，防止释放
 
 */

/// 请求draw广告
/// @param param 请求信息
/// @param completion 回调
+ (void)drawVideoAdModelWithParam:(XMAdParam *)param
                       completion:(void(^_Nonnull)(XMDrawVideoAd * _Nullable model, XMError * _Nullable error))completion;


/// 预加载
+ (void)preloadAds:(XMAdParam *)param;

@end

NS_ASSUME_NONNULL_END
