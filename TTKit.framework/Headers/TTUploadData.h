//
//  TTUploadData.h
//  TTKit
//
//  Created by Oren Zitoun on 4/3/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TTUploadItemState)
{
    TTUploadItemStateUnknown = 0,
    TTUploadItemStateDeleted,
    TTUploadItemStateUploading,
    TTUploadItemStateUploadPaused,
    TTUploadItemStatePausedDueToAppClose,
    TTUploadItemStateErrorOccured,
    TTUploadItemStateFinished,
};

/**
 *  TTUploadData holds information about an ongoing or queued attachment upload, use it to display upload progress and state changes.
 */
@interface TTUploadData : NSObject

/**
 * Current state of the upload. For possible values, see `TTUploadItemState`.
 */
@property (nonatomic) TTUploadItemState uploadState;

/**
 * A value that represents fraction of the upload completed.
 * @discussion Max value of `progress` is 1.0.
 */
@property (nonatomic) float progress;

/**
 * A value representing current uploaded size.
 */
@property (nonatomic) unsigned long long uploadedSize;

/**
 * A value representing the total file size to upload.
 */
@property (nonatomic) unsigned long long fileSize;

/**
 * An identifying token for the upload data.
 */
@property (nonatomic, strong) NSString *token;

/**
 * A block that gets invoked any time that the upload state changes.
 * @param TTUploadItemState New upload state.
 */
@property (nonatomic, copy) void (^uploadStateChangedBlock)(TTUploadItemState);

/**
 * A block that gets invoked any time there is a change in the upload progress.
 * @param float new updated progress.
 */
@property (nonatomic, copy) void (^progressChangedBlock)(float);

/**
 * Clears current state so TTUploadData can be reused.
 */
- (void)prepareForReuse;

/**
 * Updates progress of the upload.
 *
 * @param progressObject A progress object containing fraction completed information.
 */
- (void)setProgressObject:(NSProgress *)progressObject;

@end
