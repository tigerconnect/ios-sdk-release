//
//  TTProxyContactsHelper.h
//  TTKit
//
//  Created by Josh Hinman on 8/24/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A "proxy number" is a phone number that can stands in for a person's real number
 so the real number can be masked. This class's job is to add these proxy numbers
 temporarily to the local contacts database, so the real caller's name shows up
 in the caller ID.
 */
@interface TTProxyContactsHelper : NSObject

/**
 Adds a new contact with the given phone number and name
 
 @returns YES if the contact was created, NO if it wasn't.
 */
- (BOOL)createContactForProxyNumber:(NSString *)number name:(NSString *)name;

/**
 Removes a previously-added contact.
 
 @returns YES if the contact was removed, NO if it wasn't (or couldn't be found)
 */
- (void)removeContactForProxyNumber:(NSString *)number completion:(void(^)(void))completion;

/**
 Removes all the contacts previously added.
 
 @returns YES if all numbers were successfully removed, NO if there were errors.
 */
- (void)removeAllProxyNumbers;

@end
