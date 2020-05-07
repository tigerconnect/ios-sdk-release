//
//  TTConnectionStatusManager.h
//  TigerText
//
//  Created by Garo Hussenjian on 8/12/15.
//  Copyright (c) 2015 TigerText. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TTSocketService, TTLogManager;

// Clients should subscribe to TTConnectionStatusChangedNotification
extern NSString * const TTConnectionStatusChangedNotification;

/**
 *  Enumeration describing states of connectivity
 */
typedef NS_ENUM(NSUInteger, TTConnectionStatus) {

    /**
     *  Initializing status should be ignored, clients should observe changes via NSNotificationCenter.
     *  Transitions to Connecting or No Connectivity
     */
    TTConnectionStatusInitializing = 0,
    
    /**
     *  Connected status represents server-side event (SSE) socket is opening.
     *  Transitions to Connected or LowConnectivity.
     */
    TTConnectionStatusConnecting,
    
    /**
     *  Connecting status represents server-side event (SSE) stream is receiving data.
     *  Transitions to Connecting, LowConnectivity, NoConnectivity
     */
    TTConnectionStatusConnected,
    
    /**
     *  No Connectivity status occurs when system indicates no internet connection exists.
     *  Transitions to Connecting
     */
    TTConnectionStatusNoConnectivity,
};

/**
   TTConnectionStatusManager monitors TTKit network connectivty, when received in TTConnectionStatusChangedNotification notification object use it to determine TTKit connectivity to the network.
 */
@interface TTConnectionStatusManager : NSObject

/**
 Use connectionStatus property to figure out the status of the connection.
 */
@property (nonatomic, readonly) TTConnectionStatus connectionStatus;

/**
 The user token you initialized TTConnectionStatusManager with.
 */
@property (nonatomic, readonly) NSString *userToken;

@end
