//
//  XMImgTextAd.h
//  XMAd
//
//  Created by 大大东 on 2019/12/26.
//  Copyright © 2019 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XMAd/XMImgTextData.h>

@class XMAdModel;
@class XMError;
@class XMImgTextAdObjectData;

NS_ASSUME_NONNULL_BEGIN


@protocol XMImgTextAdDelegate;

@interface XMImgTextAd : NSObject

- (instancetype)initWithModel:(XMAdModel *)model;

@property (nonatomic, strong, readonly) XMAdModel *adModel;

/// 委托
@property (nonatomic, weak) id <XMImgTextAdDelegate> adDelegate;

/// 广告基本信息
@property (nonatomic, strong, readonly) XMImgTextAdObjectData *materialMeta;

/**
 下面是自渲染的register方法，模版渲染方法详见materialMeta.expressAdView的api
 */
/// 此方法 会添加点击事件 且会自动监听containerView的进屏
/// @param containerView  adView容器视图
/// @param clickableViews 可以点击的视图， if empty will clickAble containerView
/// @param vc             需传入用来弹出目标页的ViewController，一般为当前ViewController
- (void)registerAdContainer:(__kindof UIView *)containerView
             ableClickViews:(NSArray<__kindof UIView *> * _Nullable)clickableViews
                  presentVC:(UIViewController *)vc;

/// 移除containerView的进屏监听 & 移除点击事件<建议和上面的register方法成对使用>
/// tableView、collectionView等场景时，需要在合适的时机（如:cell的prepareForReuse）执行此方法，
- (void)unRegistAdContainer;



/// 此方法 会添加点击事件 且会自动监听containerView的进屏,请注意，如果接入谷歌广告，请用次注册方法
/// @param containerView  adView容器视图
/// @param clickableAssetViews 可以点击的视图， if empty will clickAble containerView
/// @param nonclickableAssetViews 不可以点击的视图
/// @param vc             需传入用来弹出目标页的ViewController，一般为当前ViewController
- (void)registerAdContainer:(__kindof UIView *)containerView
        clickableAssetViews:(NSDictionary<XMNativeAssetIdentifier, UIView *> * _Nullable)clickableAssetViews
     nonclickableAssetViews:(NSDictionary<XMNativeAssetIdentifier, UIView *> * _Nullable)nonclickableAssetViews
                  presentVC:(UIViewController *)vc;

/// 刷新ad
- (void)refreshAdData;

@end

@protocol XMImgTextAdDelegate <NSObject>
@optional

/// 展示失败,如果是模版和自渲染展示方法调用错误，将会在这个通知中抛出
/// @param ad ad
/// @param error error
- (void)imgTextShowFailed:(XMImgTextAd *)ad
                    error:(XMError *)error;

/// 曝光回调
/// @param ad ad
- (void)imgTextAdDidExposure:(XMImgTextAd *)ad;

/// 点击回调
/// @param ad ad
- (void)imgTextAdDidClick:(XMImgTextAd *)ad;

/// 关闭详情页回调
/// @param ad ad
- (void)imgTextAdDetailPageDidClose:(XMImgTextAd *)ad;

/// 关闭广告（模版广告才走这个代理,自渲染的关闭是接入方自行设计，和sdk无关）
/// @param ad ad
- (void)imgTextAdDidClose:(XMImgTextAd *)ad;

/// 视频加载，如果失败，可以调用refreshAdData，重新刷新
/// @param ad ad
/// @param error error
- (void)imgTextAdMediaLoadFinish:(XMImgTextAd *)ad
                           error:(XMError *)error;

/// 视频播放状态
/// @param ad ad
/// @param status 播放状态
/// @param userInfo 播放信息
- (void)imgTextAdMediaPlaying:(XMImgTextAd *)ad
          playerStatusChanged:(XMAdMediaPlayerStatus)status
                     userInfo:(NSDictionary *)userInfo;

@end



NS_ASSUME_NONNULL_END

