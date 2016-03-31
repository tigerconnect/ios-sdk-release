# TigerConnect iOS SDK

[![Version](https://img.shields.io/cocoapods/v/TigerConnect.svg?style=flat)](http://cocoapods.org/pods/TigerConnect)
[![License](https://img.shields.io/cocoapods/l/TigerConnect.svg?style=flat)](http://cocoapods.org/pods/TigerConnect)
[![Platform](https://img.shields.io/cocoapods/p/TigerConnect.svg?style=flat)](http://cocoapods.org/pods/TigerConnect)

This repository contains binary distributions of iOS SDK released by [TigerConnect](http://tigertext.com/tigerconnect).

If you have any questions, comments, or issues related to this repository then please contact the team by emailing [tigerconnect@tigertext.com](mailto:tigerconnect@tigertext.com).

## Overview

The TigerConnect iOS SDK provides a simple way to enhance your iOS applications with intelligent, secure messaging from TigerConnect

In order to use the TigerConnect iOS SDK you must be a registered developer. All aspects of this setup are covered in detail in the [TigerConnect Documentation](https://developer.tigertext.com/).

## Installation

TigerConnect iOS SDK can be installed directly into your application by importing a framework or via CocoaPods. Quick installation instructions are provided below for reference, but please refer to the [TigerConnect Documentation](https://developer.tigertext.com/) for full details.

### Requirements

The following are requirements for the TigerConnect iOS SDK.
* ARC
* iOS7

### CocoaPods Installation

The recommended path for installation is [CocoaPods](http://cocoapods.org/). CocoaPods provides a simple, versioned dependency management system that automates the tedious and error prone aspects of manually configuring libraries and frameworks. You can add TigerConnect iOS SDK to your project via CocoaPods by doing the following:

```sh
$ sudo gem install cocoapods
$ pod setup
```

Now create a `Podfile` in the root of your project directory and add the following:

```ruby
pod "TigerConnect"
```

Complete the installation by executing:

```sh
$ pod install
```
These instructions will setup your local CocoaPods environment and import the TigerConnect iOS SDK into your project. 

## iOS 9

If you install on iOS9 you need to this to your plist file:
```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
    <key>NSExceptionDomains</key>
    <dict>
        <key>cloudfront.net</key>
        <dict>
            <key>NSIncludesSubdomains</key>
            <true/>
            <key>NSTemporaryExceptionAllowsInsecureHTTPLoads</key>
            <true/>
            <key>NSTemporaryExceptionMinimumTLSVersion</key>
            <string>1.0</string>
            <key>NSTemporaryExceptionRequiresForwardSecrecy</key>
            <false/>
        </dict>
        <key>tigertext.me</key>
        <dict>
            <key>NSExceptionAllowsInsecureHTTPLoads</key>
            <false/>
            <key>NSIncludesSubdomains</key>
            <true/>
        </dict>
    </dict>
</dict>
```
## Swift

TTKit is an ObjC library, if you wish to run it in a swift project you will need to create a bridging header and add it to your build settings under Swift Compiler - Code Generation.  Please add <TTKit/TTKit.h> to the bridging header.  More information can be found [here on the Apple Developer Site](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html)

## Demo

Please refer to the following GIt for a quick start guide which incdlues a demo app:

https://github.com/tigerconnect/ios-app-messenger-demo

## Contact

If you have any questions please reach out to the TigerConnect team any time by emailing [tigerconnect@tigertext.com](mailto:tigerconnect@tigertext.com).

## License

TigerConnect is licensed under our [Developer Terms of Use](https://developer.tigertext.com/developer-terms-of-use/).
