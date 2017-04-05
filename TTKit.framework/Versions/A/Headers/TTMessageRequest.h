//
//  TTMessageRequest.h
//  TTKit
//
//  Created by Oren Zitoun on 3/4/16.
//  Copyright © 2016 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTMessage.h"

/**
 *  A TTMessageRequest object represents a new outgoing message to be sent using TTKit. TTMessageRequest encapsulates the recipient, message body, attachment, and metadata. To send a message in TTKit, pass a TTMessageRequest object to
 *  TTKit sendMessageWithRequest:completion: API.
 */

@interface TTMessageRequest : NSObject

/**
 *  The message recipient token, required.
 */
@property (nonatomic, readonly) NSString *recipientToken;

/**
 *  If set the message will be sent from a role, local user must opt-in to a role before sending a message as the role.
 */
@property (nonatomic, readonly) NSString *roleSenderToken;

/**
 *  Message text.
 */
@property (nonatomic) NSString *messageText;

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
@property (nonatomic) NSString *organizationToken;

/**
 *  Attachment NSData, use setMessageAttachmentWithData:mimeType: to set your attachment data
 */
@property (nonatomic, readonly) NSData *attachmentData;

/**
 *  Attachment file path, use setMessageAttachmentWithFilePath: to set the file path to your attachment
 */
@property (nonatomic, readonly) NSString *attachmentFilePath;

/**
 *  Attachment mime type
 */
@property (nonatomic, readonly) NSString *attachmentMimeType;

/**
 *  An Array of NSDictionaries representing message metadata in datum format (namespace, mimetype, payload).
 *  Use addMessageMetadata:mimeType:payload to add to this array
 */
@property (nonatomic, readonly) NSArray *metadata;

/**
 *  Initialize with recipient token.
 *  @param recipientToken The message recipient token.
 */
- (instancetype)initWithRecipientToken:(NSString *)recipientToken;

/**
 *  Initialize with recipient token.
 *  @param recipientToken The message recipient token.
 *  @param role The Role you wish to send the message from.
 */
- (instancetype)initWithRecipientToken:(NSString *)recipientToken sendAsRole:(TTRole *)role;

/**
 *  Set message attachment with data.
 *  @param data Attachment data.
 *  @param mimeType Attachment mime type.
 */
- (void)setMessageAttachmentWithData:(NSData *)data mimeType:(NSString *)mimeType;

/**
 *  Set message attachment with file path.
 *  @param filePath Attachment file path.
 *  @param mimeType Attachment mime type.
 */
- (void)setMessageAttachmentWithFilePath:(NSString *)filePath mimeType:(NSString *)mimeType;

/**
 *  Use this method to find out what attachment mime types TTMessageRequest supports
 */
- (NSArray *)supportedAttachmentMimeTypes;

/**
 *  Add message metadata.
 *  @param metadataNamespace namespace.
 *  @param mimeType metadata mime type.
 *  @param payload metadata payload.
 */
- (void)addMessageMetadata:(NSString *)metadataNamespace mimeType:(NSString *)mimeType payload:(NSString *)payload;

@end
