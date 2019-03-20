//
//  TTShift.h
//  TTKit
//
//  Created by Josh Hinman on 10/26/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//  This file was automatically generated and should not be edited.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTUser, TTRole;

/**
 * NSManagedObject representation of a shift for a role.
 */
@interface TTShift : NSManagedObject

/**
 * Date representing the start of the shift
 */
@property (nullable, nonatomic, copy) NSDate *start;

/**
 * Date representing the end of the shift.
 */
@property (nullable, nonatomic, copy) NSDate *end;

/**
 * The token of the user that has this shift.
 */
@property (nullable, nonatomic, copy) NSString *userToken;

/**
 * The token of the role that has this shift.
 */
@property (nullable, nonatomic, copy) NSString *roleToken;

/**
 * Token of the organization where this shift exists.
 */
@property (nullable, nonatomic, copy) NSString *organizationToken;

/**
 * Status of the shift.
 * @note The status string "blackout" is used for off hours,
 */
@property (nullable, nonatomic, copy) NSString *status;

/**
 * The user that has this shift.
 */
@property (nullable, nonatomic, retain) TTUser *user;

/**
 * The role that has this shift.
 */
@property (nullable, nonatomic, retain) TTRole *role;

@end
