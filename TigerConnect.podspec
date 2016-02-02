#
# Be sure to run `pod lib lint TigerConnect.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "TigerConnect"
  s.version          = "1.3.8"
  s.summary          = "TigerConnect iOS SDK"
  s.description      = "Enhance your iOS apps with intelligent, secure messaging from tigerconnect"
  s.license          = { :file => 'LICENSE', :type => 'Commercial' }
  s.author           = { "Oren Zitoun" => "oren@tigertext.com" }
  s.homepage         = "http://www.tigertext.com/tigerconnect/"
  s.requires_arc = true
  s.source           = { :git => "https://github.com/tigerconnect/ios-sdk-release.git", :tag => s.version.to_s }

  s.platform     = :ios, '7.0'
  s.vendored_framework   = 'TTKit.framework'
  s.resource = "TTKit.bundle"
  s.libraries = ["z"]
  s.ios.frameworks = 'UIKit', 'Foundation', 'CoreGraphics', 'CoreData', 'CFNetwork', 'Security', 'SystemConfiguration', 'AVFoundation', 'AddressBook', 'CoreLocation', 'MobileCoreServices', 'CoreTelephony', 'CoreMedia', 'ImageIO'
end
