//
//  TTGroup.h
//  TTKit
//
//  Created by Oren Zitoun on 9/28/15.
//  Copyright © 2015 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTParty.h"

@class TTMessage, TTUser, TTRole;

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

/**
 *  Returns list of members who are Roles
 */
- (NSSet<TTRole *> * _Nullable)roleMembers;

- (BOOL)isUserTokenPartOfGroup:(NSString * _Nonnull)token;

- (BOOL)isUserPartOfGroup:(TTUser * _Nonnull)user;

@end
