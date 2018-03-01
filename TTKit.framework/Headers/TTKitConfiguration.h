//
//  TTKitConfiguration.h
//  TTKit
//
//  Created by Hemanth Prasad on 3/16/17.
//  Copyright © 2017 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTLogManager.h"

typedef NS_ENUM(NSInteger, TTKitPersistanceType) {
    TTKitPersistanceTypeDisk = 0,
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

@interface TTKitConfiguration : NSObject

- (instancetype)initWithAppGroupIdentifier:(NSString *)appGroupIdentifier;

@property (nonatomic) TTKitPersistanceType persistanceType;
@property (nonatomic) TTKitEnvironment environment;
@property (nonatomic) NSString *agentName;
@property (nonatomic, readonly) NSString *appGroupIdentifier;

- (void)setLogDelegate:(id<TTLogDelegate>)delegate logLevelFlag:(TTLogLevelFlag)logLevelFlag
       forComponentFlag:(TTLogComponentFlag)forComponentFlag;

@end
