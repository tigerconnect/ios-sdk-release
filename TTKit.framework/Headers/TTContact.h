//
//  TTContact.h
//  TTKit
//
//  Created by Oren Zitoun on 6/20/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

/**
 *  TTContact represents a contact from the device’s address book. New TTContacts will be added upon AddressBook updates.
 */
@interface TTContact : NSManagedObject

/**
 *  Contact’s composite name (full name + prefix, suffix).
 */
@property (nullable, nonatomic, retain) NSString * compositeName;

/**
 *  Contact’s encrypted emails.
 */
@property (nullable, nonatomic, retain) NSData * encryptedEmails;

/**
 *  Contact’s emails.
 */
@property (nullable, nonatomic, retain) NSString * emailsString;

/**
 *  Contact’s first name.
 */
@property (nullable, nonatomic, retain) NSString * firstName;

/**
 *  Unique hash id. For internal use.
 */
@property (nullable, nonatomic, retain) NSString * hashId;

/**
 *  Index of contact in the device’s address book.
 */
@property (nullable, nonatomic, retain) NSNumber * index;

/**
 *  Contact’s initials.
 */
@property (nullable, nonatomic, retain) NSString * initials;

/**
 *  Contact’s last name.
 */
@property (nullable, nonatomic, retain) NSString * lastName;

/**
 *  Contact’s middle name.
 */
@property (nullable, nonatomic, retain) NSString * middleName;

/**
 *  Contact’s full name.
 */
@property (nullable, nonatomic, retain) NSString * name;

/**
 *  Organizations’s name.
 */
@property (nullable, nonatomic, retain) NSString * organization;

/**
 *  Contact’s encrypted phone numbers.
 */
@property (nullable, nonatomic, retain) NSData * encryptedPhoneNumbers;


/**
 *  Contact’s phone numbers string.
 */
@property (nullable, nonatomic, retain) NSString * phoneNumbersString;

/**
 *  Contacts unique token.
 */
@property (nullable, nonatomic, retain) NSString * token;

/**
 *  Local path to Contact's avatar.
 */
@property (nullable, nonatomic, retain) NSString * avatarUrl;

/**
 *  Retrieve Contact's emails.
 *
 *  @return An NSArray of NSDicitionaries with the emails and their type (such as 'Home','Work' etc).
 */
- (NSArray *_Nullable)getEmailAddresses;

/**
 *  Retrieve Contact's phone numbers.
 *
 *  @return An NSArray of NSDicitionaries with the phone numberss and their type (such as 'Home','Work' etc).
 */

- (NSArray *_Nullable)getPhoneNumbers;

@end
