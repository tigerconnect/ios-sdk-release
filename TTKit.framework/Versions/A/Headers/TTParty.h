//
//  TTParty.h
//  TTKit
//
//  Created by Oren Zitoun on 6/10/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTMetadata, TTRosterEntry;

/**
 *  TTParty is an abstract class, inherited by TTUser and TTGroup.
 */
@interface TTParty : NSManagedObject

/**
 *  URL of the TTParty's avatar.
 */
@property (nonatomic, retain) NSString * avatarURL;

/**
 *  encrypted display name.
 */
@property (nonatomic, retain) NSData * encryptedDisplayName;

/**
 *  TTParty's display name.
 */
@property (nonatomic, retain) NSString * displayName;

/**
 *  Boolean. YES if all of the party's details were retrieved from server, NO otherwise.
 */
@property (nonatomic, retain) NSNumber * hollow;

/**
 *  Last active time.
 */
@property (nonatomic, retain) NSDate * lastActivityDate;

/**
 *  YES while object wasn't updated to server yet, NO otherwise.
 */
@property (nonatomic, retain) NSNumber * local;

/**
 *  Token of the organization to which this TTParty belongs.
 */
@property (nonatomic, retain) NSString * organizationToken;

/**
 *  Object Token. Internal.
 */
@property (nonatomic, retain) NSString * token;

/**
 *  All TTMessages received by this TTParty.
 */
@property (nonatomic, retain) NSSet *receivedMessages;

/**
 *  All TTRosterEntries related to this TTParty.
 */
@property (nonatomic, retain) NSSet *rosterEntries;

/**
 *  All TTMessages sent by this TTParty.
 */
@property (nonatomic, retain) NSSet *sentMessages;

/**
 *  All TTMetadata related to this TTParty.
 */
@property (nonatomic, retain) NSSet *metadata;

/**
 *  Should TTParty ignore any api update.
 */
@property (nonatomic, assign) BOOL ignoreApiUpdates;

/**
 *  Is TTParty currently muted on server.
 */
@property (nonatomic, retain) NSNumber *isMuted;

/**
 *  If TTParty is currently muted, containes the mute start time
 */
@property (nonatomic, retain) NSDate *muteEndTime;

@end

@interface TTParty (CoreDataGeneratedAccessors)

///-------------------------------------------------------
/// @name Received Messages
///-------------------------------------------------------

/**
 *  Add a TTMessage to this TTParty's received messages.
 *
 *  @param value A TTMessage object.
 */
- (void)addReceivedMessagesObject:(TTMessage *)value;

/**
 *  Remove a TTMessage from this TTParty's received messages.
 *
 *  @param value A TTMessage object.
 */
- (void)removeReceivedMessagesObject:(TTMessage *)value;

/**
 *  Add multiple TTMessages to this TTParty's received messages.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)addReceivedMessages:(NSSet *)values;

/**
 *  Remove multiple TTMessages from this TTParty's received messages.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)removeReceivedMessages:(NSSet *)values;

///-------------------------------------------------------
/// @name Sent Messages
///-------------------------------------------------------

/**
 *  Add a TTMessage to this TTParty's sent messages.
 *
 *  @param value A TTMessage object.
 */
- (void)addSentMessagesObject:(TTMessage *)value;

/**
 *  Remove a TTMessage from this TTParty's sent messages.
 *
 *  @param value A TTMessage object.
 */
- (void)removeSentMessagesObject:(TTMessage *)value;

/**
 *  Add multiple TTMessages to this TTParty's sent messages.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)addSentMessages:(NSSet *)values;

/**
 *  Remove multiple TTMessages from this TTParty's sent messages.
 *
 *  @param values NSSet of TTMessage objects.
 */
- (void)removeSentMessages:(NSSet *)values;

///-------------------------------------------------------
/// @name Rosters
///-------------------------------------------------------

/**
 *  Add a TTRosterEntry to this TTParty's roster entries (i.e. add a group or a user to a conversation).
 *
 *  @param value A TTRosterEntry object.
 */
- (void)addRosterEntriesObject:(TTRosterEntry *)value;

/**
 *  Remove a TTRosterEntry from this TTParty's roster entries (i.e. remove a group or a user from a conversation).
 *
 *  @param value A TTRosterEntry object.
 */
- (void)removeRosterEntriesObject:(TTRosterEntry *)value;

/**
 *  Add multiple TTRosterEntry objects to this TTParty's roster entries.
 *
 *  @param values NSSet of TTRosterEntry objects.
 */
- (void)addRosterEntries:(NSSet *)values;

/**
 *  Remove multiple TTRosterEntry objects from this TTParty's roster entries.
 *
 *  @param values NSSet of TTRosterEntry objects.
 */
- (void)removeRosterEntries:(NSSet *)values;

///-------------------------------------------------------
/// @name Metadata
///-------------------------------------------------------

/**
 *  Add a TTMetadata object to this TTParty.
 *
 *  @param value A TTMetadata object.
 */
- (void)addMetadataObject:(TTMetadata *)value;

/**
 *  Remove a TTMetadata object from this TTParty.
 *
 *  @param value A TTRosterEntry object.
 */
- (void)removeMetadataObject:(TTMetadata *)value;

/**
 *  Add multiple TTMetadata objects to this TTParty.
 *
 *  @param values NSSet of TTMetadata objects.
 */
- (void)addMetadata:(NSSet *)values;

/**
 *  Remove multiple TTMetadata objects from this TTParty.
 *
 *  @param values NSSet of TTMetadata objects.
 */
- (void)removeMetadata:(NSSet *)values;

@end
