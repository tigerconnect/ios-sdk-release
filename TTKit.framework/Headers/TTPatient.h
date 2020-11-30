//
//  TTPatient.h
//  TTKit
//
//  Created by Oren Zitoun on 9/3/19.
//  Copyright © 2019 TigerText, Inc. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import "TTUser.h"

@class TTPatientContact;

@interface TTPatient : TTUser

@property (nullable, nonatomic, copy) NSDate *dob;
@property (nullable, nonatomic, copy) NSString *gender;
@property (nullable, nonatomic, copy) NSString *mrn;
@property (nullable, nonatomic, retain) NSSet<TTPatientContact *> *contacts;
@property (nullable, nonatomic, retain) NSSet<TTGroup *> *patientGroups;

/**
 *  Did Patient opted out of sms messages. Boolean value.
 */
@property (nullable, nonatomic, retain) NSNumber * isOptedOut;

@end

@interface TTPatient (CoreDataGeneratedAccessors)

- (void)addContactsObject:(TTPatientContact *_Nonnull)value;
- (void)removeContactsObject:(TTPatientContact *_Nonnull)value;
- (void)addContacts:(NSSet<TTPatientContact *> *_Nonnull)values;
- (void)removeContacts:(NSSet<TTPatientContact *> *_Nonnull)values;

@end
