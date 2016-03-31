//
//  TTMessage.h
//  TTKit
//
//  Created by Oren Zitoun on 2/24/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

typedef NS_ENUM(NSInteger, TTMessageType) {
    TTMessageTypeNormal = 0,
    TTMessageTypeAutoforwardNotification,
};

typedef NS_ENUM(NSInteger, TTMessagePriority) {
    TTMessagePriorityNormal = 0,
    TTMessagePriorityHigh = 1,
};

@class TTAttachmentDescriptor, TTGroup, TTMessageStatus, TTMetadata, TTParty, TTRosterEntry, TTUser;

NS_ASSUME_NONNULL_BEGIN

/**
 *  A TTMessage object represents a message.
 */
@interface TTMessage : NSManagedObject

/**
 *  The actual message string.
 */
@property (nonatomic, retain) NSString * body;

/**
 *  Conversation hash of the message.
 */
@property (nonatomic, retain) NSString * conversationHash;

/**
 *  Time the message was created.
 */
@property (nonatomic, retain) NSDate * createdTime;

/**
 *  Delete on read. Boolean value, sets message ttl to 60 seconds.
 */
@property (nonatomic, retain) NSNumber * dor;

/**
 *  If dor property is YES, expired property will be YES once expireTime has passed.
 */
@property (nonatomic, retain) NSNumber * expired;

/**
 *  Time the TTMessage will expire.
 */
@property (nonatomic, retain) NSDate * expireTime;

/**
 *  Boolean value. If YES this message was forwarded from another user.
 */
@property (nonatomic, retain) NSNumber * forward;

/**
 *  Int16 value, mapped to TTAutoforwardType enumeration.
 */
@property (nonatomic, retain) NSNumber * autoforward;

/**
 *  Boolean value. Yes if the message has not updated on the server, NO otherwise.
 */
@property (nonatomic, retain) NSNumber * isLocal;

/**
 *  Local token used until TTMessage is saved to server.
 */
@property (nonatomic, retain, nullable) NSString * localToken;

/**
 *  Organization token to which the message is related.
 */
@property (nonatomic, retain) NSString * orgToken;

/**
 *  Original Sender's name for the forwarded message.
 */
@property (nonatomic, readonly) NSString * originalSenderDisplayName DEPRECATED_ATTRIBUTE;

/**
 *  Original Sender token for the forwarded message.
 */
@property (nonatomic, readonly) NSString * originalSenderToken DEPRECATED_ATTRIBUTE;

/**
 *  Original creation date for forwarded message.
 */
@property (nonatomic, retain) NSDate   * originalTimestamp;

/**
 *  Organization token of the TTMessage’s recepient.
 */
@property (nonatomic, retain) NSString * recipientOrganizationToken;

/**
 *  Organization token of the TTMessage’s sender.
 */
@property (nonatomic, retain) NSString * senderOrganizationToken;

/**
 *  Arrival index of this TTMessage’s instance.
 */
@property (nonatomic, retain) NSNumber * sortNumber;

/**
 *  When sortNumber property reached it’s max value, sortSeries will be incremented by 1 to create a new series.
 */
@property (nonatomic, retain) NSNumber * sortSeries;

/**
 *  TTMessage status. See TTKit for possible values.
 */
@property (nonatomic, retain) NSString * status;

/**
 *  Object Token. Internal use.
 */
@property (nonatomic, retain) NSString * token;

/**
 *  TTMessage’s time to live in minutes.
 */
@property (nonatomic, retain) NSNumber * ttl;

/**
 *  Whether this TTMessage is a bang or not.
 */
@property (nonatomic, retain) NSNumber * isBang;

/**
 *  An NSOrderedSet containing all TTAttachmentDescriptors, which describe all attachments to this message.
 */
@property (nonatomic, retain, nullable) NSOrderedSet *attachmentDescriptors;

/**
 *  The related group to this message.
 */
@property (nonatomic, retain, nullable) TTGroup *group;

/**
 *  An NSSet containing all status event for a group message with more than 1 receipent.
 */
@property (nonatomic, retain, nullable) NSSet *messageStatus;

/**
 *  All metadata related to this message.
 */
@property (nonatomic, retain, nullable) NSSet *metadata;

/**
 *  The recipient. Can be either a TTGroup or a TTUser.
 */
@property (nonatomic, retain) TTParty *recipient;

/**
 *  TTRosterEntry to which this message relates.
 */
@property (nonatomic, retain) TTRosterEntry *rosterEntry;

/**
 *  The sender. Can be either a TTGroup or a TTUser.
 */
@property (nonatomic, retain) TTParty *sender;

/**
 *  The original sender of a forwarded message.
 */
@property (nonatomic, retain, nullable) TTUser *originalSender;

/**
 *  The user of an autoforwarded message.
 */
@property (nonatomic, retain, nullable) TTUser *autoforwardUser;

/**
 *  Placeholder string, not being used
 */
@property (nonatomic, retain, nullable) NSString *groupStatus;

/**
 *  Indicates the type of message (0 = normal, 1 = DND Auto-Forward notification)
 */
@property (nonatomic, retain) NSNumber *messageType;

/**
 *  Indicates if the message is of higher priority (0 = normal, 1 = High priority)
 */
@property (nullable, nonatomic, retain) NSNumber *priority;

/**
 *  Indicates message was a system-generated automated message,
 *  Example: DND Auto-Forward reciever set/unset notifications.
 */
@property (readonly) BOOL isAutomatedMessage;

/**
 *  For internal use, should not be changed.
 */
@property (nonatomic, retain) NSNumber * sendDelivered;

@property (nonatomic) BOOL ignoreApiUpdates;
@property (nonatomic) NSData *encryptedBody;

- (void)retrySendingMessage;

@end

@interface TTMessage (CoreDataGeneratedAccessors)

- (void)insertObject:(TTAttachmentDescriptor *)value inAttachmentDescriptorsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromAttachmentDescriptorsAtIndex:(NSUInteger)idx;
- (void)insertAttachmentDescriptors:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeAttachmentDescriptorsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInAttachmentDescriptorsAtIndex:(NSUInteger)idx withObject:(TTAttachmentDescriptor *)value;
- (void)replaceAttachmentDescriptorsAtIndexes:(NSIndexSet *)indexes withAttachmentDescriptors:(NSArray *)values;
- (void)addAttachmentDescriptorsObject:(TTAttachmentDescriptor *)value;
- (void)removeAttachmentDescriptorsObject:(TTAttachmentDescriptor *)value;
- (void)addAttachmentDescriptors:(NSOrderedSet *)values;
- (void)removeAttachmentDescriptors:(NSOrderedSet *)values;
- (void)addMessageStatusObject:(TTMessageStatus *)value;
- (void)removeMessageStatusObject:(TTMessageStatus *)value;
- (void)addMessageStatus:(NSSet *)values;
- (void)removeMessageStatus:(NSSet *)values;

- (void)addMetadataObject:(TTMetadata *)value;
- (void)removeMetadataObject:(TTMetadata *)value;
- (void)addMetadata:(NSSet *)values;
- (void)removeMetadata:(NSSet *)values;

@end

NS_ASSUME_NONNULL_END