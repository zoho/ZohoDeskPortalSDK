//
//  ZohoPortalAuthNetworkManager.h
//  Client_Demo
//
//  Created by Abinaya Ravichandran on 07/02/17.
//  Copyright © 2017 Zoho. All rights reserved.
//

#define Client_HTTPHeaders @"Client_HTTPHeaders"
#import <Foundation/Foundation.h>

/*!
 @typedef ClientInternalError
 @brief Types of error handled in every API calls.
 */
typedef NS_ENUM(NSInteger, ClientInternalError) {
    Client_ERR_JSONPARSE_FAILED,
    Client_ERR_JSON_NIL,
    Client_ERR_SERVER_ERROR,
    Client_ERR_CONNECTION_FAILED,
    Client_ERR_NOTHING_WAS_RECEIVED
};

@interface ZohoPortalAuthNetworkManager : NSObject

+(ZohoPortalAuthNetworkManager*)sharedManager;

-(void)sendPOSTRequestForURL:(NSString*)urlString
         parameters:(NSDictionary*)params
       successBlock:(void (^)(NSDictionary* jsonDict, NSHTTPURLResponse *httpResponse))success
       failureBlock:(void (^)(ClientInternalError errorType, id errorInfo))failed;

-(void)sendGETRequestForURL:(NSString*)urlString
         parameters:(NSDictionary*)params
       successBlock:(void (^)(NSDictionary* jsonDict, NSHTTPURLResponse *httpResponse))success
       failureBlock:(void (^)(ClientInternalError errorType, id errorInfo))failed;

-(void)sendGETRequestForURL:(NSString*)urlString
         parameters:(NSDictionary*)params
       successBlockWithData:(void (^)(NSData* data, NSHTTPURLResponse *httpResponse))success
       failureBlock:(void (^)(ClientInternalError errorType, id errorInfo))failed;


@end
