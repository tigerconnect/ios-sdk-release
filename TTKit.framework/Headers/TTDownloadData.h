//
//  TTDownloadData.h
//  TTKit
//
//  Created by Oren Zitoun on 3/31/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TTDownloadItemState) {
    TTDownloadItemStateUnknown = 0,
    TTDownloadItemStateDeleted,
    TTDownloadItemStateRetrieving,
    TTDownloadItemStateDownloading,
    TTDownloadItemStatePaused,
    TTDownloadItemStateProcessing,
    TTDownloadItemStateErrorOccured,
    TTDownloadItemStateNotEnoughStorageInCacheFolder,
    TTDownloadItemStateNotEnoughStorageOnDisk,
    TTDownloadItemStateFinished,
};

@class TTDownloadDataRootObserver;

/**
 *  TTDownloadData holds information about an ongoing or queued attachment download, use it to display download progress and state changes.
 */
@interface TTDownloadData : NSObject

@property (nonatomic) TTDownloadItemState downloadState;
@property (nonatomic) float progress;
@property (nonatomic) unsigned long long downloadedSize;
@property (nonatomic) unsigned long long fileSize;
@property (nonatomic, strong) NSString *token;
@property (nonatomic) BOOL itemManuallyPaused;

@property (nonatomic, copy) void (^downloadStateChangedBlock)(TTDownloadItemState);
@property (nonatomic, copy) void (^progressChangedBlock)(float);

- (void)prepareForReuse;

@end