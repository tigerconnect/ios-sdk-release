//
//  TTMessageStatus.h
//  TTKit
//
//  Created by Oren Zitoun on 10/3/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTUser, TTRole;

@interface TTMessageStatus : NSManagedObject

@property (nonnull, nonatomic, retain) NSString *messageToken;
@property (nullable, nonatomic, retain) NSString *status;
@property (nullable, nonatomic, retain) NSDate *timestamp;
@property (nonnull, nonatomic, retain) NSString *userToken;
@property (nullable, nonatomic, retain) TTMessage *message;
@property (nullable, nonatomic, retain) TTUser *user;
@property (nullable, nonatomic, retain) TTRole *role;

@end
