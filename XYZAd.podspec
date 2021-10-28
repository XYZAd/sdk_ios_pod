#
# Be sure to run `pod lib lint XYZAd.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#




Pod::Spec.new do |s|
  s.name             = 'XYZAd'
  s.version          = '1.4.2'
  s.summary          = 'XYZAd Description'
  s.description      = <<-DESC
                       XYZAd Description...
                       DESC

  s.homepage         = 'http://adcontrol.tt.cn/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'XYZAd' => 'lidong@021.com' }
  s.source           = { :git => 'https://github.com/XYZAd/sdk_ios_pod.git', :tag => s.version.to_s }
  
  s.ios.deployment_target = '9.0'
  s.frameworks      = 'Foundation', 'UIKit', 'CoreGraphics',
  s.weak_frameworks = 'AdSupport', 'AppTrackingTransparency', 'WebKit', 'StoreKit'


  
  s.user_target_xcconfig =  {'OTHER_LDFLAGS' => ['-lObjC'], 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.pod_target_xcconfig  =  {'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}



  s.default_subspecs = 'XMAdSDK'


  #XMAd
  s.subspec 'XMAdSDK' do |ss|
    ss.frameworks = 'Security', 'CoreMotion', 'CoreLocation', 'SystemConfiguration', 'CoreTelephony'
    ss.vendored_frameworks = 'XYZAd/XMAd/*.framework'
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
    ss.dependency 'Ads-CN', '4.0.0.1'
  end

  #百度
  s.subspec 'BDSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    # 4.81
    ss.vendored_frameworks = 'XYZAd/BD_SDK/*.framework'
    ss.resource = 'XYZAd/BD_SDK/*.bundle'
  end

  #广点通
  s.subspec 'GDTSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'GDTMobSDK', '4.13.11'
  end

  #MTG
  s.subspec 'MTGSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    # 7.0.1
    ss.vendored_frameworks = 'XYZAd/MTG_SDK/*.xcframework'
  end

  #SigmobAd
  s.subspec 'SIGMOBSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'SigmobAd-iOS', '3.4.3'
  end  

  #快手
  s.subspec 'KSMOBSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    s.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi"]
    #3.3.21
    ss.vendored_frameworks = 'XYZAd/KS_SDK/*.framework'
  end  

  #聚合
  s.subspec 'JHSDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    ss.dependency 'XYZAd/GDTSDK'
    # 42.095
    ss.vendored_frameworks = 'XYZAd/JH_SDK/*.framework'
  end  
    
  #游可盈
  s.subspec 'YouKeYingDK' do |ss|
    ss.dependency 'XYZAd/XMAdSDK'
    # 2.3.0.209
    ss.vendored_frameworks = 'XYZAd/YKY_SDK/*.framework'
  end  

end