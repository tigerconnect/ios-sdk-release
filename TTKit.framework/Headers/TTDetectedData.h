//
//  TTDetectedData.h
//  TTKit
//
//  Created by Oren Zitoun on 2/19/19.
//  Copyright © 2019 TigerText, Inc. All rights reserved.
//

#import <CoreData/CoreData.h>

@class TTMessage;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Enumeration descriving types of detected data
 */
typedef NS_ENUM(NSInteger, TTDetectedMessageType)
{
    /**
     *  No detected data type
     */
    TTDetectedMessageTypeNone = 0,
    
    /**
     *  The data is of type address if the `NSTextCheckingType` returned by `NSDataDetector` is `NSTextCheckingTypeAddress`.
     */
    TTDetectedMessageTypeAddress = 1,
    
    /**
     *  The data is of type link if the `NSTextCheckingType` returned by `NSDataDetector` is `NSTextCheckingTypeLink`.
     *  @note The data is only of type `TTDetectedMessageTypeLink` if the link does not contain an image (the link does not end with .jpg, .png, or .gif). Otherwise the data will be of `TTDetectedMessageTypeImageLink`
     */
    TTDetectedMessageTypeLink = 2,
    
    /**
     *  The data is of type image link if the `NSTextCheckingType` returned by `NSDataDetector` is `NSTextCheckingTypeLink` and the link ends with .jpg, .png, or .gif.
     */
    TTDetectedMessageTypeImageLink = 3,
    
    /**
     *  The data is of type phone number if the `NSTextCheckingType` returned by `NSDataDetector` is `NSTextCheckingTypePhoneNumber`.
     */
    TTDetectedMessageTypePhoneNo = 4,
    
    /**
     *  The data is of type email if the `NSTextCheckingType` returned by `NSDataDetector` is `NSTextCheckingTypeLink` and the link starts with "mailto:".
     */
    TTDetectedMessageTypeEmail = 5,
};

/**
 * `TTDetectedData` represents data detected from the contents of a message.
 */
@interface TTDetectedData : NSManagedObject

/**
 * Type of data detected. For possible values, see `TTDetectedMessageType`.
 */
@property (nullable, nonatomic, copy) NSNumber *type;

/**
 * NSDictionary of address components. This exists if `TTDetectedData` is of type `TTDetectedMessageTypeAddress`.
 */
@property (nullable, nonatomic, retain) NSObject *address;

/**
 * URL string that was detected from the message. This exists if `TTDetectedData` is of type `TTDetectedMessageTypeLink` or `TTDetectedMessageTypeImageLink` or `TTDetectedMessageTypeEmail`
 */
@property (nullable, nonatomic, copy) NSString *url;

/**
 * Phone number string that was detected from the message. This exists if `TTDetectedData` is of type `TTDetectedMessageTypePhoneNo`
 */
@property (nullable, nonatomic, copy) NSString *phoneNumber;

/**
 * The location that can be used to construct a `NSRange` object for representing the location of the detected data within a message text.
 */
@property (nullable, nonatomic, copy) NSNumber *rangeLocation;

/**
 * The length that can be used to construct a `NSRange` object for representing the location of the detected data within a message text.
 */
@property (nullable, nonatomic, copy) NSNumber *rangeLength;

/**
 * The message to which this `TTDetectedData` object belongs.
 */
@property (nullable, nonatomic, retain) TTMessage *message;

@end

NS_ASSUME_NONNULL_END
