//
//  TTKitConfiguration.h
//  TTKit
//
//  Created by Hemanth Prasad on 3/16/17.
//  Copyright © 2017 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTLogManager.h"

/**
 *  Enumeration for data persistent type.
 */
typedef NS_ENUM(NSInteger, TTKitPersistanceType) {
    
    /**
     *  Indicates that data is allowed to be stored on disk.
     */
    TTKitPersistanceTypeDisk = 0,
    
    /**
     *  Indicates that data is not allowed to be stored on disk, and must be stored in memory only.
     */
    TTKitPersistanceTypeMemoryOnly = 1
};

/**
 *  TTKitEnvironment types
 */
typedef NS_ENUM(NSUInteger, TTKitEnvironment){
    /**
     *  Production environment
     */
    TTKitEnvironmentProduction = 0,
    /**
     *  Test environment
     */
    TTKitEnvironmentTest,
};

/**
 * Object used to configure TTKit
 */
@interface TTKitConfiguration : NSObject

- (instancetype _Nonnull)initWithAppGroupIdentifier:(NSString * _Nullable)appGroupIdentifier enviroment:(TTKitEnvironment)enviroment;

/**
 * A value that specifies whether information gets stored on disk or strictly in memory
 */
@property (nonatomic) TTKitPersistanceType persistanceType;

/**
 * A value that specifies whether TTKit hits production environment endpoints or test environment endpoints
 */
@property (nonatomic, readonly) TTKitEnvironment environment;

/**
 * A string that identifies your developer account.
 */
@property (nonatomic, nullable) NSString *agentName;

/**
 * An identifier for the app group that is used to setup a shared resources directory to use with extensions.
 */
@property (nonatomic, readonly, nullable) NSString *appGroupIdentifier;

/**
 Sets the log manager and configures it based on params.

 @param delegate A delegate object for the log manager
 @param logLevelFlag A value indicating how specific logging should be. For possible values, see `TTLogLevelFlag`
 @param forComponentFlag A value indicating what type of information should be logged. For possible values, see `TTLogComponentFlag`.
 */
- (void)setLogDelegate:(id<TTLogDelegate> _Nullable)delegate logLevelFlag:(TTLogLevelFlag)logLevelFlag
       forComponentFlag:(TTLogComponentFlag)forComponentFlag;

@end
