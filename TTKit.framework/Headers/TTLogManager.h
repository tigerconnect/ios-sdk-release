//
//  TTLoggingService.h
//  TTKit
//
//  Created by Hemanth Prasad on 11/22/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTLogMessage.h"

@class TTLogManager;

/**
 @abstract The `TTLogDelegate` notifies its receiver when a new log message is received.
 */
@protocol TTLogDelegate <NSObject>

- (void)logManager:(TTLogManager *)logManager didReceiveMessage:(TTLogMessage *)message;

@end

/**
 Use a TTLogManager instance to receive log message from TTKit.
 */
@interface TTLogManager : NSObject

/**
 Set the delegate property to receive log messages.
 */
@property (nonatomic, weak) id<TTLogDelegate> delegate;

/**
 The userToken you initalized TTLogManager with.
 */
@property (nonatomic, readonly) NSString *userToken;

/**
 Initialize a TTLogManager instance with the local user's token.
 @param userToken user token.
 @return An TTLogManager Object.
 */
- (instancetype)initWithUserToken:(NSString *)userToken;

/**
 Set the log and component levels as a filter for TTLogManager.
 @param logLevelFlag TTLogLevelFlag filter type.
 @param componentFlag TTLogComponentFlag filter type.
 */
- (void)setLogLevelFlag:(TTLogLevelFlag)logLevelFlag
       forComponentFlag:(TTLogComponentFlag)componentFlag;

@end
