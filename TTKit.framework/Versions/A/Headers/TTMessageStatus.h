//
//  TTMessageStatus.h
//  TTKit
//
//  Created by Oren Zitoun on 10/3/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTUser;

@interface TTMessageStatus : NSManagedObject

@property (nonatomic, retain) NSString * messageToken;
@property (nonatomic, retain) NSString * status;
@property (nonatomic, retain) NSDate * timestamp;
@property (nonatomic, retain) NSString * userToken;
@property (nonatomic, retain) TTMessage *message;
@property (nonatomic, retain) TTUser *user;

@end
