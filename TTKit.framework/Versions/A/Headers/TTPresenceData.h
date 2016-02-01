//
//  TTPresenceData.h
//  TTKit
//
//  Created by Oren Zitoun on 5/1/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  When set to the type property, marks the respective TTUser as available
 */
FOUNDATION_EXPORT NSString *const kTTKitPresenceDataTypeAvailable;

/**
 *  When set to the type property, marks the respective TTUser as unavailable
 */
FOUNDATION_EXPORT NSString *const kTTKitPresenceDataTypeUnavailable;

/**
 *  TTPresenceData describes a user's status in the system - mostly if he is online or not, while providing the user's status as well.
 */
@interface TTPresenceData : NSObject

/**
 *  Token of TTUser to which of which presence data is detailed in this insatnce.
 */
@property (nonatomic, strong) NSString *userToken;

/**
 *  If type equals 'available', the available property will be YES. Any other value switches it to 'NO'.
 */
@property (nonatomic, strong) NSString *type;

/**
 *  User’s status message tagline.
 */
@property (nonatomic, strong) NSString *status;

/**
 *  YES when user is available, NO otherwise.
 */
@property (nonatomic, assign) BOOL available;

/**
 * Block that is called when Presence data type is changed
 */
@property (nonatomic, copy) void (^typeChangedBlock)(NSString*);

/**
 * Block that is called when Presence data status is changed
 */
@property (nonatomic, copy) void (^statusChangedBlock)(NSString*);

/**
 * Nilifies status and type presence changed blocks
 */
- (void)prepareForReuse;

@end
