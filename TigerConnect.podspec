Pod::Spec.new do |s|
  s.name             = "TigerConnect"
  s.version          = "1.9.1"
  s.summary          = "TigerConnect iOS SDK"
  s.description      = "Enhance your iOS apps with intelligent, secure messaging from TigerConnect"
  s.license          = 'Commercial'
  s.author           = { "TigerConnect" => "oren@tigertext.com" }
  s.homepage         = "https://developer.tigertext.com/docs"
  s.requires_arc     = true
  s.source           = { :git => "https://github.com/tigerconnect/ios-sdk-release.git", :tag => s.version.to_s }

  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  s.platform     = :ios, '11.0'
  s.vendored_framework   = 'TTKit.framework'
  s.libraries = ["z"]
  s.ios.frameworks = 'UIKit', 'Foundation', 'CoreGraphics', 'CoreData', 'CFNetwork', 'Security', 'SystemConfiguration', 'AVFoundation', 'AddressBook', 'CoreLocation', 'MobileCoreServices', 'CoreTelephony', 'CoreMedia', 'ImageIO'
end
