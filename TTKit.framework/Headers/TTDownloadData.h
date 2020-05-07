//
//  TTDownloadData.h
//  TTKit
//
//  Created by Oren Zitoun on 3/31/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Enumeration for download status.
 */
typedef NS_ENUM(NSUInteger, TTDownloadItemState) {
    
    /**
     *  The initial state of `TTDownloadDataRootObserver` and `TTDownloadData` when it first gets initialized.
     */
    TTDownloadItemStateUnknown = 0,
    
    /**
     *
     TTDownloadItemStateDeleted,
     */
    
    /**
     *
    TTDownloadItemStateRetrieving,
     */
    
    /**
     *  The initial state of `TTDownloadDataManager` when download is has started.
     */
    TTDownloadItemStateDownloading,
    
    /**
     *
    TTDownloadItemStatePaused,
     */
    
    /**
     *
     TTDownloadItemStateProcessing,
     */
    
    /**
     *  The state where an error has occurred when saving downloaded data to disk.
     */
    TTDownloadItemStateErrorOccured,
    
    /**
     *
     TTDownloadItemStateNotEnoughStorageInCacheFolder,
     */
    
    /**
     *
    TTDownloadItemStateNotEnoughStorageOnDisk,
     */
    
    /**
     *  The state once a download is successfully saved to disk.
     */
    TTDownloadItemStateFinished,
};

@class TTDownloadDataRootObserver;

/**
 *  TTDownloadData holds information about an ongoing or queued attachment download, use it to display download progress and state changes.
 */
@interface TTDownloadData : NSObject

/**
 * A value representing the current state of the download. For possible values, see `TTDownloadItemState`.
 */
@property (nonatomic) TTDownloadItemState downloadState;

/**
 * A value that represents fraction of the download completed.
 * @note max value of `progress` is 1.0.
 */
@property (nonatomic) float progress;

/**
 * A value representing current downloaded size.
 */
@property (nonatomic) unsigned long long downloadedSize;

/**
 * A value representing the total file size to download.
 */
@property (nonatomic) unsigned long long fileSize;

/**
 * An identifying token for the download data.
 */
@property (nonatomic, strong) NSString *token;

/**
 * A BOOL value representing if the download has been paused by the user.
 */
@property (nonatomic) BOOL itemManuallyPaused;

/**
 * A block that gets invoked any time that the download state changes.
 * @param TTDownloadItemState New download state.
 * @see `TTDownloadItemState`
 */
@property (nonatomic, copy) void (^downloadStateChangedBlock)(TTDownloadItemState);

/**
 * A block that gets invoked any time there is a change in the download progress.
 * @param float new updated progress.
 */
@property (nonatomic, copy) void (^progressChangedBlock)(float);

/**
 * Clears current state so TTDownloadData can be reused.
 */
- (void)prepareForReuse;

@end
