//
//  JHAdProtocol.h
//  JHAd
//
//  Created by chenzhen on 2022/5/30.
//  Copyright © 2022 ljj. All rights reserved.
//

#ifndef JHAdProtocol_h
#define JHAdProtocol_h

#define JH_REQ_ID_KEY @"request_id"
#define JH_M_W_E_COST_PRICE @"expectCostPrice"
#define JH_M_W_H_LOSS_PRICE @"highestLossPrice"
#define JH_M_L_WIN_PRICE @"winPrice"
#define JH_M_L_LOSS_REASON @"lossReason"
#define JH_M_ADNID  @"adnId"

@protocol JHAdProtocol <NSObject>

@optional
- (NSDictionary *)extraInfo;

@end

#endif /* JHAdProtocol_h */
