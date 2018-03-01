//
//  TTShift.h
//  TTKit
//
//  Created by Josh Hinman on 10/26/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//  This file was automatically generated and should not be edited.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTUser, TTRole;

@interface TTShift : NSManagedObject

@property (nullable, nonatomic, copy) NSDate *start;
@property (nullable, nonatomic, copy) NSDate *end;
@property (nullable, nonatomic, copy) NSString *userToken;
@property (nullable, nonatomic, copy) NSString *roleToken;
@property (nullable, nonatomic, copy) NSString *organizationToken;
@property (nullable, nonatomic, copy) NSString *status;
@property (nullable, nonatomic, retain) TTUser *user;
@property (nullable, nonatomic, retain) TTRole *role;

@end
