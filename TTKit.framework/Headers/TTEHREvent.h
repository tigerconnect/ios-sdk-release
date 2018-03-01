//
//  TTEHREvent+CoreDataClass.h
//  TTKit
//
//  Created by Oren Zitoun on 6/29/17.
//  Copyright © 2017 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class NSObject, TTMessage, TTEHRMeasurement;

@interface TTEHREvent : NSManagedObject

@property (nullable, nonatomic, retain) NSObject *data;
@property (nullable, nonatomic, copy) NSString *organizationToken;
@property (nullable, nonatomic, copy) NSString *type;
@property (nullable, nonatomic, retain) TTMessage *message;
@property (nullable, nonatomic, retain) NSSet<TTEHRMeasurement *> *ehrMeasurements;

@end


