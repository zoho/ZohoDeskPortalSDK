//
//  BaseChatApi.h
//  PEXLibrary
//
//  Created by Balaji Sankar on 17/03/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

@class ChatInfoMessage;
@interface BaseChatApi : NSObject

- (id)init;
+ (void)sendMessage:(NSString *)chid andMessage:(NSString *)msg andHandler:(id<PEXEventHandler>)handler andMsgId:(NSString *)msgId;
+ (void)sendMessage:(NSString *)chid andMessage:(NSString *)msg andHandler:(id<PEXEventHandler>)handler;
+ (void)sendTaskWithType:(PEXTaskTypes *)taskType andInfo:(id)info andHandler:(id<PEXEventHandler>)handler;
+ (void)joinAndAttachSessionWithChid:(NSString *)chid andHandler:(id<PEXEventHandler>)handler;
+ (void)createChat:(id)recipants andForceNew:(BOOL)forceNew andJoin:(BOOL)join andTitle:(NSString *)title andHandler:(id<PEXEventHandler>)handler andType:(int)type andPrivate:(BOOL)isPrivate;
+ (void)joinChat:(NSString *)chid andUname:(NSString *)uname andHandler:(id<PEXEventHandler>)handler;
+ (void)addMember:(NSString *)chid andRecipants:(id)recipants andDetails:(NSDictionary *)details andHandler:(id<PEXEventHandler>)handler;
+ (void)quitChat:(NSString *)chid andHandler:(id<PEXEventHandler>)handler;
+ (void)deleteMember:(NSString *)chid andRecipants:(id)recipants andDetails:(NSDictionary *)details andHandler:(id<PEXEventHandler>)handler;
+ (void)sendInfoMessage:(NSString *)chid andMsg:(id)msg andChatInfoMessage:(ChatInfoMessage *)chatInfoMessage andHandler:(id<PEXEventHandler>)handler;
+ (void)clearUnreadChats:(NSString *)chids andHandler:(id<PEXEventHandler>)handler;
+ (void)blockNotificationsForChatId:(NSString *)chid withInterval:(NSString *)interval andHandler:(id<PEXEventHandler>)handler;
+ (void)setLocation:(NSDictionary *)dict andHandler:(id<PEXEventHandler>)handler;
+ (void)getBadgeWithHandler:(id<PEXEventHandler>)handler;
@end
