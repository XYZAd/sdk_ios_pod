//
//  KSAdBiddingTokenManager.h
//  KSUServerBidding
//
//  Created by 李姝谊 on 2021/10/29.
//

#import <Foundation/Foundation.h>
@class KSAdBiddingAdModel;

@interface KSAdBiddingTokenManager : NSObject

// 返回token json字符串 是请求广告的参数
 
+ (NSString *)biddingTokenWithModel:(KSAdBiddingAdModel *)model dataFlowAutoStart:(NSInteger)dataFlowAutoStart;

@end
