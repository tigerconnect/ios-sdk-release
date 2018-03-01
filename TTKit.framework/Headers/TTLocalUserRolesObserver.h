//
//  TTLocalUserRolesObserver.h
//  TTKit
//
//  Created by Josh Hinman on 5/26/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TTLocalUserRolesObserver, TTRole, TTRosterEntry;

NS_ASSUME_NONNULL_BEGIN

@protocol TTLocalUserRolesObserverDelegate <NSObject>

/**
 Notifies the delegate that the roles for the local user have changed
 */
- (void)rolesDidChange:(TTLocalUserRolesObserver *)observer;

@end

/**
 This handler is called after the user makes a selection in the role selector.
 
 @param cancelled if YES, the user tapped the "Cancel" button
 @param selectedRole The role that the user selected, or nil if the user selected their own name.
 */
typedef void (^TTRoleSelectorHandler)(BOOL cancelled, TTRole *_Nullable selectedRole);

/**
 Provides a simple API for retrieving roles owned by the local user and watching for changes to those roles.
 This class should only be created, used, and deallocated on the main thread!
 */
@interface TTLocalUserRolesObserver : NSObject

@property (nonatomic, weak, nullable) id<TTLocalUserRolesObserverDelegate> delegate;

/**
 A set of roles owned by the local user
 */
@property (nonatomic, readonly) NSSet<TTRole *> *roles;

/**
 
 @param userToken The local user token you wish to track role changes for.
 
 **/
- (instancetype)initWithUserToken:(NSString *)userToken;

#if TARGET_OS_IOS

/**
 An action sheet that offers the user a choice of each role they currently own plus their own name.
 
 @param organizationToken Organization token, pass nil to show roles for all organizations

 */
- (nullable UIAlertController *)roleSelectorWithTitle:(nullable NSString *)title handler:(TTRoleSelectorHandler)handler organizationToken:(nullable NSString *)organizationToken;

/**
 An action sheet that offers the user a choice of each role they currently own for a specific TTRosterEntry object.
 
 @param organizationToken Organization token, pass nil to show roles for all organizations
 
 */
- (nullable UIAlertController *)rosterRoleSelectorWithTitle:(nullable NSString *)title handler:(TTRoleSelectorHandler)handler rosterEntry:(TTRosterEntry *)rosterEntry;

/**
 An action sheet that offers the user a choice of each role they currently own plus their own name in a roster entry.
 @param rosterEntry The TTRosterEntry for which the roles are requested for.
 */
- (nullable UIAlertController *)roleSelectorAlertWithTitle:(nullable NSString *)title handler:(TTRoleSelectorHandler)handler rosterEntry:(TTRosterEntry *)rosterEntry;

#endif

/**
 A set of roles owned by the local user for a given organization token.
 
 @param organizationToken Organization token, pass nil to retrieve roles for all organizations
 */
- (NSArray<TTRole *> *)rolesForOrganizationToken:(nullable NSString *)organizationToken;

/**
 A set of acting roles by the local user for a given rosterEntry.
 
 @param rosterEntry The TTRosterEntry for which the roles are requested for.
 
 **/
- (NSSet<TTRole *> *)actingRolesForRoster:(TTRosterEntry *)rosterEntry;


/**
 A set of acting roles by the local user for a given group.
 
 @param rosterEntry The TTgroup for which the roles are requested for.
 
 **/
- (NSSet<TTRole *> *)actingRolesForGroup:(TTGroup *)group organizationToken:(NSString *)organizationToken;


- (NSArray *)roleTokens;

@end

NS_ASSUME_NONNULL_END
