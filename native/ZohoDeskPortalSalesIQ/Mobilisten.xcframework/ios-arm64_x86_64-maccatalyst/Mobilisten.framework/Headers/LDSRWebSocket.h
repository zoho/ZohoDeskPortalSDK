//
//   Copyright 2012 Square Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <Foundation/Foundation.h>
#import <Security/SecCertificate.h>

typedef NS_ENUM(NSInteger, LDSRReadyState) {
    LDSR_CONNECTING   = 0,
    LDSR_OPEN         = 1,
    LDSR_CLOSING      = 2,
    LDSR_CLOSED       = 3,
};

typedef enum LDSRStatusCode : NSInteger {
    LDSRStatusCodeNormal = 1000,
    LDSRStatusCodeGoingAway = 1001,
    LDSRStatusCodeProtocolError = 1002,
    LDSRStatusCodeUnhandledType = 1003,
    // 1004 reserved.
    LDSRStatusNoStatusReceived = 1005,
    // 1004-1006 reserved.
    LDSRStatusCodeInvalidUTF8 = 1007,
    LDSRStatusCodePolicyViolated = 1008,
    LDSRStatusCodeMessageTooBig = 1009,
} LDSRStatusCode;

@class LDSRWebSocket;

extern NSString *const LDSRWebSocketErrorDomain;
extern NSString *const LDSRHTTPResponseErrorKey;

#pragma mark - SRWebSocketDelegate

@protocol LDSRWebSocketDelegate;

#pragma mark - LDSRWebSocket

@interface LDSRWebSocket : NSObject <NSStreamDelegate>

@property (nonatomic, strong) NSMutableDictionary *additionalheader;
@property (nonatomic, strong) NSMutableDictionary *cookies;
@property (nonatomic, weak) id <LDSRWebSocketDelegate> delegate;

@property (nonatomic, readonly) LDSRReadyState readyState;
@property (nonatomic, readonly, retain) NSURL *url;


@property (nonatomic, readonly) CFHTTPMessageRef receivedHTTPHeaders;

// Optional array of cookies (NSHTTPCookie objects) to apply to the connections
@property (nonatomic, readwrite) NSArray * requestCookies;

// This returns the negotiated protocol.
// It will be nil until after the handshake completes.
@property (nonatomic, readonly, copy) NSString *protocol;

// Protocols should be an array of strings that turn into Sec-WebSocket-Protocol.
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols;
- (id)initWithURLRequest:(NSURLRequest *)request;

// Some helper constructors.
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols;
- (id)initWithURL:(NSURL *)url;

// Delegate queue will be dispatch_main_queue by default.
// You cannot set both OperationQueue and dispatch_queue.
- (void)setDelegateOperationQueue:(NSOperationQueue*) queue;
- (void)setDelegateDispatchQueue:(dispatch_queue_t) queue;

// By default, it will schedule itself on +[NSRunLoop SR_networkRunLoop] using defaultModes.
- (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
- (void)unscheduleFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;

// SRWebSockets are intended for one-time-use only.  Open should be called once and only once.
- (void)open;

- (void)close;
- (void)closeWithCode:(NSInteger)code reason:(NSString *)reason;

// Send a UTF8 String or Data.
- (void)send:(id)data;

// Send Data (can be nil) in a ping message.
- (void)sendPing:(NSData *)data;

- (void)addHeaders:(NSDictionary *)headers;
- (void)addHeader:(NSString *)key andValue:(NSString *)value;
- (void)addCookies:(NSDictionary *)cookies1;

@end

#pragma mark - LDSRWebSocketDelegate

@protocol LDSRWebSocketDelegate <NSObject>

// message will either be an NSString if the server is using text
// or NSData if the server is using binary.
- (void)webSocket:(LDSRWebSocket *)webSocket didReceiveMessage:(id)message;

@optional

- (void)webSocketDidOpen:(LDSRWebSocket *)webSocket;
- (void)webSocket:(LDSRWebSocket *)webSocket didFailWithError:(NSError *)error;
- (void)webSocket:(LDSRWebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean;
- (void)webSocket:(LDSRWebSocket *)webSocket didReceivePong:(NSData *)pongPayload;

@end

#pragma mark - NSURLRequest (LDSRCertificateAdditions)

@interface NSURLRequest (LDSRCertificateAdditions)

@property (nonatomic, retain, readonly) NSArray *LDSR_SSLPinnedCertificates;

@end

#pragma mark - NSMutableURLRequest (LDSRCertificateAdditions)

@interface NSMutableURLRequest (LDSRCertificateAdditions)

@property (nonatomic, retain) NSArray *LDSR_SSLPinnedCertificates;

@end

#pragma mark - NSRunLoop (LDSRWebSocket)

@interface NSRunLoop (LDSRWebSocket)

+ (NSRunLoop *)LDSR_networkRunLoop;

@end
