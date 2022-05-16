//
//  KSVideoAdView.h
//  KSAdSDK
//
//  Created by 徐志军 on 2019/10/16.
//  Copyright © 2019 KuaiShou. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSVideoAdView : UIView

@property (nonatomic, assign, readwrite) BOOL videoSoundEnable;
@property (nonatomic, assign, readwrite) BOOL playFinished;
// CoverView是否显示appIcon和appName
@property (nonatomic, assign, readwrite) BOOL isShowAppInfo;

@end

NS_ASSUME_NONNULL_END
