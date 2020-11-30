//
//  TTPatientForwardMessageMetadata.h
//  TTKit
//
//  Created by Yuxi Lin on 10/23/19.
//  Copyright © 2019 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TTPatientForwardMessageMetadata : NSObject

@property (nonnull, nonatomic, retain) NSString *patientToken;
@property (nonnull, nonatomic, retain) NSString *patientName;
@property (nonnull, nonatomic, retain) NSString *patientMRN;
@property (nullable, nonatomic, retain) NSDate *patientDOB;
@property (nullable, nonatomic, retain) NSString *patientGender;

@property (nullable, nonatomic, retain) NSString *contactToken;
@property (nullable, nonatomic, retain) NSString *contactName;
@property (nullable, nonatomic, retain) NSString *contactRelation;

@property (nullable, nonatomic, retain) NSString *groupName;

+ (TTPatientForwardMessageMetadata * _Nullable)parseMetadataPayload:(NSDictionary * _Nonnull)metadata;

@end

