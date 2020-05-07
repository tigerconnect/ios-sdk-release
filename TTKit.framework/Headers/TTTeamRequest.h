//
//  TTTeamRequest.h
//  TTKitTests
//
//  Created by Oren Zitoun on 12/13/19.
//  Copyright © 2019 TigerText, Inc. All rights reserved.
//

@class TTTeam, TTUser, TTMessage;

@interface TTTeamRequest : NSManagedObject

@property (nullable, nonatomic, copy) NSString *organizationToken;
@property (nullable, nonatomic, copy) NSString *token;
@property (nullable, nonatomic, copy) NSString *reason;
@property (nullable, nonatomic, copy) NSString *status;
@property (nullable, nonatomic, retain) TTMessage *message;
@property (nullable, nonatomic, retain) TTUser *createdBy;
@property (nullable, nonatomic, retain) TTUser *handledBy;
@property (nullable, nonatomic, retain) TTTeam *team;

@end
