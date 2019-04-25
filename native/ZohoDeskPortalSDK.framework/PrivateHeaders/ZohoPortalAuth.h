//
//  ZohoPortalAuth.h
//  IAM_ClientUsers
//
//  Created by Kumareshwaran on 26/02/18.
//  Copyright © 2018 Dhanasekar K. All rights reserved.
//

#import <Foundation/Foundation.h>
#if !TARGET_OS_WATCH
#import <UIKit/UIKit.h>
#endif
#import "ZohoPortalAuthRequestBlocks.h"
#import "ZohoPortalAuthToken.h"

@interface ZohoPortalAuth : NSObject

#if !TARGET_OS_WATCH
+(void) initWithClientID: (NSString*)clientID
             ClientSecret: (NSString*)clientSecret
                 PortalID:(NSString *)portalID
                    Scope:(NSArray*)scopearray
                URLScheme:(NSString*)urlScheme
               MainWindow:(UIWindow*)mainWindow
        AccountsPortalURL:(NSString*)accountsPortalURL;
#endif

+(void) initExtensionWithClientID:(NSString*)clientID
                      ClientSecret: (NSString*)clientSecret
                          PortalID:(NSString *)portalID
                             Scope:(NSArray*)scopearray
                         URLScheme:(NSString*)urlScheme
                 AccountsPortalURL:(NSString*)accountsPortalURL;

+(void)clearZohoAuthPortalDetailsForFirstLaunch;

+(BOOL)handleURL:url sourceApplication:sourceApplication annotation:annotation;

+(BOOL)isUserSignedIn;

+(BOOL)isUserSignedInForPortalID:(NSString *)portalID;

+(void)setHavingAppExtensionWithAppGroup:(NSString *)appGroup;

+(void)getOauth2Token:(ZohoPortalAuthAccessTokenHandler)tokenBlock;

+(void)getOauth2TokenForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock;

+(void)getOauth2TokenForWMS:(ZohoPortalAuthWMSAccessTokenHandler)tokenBlock;

+(ZohoPortalAuthToken *)getOauth2TokenForWMS;

+(NSDictionary *)giveOAuthDetailsForWatchApp;

+(void)setOAuthDeteailsInKeychainForWatchApp:(NSDictionary *)OAuthDetails;

+(void) presentZohoPortalSignIn:(ZohoPortalAuthSignInHandler)signinBlock;

+ (void) presentZohoPortalSignInWithCustomParams:(NSString *)urlParams
                                        signinHandler:(ZohoPortalAuthSignInHandler)signinBlock;

+(void) presentZohoPortalSignInForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL signinHanlder:(ZohoPortalAuthSignInHandler)signinBlock;

+(void) getOAuthTokenForRemoteUser:(NSString *)userToken tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock;

+(void)revokeAccessToken:(ZohoPortalAuthRevokeAccessTokenHandler)revokeBlock;

+(void)revokeAccessTokenForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL revokeHandler:(ZohoPortalAuthRevokeAccessTokenHandler)revokeBlock;

+(NSString *)getIAMSignInURLForLoadingInWebView;
+(void)continueLoginFromWebviewHavingURL:(NSURL *)url signinhandler:(ZohoPortalAuthSignInHandler)signinBlock;

/**
 Method used for Scope Enhancements. Call this method once if you are introducing new scopes in your app update.
 
 @param tokenBlock callback in which you will get the required access token.
 */
+(void)enhanceScopes:(ZohoPortalAuthAccessTokenHandler)tokenBlock NS_EXTENSION_UNAVAILABLE_IOS("");
+(void)enhanceScopesForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL tokenHandler:(ZohoPortalAuthAccessTokenHandler)tokenBlock;
@end
