//
//  TTMessageStatus.h
//  TTKit
//
//  Created by Oren Zitoun on 10/3/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTUser, TTRole;

@interface TTMessageStatus : NSManagedObject

/**
 * Identifying token of the message with this message status.
 */
@property (nonnull, nonatomic, retain) NSString *messageToken;

/**
 * NSString of the status.
 * @discussion Possible values: kTTKitMessageStatusSending, kTTKitMessageStatusSent, kTTKitMessageStatusFailed, kTTKitMessageStatusRead, kTTKitMessageStatusToBeRead, kTTKitMessageStatusDelivered, kTTKitMessageStatusNew.
 */
@property (nullable, nonatomic, retain) NSString *status;

/**
 * Time of the last change to message status.
 */
@property (nullable, nonatomic, retain) NSDate *timestamp;

/**
 * Token of the user that sent the message.
 */
@property (nonnull, nonatomic, retain) NSString *userToken;

/**
 * Message object with this message status.
 */
@property (nullable, nonatomic, retain) TTMessage *message;

/**
 * User object with `userToken` as its token.
 */
@property (nullable, nonatomic, retain) TTUser *user;

/**
 * Role object that sent the message. When setting `user` property, if `user` is of type `TTRole`, then `role` is set as well.
 */
@property (nullable, nonatomic, retain) TTRole *role;

@end
