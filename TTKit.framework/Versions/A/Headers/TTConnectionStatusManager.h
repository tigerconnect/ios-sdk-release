//
//  TTConnectionStatusManager.h
//  TigerText
//
//  Created by Garo Hussenjian on 8/12/15.
//  Copyright (c) 2015 TigerText. All rights reserved.
//

#import <Foundation/Foundation.h>

// Clients should subscribe to TTConnectionStatusChangedNotification
extern NSString * const TTConnectionStatusChangedNotification;

typedef NS_ENUM(NSUInteger, TTConnectionStatus) {
    
    // Initializing status should be ignored, clients should observe changes via NSNotificationCenter
    // Transitions to Connecting or No Connectivity
    TTConnectionStatusInitializing = 0,
    
    // Connected status represents server-side event (SSE) socket is opening
    // Transitions to Connected or LowConnectivity
    TTConnectionStatusConnecting,
    
    // Connecting status represents server-side event (SSE) stream is receiving data
    // Transitions to Connecting, WaitingForNetwork, LowConnectivity, NoConnectivity
    TTConnectionStatusConnected,
    
    // Waiting for Network status occurs when in-flight API calls exceed 5 seconds
    // Transitions to Connected or Low Connectivity
    TTConnectionStatusWaitingForNetwork,
    
    // Low Connectivity status occurs when some timeouts occur, persists for 5 seconds.
    // Transitions to Connected
    TTConnectionStatusLowConnectivity,
    
    // No Connectivity status occurs when system indicates no internet connection exists
    // Transitions to Connecting
    TTConnectionStatusNoConnectivity,
};

@interface TTConnectionStatusManager : NSObject

@property (nonatomic, readonly) TTConnectionStatus connectionStatus;

+ (instancetype)sharedInstance;

@end
