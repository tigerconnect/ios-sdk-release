//
//  TTScheduleMessage+CoreDataClass.h
//  TTKit
//
//  Created by Oren Zitoun on 7/14/20.
//  Copyright © 2020 TigerText, Inc. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTUser, TTParty, TTMessageTemplate;

@interface TTScheduleMessage : NSManagedObject

@property (nullable, nonatomic, copy) NSString *token;
@property (nullable, nonatomic, copy) NSString *attachmentName;
@property (nullable, nonatomic, copy) NSNumber *attachmentSize;
@property (nullable, nonatomic, copy) NSString *attachmentType;
@property (nullable, nonatomic, copy) NSString *body;
@property (nullable, nonatomic, copy) NSDate *createdOn;
@property (nullable, nonatomic, copy) NSDate *scheduledTime;
@property (nullable, nonatomic, copy) NSDate *endDate;
@property (nullable, nonatomic, copy) NSString *status;
@property (nullable, nonatomic, copy) NSString *network;
@property (nullable, nonatomic, copy) NSNumber *noReply;
@property (nullable, nonatomic, copy) NSNumber *processedCount;
@property (nullable, nonatomic, copy) NSString *repeating;
@property (nullable, nonatomic, copy) NSNumber *remainingCount;
@property (nullable, nonatomic, copy) NSDate *startDate;
@property (nullable, nonatomic, copy) NSString *startTime;
@property (nullable, nonatomic, copy) NSString *templateId;
@property (nullable, nonatomic, copy) NSString *templateName;
@property (nullable, nonatomic, copy) NSString *timezoneName;
@property (nullable, nonatomic, copy) NSDate *updatedOn;
@property (nullable, nonatomic, retain) TTUser *createdBy;
@property (nullable, nonatomic, retain) TTParty *recipient;
@property (nullable, nonatomic, retain) TTUser *updatedBy;
@property (nullable, nonatomic, retain) TTMessageTemplate *messageTemplate;
@property (nullable, nonatomic, copy) NSString *organizationToken;
@property (nullable, nonatomic, copy) NSNumber *numMembers;
@property (nullable, nonatomic, copy) NSString *eventId;

@end
