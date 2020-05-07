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
    TTMessageTypeEmptyRoleNotification,
    TTMessageTypeAlert,
    TTMessageTypePatientCare,
    TTMessageTypeRoleAwayResponse,
    TTMessageTypePatientNetwork,
    TTMessageTypeLocalUnreadIndicator,
    TTMessageTypePatientNetworkAutomatedResponse,
    TTMessageTypePatientNetworkForwardedToProvider,
    TTMessageTypeTeamRequest,
    TTMessageTypeSystem,
};

typedef NS_ENUM(NSInteger, TTMessagePriority) {
    TTMessagePriorityNormal = 0,
    TTMessagePriorityHigh = 1,
    TTMessagePriorityEscalation = 2,
};

@class TTAttachmentDescriptor, TTGroup, TTMessageStatus, TTMetadata, TTParty, TTRosterEntry, TTUser, TTRole, TTEHREvent, TTAlertEvent, TTEscalation, TTDetectedData, TTTeamRequest;
 
/**
 *  A TTMessage object represents a message.
 */
@interface TTMessage : NSManagedObject

/**
 *  The actual message string.
 */
@property (nullable, nonatomic, retain) NSString * body;

/**
 *  Conversation hash of the message.
 */
@property (nonnull, nonatomic, retain) NSString * conversationHash;

/**
 *  Time the message was created.
 */
@property (nullable, nonatomic, retain) NSDate * createdTime;

/**
 *  Delete on read. Boolean value, sets message ttl to 60 seconds.
 */
@property (nullable, nonatomic, retain) NSNumber * dor;

/**
 *  If dor property is YES, expired property will be YES once expireTime has passed.
 */
@property (nullable, nonatomic, retain) NSNumber * expired;

/**
 *  Time the TTMessage will expire.
 */
@property (nullable, nonatomic, retain) NSDate * expireTime;

/**
 *  Boolean value. If YES this message was forwarded from another user.
 */
@property (nullable, nonatomic, retain) NSNumber * forward;

/**
 *  Int16 value, mapped to TTAutoforwardType enumeration.
 */
@property (nullable, nonatomic, retain) NSNumber * autoforward;

/**
 *  Boolean value. Yes if the message has not updated on the server, NO otherwise.
 */
@property (nonnull, nonatomic, retain) NSNumber * isLocal;

/**
 *  Local token used until TTMessage is saved to server.
 */
@property (nullable, nonatomic, retain) NSString * localToken;

/**
 *  Organization token to which the message is related.
 */
@property (nullable, nonatomic, retain) NSString * orgToken;

/**
 *  Original Sender's name for the forwarded message.
 */
@property (nullable, nonatomic, readonly) NSString * originalSenderDisplayName DEPRECATED_ATTRIBUTE;

/**
 *  Original Sender token for the forwarded message.
 */
@property (nullable, nonatomic, readonly) NSString * originalSenderToken DEPRECATED_ATTRIBUTE;

/**
 *  Original creation date for forwarded message.
 */
@property (nullable, nonatomic, retain) NSDate   * originalTimestamp;

/**
 *  Organization token of the TTMessage’s recepient.
 */
@property (nonnull, nonatomic, retain) NSString * recipientOrganizationToken;

/**
 *  Organization token of the TTMessage’s sender.
 */
@property (nonnull, nonatomic, retain) NSString * senderOrganizationToken;

/**
 *  Arrival index of this TTMessage’s instance.
 */
@property (nonnull, nonatomic, retain) NSNumber * sortNumber;

/**
 *  When sortNumber property reached it’s max value, sortSeries will be incremented by 1 to create a new series.
 */
@property (nonnull, nonatomic, retain) NSNumber * sortSeries;

/**
 *  TTMessage status. See TTKitConstants for possible values.
 */
@property (nonnull, nonatomic, retain) NSString * status;

/**
 *  Object Token. Internal use.
 */
@property (nullable, nonatomic, retain) NSString * token;

/**
 *  TTMessage’s time to live in minutes.
 */
@property (nonnull, nonatomic, retain) NSNumber * ttl;

/**
 *  Whether this TTMessage is a bang or not.
 */
@property (nonnull, nonatomic, retain) NSNumber * isBang;

/**
 *  An NSOrderedSet containing all TTAttachmentDescriptors, which describe all attachments to this message.
 */
@property (nullable, nonatomic, retain) NSOrderedSet *attachmentDescriptors;

/**
 *  The related group to this message.
 */
@property (nullable, nonatomic, retain) TTGroup *group;

/**
 *  An NSSet containing all status event for a group message with more than 1 receipent.
 */
@property (nullable, nonatomic, retain) NSSet *messageStatus;

/**
 *  All metadata related to this message.
 */
@property (nullable, nonatomic, retain) NSSet *metadata;

/**
 *  The recipient. Can be either a TTGroup or a TTUser.
 */
@property (nonnull, nonatomic, retain) TTParty *recipient;

/**
 *  The sender. Can be either a TTGroup or a TTUser.
 */
@property (nonnull, nonatomic, retain) TTParty *sender;

/**
 *  The original sender of a forwarded message.
 */
@property (nullable, nonatomic, retain) TTUser *originalSender;

/**
 *  The user of an autoforwarded message.
 */
@property (nullable, nonatomic, retain) TTUser *autoforwardUser;

/**
 *  The message sender's role.
 */
@property (nullable, nonatomic, retain) TTRole *senderRole;

/**
 *  Placeholder string, not being used
 */
@property (nullable, nonatomic, retain) NSString *groupStatus;

/**
 *  Indicates the type of message (0 = normal, 1 = DND Auto-Forward notification)
 */
@property (nullable, nonatomic, retain) NSNumber *messageType;

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
@property (nullable, nonatomic, retain) NSNumber * sendDelivered;

@property (nonatomic) BOOL ignoreApiUpdates;
@property (nullable, nonatomic) NSData *encryptedBody;

/**
 *  The related EHR event to this message.
 */
@property (nullable, nonatomic, retain) TTEHREvent *ehrEvent;

/**
 *  The related Alert event to this message.
 */

@property (nullable, nonatomic, retain) TTAlertEvent *alertEvent;

/**
 *  The related escalation to this message.
 */
@property (nullable, nonatomic, retain) TTEscalation *escalation;

/**
 * Set of data that is detected from the message body. For types, see `TTDetectedMessageType`.
 */
@property (nullable, nonatomic, retain) NSSet<TTDetectedData *> *detectedDatas;

/**
 * A BOOL value indicating whether the message has been processed for detectedData already.
 */
@property (nonnull, nonatomic, retain) NSNumber *didProcessDetectedData;

/**
 * sectionDate is being used to section message FetchedResultsController reuslts into section by day.
 */
@property (nullable, nonatomic, retain) NSDate *sectionDate;

/**
 *  Team Request Object.
 */
@property (nullable, nonatomic, retain) TTTeamRequest *teamRequest;

@end
