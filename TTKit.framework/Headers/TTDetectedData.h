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

typedef NS_ENUM(NSInteger, TTDetectedMessageType)
{
    TTDetectedMessageTypeNone = 0,
    TTDetectedMessageTypeAddress = 1,
    TTDetectedMessageTypeLink = 2,
    TTDetectedMessageTypeImageLink = 3,
    TTDetectedMessageTypePhoneNo = 4,
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
 * The location that can be used to construct a `NSRange` object for representing the location of the detected data.
 */
@property (nullable, nonatomic, copy) NSNumber *rangeLocation;

/**
 * The length that can be used to construct a `NSRange` object for representing the location of the detected data.
 */
@property (nullable, nonatomic, copy) NSNumber *rangeLength;

/**
 * The message to which this `TTDetectedData` object belongs.
 */
@property (nullable, nonatomic, retain) TTMessage *message;

@end

NS_ASSUME_NONNULL_END
