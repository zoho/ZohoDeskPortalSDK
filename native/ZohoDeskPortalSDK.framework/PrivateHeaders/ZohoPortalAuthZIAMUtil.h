//
//  ClientZIAMUtil.h
//  SSO_Demo
//
//  Created by Kumareshwaran on 8/7/15.
//  Copyright © 2015 Zoho. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "ZohoPortalAuthConstants.h"
#import "ZohoPortalAuthToken.h"

static const long wmsTimeCheckMargin = 420000 ;

typedef void (^requestSuccessBlock)(NSString *token);
typedef void (^requestWMSSuccessBlock)(NSString *token,long expiresMillis);

typedef void (^requestFailureBlock)(NSError *error);

typedef void (^requestLogoutSuccessBlock)();
typedef void (^requestLogoutFailureBlock)(NSError *error);


@interface ZohoPortalAuthZIAMUtil :NSObject
{
@public
    NSString* Scopes;
    NSString* AppName;
    NSString* BaseUrl;
    NSString* ClientID;
    NSString* ClientSecret;
    NSString* PortalID;
    NSString *UrlScheme;
    NSString *ma_portalID;
    NSString *ma_accountsPortalURL;
#if !CP_APP__EXTENSION_API_ONLY
    UIWindow *MainWindow;
#endif
    requestSuccessBlock finalSuccessBlock;
    requestFailureBlock finalFailureBlock;
    BOOL isLoadingInWebview;
    NSString* UrlParams;
    
    NSString *ScopeEnhancementUrl;
    NSString *ScopeEnhancementPortalID;
    NSString *ScopeEnhancementAccountsPortalURL;
    
}
@property NSString *ExtensionAppGroup;


+ (ZohoPortalAuthZIAMUtil *)sharedUtil;
-(BOOL)handleURL:url sourceApplication:sourceApplication annotation:annotation;


#if !TARGET_OS_WATCH
- (void) initWithClientID: (NSString*)clientID
                    ClientSecret: (NSString*)clientSecret
                 PortalID:(NSString *)portalID
                    Scope:(NSArray*)scopearray
                URLScheme:(NSString*)URLScheme
               MainWindow:(UIWindow*)mainWindow
                AccountsPortalURL:(NSString*)accountsPortalURL;
#endif

- (void) initExtensionWithClientID:(NSString*)clientID
                            ClientSecret: (NSString*)clientSecret
                            PortalID:(NSString *)portalID
                             Scope:(NSArray*)scopearray
                         URLScheme:(NSString*)URLScheme
                         AccountsPortalURL:(NSString*)accountsPortalURL;

-(void)clearClientDetailsForFirstLaunch;

-(BOOL)isUserSignedIn;

-(BOOL)isUserSignedInForPortalID:(NSString *)portalID;

- (void)setHavingAppExtensionWithAppGroup:(NSString *)appGroup;


-(void)getOauth2Token:(requestSuccessBlock)successBlock failure:(requestFailureBlock)failureBlock;

-(void)getOauth2TokenForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL success:(requestSuccessBlock)successBlock failure:(requestFailureBlock)failureBlock;

- (void) getTokenForWMSWithSuccess:(requestWMSSuccessBlock)success andFailure:(requestFailureBlock)failure;
-(ZohoPortalAuthToken *)getSyncOAuthToken;

- (NSDictionary *)giveOAuthDetailsForWatchApp;

-(void)setOAuthDeteailsInKeychainForWatchApp:(NSDictionary *)OAuthDetails;

- (void) presentInitialViewControllerWithSuccess:(requestSuccessBlock)success andFailure:(requestFailureBlock)failure;

- (void) presentInitialViewControllerWithCustomParams:(NSString *)urlParams success:(requestSuccessBlock)success andFailure:(requestFailureBlock)failure;

- (void) presentInitialViewControllerForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL Success:(requestSuccessBlock)success andFailure:(requestFailureBlock)failure;

- (void) getOAuthTokenForRemoteUser:(NSString *)userToken havingSuccess:(requestSuccessBlock)success andFailure:(requestFailureBlock)failure;

-(void)removeAllScopesWithsuccess:(requestLogoutSuccessBlock)successBlock failure:(requestLogoutFailureBlock)failureBlock;

-(void)removeAllScopesForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL success:(requestLogoutSuccessBlock)successBlock failure:(requestLogoutFailureBlock)failureBlock;

-(NSString *)getIAMSignInURLForLoadingInWebView;
-(void)continueLoginFromWebviewHavingURL:(NSURL *)url WithSuccess:(requestSuccessBlock)success andFailure:(requestFailureBlock)failure;

-(void)enhanceScopesWithSuccess:(requestSuccessBlock)success andFailure:(requestFailureBlock)failure;
-(void)enhanceScopesForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL success:(requestSuccessBlock)successBlock failure:(requestFailureBlock)failureBlock;

//Internal Methods
-(void)showNetworkActivityIndicator;
-(void)hideNetworkActivityIndicator;
-(NSString *) getUserAgentString;
-(void)fetchAccessTokenFromServerForPortalID:(NSString *)portalID havingAccountsPortalURL:(NSString *)accountsPortalURL success:(requestSuccessBlock)successBlock failure:(requestFailureBlock)failureBlock;

@end
