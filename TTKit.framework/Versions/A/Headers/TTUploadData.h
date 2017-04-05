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

@interface TTUploadData : NSObject

@property (nonatomic) TTUploadItemState uploadState;
@property (nonatomic) float progress;
@property (nonatomic) unsigned long long uploadedSize;
@property (nonatomic) unsigned long long fileSize;
@property (nonatomic, strong) NSString *token;

@property (nonatomic, copy) void (^uploadStateChangedBlock)(TTUploadItemState);
@property (nonatomic, copy) void (^progressChangedBlock)(float);

- (void)prepareForReuse;

- (void)setProgressObject:(NSProgress *)progressObject;

@end