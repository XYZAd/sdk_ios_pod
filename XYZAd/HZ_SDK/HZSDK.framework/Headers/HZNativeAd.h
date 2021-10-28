//
//  HZNativeAd.h
//  HZSDK
//
//  Created by C on 2021/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class HZMaterialMeta;

@protocol HZNativeAdDelegate;

@interface HZNativeAd : NSObject
/**
 Ad slot material.
 */
@property (atomic, strong, readonly, nullable) HZMaterialMeta *data;

/**
 The delegate for receiving state change messages.
 The delegate is not limited to viewcontroller.
 The delegate can be set to any object which conforming to <HZNativeAdDelegate>.
 */
@property (nonatomic, weak, readwrite, nullable) id<HZNativeAdDelegate> delegate;

/**
 required.
 Root view controller for handling ad actions.
 Action method includes is 'presentViewController'.
 */
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;

/**
 Initializes native ad with ad slot.
 @param object : ad infomation
 @return HZNativeAd
 */
- (instancetype)initWithObject:(id)object;

/**
 Register clickable views in native ads view.
 Interaction types can be configured on TikTok Audience Network.
 Interaction types include view download the app, open the webpage within the app, etc.
 @param containerView : required.
                        container view of the native ad.
 @param clickableViews : optional.
                        Array of views that are clickable.
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;

/**
 Unregister ad view from the native ad.
 */
- (void)unregisterView;


@end


@protocol HZNativeAdDelegate <NSObject>

@optional

/**
 This method is called when native ad slot has been shown.
 */
- (void)hz_nativeAdDidBecomeVisible:(HZNativeAd *)nativeAd;

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
- (void)hz_nativeAdDidCloseOtherController:(HZNativeAd *)nativeAd interactionType:(HZInteractionType)interactionType;

/**
 This method is called when native ad is clicked.
 */
- (void)hz_nativeAdDidClick:(HZNativeAd *)nativeAd withView:(UIView *_Nullable)view;


@end

NS_ASSUME_NONNULL_END
