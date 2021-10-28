//
//  HZMaterialMeta.h
//  HZSDK
//
//  Created by C on 2021/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, HZInteractionType) {
    HZInteractionTypeWeb        = 0 ,
    
    HZInteractionTypeDownload       ,        // download the app
};

typedef NS_ENUM(NSInteger, HZFeedADMode) {
    HZFeedADModeSmallImage = 2,
    HZFeedADModeLargeImage = 3,
    HZFeedADModeGroupImage = 4,
};


@interface HZImage : NSObject

// image address URL
@property (nonatomic, copy) NSString *imageURL;

// image width
@property (nonatomic, assign) float width;

// image height
@property (nonatomic, assign) float height;

@end

/// 广告标识
@interface HZLogoImage : HZImage

// image
@property (nonatomic, strong) UIImage *image;

@end

@interface HZMaterialMeta : NSObject

/// interaction types supported by ads.
@property (nonatomic, assign) HZInteractionType interactionType;

/// material pictures.
@property (nonatomic, strong) NSArray<HZImage *> *imageAry;

/// ad logo icon.
@property (nonatomic, strong) HZLogoImage *adLogo;

/// ad headline.
@property (nonatomic, copy) NSString *adTitle;

/// ad description.
@property (nonatomic, copy) NSString *adDescription;

/// ad source.
@property (nonatomic, copy) NSString *source;


/// display format of the in-feed ad, other ads ignores it.
@property (nonatomic, assign) HZFeedADMode imageMode;

/// ad ecmp level
@property (nonatomic, copy) NSString *ecmpLevel;

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy) NSString *placementId;


@end

NS_ASSUME_NONNULL_END
