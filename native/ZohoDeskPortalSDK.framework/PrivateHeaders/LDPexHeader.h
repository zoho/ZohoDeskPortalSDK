//
//  LDPexHeader.h
//  LiveChat
//
//  Created by Shanmuga Sundaram G on 05/05/16.
//  Copyright © 2016 Zoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PEXLibrary.h"

@interface LDPexHeader : PEXLibrary
+ (void)setAppKey:(NSString *)appKey;
+ (void)setPexHeader:(NSString *)agentHeader;

+ (void)setMessageHandler:(MessageHandler *)handler;
+ (void)sendMessage:(NSDictionary *)data andHandler:(id<PEXEventHandler>)handler ;
+ (void)clearUnreadChats:(NSString *)chids andHandler:(id<PEXEventHandler>)handler;
@end
