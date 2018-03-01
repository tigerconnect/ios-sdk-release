//
//  TTLogMessage.h
//  TTKit
//
//  Created by Hemanth Prasad on 11/23/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TTLogComponent){
    TTLogComponentUndefined,
    TTLogComponentInitialization,
    TTLogComponentNetworking,
    TTLogComponentDataPersistance
};

static inline TTLogComponent TTLogComponentLast() { return TTLogComponentDataPersistance; }

typedef NS_ENUM(NSUInteger, TTLogLevel){
    TTLogLevelOff,
    TTLogLevelError,
    TTLogLevelWarn,
    TTLogLevelInfo,
    TTLogLevelDebug,
    TTLogLevelVerbose
};

static inline TTLogLevel TTLogLevelLast() { return TTLogLevelVerbose; }

typedef NS_OPTIONS(NSUInteger, TTLogLevelFlag){
    TTLogLevelFlagOff        = (1 << 0),
    TTLogLevelFlagError      = (1 << 1),
    TTLogLevelFlagWarn       = (1 << 2),
    TTLogLevelFlagInfo       = (1 << 3),
    TTLogLevelFlagDebug      = (1 << 4),
    TTLogLevelFlagVerbose    = (1 << 5),
    TTLogLevelFlagAll        = INT_MAX
};

static inline TTLogLevelFlag TTLogLevelFlagLast() { return TTLogLevelFlagVerbose; }

typedef NS_OPTIONS(NSUInteger, TTLogComponentFlag){
    TTLogComponentFlagUndefined         = (1 << 0),
    TTLogComponentFlagInitialization    = (1 << 1),
    TTLogComponentFlagNetworking        = (1 << 2),
    TTLogComponentFlagDataPersistance   = (1 << 3),
    TTLogComponentFlagAll               = INT_MAX
};

static inline TTLogComponentFlag TTLogComponentFlagLast() { return TTLogComponentFlagDataPersistance; }

/**
 *  TTLogMessage represent a log object containing the text, date and component.
 */

@interface TTLogMessage : NSObject

/**
 *  The text property contains the log message text.
 */
@property (nonatomic, readonly) NSString *text;

/**
 *  The date property contains the log date.
 */
@property (nonatomic, readonly) NSDate *date;

/**
 *  The logLevel property refers to the severity or category of the log.
 */
@property (nonatomic, readonly) TTLogLevel logLevel;

/**
 *  The logComponent property refers component of the log.
 */
@property (nonatomic, readonly) TTLogComponent logComponent;

@end
