//
//  TTEscalationPolicy+CoreDataClass.h
//  TTKitTests
//
//  Created by Oren Zitoun on 11/28/18.
//  Copyright © 2018 TigerText, Inc. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTUser;

@class TTRole, TTUser;

/**
 * TTEscalationPolicy contains the rules for escalated messages sent to a specific role.
 * @discussion
 * Rules include how long to wait before escalating to the backup recipients, whom to message after the current recipient did not respond, and how long the group is kept alive after the escalation has resolved.
 */
@interface TTEscalationPolicy : NSManagedObject

/**
 * Policy's identifying token
 */
@property (nullable, nonatomic, copy) NSString *token;

/**
 * BOOL indicating whether escalation is always on for every message sent to the target.
 */
@property (nullable, nonatomic, copy) NSNumber *alwaysEscalate;

/**
 * Amount of time the escalation group exists after escalation has completed (acknowledged, no response or cancelled).
 */
@property (nullable, nonatomic, copy) NSNumber *destructionDuration;

/**
 * Amount of time in minutes allowed for the initial recipient to answer before message gets sent to the first back up role/user.
 */
@property (nullable, nonatomic, copy) NSNumber *targetDuration;

/**
 * Amount of time in minutes allowed for the first back up role/user to answer before message gets sent to the second back up role/user.
 */
@property (nullable, nonatomic, copy) NSNumber *backup1EscalationDuration;

/**
 * Amount of time in minutes allowed for the second back up role/user to answer before escalation is marked with a "No Response" resolution.
 */
@property (nullable, nonatomic, copy) NSNumber *backup2EscalationDuration;

/**
 * Role/user to which the message gets sent after the initial recipient opts to skip or after the `targetDuration` time expires before the initial recipient responds.
 */
@property (nullable, nonatomic, retain) NSSet<TTUser *> *backup1;

/**
 * Role/user to which the message gets sent after the first back up role/user opts to skip or after the `backup1EscalationDuration` time expires before the first back up role/user responds.
 */
@property (nullable, nonatomic, retain) NSSet<TTUser *> *backup2;

/**
 * Initial recipient of the escalated message.
 */
@property (nullable, nonatomic, retain) TTRole *role;

@end
