//
//  WMSPEXAdapter.h
//  ZohoMessenger
//
//  Created by Balaji Sankar on 04/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ChatHandler.h"
#import "CollaborationHandler.h"
#import "ChannelHandler.h"
#import "TazHandler.h"
#import "EntityChatHandler.h"
#import "ServiceChatHandler.h"
#import "CustomChatHandler.h"
#import "PresenceGroupHandler.h"
#import "ZohoMessenger.h"
#import "WmsService.h"
#import "PEX.h"

typedef enum {
    WMSCONNECTED   = 1,
    DISCONNECTED = 0,
    WMSCONNECTING = 2,
} connectionStatus;




@interface WMSPEXAdapter : NSObject
<PEXConnectionHandler>
{
    MessageHandler *messageHandler;
    PEX *pexInstance;
}
+ (id)getSharedInstance;
-(NSDictionary *)addAdditionalHeader:(NSMutableDictionary* )header;
- (void)setHandler:(id)handler ofType:(handlerType)type;
- (void)connect:(PEXCredentials *)credential :(WmsService *)productCode :(NSString *)sessionConfig;
- (void)setConnectionHandler:(id<ConnectionHandler>)delegate;
- (void)setMessageHandler:(MessageHandler *)handler;
- (void)setContactsHandler:(ContactsHandler *)handler;
- (void)disconnect;
- (void)hold;
- (void)resume;
- (void)networkFailure;
- (void)process:(PEXEvent *)request;
- (BOOL)getConnectionStatus;
@property(strong) NSString * dclPfx;
@property(strong) NSString * dclBaseBomain;

@end
