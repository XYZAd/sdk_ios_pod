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


+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position
                             gametypeID:(nullable NSString *)gametypeID;

@end

/// 广告类型
typedef NS_ENUM(NSUInteger, XMAdPositionAdType) {
    XMAdPositionAdTypeFeed                   = 0, /// 信息流(默认)(支持模版，自渲染混出，如果需要混出，请设置expectAdSize)
    XMAdPositionAdTypeNativeInterstitial     = 1, /// 原生插屏
    XMAdPositionAdTypeNativeBanner           = 2, /// 原生banner(暂不支持)
    XMAdPositionAdTypePaster                 = 3, /// 视频贴片广告（支持混出，需要设置expectAdSize）
    XMAdPositionAdTypeDraw                   = 4, /// draw广告（支持混出，需要设置expectAdSize）
    
    
};

/// 自渲染插屏默认两个尺寸选择，也可以通过nativeImageSize自定义设置
typedef NS_ENUM(NSUInteger, XMNativeInterstitialImageSize) {
    XMNativeImageSize1080x1920          = 0,        // 大图
    XMNativeImageSize640x960            = 1,        // 小图或者组图
};


@interface XMAdImgTextParam : XMAdParam

/// 请求类型
@property (nonatomic, assign) XMAdPositionAdType adPositionAdType;



/*
 
 如果是原生插屏，则传入
 大图(高宽比：1.78的图片)
 小图(高宽比：1.52的图片)
 组图(三张高宽比：1.52的图片)
 
 如果是原生信息流，则传入
 1280*720, 传入的图片尺寸比例范围: 1.64 ~ 1.92
 480*320, 传入的图片尺寸比例范围: 1.36 ~ 1.64
 
 如果是原生banner，则传入
 640*100, 传入的图片尺寸比例范围在 5.63~7.17
 640*160, 传入的图片尺寸比例范围在 3.52~4.48
 644*280, 传入的图片尺寸比例范围在 2.15~2.57
 720*360, 传入的图片尺寸比例范围在 2.16~2.15
 
 
 如果是模版广告，则传入期望size
 
 
 */
/// 期望大小（信息流广告（且是穿山甲、京东）的插屏、banner，或者是banner才用到）unit pixel（px）.
@property (nonatomic, assign) CGSize expectAdSize;

/// 设置插屏默认大小选项，如果设置了nativeImageSize，这下面这个参数无效
@property (nonatomic, assign) XMNativeInterstitialImageSize defaultImageSize;

+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position
                             gametypeID:(nullable NSString *)gametypeID NS_UNAVAILABLE;

+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position
                             gametypeID:(nullable NSString *)gametypeID
                       adPositionAdType:(XMAdPositionAdType)adPositionAdType
                           expectAdSize:(CGSize)expectAdSize;

@end



typedef NS_ENUM(NSInteger, XMInterstitialType) {
    XMInterstitialTypeCommon                = 0, /// 通用插屏
    XMInterstitialTypeNew                   = 1, /// 新插屏（只针对于穿山甲有效）
};

/** 模版插屏类广告请求时 需要的参数*/
@interface XMAdIntersititialParam : XMAdParam

/*
 
 对于插屏来说，模版的size是穿山甲和快手、京东的请求参数，若不接穿山甲、京东和快手，则可以忽略这个参数，
 这里穿山甲提供三个默认值选项
 宽高比1:1== {300,300}
 宽高比2:3== {300,450}
 宽高比3:2== {300,200}
 
 快手、京东也可以用穿山甲的这三个值，快手不做这个限制
 
 京东sdk插屏：请确保size 的 width : height = 1:1 or 2:3 or 3:2
 
 
 */
/// 模板size
@property (nonatomic, assign) CGSize size;


/// 插屏类型
@property (nonatomic, assign) XMInterstitialType interstitialType;

+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position
                             gametypeID:(nullable NSString *)gametypeID NS_UNAVAILABLE;

/// 初始化
+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position
                             gametypeID:(nullable NSString *)gametypeID adSize:(CGSize)adSize;

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

+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position
                             gametypeID:(nullable NSString *)gametypeID NS_UNAVAILABLE;

/// 初始化
+ (instancetype)adReqParamsWithPosition:(nonnull XMAdPageType *)position
                             gametypeID:(nullable NSString *)gametypeID
                                 adSize:(CGSize)adSize
                    presentedController:(nonnull UIViewController *)controller
                     autoSwitchInterval:(int)autoSwitchInterval;

@end



NS_ASSUME_NONNULL_END
