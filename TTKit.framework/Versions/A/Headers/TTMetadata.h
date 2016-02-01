//
//  TTMetadata.h
//  TTKit
//
//  Created by Oren Zitoun on 6/10/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTParty;

/**
 *  TTMetadata enables developers the ability to add customized values to specific model objects (Mainly a TTParty, TTGroup, TTUser and TTMessage) by which objects can later be filtered and searched.
 */
@interface TTMetadata : NSManagedObject

/**
 *  Key of the stored metadata value.
 */
@property (nonatomic, retain) NSString * key;

/**
 *  Unused for now.
 */
@property (nonatomic, retain) NSString * type;

/**
 *  Metadata value.
 */
@property (nonatomic, retain) NSString * value;

/**
 *  TTParty to which this TTMetadata instance is linked.
 */
@property (nonatomic, retain) TTParty *party;

/**
 *  TTMessage to which this TTMetadata instance is linked.
 */
@property (nonatomic, retain) TTMessage *message;

@end
