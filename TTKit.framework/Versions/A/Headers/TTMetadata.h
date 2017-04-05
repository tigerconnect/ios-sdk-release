//
//  TTMetadata.h
//  TTKit
//
//  Created by Oren Zitoun on 1/13/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage, TTParty;

NS_ASSUME_NONNULL_BEGIN

@interface TTMetadata : NSManagedObject

/**
 *  Key of the stored metadata value.
 */
@property (nullable, nonatomic, retain) NSString *key;

/**
 *  String to be used as mimeType.
 */
@property (nullable, nonatomic, retain) NSString *type;

/**
 *  Metadata value.
 */
@property (nullable, nonatomic, retain) id value;

/**
 *  TTMessage to which this TTMetadata instance is linked.
 */
@property (nullable, nonatomic, retain) TTMessage *message;

/**
 *  TTParty to which this TTMetadata instance is linked.
 */
@property (nullable, nonatomic, retain) TTParty *party;

@end

NS_ASSUME_NONNULL_END
