//
//  TTRole.h
//  TTKit
//
//  Created by Oren Zitoun on 6/16/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTUser.h"

@class TTMessage, TTMessageStatus, TTTag, TTShift;

@interface TTRole : TTUser

@property (nullable, nonatomic, retain) NSNumber *isOptingOut;
@property (nullable, nonatomic, retain) NSNumber *locked;
@property (nullable, nonatomic, retain) NSNumber *replayHistory;
@property (nullable, nonatomic, retain) NSString *roleDescription;
@property (nullable, nonatomic, retain) NSNumber *saved;
@property (nullable, nonatomic, retain) NSSet<TTMessage *> *messages;
@property (nullable, nonatomic, retain) NSSet<TTMessageStatus *> *messageStatus;
@property (nullable, nonatomic, retain) NSSet<TTUser *> *owners;
@property (nullable, nonatomic, retain) TTTag *tag;
@property (nullable, nonatomic, retain) NSSet<TTShift *> *roleShifts;

@end
