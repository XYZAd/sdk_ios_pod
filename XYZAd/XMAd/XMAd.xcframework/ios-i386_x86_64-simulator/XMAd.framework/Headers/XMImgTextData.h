//
//  XMImgTextData.h
//  XMAd
//
//  Created by C on 2021/3/12.
//  Copyright © 2021 XMAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, XMFeedADMode) {
    XMFeedADMode_LargeImage                  = 0 , ///图文(大图)
    XMFeedADMode_GroupImage                      , ///组图
    XMFeedADMode_SmallImage                      , ///单图
    XMFeedADMode_VideoImage                      , ///视频
    XMFeedAdMode_Text                            , ///只有文字，没有图片
};

/// 图片
@interface XMAdImage : NSObject

@property (nonatomic, copy  ) NSString *imgURL;
@property (nonatomic, assign) CGFloat   imgWidth;       // may be equal 0
@property (nonatomic, assign) CGFloat   imgHeight;      // may be equal 0

@end

@interface XMLogoImage : NSObject

/// 资源图片（本地资源读取）如果imageURL有值，image可能为nil
@property (nonatomic, strong, nullable) UIImage *image;
/// 资源图片地址链接（接口返回）可能为nil
@property (nonatomic, copy, nullable) NSString *imageURL;

@end

@interface XMExpressAttributed : NSObject

/**
 Background color of the native ad view.
 */
@property (nonatomic, copy, nullable) UIColor *backgroundColor;
/**
 Color of the title label.
 */
@property (nonatomic, copy, nullable) UIColor *titleColor;
/**
 Color of the advertiser name label.
 */
@property (nonatomic, copy, nullable) UIColor *advertiserNameColor;
/**
 Color of the ad choices icon.
 */
@property (nonatomic, copy, nullable) UIColor *adChoicesForegroundColor;
/**
 Font of the title label.
 */
@property (nonatomic, copy, nullable) UIFont *titleFont;
/**
 Color of the description label.
 */
@property (nonatomic, copy, nullable) UIColor *descriptionColor;
/**
 Font of the description label.
 */
@property (nonatomic, copy, nullable) UIFont *descriptionFont;
/**
 Background color of the call to action button.
 */
@property (nonatomic, copy, nullable) UIColor *buttonColor;
/**
 Color of the call to action button's title label.
 */
@property (nonatomic, copy, nullable) UIColor *buttonTitleColor;
/**
 Font of the call to action button's title label.
 */
@property (nonatomic, copy, nullable) UIFont *buttonTitleFont;
/**
 Border color of the call to action button. If nil, no border is shown.
 */
@property (nonatomic, copy, nullable) UIColor *buttonBorderColor;

/**
 cornerRadius of the call to action button. If nil, no corner.
 */
@property (nonatomic, strong, nullable) NSNumber *buttonCornerRadius;

@end


typedef NSString *XMNativeAssetIdentifier;

FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeTitleAsset; //标题
FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeContentAsset; //副标题
FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeIconAsset; //广告icon(app icon)
FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeLogoAsset; //广告Logo
FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeBodyImageAsset; // 广告图片
FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeDownloadAsset; // 下载按钮
FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeMediaAsset;// 视频
FOUNDATION_EXTERN XMNativeAssetIdentifier _Nonnull const XMNativeAppNameAsset;// appname


NS_ASSUME_NONNULL_END
