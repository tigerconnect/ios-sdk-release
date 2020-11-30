//
//  TTParty.h
//  TTKit
//
//  Created by Oren Zitoun on 6/10/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTMetadata, TTRosterEntry, TTCallLog, TTScheduleMessage;

/**
 *  TTParty is an abstract class, inherited by TTUser and TTGroup.
 */
@interface TTParty : NSManagedObject

/**
 *  URL of the TTParty's avatar.
 */
@property (nullable, nonatomic, retain) NSString *avatarURL;

/**
 A set of capabilities that are disabled for this party.
 */
@property (nullable, nonatomic, retain) NSSet<NSString *> *disabledCapabilities;

/**
 *  encrypted display name.
 */
@property (nullable, nonatomic, retain) NSData *encryptedDisplayName;

/**
 *  TTParty's display name.
 */
@property (nullable, nonatomic, retain) NSString *displayName;

/**
 *  Boolean. YES if all of the party's details were retrieved from server, NO otherwise.
 */
@property (nullable, nonatomic, retain) NSNumber *hollow;

/**
 *  Last active time.
 */
@property (nullable, nonatomic, retain) NSDate *lastActivityDate;

/**
 *  YES while object wasn't updated to server yet, NO otherwise.
 */
@property (nullable, nonatomic, retain) NSNumber *local;

/**
 *  Token of the organization to which this TTParty belongs.
 */
@property (nullable, nonatomic, retain) NSString *organizationToken;

/**
 *  Object Token. Internal.
 */
@property (nonnull, nonatomic, retain) NSString * token;

/**
 *  All TTMessages received by this TTParty.
 */
@property (nullable, nonatomic, retain) NSSet *receivedMessages;

/**
 *  All TTRosterEntries related to this TTParty.
 */
@property (nullable, nonatomic, retain) NSSet *rosterEntries;

/**
 *  All TTMessages sent by this TTParty.
 */
@property (nullable, nonatomic, retain) NSSet *sentMessages;

/**
 *  All TTMetadata related to this TTParty.
 */
@property (nullable, nonatomic, retain) NSSet *metadata;

/**
 *  Should TTParty ignore any api update.
 */
@property (nonatomic, assign) BOOL ignoreApiUpdates;

/**
 *  Is TTParty currently muted on server.
 */
@property (nullable, nonatomic, retain) NSNumber *isMuted;

/**
 *  If TTParty is currently muted, containes the mute start time
 */
@property (nullable, nonatomic, retain) NSDate *muteEndTime;

/**
 *  Indicates if TTParty belongs to any service (like alerts).
 */
@property (nullable, nonatomic, retain) NSString *service;

/**
 *  Inverse relationship from TTCallLog caller.
 */
@property (nullable, nonatomic, retain) NSSet<TTCallLog *> *callLogCaller;

/**
 *  Inverse relationship from TTCallLog taget.
 */
@property (nullable, nonatomic, retain) NSSet<TTCallLog *> *callLogTarget;

@property (nullable, nonatomic, retain) NSSet<TTScheduleMessage *> *scheduleMessages;

@end

@interface TTParty (CoreDataGeneratedAccessors)

///-------------------------------------------------------
/// @name Metadata
///-------------------------------------------------------

/**
 *  Add a TTMetadata object to this TTParty.
 *
 *  @param value A TTMetadata object.
 */
- (void)addMetadataObject:(TTMetadata *_Nonnull)value;

/**
 *  Remove a TTMetadata object from this TTParty.
 *
 *  @param value A TTRosterEntry object.
 */
- (void)removeMetadataObject:(TTMetadata *_Nonnull)value;

/**
 *  Add multiple TTMetadata objects to this TTParty.
 *
 *  @param values NSSet of TTMetadata objects.
 */
- (void)addMetadata:(NSSet *_Nonnull)values;

/**
 *  Remove multiple TTMetadata objects from this TTParty.
 *
 *  @param values NSSet of TTMetadata objects.
 */
- (void)removeMetadata:(NSSet *_Nonnull)values;

///-------------------------------------------------------
/// @name Capabilities
///-------------------------------------------------------

/**
 *  Is this user available to receive calls?
 */
- (BOOL)canReceiveCallsWithOrganizationToken:(NSString *_Nonnull)orgToken;

@end
