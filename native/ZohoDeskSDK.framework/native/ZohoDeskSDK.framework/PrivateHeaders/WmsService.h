//
//  WmsService.h
//  ZohoMessenger
//
//  Created by Balaji Sankar on 05/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 The WmsService class stores the list of product codes associated with each Zoho Product
 */
@interface WmsService : NSObject
/**
 The method initWithPrd is used to initialize a WmsService instance
 Usage :
     WmsService *wmsService=[[WmsService alloc] initWithPrd:@"BA"];
 @param productCode Product code of the service.
 @warning Use this method only for csez set up and the product code must be a valid entry present in the WmsServer
 */
- (id)initWithPrd:(NSString *)productCode;

- (NSString *)getPrd;
/**
 *  Zoho CRM
 */
+ (WmsService *)CRM;
/**
 * Zoho Mail
 */
+ (WmsService *)MAIL;
/**
 * Zoho Business
 */
+ (WmsService *)BUSSINESS;
/**
 * Zoho Projects
 */
+ (WmsService *)PROJECTS;
/**
 * Zoho Sheet
 */
+ (WmsService *)SHEET;
/**
 * Zoho Chat
 */
+ (WmsService *)CHAT;
/**
 * Zoho Writer
 */
+ (WmsService *)WRITER;
/**
 * Zoho Show
 */
+ (WmsService *)SHOW;
/**
 * Zoho Meeting
 */
+ (WmsService *)MEETING;
/**
 * Zoho Planner
 */
+ (WmsService *)PLANNER;
/**
 * Zoho Notebook
 */
+ (WmsService *)NOTEBOOK;
/**
 * Zoho Discussions
 */
+ (WmsService *)FORUMS;
/**
 * Zoho IAM
 */
+ (WmsService *)ACCOUNTS;
/**
 * Zoho Docs
 */
+ (WmsService *)EXPLORER;
/**
 * Zoho Share
 */
+ (WmsService *)SHARE;
/**
 * Zoho Calendar
 */
+ (WmsService *)CALENDAR;
/**
 * Zoho Contacts
 */
+ (WmsService *)CONTACTS;
/**
 * Zoho Creator
 */
+ (WmsService *)CREATOR;
/**
 * Zoho People
 */
+ (WmsService *)PEOPLE;
/**
 * Zoho Connects/Gadgets
 */
+ (WmsService *)CONNECTS;
/**
 * Zoho Store
 */
+ (WmsService *)STORE;
/**
 * Zoho Search
 */
+ (WmsService *)SEARCH;
/**
 * Zoho Firefox Addon
 */
+ (WmsService *)ZOHOFOX;
/**
 * Zoho Videos
 */
+ (WmsService *)VIDEOS;
/**
 * Zoho Wiki
 */
+ (WmsService *)WIKI;
/**
 * Zoho Support
 */
+ (WmsService *)SUPPORT;
/**
 * Zoho Campaigns
 */
+ (WmsService *)CAMPAIGN;
/**
 * Zoho Desktop Client (Adobe Air)
 */
+ (WmsService *)DESKTOP;
/**
 * Zoho Blogs
 */
+ (WmsService *)BLOGS;
/**
 * Zoho Mobile Sync
 */
+ (WmsService *)MOBILE;
/**
 * Zoho Remote Agent for Office Suite
 */
+ (WmsService *)REMOTE_AGENT;
/**
 * Zoho Telephony Adapter
 */
+ (WmsService *)TELE_ADAPTER;
/**
 * Zoho Issue Tracker
 */
+ (WmsService *)ISSUE_TRACKER;
/**
 * Service Desk Plus
 */
+ (WmsService *)SERVICE_DESK;
/**
 * Opmanager
 */
+ (WmsService *)OPMANAGER;
/**
 * Zoho Contacts Manager
 */
+ (WmsService *)CONTACTS_MANAGER;
/**
 * Zoho Pulse
 */
+ (WmsService *)PULSE;
/**
 * Zoho Intranet
 */
+ (WmsService *)INTRANET;
/**
 * Zoho Site 24*7
 */
+ (WmsService *)SITE24_7;
/**
 * Zoho Reach
 */
+ (WmsService *)REACH;
/**
 * Activity Collation Server
 */
+ (WmsService *)AC_SERVER;
/**
 * LiveDesk
 */
+ (WmsService *)LIVEDESK;
/**
 * Jabber Server
 */
+ (WmsService *)JABBER_SERVER;
/**
 * Payments
 */
+ (WmsService *)PAYMENTS;
/**
 * PIE
 */
+ (WmsService *)PIE;

/**
 * Zoho Home
 */
+ (WmsService *)HOME;

@end


