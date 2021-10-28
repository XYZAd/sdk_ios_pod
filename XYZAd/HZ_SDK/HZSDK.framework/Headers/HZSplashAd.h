//
//  HZSplashAd.h
//  HZSDK
//
//  Created by C on 2021/3/29.
//

#import <UIKit/UIKit.h>
#import <HZSDK/HZMaterialMeta.h>

NS_ASSUME_NONNULL_BEGIN

@protocol HZSplashAdDelegate;

@class HZError;

@interface HZSplashAd : UIView

/**
The unique identifier of splash ad.
 */
@property (nonatomic, copy, readonly, nonnull) NSString *placementId;

/**
 Maximum allowable load timeout, default 3s, unit s.
 */
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;


/**
 The delegate for receiving state change messages.
 */
@property (nonatomic, weak, nullable) id<HZSplashAdDelegate> delegate;

/*
 required.
 Root view controller for handling ad actions.
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 Whether the splash ad data has been loaded.
 */
@property (nonatomic, assign, readonly) BOOL adValid;

/**
 Initializes splash ad with slot id and frame.
 @param appid : app ad id
 @param placementId : the unique identifier of splash ad
 @param frame : the frame of splashAd view. It is recommended for the mobile phone screen.
 @return HZSpalshAd
 */
- (instancetype)initWithAppid:(NSString *)appid placementId:(NSString *)placementId frame:(CGRect)frame;

/**
 Load splash ad datas.
 Start the countdown(@tolerateTimeout) as soon as you request datas.
 */
- (void)loadAdData;

/**
 返回广告的eCPM等级
 
 @return 成功返回一个包含数字的string，@""或nil表示无权限或后台异常
 */
- (NSString *)eCPMLevel;


@end

@protocol HZSplashAdDelegate <NSObject>


@optional
/**
 This method is called when splash ad material loaded successfully.
 */
- (void)hz_splashAdDidLoad:(HZSplashAd *)splashAd;

/**
 This method is called when splash ad material failed to load.
 @param error : the reason of error
 */
- (void)hz_splashAd:(HZSplashAd *)splashAd didFailWithError:(HZError * _Nullable)error;

/**
 This method is called when splash ad slot will be showing.
 */
- (void)hz_splashAdWillVisible:(HZSplashAd *)splashAd;

/**
 This method is called when splash ad is clicked.
 */
- (void)hz_splashAdDidClick:(HZSplashAd *)splashAd;

/**
 This method is called when splash ad is closed.
 */
- (void)hz_splashAdDidClose:(HZSplashAd *)splashAd;

/**
 This method is called when splash ad is about to close.
 */
- (void)hz_splashAdWillClose:(HZSplashAd *)splashAd;

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
- (void)hz_splashAdDidCloseOtherController:(HZSplashAd *)splashAd interactionType:(HZInteractionType)interactionType;

/**
 This method is called when spalashAd skip button  is clicked.
 */
- (void)hz_splashAdDidClickSkip:(HZSplashAd *)splashAd;

/**
 This method is called when spalashAd countdown equals to zero
 */
- (void)hz_splashAdCountdownToZero:(HZSplashAd *)splashAd;

@end

NS_ASSUME_NONNULL_END
