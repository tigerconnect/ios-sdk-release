//
//  TTMessageRequest.h
//  TTKit
//
//  Created by Oren Zitoun on 3/4/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TTMessage;
/**
 *  A TTMessageRequest object represents a new outgoing message to be sent using TTKit. TTMessageRequest encapsulates the recipient, message body, attachment, and metadata. To send a message in TTKit, pass a TTMessageRequest object to
 *  TTKit sendMessageWithRequest:completion: API.
 */

@interface TTMessageRequest : NSObject

/**
 *  The message recipient token, required.
 */
@property (nullable, nonatomic, readonly) NSString *recipientToken;

/**
 *  If set the message will be sent from a role, local user must opt-in to a role before sending a message as the role.
 */
@property (nullable, nonatomic, readonly) NSString *roleSenderToken;

/**
 *  Message text.
 */
@property (nullable, nonatomic) NSString *messageText;

/**
 *  Message time to live in minutes. Default is 30 days
 */
@property (nonatomic) NSUInteger timeToLive;

/**
 *  Delete on read, sets message timeToLive to 60 seconds once the message is read.
 */
@property (nonatomic) BOOL deleteOnRead;

/**
 *  Indicates the message priority. Default is TTMessagePriorityNormal
 */
@property (nonatomic) TTMessagePriority messagePriority;

/**
 *  The organization token. Default is the current organization token
 */
@property (nullable, nonatomic) NSString *organizationToken;

/**
 *  Attachment NSData, use setMessageAttachmentWithData:mimeType: to set your attachment data
 */
@property (nullable, nonatomic, readonly) NSData *attachmentData;

/**
 *  Attachment file path, use setMessageAttachmentWithFilePath: to set the file path to your attachment
 */
@property (nullable, nonatomic, readonly) NSString *attachmentFilePath;

/**
 *  Attachment mime type
 */
@property (nullable, nonatomic, readonly) NSString *attachmentMimeType;

/**
 *  An Array of NSDictionaries representing message metadata in datum format (namespace, mimetype, payload).
 *  Use addMessageMetadata:mimeType:payload to add to this array
 */
@property (nullable, nonatomic, readonly) NSArray *metadata;

/**
 *  Initialize with recipient token.
 *  @param recipientToken The message recipient token.
 */
- (instancetype _Nonnull)initWithRecipientToken:(NSString *_Nonnull)recipientToken;

/**
 *  Initialize with recipient token.
 *  @param recipientToken The message recipient token.
 *  @param role The Role you wish to send the message from.
 */
- (instancetype _Nonnull)initWithRecipientToken:(NSString *_Nonnull)recipientToken sendAsRole:(TTRole *_Nullable)role;

/**
 *  Set message attachment with data.
 *  @param data Attachment data.
 *  @param mimeType Attachment mime type.
 */
- (void)setMessageAttachmentWithData:(NSData *_Nonnull)data mimeType:(NSString *_Nonnull)mimeType;

/**
 *  Set message attachment with file path.
 *  @param filePath Attachment file path.
 *  @param mimeType Attachment mime type.
 */
- (void)setMessageAttachmentWithFilePath:(NSString *_Nonnull)filePath mimeType:(NSString *_Nonnull)mimeType;


/**
 *  Add message metadata.
 *  @param metadataNamespace namespace.
 *  @param mimeType metadata mime type.
 *  @param payload metadata payload.
 */
- (void)addMessageMetadata:(NSString *_Nonnull)metadataNamespace mimeType:(NSString *_Nonnull)mimeType payload:(NSString *_Nonnull)payload;

@end
