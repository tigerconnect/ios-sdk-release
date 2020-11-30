//
//  TTMessageTemplate.h
//  TTKit
//
//  Created by Oren Zitoun on 7/27/20.
//  Copyright © 2020 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTUser, TTScheduleMessage;

@interface TTMessageTemplate : NSManagedObject

@property (nullable, nonatomic, copy) NSDate *createdOn;
@property (nullable, nonatomic, copy) NSString *network;
@property (nullable, nonatomic, copy) NSString *repository;
@property (nullable, nonatomic, copy) NSString *title;
@property (nullable, nonatomic, copy) NSString *token;
@property (nullable, nonatomic, copy) NSDate *updatedOn;
@property (nullable, nonatomic, copy) NSNumber *attachmentSize;
@property (nullable, nonatomic, copy) NSString *attachmentName;
@property (nullable, nonatomic, copy) NSString *attachmentType;
@property (nullable, nonatomic, copy) NSString *body;
@property (nullable, nonatomic, copy) NSString *organizationToken;
@property (nullable, nonatomic, retain) TTUser *createdBy;
@property (nullable, nonatomic, retain) TTUser *updatedBy;
@property (nullable, nonatomic, retain) NSSet<TTScheduleMessage *> *scheduleMessages;

@end
