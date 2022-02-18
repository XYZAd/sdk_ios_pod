//
//  XMImgTextAdObjectData.h
//  XMAd
//
//  Created by C on 2022/1/21.
//  Copyright © 2022 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMAdMaterialMeta.h>
#import <XMAd/XMImgTextData.h>
@class XMAdExpressView, XMVideoAdView;
@class XMLogoImage, XMVideoConfig;
NS_ASSUME_NONNULL_BEGIN

/// 图文类型
typedef NS_ENUM(NSInteger, XMImgTextRenderType) {
    XMImgTextRenderTypeNative           = 0,/// 原生渲染（自渲染）
    XMImgTextRenderTypeExpress          = 1,/// 模版渲染
};

/// 物料信息类
@interface XMImgTextAdObjectData : XMAdMaterialMeta


/// 广告标题
@property (nonatomic, copy, readonly, nullable) NSString *adTitle;

/// 广告副标题
@property (nonatomic, copy, readonly, nullable) NSString *adSubTitle;

/// 广告来源
@property (nonatomic, copy, readonly, nullable) NSString *adSource;

/// 广告的icon地址，下载类的会有
@property (nonatomic, copy, readonly, nullable) NSString *iconUrl;

/// 封面 优先封面 其次取第一张小图
@property (nonatomic, strong, readonly) XMAdImage *coverImage;

/// 组图
@property (nonatomic, strong, readonly, nullable) NSArray<XMAdImage *> *imageArr;

/// 广告类型，接入方请根据广告类型进行渲染
@property (nonatomic, assign, readonly) XMFeedADMode imageMode;

/// 视频试图，imageMode为image时，为空。注意：小众广告，例如游可赢、FB广告等等，无论是什么类型的广告，该字段一直有值，且类型是Video，请按照Video类型进行渲染
@property (nonatomic, strong, readonly, nullable) XMVideoAdView *videoView;

/// 如果是弹窗大图广告（动效云控），如果是其他nil  <这字段有ge毛用>
@property (nonatomic, copy, nullable) NSString *displayEffect_Style;

/// 是否有效，如果已经曝光，或者已经过期，该值则是false，其他是true。广告有效时间，一般是30分钟
@property (nonatomic, assign, readonly) BOOL effective;

/// 是否是下载类，注意：小部分广告无法区分是否是下载类，返回的是false
@property (nonatomic, assign, readonly) BOOL isAppAd;

/// 广告角标,一般指的是广告标识
@property (nonatomic, strong, readonly) XMLogoImage *logoImage;

/// 渲染类型,接入时请注意是否是模版渲染，如果是模版渲染，则基本物料信息则是空，例如标题、封面元素等等
@property (nonatomic, assign, readonly) XMImgTextRenderType imgTextRenderType;

/// 广告类型，请求广告时，接入方传入的值，这里用于回传出去
@property (nonatomic, assign, readonly) XMAdPositionAdType adPositionAdType;

/// 模版试图，如果是模版渲染，则该值有值，反之，则没有，请用自渲染方式渲染广告
@property (nonatomic, strong, readonly, nullable) XMAdExpressView *expressView;


@end


NS_ASSUME_NONNULL_END
