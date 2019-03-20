//
//  TTEscalation.h
//  TTKit
//
//  Created by Oren Zitoun on 11/9/18.
//  Copyright © 2018 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

/**
 * An object representing an escalation occurrence. Each escalation occurrence follows the rules of an escalation policy.
 */
@interface TTEscalation : NSManagedObject

/**
 * Date of the last action taken (escalation cancelled, escalation acknowledged)
 */
@property (nullable, nonatomic, copy) NSDate *actionDate;

/**
 * Username of the user who took the last action.
 */
@property (nullable, nonatomic, copy) NSString *actionUserName;

/**
 * User token of the user who took the last action.
 */
@property (nullable, nonatomic, copy) NSString *actionUserToken;

/**
 * BOOL indicating whether escalation is always on for every message sent to the target.
 */
@property (nullable, nonatomic, copy) NSNumber *alwaysEscalate;

/**
 * Amount of time in minutes allowed for the first back up role/user to answer before message gets sent to the second back up role/user.
 */
@property (nullable, nonatomic, copy) NSNumber *backup1EscalationDuration;

/**
 * Amount of time in minutes allowed for the second back up role/user to answer before escalation is marked with a "No Response" resolution.
 */
@property (nullable, nonatomic, copy) NSNumber *backup2EscalationDuration;

/**
 * Amount of time the escalation group exists after escalation has completed (acknowledged, no response or cancelled).
 */
@property (nullable, nonatomic, copy) NSNumber *destructionDuration;

/**
 * The token that appears in the title "ESCALATION #`displayToken`".
 */
@property (nullable, nonatomic, copy) NSString *displayToken;

/**
 * Amount of time in minutes allowed for the initial recipient to answer before message gets sent to the first back up role/user.
 */
@property (nullable, nonatomic, copy) NSNumber *escalationDuration;

/**
 * The token that identifies the group created for the escalation.
 */
@property (nullable, nonatomic, copy) NSString *escalationGroupToken;

/**
 * The token that identifies the escalated message.
 */
@property (nullable, nonatomic, copy) NSString *escalationMessageToken;

/**
 * The date that the escalation expires (Shown in the escalation banner as "... This conversation expires `expireDate`").
 */
@property (nullable, nonatomic, copy) NSDate *expireDate;

/**
 * The number representing where the escalation is in its lifecycle.
 *
 * @discussion
 * level 0: escalated to original recipient.
 *
 * level 1: escalated to first back up role/user.
 *
 * level 2: escalated to second back up role/user.
 */
@property (nullable, nonatomic, copy) NSNumber *level;

/**
 * The token that identifies the organization in which the escalation exists.
 */
@property (nullable, nonatomic, copy) NSString *orgToken;

/**
 ? * The token of the message that triggered the escalation.
 */
@property (nullable, nonatomic, copy) NSString *originalMessageToken;

/**
 * The token of the initial recipient.
 */
@property (nullable, nonatomic, copy) NSString *originalRecipientToken;

/**
 * String representing the current status of the escalation.
 *
 * @discussion
 * Possible values:
 *
 * `kTTKitEscalationStatusEscalated`
 *
 * `kTTKitEscalationStatusInProgress`
 *
 * `kTTKitEscalationStatusAcknowledged`
 *
 * `kTTKitEscalationStatusCancelled`
 *
 * `kTTKitEscalationStatusNoResponse`
 *
 * `kTTKitEscalationStatusConversationEscalated`
 */
@property (nullable, nonatomic, copy) NSString *status;

/**
 * String token that identifies the escalation.
 */
@property (nullable, nonatomic, copy) NSString *token;

/**
 * Initial recipient of the escalated message.
 */
@property (nullable, nonatomic, retain) TTRole *originalTarget;

/**
 * The object that represents the user who took the last action (escalation cancelled, escalation acknowledged)
 * @note `actionUserToken` is `actionUser`'s token.
 */
@property (nullable, nonatomic, retain) TTUser *actionUser;

/**
 * Role/user to which the message gets sent after the initial recipient opts to skip or after the `escalationDuration` time expires before the initial recipient responds.
 */
@property (nullable, nonatomic, retain) NSSet<TTUser *> *backup1;

/**
 * Role/user to which the message gets sent after the first back up role/user opts to skip or after the `backup1EscalationDuration` time expires before the first back up role/user responds.
 */
@property (nullable, nonatomic, retain) NSSet<TTUser *> *backup2;

/**
 * The group created after the initial recipient does not respond or chooses to skip.
 */
@property (nullable, nonatomic, retain) TTGroup *escalationGroup;

/**
 * Contains the message that triggered the escalation and the escalated message.
 */
@property (nullable, nonatomic, retain) NSSet<TTMessage *> *messages;

@end
