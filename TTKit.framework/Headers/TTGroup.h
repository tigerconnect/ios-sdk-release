//
//  TTGroup.h
//  TTKit
//
//  Created by Oren Zitoun on 9/28/15.
//  Copyright © 2015 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTParty.h"

@class TTMessage, TTUser, TTRole, TTEscalation, TTPatient, TTTeam;

/**
 *  TTGroup is a class that represents a TigerText Group or Room.
 */
@interface TTGroup : TTParty

/**
 *  Boolean value. If YES, the group is public and the local user can join it.
 */
@property (nullable, nonatomic, retain) NSNumber *isPublic;

/**
 *  Boolean value. If YES, the local user is a part of this group.
 */
@property (nullable, nonatomic, retain) NSNumber *isUserPartOfGroup;

/**
 *  Boolean value. If YES, the group is a distribution list.
 */
@property (nullable, nonatomic, retain) NSNumber *isDistributionList;

/**
 *  NSSet containing TTUser objects, representing all users which are members of this group.
 */
@property (nullable, nonatomic, retain) NSSet<TTUser *> *members;

/**
 *  Last TTMessage received for this group.
 */
@property (nullable, nonatomic, retain) TTMessage *message;

/**
 * BOOL value to indicate whether to show history in the group when a new member joins.
 */
@property (nullable, nonatomic, retain) NSNumber *replayHistory;

/**
 *  Group messages count (only available for public groups/rooms for now).
 */
@property (nullable, nonatomic, retain) NSNumber *messagesCount;

/**
 *  Group members count (only available for public groups/rooms for now).
 */
@property (nullable, nonatomic, retain) NSNumber *roomMembersCount;

/**
 *  Group created date (only available for public groups/rooms for now).
 */
@property (nullable, nonatomic, retain) NSDate *createdTime;

/**
 *  Group description (only available for public groups/rooms for now).
 */
@property (nullable, nonatomic, retain) NSString *groupDescription;

/**
 *  Return the TTUser who created to group (only available for public groups/rooms for now).
 */
@property (nullable, nonatomic, retain) TTUser *createdBy;

@property (nullable, nonatomic, retain) TTEscalation *escalation;

/**
 * NSDictionary storing information about users in the group as roles.
 * @discussion A user is a "proxiedMember" if the user is in the group as the owner of a role.
 */
@property (nullable, nonatomic, retain) NSObject *proxiedMembers;

@property (nullable, nonatomic, retain) TTPatient *patient;

@property (nullable, nonatomic, retain) TTTeam *team;

/**
 *  Returns list of members who are Roles
 */
- (NSSet<TTRole *> * _Nullable)roleMembers;

/**
 * Checks whether the given user token belongs to a member of the group.
 */
- (BOOL)isUserTokenPartOfGroup:(NSString * _Nonnull)token;

/**
 * Checks whether the given user is a member of the group.
 */
- (BOOL)isUserPartOfGroup:(TTUser * _Nonnull)user;

/**
 * Checks whether the given user is in the group as the user, and not as a role owner.
 *
 @return YES if the user's user token is not in `proxiedMembers`.
 */
- (BOOL)isUserInGroupNotAsRoleOwner:(TTUser * _Nonnull)user;

/**
 * Checks whether this group belongs to an activated team
 *
 @return YES if this group belongs to an activated team.
 */
- (BOOL)isActivatedTeamGroup;

/**
 * Checks whether this group is an intra-team group.
 *
 @return YES if this group is an intra-team group.
 */
- (BOOL)isIntraTeamGroup;

@end
