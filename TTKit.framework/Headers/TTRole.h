//
//  TTRole.h
//  TTKit
//
//  Created by Oren Zitoun on 6/16/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTUser.h"

@class TTMessage, TTMessageStatus, TTTag, TTShift, TTEscalationPolicy, TTEscalation;

@interface TTRole : TTUser

/**
 * A BOOL value indicating whether there is a user in the process of opting out of the role.
 */
@property (nullable, nonatomic, retain) NSNumber *isOptingOut;

/**
 * BOOL that indicates if this role can ever be without an owner.
 */
@property (nullable, nonatomic, retain) NSNumber *ownerRequired;

/**
 * BOOL that indicates whether the role can be assigned to anyone.
 * @discussion When a role is not locked, it can be assigned to anyone.
 */
@property (nullable, nonatomic, retain) NSNumber *locked;

/**
 * BOOL value indicating whether to show role history when user opts into the role.
 */
@property (nullable, nonatomic, retain) NSNumber *replayHistory;

/**
 * Description of role.
 */
@property (nullable, nonatomic, retain) NSString *roleDescription;

/**
 * Automated response set for the role.
 */
@property (nullable, nonatomic, retain) NSString *awayStatus;

/**
 * BOOL value indicating whether this role has been added to "Saved Roles" for a user.
 */
@property (nullable, nonatomic, retain) NSNumber *saved;

/**
 * Set of messages associated with this role.
 */
@property (nullable, nonatomic, retain) NSSet<TTMessage *> *messages;

/**
 * Set of message statuses of the messages that are associated with this role.
 */
@property (nullable, nonatomic, retain) NSSet<TTMessageStatus *> *messageStatus;

/**
 * Set of owners of this role.
 * @note Currently `owners` set only contains a max of one user.
 */
@property (nullable, nonatomic, retain) NSSet<TTUser *> *owners;

/**
 * Role tag that can be used to filter in a list of roles.
 */
@property (nullable, nonatomic, retain) TTTag *tag;

/**
 * Escalation policy associated with this role.
 */
@property (nullable, nonatomic, retain) TTEscalationPolicy *escalationPolicy;

/**
 * Shifts associated with this role.
 */
@property (nullable, nonatomic, retain) NSSet<TTShift *> *roleShifts;

/**
 * Inverse relationship to TTEscalation's originalTarget.
 * @discussion This is only not empty when role is set to be the original target in an escalation event.
 */
@property (nullable, nonatomic, retain) TTEscalation *escalationOriginalTarget;

@end
