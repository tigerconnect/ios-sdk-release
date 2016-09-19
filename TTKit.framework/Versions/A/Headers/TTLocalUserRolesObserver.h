//
//  TTLocalUserRolesObserver.h
//  TTKit
//
//  Created by Josh Hinman on 5/26/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TTLocalUserRolesObserver;
@class TTRosterEntry;

@protocol TTLocalUserRolesObserverDelegate <NSObject>

/**
 Notifies the delegate that the roles for the local user have changed
 */
- (void)rolesDidChange:(TTLocalUserRolesObserver *)observer;

@end

@class TTRole;

/**
 This handler is called after the user makes a selection in the role selector.
 
 @param cancelled if YES, the user tapped the "Cancel" button
 @param selectedRole The role that the user selected, or nil if the user selected their own name.
 */
typedef void (^TTRoleSelectorHandler)(BOOL cancelled, TTRole *selectedRole);

/**
 Provides a simple API for retrieving roles owned by the local user and watching for changes to those roles.
 This class should only be created, used, and deallocated on the main thread!
 */
@interface TTLocalUserRolesObserver : NSObject

@property (nonatomic, weak) id<TTLocalUserRolesObserverDelegate> delegate;

/**
 A set of roles owned by the local user
 */
@property (nonatomic, readonly) NSSet<TTRole *> *roles;

/**
 An action sheet that offers the user a choice of each role they currently own plus their own name.
 
 @param organizationToken Organization token, pass nil to show roles for all organizations

 */
- (UIAlertController *)roleSelectorWithTitle:(NSString *)title handler:(TTRoleSelectorHandler)handler organizationToken:(NSString *)organizationToken;

/**
 An action sheet that offers the user a choice of each role they currently own for a specific TTRosterEntry object.
 
 @param organizationToken Organization token, pass nil to show roles for all organizations
 
 */
- (UIAlertController *)rosterRoleSelectorWithTitle:(NSString *)title handler:(TTRoleSelectorHandler)handler rosterEntry:(TTRosterEntry *)rosterEntry organizationToken:(NSString *)organizationToken;

/**
 An action sheet that offers the user a choice of each role they currently own plus their own name in a roster entry.
 @param rosterEntry The TTRosterEntry for which the roles are requested for.
 */
- (UIAlertController *)roleSelectorAlertWithTitle:(NSString *)title handler:(TTRoleSelectorHandler)handler rosterEntry:(TTRosterEntry *)rosterEntry;


/**
 A set of roles owned by the local user for a given organization token.
 
 @param organizationToken Organization token, pass nil to retrieve roles for all organizations
 */
- (NSArray<TTRole *> *)rolesForOrganizationToken:(NSString *)organizationToken;

/**
 A set of acting roles by the local user for a given rosterEntry.
 
 @param rosterEntry The TTRosterEntry for which the roles are requested for.
 
 **/
- (NSSet<TTRole *> *)actingRolesForRoster:(TTRosterEntry *)rosterEntry;

@end
