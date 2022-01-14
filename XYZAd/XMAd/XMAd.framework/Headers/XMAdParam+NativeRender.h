//
//  XMAdParam+CusRender.h
//  XMAd
//
//  Created by C on 2021/12/28.
//  Copyright © 2021 XMAd. All rights reserved.
//

#import <XMAd/XMAd.h>

NS_ASSUME_NONNULL_BEGIN

/// 这个枚举只有原生信息流广告且穿山甲、京东广告才会用到，若不接入京东或京东广告，则忽略这个类
typedef NS_ENUM(NSUInteger, XMNativeRenderType) {
    XMNativeRenderType_Feed             = 0, /// 原生信息流
    XMNativeRenderType_Interstitial     = 1, /// 原生插屏
    XMNativeRenderType_Banner           = 2, /// 原生banner(暂不支持)
    XMNativeRenderType_Paster           = 3, /// 视频贴片广告，目前暂时只支持穿山甲（暂不支持）
    
    
};

/// 默认两个尺寸选择，也可以通过nativeImageSize自定义设置
typedef NS_ENUM(NSUInteger, XMNativeInterstitialImageSize) {
    XMNativeImageSize1080x1920          = 0,        // 大图
    XMNativeImageSize640x960            = 1,        // 小图或者组图
};


@interface XMAdParam (NativeRender)

/// 请求类型
@property (nonatomic, assign) XMNativeRenderType nativeRenderType;



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
 
 */
/// 原生图片大小（信息流广告（且是穿山甲、京东）的插屏、banner才用到）unit pixel.
@property (nonatomic, assign) CGSize nativeImageSize;

/// 设置插屏默认大小选项，如果设置了nativeImageSize，这下面这个参数无效
@property (nonatomic, assign) XMNativeInterstitialImageSize defaultImageSize;

@end

NS_ASSUME_NONNULL_END
