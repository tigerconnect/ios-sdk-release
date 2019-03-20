//
//  TTUser.h
//  TTKit
//
//  Created by Oren Zitoun on 5/22/15.
//  Copyright (c) 2015 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "TTParty.h"

@class TTShift;

@class TTGroup, TTMessage, TTMessageStatus, TTRole, TTRoleGroup, TTEscalation, TTEscalationPolicy;

@interface TTUser : TTParty

/**
 *  User’s email address.
 */
@property (nullable, nonatomic, retain) NSString *emailAddress;

/**
 *  User’s first name.
 */
@property (nullable, nonatomic, retain) NSString *firstName;

/**
 *  User’s last name.
 */
@property (nullable, nonatomic, retain) NSString *lastName;

/**
 *  User’s home phone.
 */
@property (nullable, nonatomic, retain) NSString *phoneHome;

/**
 *  User’s mobile phone.
 */
@property (nullable, nonatomic, retain) NSString *phoneMobile;

/**
 *  User’s office phone.
 */
@property (nullable, nonatomic, retain) NSString *phoneOffice;

/**
 *  The user’s customizable status message tagline.
 */
@property (nullable, nonatomic, retain) NSString *status;

/**
 *  Username.
 */
@property (nullable, nonatomic, retain) NSString *username;

/**
 *  Do not disturb enabled (use boolValue).
 */
@property (nullable, nonatomic, retain) NSNumber *dnd;

/**
 *  Do not disturb custom message.
 */
@property (nullable, nonatomic, retain) NSString *dndText;

/**
 *  User's Title.
 */
@property (nullable, nonatomic, retain) NSString *title;

/**
 *  User's Department.
 */
@property (nullable, nonatomic, retain) NSString *department;

/**
 *  Account type.
 */
@property (nullable, nonatomic, retain) NSString *accountType;

/**
 *  All related group message status objects.
 */
@property (nullable, nonatomic, retain) NSSet<TTMessageStatus *> *messageStatuses;

/**
 *  Public groups created by the User.
 */
@property (nullable, nonatomic, retain) NSSet<TTGroup *> *createdGroups;

/**
 *  All TTGroups of which this TTUser is a member of.
 */
@property (nullable, nonatomic, retain) NSSet *groups;

/**
 *  All methods forwarded message from this user (inverse relationship for message.originalSender).
 */
@property (nullable, nonatomic, retain) NSSet *forwardedMessages;

/**
 *  All rosters autoforwarding to this user (inverse relationship for rosterEntry.autoforwardRecipient).
 */
@property (nullable, nonatomic, retain) NSSet *autoforwardRosters;

/**
 *  All rosters assumed by the user.
 */
@property (nullable, nonatomic, retain) NSSet<TTRole *> *roles;

/**
 *  Inverse relashionship with TTRoleGroup target.
 */
@property (nullable, nonatomic, retain) NSSet<TTRoleGroup *> *roleGroups;

/**
 * Set of shifts that belongs to this user.
 */
@property (nullable, nonatomic, retain) NSSet<TTShift *> *userShifts;

/**
 * Inverse relationship to TTEscalation's backup1.
 * @discussion This value is only not empty when this user is a backup1 for an escalation event.
 */
@property (nullable, nonatomic, retain) TTEscalation *escalationTarget1;

/**
 * Inverse relationship to TTEscalation's backup2.
 * @discussion This value is only not empty when this user is a backup2 for an escalation event.
 */
@property (nullable, nonatomic, retain) TTEscalation *escalationTarget2;

/**
 * Inverse relationship to TTEscalationPolicy's backup1.
 * @discussion This value is only not empty when this user is a backup1 for an escalation policy.
 */
@property (nullable, nonatomic, retain) TTEscalationPolicy *escalationPolicyTarget1;

/**
 * Inverse relationship to TTEscalationPolicy's backup2.
 * @discussion This value is only not empty when this user is a backup2 for an escalation policy.
 */
@property (nullable, nonatomic, retain) TTEscalationPolicy *escalationPolicyTarget2;

/**
 * Inverse relationship to TTEscalation's actionUser.
 * @discussion This value is only not empty when this user has taken some action (cancel or acknowledge) in an escalation event.
 */
@property (nullable, nonatomic, retain) NSSet<TTEscalation *> *escalationAction;

@end

@interface TTUser (CoreDataGeneratedAccessors)

/**
 *  Add a forwarded TTMessage to this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)addForwardedMessagesObject:(TTMessage * _Nonnull)value;

/**
 *  Remove a forwarded TTMessage from this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)removeForwardedMessagesObject:(TTMessage *_Nonnull)value;

/**
 *  Add multiple forwarded TTMessages to this TTUser.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)addForwardedMessages:(NSSet<TTMessage *> *_Nonnull)values;

/**
 *  Remove multiple forwarded TTMessages from this TTUser.
 *
 *  @param values NSSet of TTUser objects.
 */
- (void)removeForwardedMessages:(NSSet<TTMessage *> *_Nonnull)values;


/**
 *  Add an autoforwarded TTMessage to this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)addAutoforwardedMessagesObject:(TTMessage *_Nonnull)value;

/*
 *  Remove an autoforwarded TTMessage from this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)removeAutoforwardedMessagesObject:(TTMessage *_Nonnull)value;

/**
 *  Add multiple autoforwarded TTMessages to this TTUser.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)addAutoforwardedMessages:(NSSet<TTMessage *> *_Nonnull)values;

/**
 *  Remove multiple autoforwarded TTMessages from this TTUser.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)removeAutoforwardedMessages:(NSSet<TTMessage *> *_Nonnull)values;

/**
 *  Add this TTUser to a TTGroup.
 *
 *  @param value A TTGroup object.
 */
- (void)addGroupsObject:(TTGroup *_Nonnull)value;

/**
 *  Remove this TTUser from a TTGroup.
 *
 *  @param value A TTGroup Object.
 */
- (void)removeGroupsObject:(TTGroup *_Nonnull)value;

/**
 *  Add this TTUser to multiple TTGroups.
 *
 *  @param values NSSet of TTGroup objects.
 */
- (void)addGroups:(NSSet<TTGroup *> * _Nonnull)values;

/**
 *  Remove this TTUser from multiple groups.
 *
 *  @param values NSSet of TTGroup objects.
 */
- (void)removeGroups:(NSSet<TTGroup *> * _Nonnull)values;

/**
 *  Add a Pulic Group created by the user.
 *
 *  @param value A TTGroup object.
 */
- (void)addCreatedGroupsObject:(TTGroup * _Nonnull)value;

/**
 *  Remove a Pulic Group created by the user.
 *
 *  @param value A TTGroup object.
 */
- (void)removeCreatedGroupsObject:(TTGroup * _Nonnull)value;

/**
 *  Add Public Groups created by the user.
 *
 *  @param values NSSet of TTGroup objects.
 */
- (void)addCreatedGroups:(NSSet<TTGroup *> * _Nonnull)values;

@end
