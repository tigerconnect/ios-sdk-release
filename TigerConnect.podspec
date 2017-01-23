Pod::Spec.new do |s|
  s.name             = "TigerConnect"
  s.version          = "1.5.5"
  s.summary          = "TigerConnect iOS SDK"
  s.description      = "Enhance your iOS apps with intelligent, secure messaging from TigerConnect"
  s.license          = 'Commercial'
  s.author           = { "Oren Zitoun" => "oren@tigertext.com" }
  s.homepage         = "http://www.tigertext.com/tigerconnect/"
  s.requires_arc     = true
  s.source           = { :git => "https://github.com/tigerconnect/ios-sdk-release.git", :tag => s.version.to_s }

  s.platform     = :ios, '8.0'
  s.vendored_framework   = 'TTKit.framework'
  s.libraries = ["z"]
  s.ios.frameworks = 'UIKit', 'Foundation', 'CoreGraphics', 'CoreData', 'CFNetwork', 'Security', 'SystemConfiguration', 'AVFoundation', 'AddressBook', 'CoreLocation', 'MobileCoreServices', 'CoreTelephony', 'CoreMedia', 'ImageIO'
end
