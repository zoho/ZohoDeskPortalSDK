//
//  PEX_p.h
//  LiveChat
//
//  Created by Balaji Sankar on 16/09/13.
//  Copyright (c) 2013 Balaji Sankar. All rights reserved.
//
//#import "LibProperty.h"
//#import "WebSocket.h"
#import "PEXHeader.h"
#import "WmsService.h"
@class PEX;
@class PEXResponse;
@class PEXError;
@class PEXEvent;
@class PEXTaskTypes;
@class PEXCredentials;



@protocol PEXConnectionHandler <NSObject>
- (void)onConnect;
- (void)onDisconnect;
- (void)onMessage:(NSDictionary *)msg;
@end

@interface PEX : NSObject
{
    int timeout;
    NSString *sid;
    NSString *xa;
}
@property(nonatomic, strong)NSMutableArray *seqList;
@property BOOL isHold;
@property int timeout;
@property NSString *sid;
@property NSString *xa;
@property id <PEXConnectionHandler> PexConnectionHandlerdelegate;
- (void)process:(PEXEvent *)evt andEventHandler:(id)eventHandler;
- (void)process:(PEXEvent *)evt;
- (void)initWithCredentials:(PEXCredentials *)theCredentials prd:(WmsService *)prd andconfig:(NSString *)configs;
- (void)initWithURL:(NSString *)theUrl andCredentials:(PEXCredentials *)theCredentials prd:(WmsService *)prd andconfig:(NSString *)configs;
- (void)initWithURL:(NSString *)theUrl prd:(WmsService *)prd andconfig:(NSString *)configs;
- (void)initWithURL:(NSString *)theUrl andCredentials:(PEXCredentials *)theCredentials prd:(WmsService *)prd andconfig:(NSString *)configs andtheHeader:(NSDictionary *)theheader;
- (void)setTimeout:(int)time;
- (void)close;
- (id)init;
- (void)hold;
- (void)resume;
- (void)reconnect:(NSNumber *)isSendSidAndXa;
+ (id)getSharedInstance;
@end

@interface PEXTask : PEXEvent
{
    NSString *operation;
}
- (id)initWithTaskType:(PEXTaskTypes *)type andObject:(id)theobject;
- (id)initWithProgTaskType:(PEXTaskTypes *)type andObject:(id)theobject;
@end


@interface PEXCredentials ()
{
     NSString *key;
    int type;
    NSString *uagent;
    NSMutableDictionary *info;
    NSString *insid;
    NSString *pnsKey;

}
@property(readonly) NSString *key;
@property NSString *uagent;
@property int type;
- (NSString *)getInsid;
@end

@interface WMSAuthTypes : NSObject
+ (int)DEFAULT;
+ (int)AUTH_TOKEN;
+ (int)PORTAL_USER;
+ (int)SS_TICKET;
+ (int)ANNON_AUTH;
+ (int)PEX_AUTH;

@end


@interface PEXReadyState : NSObject
- (PEXReadyState *)initWithState:(int)rs;
@end


