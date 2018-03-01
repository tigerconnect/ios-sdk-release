//
//  TTOrganization.h
//  TTKit
//
//  Created by Oren Zitoun on 2/13/15.
//  Copyright (c) 2015 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTRosterEntry;

@interface TTOrganization : NSManagedObject

/**
 *  Delete on read defaut setting for all TTMessages related to organization. Not used for now.
 */
@property (nullable, nonatomic, retain) NSNumber *dor;

/**
 *  Organization's name.
 */
@property (nonnull, nonatomic, retain) NSString *name;

/**
 *  Number of members in the organization.
 */
@property (nonnull, nonatomic, retain) NSNumber *numberOfMembers;

/**
 *  Is organization paid or not. Boolean value.
 */
@property (nonnull, nonatomic, retain) NSNumber *paid;

/**
 *  Is organization approved or pending. Boolean value
 */
@property (nonnull, nonatomic, retain) NSNumber *pending;

/**
 *  Pending email address. String value
 */
@property (nullable, nonatomic, retain) NSString *pendingEmail;

/**
 *  Is organization approved by admin. Boolean value
 */
@property (nullable, nonatomic, retain) NSNumber *pendingAdminApproval;

/**
 *  Is organization useing pinLock. Boolean value.
 */
@property (nullable, nonatomic, retain) NSNumber *pinLock;

/**
 *  Organization's token.
 */
@property (nonnull, nonatomic, retain) NSString *token;

/**
 *  Time to live default value for all TTMessages related to organization. Unused for now.
 */
@property (nullable, nonatomic, retain) NSNumber *ttl;

/**
 *  NSSet containing all TTRosterEntries related to the TTOrganization.
 */
@property (nullable, nonatomic, retain) NSSet *rosterEntries;

/**
 * Are the settings for this organization locked? Boolean value.
 */
@property (nullable, nonatomic, retain) NSNumber *settingsLocked;

/**
 * If on no outbound messaging is allowed.
 */
@property (nullable, nonatomic, retain) NSNumber *blocked;

/**
 *  Is TTOrganization currently muted on server.
 */
@property (nullable, nonatomic, retain) NSNumber *isMuted;

/**
 *  If TTOrganization is currently muted, contains the mute end time
 */
@property (nullable, nonatomic, retain) NSDate *muteEndTime;


@property (nonatomic, assign)   BOOL ignoreApiUpdates;
@end

@interface TTOrganization (CoreDataGeneratedAccessors)

/**
 *  Add a TTRosterEntry to the organization.
 *
 *  @param value A TTRosterEntry.
 */
//- (void)addRosterEntriesObject:(TTRosterEntry *_Nonnull)value;

/**
 *  Remove a TTRosterEntry from the organization.
 *
 *  @param value A TTRosterEntry.
 */
//- (void)removeRosterEntriesObject:(TTRosterEntry *_Nonnull)value;

/**
 *  Add multiple TTRosterEntry objects to the organization.
 *
 *  @param values NSSet containing TTRosterEntry objects.
 */
//- (void)addRosterEntries:(NSSet *_Nonnull)values;

/**
 *  Remove multiple TTRosterEntry objects from the organization.
 *
 *  @param values NSSet containing TTRosterEntry objects.
 */
//- (void)removeRosterEntries:(NSSet *_Nonnull)values;

@end

