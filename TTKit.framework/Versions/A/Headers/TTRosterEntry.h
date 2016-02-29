//
//  TTRosterEntry.h
//  TTKit
//
//  Created by Oren Zitoun on 8/8/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTOrganization, TTParty, TTUser;

/**
 *  A TTRosterEntry is a conversation. The conversation may have several properties which are detailed below. A TTRosterEntry must always have a target, which can be a TTUser or a TTGroup (both inherit from TTParty).
 */
@interface TTRosterEntry : NSManagedObject

/**
 *  URL of the TTRosterEntry’s avatar.
 */
@property (nonatomic, retain) NSString * avatarUrl;

/**
 *  Conversation hash. Can be used to retrieve related objects, such as TTMessages.
 */
@property (nonatomic, retain) NSString * conversationHash;

/**
 *  Display name of the roster entry.
 */
@property (nonatomic, retain) NSData * encryptedDisplayName;

/**
 *  Display name of the roster entry.
 */
@property (nonatomic, retain) NSString * displayName;

/**
 *  When set to YES, TTRosterEntry can only be deleted locally. Default is NO.
 */
@property (nonatomic, retain) NSNumber * ignoreApiUpdate;

/**
 *  YES if the TTRosterEntry’s target is a TTGroup.
 */
@property (nonatomic, retain) NSNumber * isGroup;

/**
 *  YES if the TTRosterEntry’s target is a TTUser.
 */
@property (nonatomic, retain) NSNumber * isUser;

/**
 *  Organization token of the TTOrganization to which the TTRosterEntry belongs to.
 */
@property (nonatomic, retain) NSString * organizationToken;

/**
 *  Latest message received or sent for this TTRosterEntry. Epoch format.
 */
@property (nonatomic, retain) NSNumber * timestamp;

/**
 *  TTRosterEntry token. Internal, use conversationHash instead.
 */
@property (nonatomic, retain) NSString * token;

/**
 *  When set to YES, TTRosterEntry can only be deleted locally. Default is NO.
 */
@property (nonatomic, retain) NSString * title;

/**
 *  When set to YES, TTRosterEntry can only be deleted locally. Default is NO.
 */
@property (nonatomic, retain) NSString * department;

/**
 *  Latest TTMessage related to this TTRosterEntry.
 */
@property (nonatomic, retain) TTMessage *latestMessage;

/**
 *  TTOrganization related to this TTRosterEntry.
 */
@property (nonatomic, retain) TTOrganization *organization;

/**
 *  The target of the TTRosterEntry. Can be a TTUser or a TTGroup (both inherit from TTParty).
 */
@property (nonatomic, retain) TTParty *target;

/**
 *  Do not disturb state
 */
@property (nonatomic, retain) NSNumber * dnd;

/**
 *  Do not disturb text
 */
@property (nonatomic, retain) NSString * dndText;

/**
 *  Original Autoforwarding receiver token set by the roster target user in a P2P conversation.
 */
@property (nonatomic, retain) NSString * autoforwardReceiver;

/**
 *  Convenience getter for autoforwardReceiver is non-empty, when autoforward is enabled.
 */
@property (readonly) BOOL autoforward;

@end
