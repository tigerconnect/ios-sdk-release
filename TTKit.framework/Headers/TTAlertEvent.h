//
//  TTAlertEvent+CoreDataClass.h
//  TTKit
//
//  Created by Oren Zitoun on 10/27/17.
//  Copyright © 2017 TigerText, Inc. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class NSObject, TTMessage;

@interface TTAlertEvent : NSManagedObject

@property (nullable, nonatomic, retain) NSObject *data;
@property (nullable, nonatomic, copy) NSString *organizationToken;
@property (nullable, nonatomic, copy) NSString *type;
@property (nullable, nonatomic, copy) NSNumber *priority;
@property (nullable, nonatomic, retain) TTMessage *message;

@end
