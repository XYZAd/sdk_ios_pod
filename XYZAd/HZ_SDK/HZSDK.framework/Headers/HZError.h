//
//  HZError.h
//  HZSDK
//
//  Created by C on 2021/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
FOUNDATION_EXTERN NSString *const HZAdErrorDomain;


typedef NS_ENUM(NSInteger, HZADErrorCode) {
    HZADErrorCode_None              = 0,
    HZADErrorCode_Data_invalid      = 1,///返回数据无效

    HZADErrorCode_Splash_image_load_fail    = 15, /// 开屏图片加载失败
    
    HZADErrorCode_Video_play_error          = 16, /// 激励视频播放失败
    
    HZADErrorCode_req_err_shield_region     = 1000,///请求参数错误，当前应用已屏蔽当前地域广告投放
    HZADErrorCode_req_err_timeout           = 1001,///请求参数错误，构建请求参数超时
    HZADErrorCode_req_err_param_null        = 1002,///请求参数错误，tagid为空或者imei与oaid为空
    HZADErrorCode_req_err_blacklist         = 1003,///请求参数错误，imei,accid黑名单过滤
    HZADErrorCode_req_err_channal_shield    = 1004,///请求参数错误，应用渠道屏蔽
    HZADErrorCode_req_err_install_devide_shield = 1005,///请求参数错误，当天安装部分应用机型屏蔽
    HZADErrorCode_req_err_param_slotid_invalied = 1006,///请求参数错误，appid和tagid不匹配
    HZADErrorCode_req_err_param_bundleid_invalied = 1007,///请求参数错误，包名不匹配
    
    HZADErrorCode_req_err_param_traffic_turnoff_or_appid_invalid    = 2000,///请求参数错误，应用流量开关关闭或appid有误
    
    
    
    
    
    
    HZADErrorCode_no_data_ad_level_filter           = 3000,///未匹配到广告，广告等级过滤
    HZADErrorCode_no_data_ad_style_filter           = 3001,///未匹配到广告，广告样式过滤
    HZADErrorCode_no_data_slotid_filter             = 3002,///未匹配到广告，tagid过滤
    HZADErrorCode_no_data_platform_filter           = 3003,///未匹配到广告，当前平台广告过滤
    HZADErrorCode_no_data_system_filter             = 3004,///未匹配到广告，操作系统过滤
    HZADErrorCode_no_data_region_filter             = 3005,///未匹配到广告，地域过滤
    HZADErrorCode_no_data_ocpa_app_filter           = 3006,///未匹配到广告，ocpa当前应用下载类广告l过滤
    HZADErrorCode_no_data_install_time_filter       = 3007,///未匹配到广告，应用安装时间过滤
    HZADErrorCode_no_data_big_teacher_filter        = 3008,///未匹配到广告，大师傅过滤
    HZADErrorCode_no_data_imei_filter               = 3009,///未匹配到广告，imei定向过滤
    HZADErrorCode_no_data_network_filter            = 3010,///未匹配到广告，网络过滤
    HZADErrorCode_no_data_ocpa_form_filter          = 3011,///未匹配到广告，ocpa网页表单类接口版本过滤
    HZADErrorCode_no_data_mobile_firm_filter        = 3012,///未匹配到广告，手机厂商过滤
    HZADErrorCode_no_data_mobile_operator_filter    = 3013,///未匹配到广告，手机运营商过滤
    HZADErrorCode_no_data_sex_age_filter            = 3014,///未匹配到广告，性别、年龄、兴趣偏好过滤
    HZADErrorCode_no_data_tag_filter                = 3015,///未匹配到广告，用户标签过滤
    HZADErrorCode_no_data_crowd_filter              = 3016,///未匹配到广告，人群包过滤
    HZADErrorCode_no_data_click_filter              = 3017,///未匹配到广告，用户点击过滤
    HZADErrorCode_no_data_ocpa_level_filter         = 3018,///未匹配到广告，ocpa分层过滤
    HZADErrorCode_no_data_level_section_filter      = 3019,///未匹配到广告，分层区间过滤
    HZADErrorCode_no_data_estimate_interface_filter = 3020,///未匹配到广告，预估接口过滤
    HZADErrorCode_no_data_account_zero_filter       = 3021,///未匹配到广告，账户余额为0过滤
    HZADErrorCode_no_data_ad_banlance_zero_filter   = 3021,///未匹配到广告，广告余额限速过滤
    HZADErrorCode_no_data_show_interval_filter      = 3023,///未匹配到广告，展现间隔时间过滤
    HZADErrorCode_no_data_rta_filter                = 3024,///未匹配到广告，rta过滤
    HZADErrorCode_no_data_app_install_repeat_filter = 3025,///未匹配到广告，下载类安装去重过滤
    HZADErrorCode_no_data_app_install_filter        = 3026,///未匹配到广告，app安装定向过滤
    HZADErrorCode_no_data_app_no_install_filter     = 3027,///未匹配到广告，app未安装定向过滤
    HZADErrorCode_no_data_form_transform_filter     = 3028,///未匹配到广告，网页表单转化过滤
    HZADErrorCode_no_data_history_price_filter      = 3029,///未匹配到广告，历史低价过滤
    HZADErrorCode_no_data_match_empty               = 3030,///未匹配到广告，未匹配到广告
    
    HZADErrorCode_no_data_pull_empty                = 4000,///未匹配到广告，未拉取到广告
    HZADErrorCode_no_data_cpm_filter                = 4001,///未匹配到广告，cpm阀值过滤
    
    
    HZADErrorCode_server_error                      = 5000,///服务端程序异常
    HZADErrorCode_unknown_error                     = 5001,///未知异常
    
    
    
    
    
    
    
};



@interface HZError : NSError

+ (instancetype)errorWithCode:(NSInteger)code userInfo:(NSDictionary<NSErrorUserInfoKey,id> *)dict;

@end

NS_ASSUME_NONNULL_END
