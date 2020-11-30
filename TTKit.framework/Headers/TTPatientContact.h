//
//  TTPatientContact.h
//  TTKit
//
//  Created by Oren Zitoun on 9/3/19.
//  Copyright © 2019 TigerText, Inc. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import "TTUser.h"

@class TTPatient;

@interface TTPatientContact : TTUser

@property (nullable, nonatomic, copy) NSString *patientToken;
@property (nullable, nonatomic, copy) NSString *relationName;
@property (nullable, nonatomic, retain) NSSet<TTPatient *> *patients;

/**
 *  Did Patient Contact opted out of sms messages. Boolean value.
 */
@property (nullable, nonatomic, retain) NSNumber * isOptedOut;


@end

@interface TTPatientContact (CoreDataGeneratedAccessors)

- (void)addPatientsObject:(TTPatient *_Nonnull)value;
- (void)removePatientsObject:(TTPatient *_Nonnull)value;
- (void)addPatients:(NSSet<TTPatient *> *_Nonnull)values;
- (void)removePatients:(NSSet<TTPatient *> *_Nonnull)values;

@end
