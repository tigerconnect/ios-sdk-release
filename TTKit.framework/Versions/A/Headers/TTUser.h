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

NS_ASSUME_NONNULL_BEGIN

@class TTGroup, TTMessage, TTMessageStatus, TTRole, TTRoleGroup;

@interface TTUser : TTParty

/**
 *  User’s email address.
 */
@property (nonatomic, retain) NSString *emailAddress;

/**
 *  User’s first name.
 */
@property (nonatomic, retain) NSString *firstName;

/**
 *  User’s last name.
 */
@property (nonatomic, retain) NSString *lastName;

/**
 *  User’s home phone.
 */
@property (nonatomic, retain) NSString *phoneHome;

/**
 *  User’s mobile phone.
 */
@property (nonatomic, retain) NSString *phoneMobile;

/**
 *  User’s office phone.
 */
@property (nonatomic, retain) NSString *phoneOffice;

/**
 *  The user’s customizable status message tagline.
 */
@property (nonatomic, retain) NSString *status;

/**
 *  Username.
 */
@property (nonatomic, retain) NSString *username;

/**
 *  Do not disturb enabled (use boolValue).
 */
@property (nonatomic, retain) NSNumber *dnd;

/**
 *  Do not disturb custom message.
 */
@property (nonatomic, retain) NSString *dndText;

/**
 *  User's Title.
 */
@property (nonatomic, retain) NSString *title;

/**
 *  User's Department.
 */
@property (nonatomic, retain) NSString *department;

/**
 *  Account type.
 */
@property (nonatomic, retain) NSString *accountType;

/**
 *  All related group message status objects.
 */
@property (nonatomic, retain) NSSet<TTMessageStatus *> *messageStatuses;

/**
 *  Public groups created by the User.
 */
@property (nonatomic, retain) NSSet<TTGroup *> *createdGroups;

/**
 *  All TTGroups of which this TTUser is a member of.
 */
@property (nonatomic, retain) NSSet *groups;

/**
 *  All methods forwarded message from this user (inverse relationship for message.originalSender).
 */
@property (nonatomic, retain) NSSet *forwardedMessages;

/**
 *  All rosters autoforwarding to this user (inverse relationship for rosterEntry.autoforwardRecipient).
 */
@property (nonatomic, retain) NSSet *autoforwardRosters;

/**
 *  All rosters assumed by the user.
 */
@property (nullable, nonatomic, retain) NSSet<TTRole *> *roles;

/**
 *  Inverse relashionship with TTRoleGroup target.
 */
@property (nullable, nonatomic, retain) NSSet<TTRoleGroup *> *roleGroups;

@end

@interface TTUser (CoreDataGeneratedAccessors)

/**
 *  Add a forwarded TTMessage to this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)addForwardedMessagesObject:(TTMessage *)value;

/**
 *  Remove a forwarded TTMessage from this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)removeForwardedMessagesObject:(TTMessage *)value;

/**
 *  Add multiple forwarded TTMessages to this TTUser.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)addForwardedMessages:(NSSet<TTMessage *> *)values;

/**
 *  Remove multiple forwarded TTMessages from this TTUser.
 *
 *  @param values NSSet of TTUser objects.
 */
- (void)removeForwardedMessages:(NSSet<TTMessage *> *)values;


/**
 *  Add an autoforwarded TTMessage to this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)addAutoforwardedMessagesObject:(TTMessage *)value;

/*
 *  Remove an autoforwarded TTMessage from this TTUser.
 *
 *  @param value A TTMessage object.
 */
- (void)removeAutoforwardedMessagesObject:(TTMessage *)value;

/**
 *  Add multiple autoforwarded TTMessages to this TTUser.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)addAutoforwardedMessages:(NSSet<TTMessage *> *)values;

/**
 *  Remove multiple autoforwarded TTMessages from this TTUser.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)removeAutoforwardedMessages:(NSSet<TTMessage *> *)values;

/**
 *  Add this TTUser to a TTGroup.
 *
 *  @param value A TTGroup object.
 */
- (void)addGroupsObject:(TTGroup *)value;

/**
 *  Remove this TTUser from a TTGroup.
 *
 *  @param value A TTGroup Object.
 */
- (void)removeGroupsObject:(TTGroup *)value;

/**
 *  Add this TTUser to multiple TTGroups.
 *
 *  @param values NSSet of TTGroup objects.
 */
- (void)addGroups:(NSSet<TTGroup *> *)values;

/**
 *  Remove this TTUser from multiple groups.
 *
 *  @param values NSSet of TTGroup objects.
 */
- (void)removeGroups:(NSSet<TTGroup *> *)values;

/**
 *  Add a Pulic Group created by the user.
 *
 *  @param value A TTGroup object.
 */
- (void)addCreatedGroupsObject:(TTGroup *)value;

/**
 *  Remove a Pulic Group created by the user.
 *
 *  @param value A TTGroup object.
 */
- (void)removeCreatedGroupsObject:(TTGroup *)value;

/**
 *  Add Public Groups created by the user.
 *
 *  @param values NSSet of TTGroup objects.
 */
- (void)addCreatedGroups:(NSSet<TTGroup *> *)values;

@end

NS_ASSUME_NONNULL_END

