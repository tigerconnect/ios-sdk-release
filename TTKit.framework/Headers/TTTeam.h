//
//  TTTeam.h
//  TTKit
//
//  Created by Oren Zitoun on 12/2/19.
//  Copyright © 2019 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TTUser, TTGroup, TTTeamRequest;

@interface TTTeam : NSManagedObject

@property (nullable, nonatomic, copy) NSString *token;
@property (nullable, nonatomic, copy) NSString *displayName;
@property (nullable, nonatomic, copy) NSString *teamDescription;
@property (nullable, nonatomic, copy) NSString *organizationToken;
@property (nullable, nonatomic, retain) NSNumber *canRequestToJoin;
@property (nullable, nonatomic, retain) NSNumber *canMembersLeave;
@property (nullable, nonatomic, retain) NSNumber *membersCount;
@property (nullable, nonatomic, retain) id pendingRequestUserTokens;
@property (nullable, nonatomic, retain) NSSet<TTTeamRequest *> *requests;
/**
 * The Team's Intra Group
 */
@property (nullable, nonatomic, retain) TTGroup *intraTeamGroup;

/**
 *  NSSet containing TTUser objects, representing all users which are members of this group.
 */
@property (nullable, nonatomic, retain) NSSet<TTUser *> *members;

- (BOOL)isUserTokenPartOfTeam:(NSString *_Nonnull)userToken;

@end
