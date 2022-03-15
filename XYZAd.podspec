#
# Be sure to run `pod lib lint XYZAd.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#




Pod::Spec.new do |s|
  s.name             = 'XYZAd'
  s.version          = '1.4.9'
  s.summary          = 'XYZAd Description'
  s.description      = <<-DESC
                       XYZAd Description...
                       DESC

  s.homepage         = 'http://adcontrol.tt.cn/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'XYZAd' => 'lidong@021.com' }
  s.source           = { :git => 'https://github.com/XYZAd/sdk_ios_pod.git', :tag => s.version.to_s }
  # s.source           = { :path => '.'}
  s.ios.deployment_target = '9.0'
  s.frameworks      = 'Foundation', 'UIKit', 'CoreGraphics',
  s.weak_frameworks = 'AdSupport', 'AppTrackingTransparency', 'WebKit', 'StoreKit'


  
  s.user_target_xcconfig =  {'OTHER_LDFLAGS' => ['-lObjC'], 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ENABLE_BITCODE' => 'NO'}
  s.pod_target_xcconfig  =  {'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  # s.xcconfig = {'USER_HEADER_SEARCH_PATHS' => '"${PROJECT_DIR}/.."/**' }


  s.default_subspecs = 'XMAdSDK'


  #XMAd
  s.subspec 'XMAdSDK' do |ss|
    ss.frameworks = 'Security', 'CoreMotion', 'CoreLocation', 'SystemConfiguration', 'CoreTelephony'
    ss.vendored_frameworks = 'XYZAd/XMAd/*.xcframework','XYZAd/XMAd/*.framework'
    #ss.vendored_xcframeworks = 'XYZAd/XMAd/*.xcframework'
    ss.resource = 'XYZAd/XMAd/*.bundle'
  end
  
  #禾赞
  s.subspec 'HZSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.vendored_frameworks = 'XYZAd/HZ_SDK/*.framework'
    ss.resource = 'XYZAd/HZ_SDK/*.bundle'
  end

  #穿山甲
  s.subspec 'JRTTSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'Ads-CN', '4.2.5.6'
  end

  #百度
  s.subspec 'BDSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'BaiduMobAdSDK', '4.85'
  end

  #广点通
  s.subspec 'GDTSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'GDTMobSDK', '4.13.50'
  end

  #MTG
  s.subspec 'MTGSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'MintegralAdSDK/All', '7.1.1'
  end

  #SigmobAd
  s.subspec 'SIGMOBSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'SigmobAd-iOS', '3.5.3'
  end  

  #快手
  s.subspec 'KSMOBSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    s.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi"]
    #3.3.27
    ss.vendored_frameworks = 'XYZAd/KS_SDK/*.framework'
  end  

  #聚合
  s.subspec 'JHSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
	  ss.dependency 'GDTMobSDK', '4.13.50'
    # 42.101
    ss.vendored_frameworks = 'XYZAd/JH_SDK/*.framework'
  end  
    
  #游可盈
  s.subspec 'YouKeYingSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    # 2.5.1.202
    ss.vendored_frameworks = 'XYZAd/YKY_SDK/*.framework'
  end  

  #AdColony
  s.subspec 'AdColonySDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'AdColony', '4.7.2'
  end

  #IronSource
  s.subspec 'IronSourceSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'IronSourceSDK','7.1.12.0'
  end

  #京东
  s.subspec 'JDSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    # 1.4.0
    ss.vendored_frameworks = 'XYZAd/JD_SDK/*.framework'
  end

  s.subspec 'UMengSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'UMCommon', '7.3.6'
    ss.dependency 'UMUnionSDK', '1.1.0'
    ss.dependency 'UMDevice', '2.2.0'
  end

  s.subspec 'UnityAdSDK' do |ss|
  	ss.dependency 'XYZAd/XMAdSDK'
  	ss.dependency 'UnityAds', '4.0.0'
  end

  s.subspec 'FBAdSDK' do |ss|
    #6.9.0
  	ss.dependency 'XYZAd/XMAdSDK'
    ss.vendored_frameworks = 'XYZAd/FB_SDK/*.xcframework'
  end

  s.subspec 'GADAdSDK' do |ss|
  	ss.dependency 'XYZAd/XMAdSDK'
  	#9.1.0
  	ss.vendored_frameworks = 'XYZAd/GAD_SDK/*.xcframework'
  end

end
