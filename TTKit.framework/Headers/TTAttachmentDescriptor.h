//
//  TTAttachmentDescriptor.h
//  TTKit
//
//  Created by Oren Zitoun on 4/14/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage;

/**
 *  TTAttachmentDescriptor describes an attachment added to a specific TTMessage.
 *  @note For supported attachment types, see `TTAttachmentType`, and for supported MIME types, see `TTAttachmentDescriptor.mimeType`.
 */
@interface TTAttachmentDescriptor : NSManagedObject

/**
 *  Index of attachment in TTMessage's attachmentDescriptors NSSet.
 */
@property (nullable, nonatomic, retain) NSNumber * index;

/**
 *  Boolean value to indicate whether attachment is downloaded and stored locally.
 */
@property (nullable, nonatomic, retain) NSNumber * isDownloaded;

/**
 *  If attachment was downloaded, this property contains its path on the device.
 */
@property (nullable, nonatomic, retain) NSString * localPath;

/**
 *  Attachment MIME type.
 *  @note Supported MIME types include ```image/jpeg, image/pjpeg, image/png, image/x-png, image/gif, image/bmp, audio/mp4, audio/wav, audio/x-wav, audio/mpeg, audio/x-m4a, audio/mp3, video/mp4, video/x-m4v, video/quicktime, application/pdf, application/msword, application/vnd.openxmlformats-officedocument.wordprocessingml.document, application/vnd.ms-excel, application/vnd.openxmlformats-officedocument.spreadsheetml.sheet, application/vnd.ms-powerpoint, application/vnd.openxmlformats-officedocument.presentationml.presentation```
 */
@property (nonnull, nonatomic, retain) NSString * mimeType;

/**
 *  Size of attachment, in bytes.
 */
@property (nullable, nonatomic, retain) NSNumber * size;

/**
 *  Attachment type.
 *
 *  @see `TTAttachmentType`.
 */
@property (nonnull, nonatomic, retain) NSNumber * type;

/**
 *  The TTMessage to which this TTAttachmentDescriptor is linked.
 */
@property (nonnull, nonatomic, retain) TTMessage *message;

@end
