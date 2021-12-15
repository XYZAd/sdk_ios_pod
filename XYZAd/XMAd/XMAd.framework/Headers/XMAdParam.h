//
//  XMAdParam.h
//  XMAd
//
//  Created by C on 2020/12/17.
//  Copyright © 2020 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 请求广告时 需要的基础参数
@interface XMAdParam : NSObject

/// 广告位置
@property (nonatomic, copy, nonnull   ) XMAdPageType *position;

/// 类型（区分是哪个位置）
@property (nonatomic, copy, nullable  ) NSString *gametypeID;

/// 请求超时时间 (当<=0时无效, 使用SDK默认时间)
@property (nonatomic, assign          ) NSTimeInterval reqTimeout;


+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position gametypeID:(nullable NSString *)gametypeID;

@end


/** 模板类广告请求时 需要的参数*/
@interface XMAdExpressParam : XMAdParam

/*
 
 对于插屏来说，模版的size是穿山甲和快手的请求参数，若不接穿山甲和快手，则可以忽略这个参数，
 这里穿山甲提供三个默认值选项
 宽高比1:1== {300,300}
 宽高比2:3== {300,450}
 宽高比3:2== {300,200}
 
 快手也可以用穿山甲的这三个值，快手不做这个限制
 
 
 */
/// 模板size
@property (nonatomic, assign) CGSize size;

+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position gametypeID:(nullable NSString *)gametypeID NS_UNAVAILABLE;

/// 初始化
+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position gametypeID:(nullable NSString *)gametypeID adSize:(CGSize)adSize;

@end


/** Banner广告请求时 需要的参数*/
@interface XMAdBannerParam : XMAdParam

/*
 
 banner的size，这个可以自定义，没有限制
 
 */
/// 显示size
@property (nonatomic, assign) CGSize size;

/// 当前页面VC
@property (nonatomic, weak  ) UIViewController *viewController;

/// 自动切换时间间隔, 区间为[30 120], 为0时等价于关闭, 默认值0
@property (nonatomic, assign) int autoSwitchInterval;

+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position gametypeID:(nullable NSString *)gametypeID NS_UNAVAILABLE;

/// 初始化
+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position gametypeID:(nullable NSString *)gametypeID adSize:(CGSize)adSize presentedController:(nonnull UIViewController *)controller autoSwitchInterval:(int)autoSwitchInterval;

@end



NS_ASSUME_NONNULL_END
