//
//  PEXHeader.h
//  PEXLibrary
//
//  Created by Balaji Sankar on 25/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//
#import "WmsService.h"
#import "LibProperty.h"
//#import "LibProps.h"

@class PEX;
@class PEXResponse;
@class PEXError;
@class PEXEvent;
@class PEXTaskTypes;
@class PEXCredentials;

@class ServiceChatApi;
@class PresenceGroupApi;
@class CustomChatApi;
@class CollaborationApi;
@class ChatHandler;
@class CollaborationHandler;
@class ChannelHandler;
@class TazHandler;
@class EntityChatHandler;
@class ServiceChatHandler;
@class CustomChatHandler;
@class PresenceGroupHandler;
@class ContactsHandler;
@class MessageHandler;
@class ChatApi;
@class WmsService;

/*! \mainpage PEXLibrary Documentation
 *
 * \section Links
 *
 * PEXLibrary     ZohoMessenger      ZohoService
 *
 * PEXRequest     PEXException      PEXResponse
 *
 * ChatHandler    WmsConfig         MessageInterface
 *
 * \section install_sec Installation
 *
 * 1) Download and extract WMSApi.zip
 
 2) After Extracting add the files present inside WMSApi/SupportingFiles/ to your project
 
 3) Add "libPEXLibrary.a" present inside WMSApi/lib folder to your project
 
 4) Extend ChatHandler, CollaborationHandler, MessageHandler, ServiceChatHandler, PresenceGroupHandler, CustomChatHandler, ContactsHandler depending upon your need
 
 5) Add the following frameworks to your project
 
 * i)CFNetwork.framework
 
 * ii)libicucore.dylib
 
 * iii)Foundation.framework
 
 * iv)CoreFoundation.framework
 
 6) In your code, enable the required wms configurations
 example:
 
 *    #import "WmsConfig.h"
 
      ….
 
      ….
 
      WmsConfig *config=[[WmsConfig alloc] init];
 
      [config enablePersonalPresence];
 
      [config enableOrgPresence];
 
      [config enableChatPresence];
 
 7) In case if you extend ChatHandler and your derived interface name is TestClass then
 
      #import "PEXHeader.h"
 
      …
 
      ...
 
      TestClass *tc=[[TestClass alloc] init];
 
      [ZohoMessenger setChatHandler:tc];
 
      // similarly for service related operations like Collaboration
 
      #import "ZohoService.h"
 
      [ZohoService setCollaborationHandler:<#(CollaborationHandler *)#>]
 
 8) Your interface must follow the protocol <ConnectionHandler> (declared in PEXLibrary.h) and you must implement the methods declared in that protocol in your interface i.e., onConnect,onReconnect,onDisconnect and then register your interface to ZohoMessenger with the following code
      [ZohoMessenger setConnectionHandler:self];
 
 9) Each product has its unique Product code , which can be retrieved from WmsService.h
 
 10) In WMSProperties.plist , set your wms url for the key "wmsurl" default value is wss://mms.zoho.com
 
 11) Finally, start using ZohoMessenger Api with the following code
 
 Create a PEXCredentials object based on your need.. There are two types of credentials with which you can connect - IAMAuthToken & IAMTicket. For IAMAuthToken, it is mandatory to set iscscope, else we'll throw PEXException if insufficient credentials are supplied.
 
      [ZohoMessenger connect:credential :[WmsService CHAT] :[config getConfig]];
 
 The above method might throw PEXException if Improper credentials are supplied
 
 // variable config is mentioned in Step 6
 *
 12) To Create a PEXRequest,
 
 First import PEXHeader.h, WmsService.h
 
 We Recommend using a separate interface for a particular PEXRequest
 
 In that interface, in any of the methods, you can create a PEXRequest as follows
 
       PEXRequest *req=[[PEXRequest alloc] initRequestWithType:[WmsService product_name] andURL:theURL anddata:dict];
 
 Here "theURL" is a relative path from the product landing directory
 
 For example in order to call http://chat.zoho.com/mpchat.do , theURL will be just @"mpchat.do"
 
 "dict" refers to the dictionary of key-value pairs that you wish to send it to the wms server along with the PEX Request
 
       [req setMethod:@"POST"]; // The method can be set as @"GET", @"PUT", @"DELETE" etc signifying the HTTP counterpart.
 
       [req setHandler:self]; // Call this method so as to receive updates about the status of the PEXRequest. Your interface must obey PEXEventHandler protocol if you are calling this method
 
 
 Obey the protocol PEXEventHandler to get updates about the status of the pex request.
 
 then call
 
      @try {
 
      [PEXLibrary process:req];
 
      }
 
      @catch (PEXException *exception) {
 
 
 
      }
 
      @finally {}
 
 
 13) Similarly for calling API methods (for chat, collaboration, service chat, presence group, custom chat), invocation must be done as follows. API methods can be invoked by getting the respective instance of these interfaces from ZohoMessenger, ZohoService . Initializing the API's by yourself will return nil.
 
        @try {
 
        ChatInfoMessage *cim=[ChatInfoMessage TYPING];
        
        [[ZohoMessenger CHAT] sendInfoMessage:chid andMsg:@"hello" andChatInfoMessage:cim andHandler:nil];
 
        }
 
        @catch (PEXException *exception) {
 
        }
        
        @finally {
        
        }
 
 
 */

@class PEXRequest;


/**
 The class LibProperty is used to refer an object present in WMSProperties.plist.
 */
@interface LibProperty : NSObject
/**
 The method is used to initialize the LibProperty object with a key of WMSProperties.plist.
 @param theKey Key present in WMSProperties.plist.
 */
- (id)initWithKey:(NSString *)theKey;
/**
 This method returns the Key .
 @return The initial key.
 */
- (NSString *)getKey;
@end

/**
 enum constants
 */
typedef enum {
    CHAT = 1,
    COLLABORATION = 2,
    SERVICE_CHAT = 4,
    CUSTOM_CHAT = 5,
    PRESENCE_CHAT = 6,
    CHANNEL = 8,
    TAZ = 9,
    ENTITYCHAT = 10,
}handlerType;

/**
 The protocol ConnectionHandler declares a set of methods with which the app is notified about any change in status of connection to the WMS Server
 */
@protocol ConnectionHandler <NSObject>
/**
 The method onConnect is invoked after establishing a connection with the server and getting a valid wmsid and session id
 @param wmsid wmsid of the user
 @param sid Session id of the session
 @param dname Dname of the user.
 @param email email id of the user.
 @param depricated status of the application.
 @param messageObject complete details from server.
 */
- (void)onConnect:(NSString *)wmsid sid:(NSString *)sid andDname:(NSString *)dname andXA:(NSString *)xA andEmail:(NSString*)email andDepricated:(NSString*)depricated andMessage:(id)messageObject;
/**
 The method onReconnect is invoked when the following sequence of events occurs
 <li>Connection is lost due to network problems or other factors
 <li>Connection is once again established successfully/
 */
- (void)onReconnect;
/**
 The method onDisconnect is called when the connection to the server is lost
 @param manual The value will be YES if the client has requested the connection to terminate by calling the method PEXLibrary::disconnect else NO
 @param reason Reason behind the Disconnection.
 */
- (void)onDisconnect:(BOOL)manual andReason:(NSString *)reason;

/**
 The method onNetworkUp is invoked when connection established immediately after disconnected
 */
- (void)onNetworkUp;
@end

/**
 The protocol PEXEventHandler declares a set of call back methods that should be implemented by the receiver, which constructs an object of PEXEvent class to send a request to the WMS Server, so as to get updates about the status of PEXEvent
 */
@protocol PEXEventHandler <NSObject>
/**
 The method onComplete is invoked when a PEXEvent is completed
 @discussion Not to be confused with onSuccess. onSuccess is generated only when a Particular PEXRequest is sent successfully to the server and gets back a valid response. OnComplete will also be invoked in the case where the server returns an error response denoting that the request can't be processed
 @param response PEXResponse object from which the actual response can be extracted
 @param success Indicates that the particular event was successful in communicating to the server and received a valid response or not. if YES the event was successful else NO
 */
- (void)onComplete:(PEXResponse *)response isSuccess:(BOOL)success;
/**
 The method onProgress is invoked after receiving each chunk of a progressive response
 @param response PEXResponse object from which the actual response can be extracted
 */
- (void)onProgress:(PEXResponse *)response;
/**
 The method onProgress is invoked after sending a valid request to the server and getting a valid response for that particular reques
 @param response PEXResponse object from which the actual response can be extracted
 */
- (void)onSuccess:(PEXResponse *)response;
/**
 The method onFailure is invoked when a particular request receives an error response from the server
 @param error A PEXError object containing the error code and the associated error message
 */
- (void)onFailure:(PEXError *)error;
/**
 The method onBeforeSend is invoked before PEX forwards the request to the WMSServer
 @param event PEXEvent object, which is about to be forwarded to the WMSServer
 */
- (void)onBeforeSend:(PEXEvent *)event;
/**
 The method onTimeOut is invoked if a particular PexRequest doesn't get a valid response within the stipulated time.
 @param event PEXEvent object, which was forwarded to the server
 */
- (void)onTimeOut:(PEXEvent *)event;
@end


/**
 PEXLibrary is the base class by which connection can be established with the WMS Server and it processes PEXRequest and forwards it to the WMS server
 */
@interface PEXLibrary : NSObject
/**
 The method connect is used to establish connection with the WMS server
 @param credential A valid credential is needed to establish a connection with the Wms server.
 @param productCode A WmsService object indicating the respective product.
 @param sessionConfig A session config value is needed to establish a connection with the server .
 @warning Throws PEXException
 @see PEXException
 */
+ (void)connect:(PEXCredentials *)credential :(WmsService *)productCode :(NSString *)sessionConfig;
/**
 Call this method to hold the connection
 */
+ (void)hold;
/**
 Call this method to resume the connection, after holding the connection.
 */
+ (void)resume;
/**
 Call this method to network unreachable.
 */

+ (void)setDclPfx:(NSString*)name;
/**
 Call this method to network unreachable.
 */
/**
Call this method to set Multi DC base domain
*/
+ (void)setDclBaseDomain:(NSString*)name;

+ (void)networkFailure;
/**
 This method, when invoked, closes the existing connection with the WMS server
 */
+ (void)disconnect;
/**
 The method setConnectionHandler method is used to register a delegate object which obeys ConnectionHandler protocol. Once a delegate is registered it'll receive updates during any change in connection status
 @param delegate Must be a delegate object which should have implemented the ConnectionHandler Protocol
 */
+ (void)setConnectionHandler:(id<ConnectionHandler>)delegate;
/**
 The method process should be called so as to send a PEXRequest to the WMS server.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @param request A Valid PEXRequest object is needed so as to forward the request to the server.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)process:(PEXRequest *)request;
/**
 The method connectionStatus returns a BOOL to indicate that whether the connection to the WMS server is alive or not;
 */

+ (BOOL)connectionStatus;
/**
 The method getInsWithHandler is used to register with the WMS server to get ID , which points to a device
 @param handler Handler can be any object which obeys PEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)getInsWithHandler:(id<PEXEventHandler>)handler;
/**
 The method syncContactsWithData is used to get the contacts from the wms server. Data must be previous total contact list checksum and sum of individual contacts check sums
 @param dict The NSDictionary which contains the param values.
 @param handler Handler can be any object which obeys PEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)syncContactsWithData:(NSDictionary *)dict andHandler:(id<PEXEventHandler>)handler;
/**
 The method getContactInfo is used to retrieve the contact details of the list of parameters  that are supplied as parameters
 @param dict The NSDictionary containing the contact type and comma separated zuids
 Format is 
 {
    @"type":<Contact type as NSString>
    @"ulist":<Comma Separated Zuids>
 }
 @param handler Handler can be any object which obeys PEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)getContactInfo:(NSDictionary *)dict andHandler:(id<PEXEventHandler>)handler;
/**
 The method registerUnsWithDict is used to register the device by passing device specific parameters and ins id.
 @param dict The NSDictionary containing param's necessary for registering.
 @param handler Handler can be any object which obeys PEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */

+ (void)registerUnsWithDict:(NSDictionary *)dict andHandler:(id<PEXEventHandler>)handler;
/**
 The method unregisterUnsWithDict is used to unregister the device by passing device specific parameters and ins id
 @param dict The NSDictionary containing param's which was supplied during registration.
 @param handler Handler can be any object which obeys PEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)unregisterUnsWithDict:(NSDictionary *)dict andHandler:(id<PEXEventHandler>)handler;
/**
 Use this method to pass the push notification message intended for PEXLibrary, from didReceiveRemoteNotification method of the app delegate.
 @param pushNotificationMessage NSDictionary containing push notification message.
*/
+ (void)onReceivingPushNotification:(NSDictionary *)pushNotificationMessage;

@end


/**
 Zoho Messenger is extended from PEXLibrary. Rather than being purely connection oriented , it helps in registering listeners for Chat, Contacts and Message
 */
@interface ZohoMessenger : PEXLibrary

/** 
 The method CHAT creates an instance of the class ChatApi and returns it. This object can be used for further communication with the WMS Server
 @return ChatApi instance
 */
+ (ChatApi *)CHAT;
/**
 The method setChatHandler is used to register a class which has extended (inherited from) ChatHandler class so as to receive incoming messages intended for Chat
 @param handler A class which has extended(inherited from) ChatHandler
 */
+ (void)setChatHandler:(ChatHandler *)handler;
/**
 The method setContactsHandler is used to register a class which has extended (inherited from) ContactsHandler class so as to receive incoming messages intended for Contacts
 @param handler A class which has extended(inherited from) ContactsHandler
 */
+ (void)setContactsHandler:(ContactsHandler *)handler;
/**
 The method setMessageHandler is used to register a class which has extended (inherited from) MessageHandler class so as to receive incoming messages intended for Message
 @param handler A class which has extended(inherited from) Message
 */
+ (void)setMessageHandler:(MessageHandler *)handler;
/**
 The method sendInfoMessage is used to send Info Message across the products.
 @param recipants Denotes the zuid of the person(s),with whom the user wishes to send an information message. 
 @param msg The message that needs to be passed.
 @param handler Handler can be any object which obeys PEXEventHandler protocol, it is used to receive updates about the status of the request.
 @discussion The following method throws PEXException if any error occurs while processing the request. The invoking block should catch PEXException and handle it accordingly.
 @warning Throws PEXException
 @see PEXException
 */
+ (void)sendInfoMessage:(NSString *)recipants andMsg:(id)msg andHandler:(id<PEXEventHandler>)handler;

@end

/**
 ZohoService is an extension to PEXLibrary that  deals with chat related features
 */
@interface ZohoService : PEXLibrary

/**
 The method SERVICECHAT creates an instance of the class ServiceChatApi and returns it. This object can be used for further communication with the WMS Server
 @return ServiceChatApi instance
 */
+ (ServiceChatApi *)SERVICECHAT;
/**
 The method PRESENCEGROUP creates an instance of the class PresenceGroupApi and returns it. This object can be used for further communication with the WMS Server
 @return PresenceGroupApi instance
 */
+ (PresenceGroupApi *)PRESENCEGROUP;
/**
 The method CUSTOMCHAT creates an instance of the class CustomChatApi and returns it. This object can be used for further communication with the WMS Server
 @return CustomChatApi instance
 */
+ (CustomChatApi *)CUSTOMCHAT;
/**
 The method COLLABORATION creates an instance of the class CollaborationApi and returns it. This object can be used for further communication with the WMS Server
 @return CollaborationApi instance
 */
+ (CollaborationApi *)COLLABORATION;

/**
The method setCollaborationHandler is used to register a class which has extended (inherited from) CollaborationHandler class so as to receive incoming messages intended for collaboration
@param handler A class which has extended(inherited from) CollaborationHandler
 */
+ (void)setCollaborationHandler:(CollaborationHandler *)handler;

/**
 The method setCollaborationHandler is used to register a class which has extended (inherited from) ChannelHandler class so as to receive incoming messages intended for collaboration
 @param handler A class which has extended(inherited from) ChannelHandler
 */
+ (void)setChannelHandler:(ChannelHandler *)handler;

/**
 The method setTazHandler is used to register a class which has extended (inherited from) TazHandler class so as to receive incoming messages intended for taz messages
 @param handler A class which has extended(inherited from) TazHandler
 */
+ (void)setTazHandler:(TazHandler *)handler;

/**
 The method setEntityChatHandler is used to register a class which has extended (inherited from) EntityChatHandler class so as to receive incoming messages intended for entity chat messages
 @param handler A class which has extended(inherited from) EntityChatHandler
 */
+ (void)setEntityChatHandler:(EntityChatHandler *)handler;

/**
 The method setServiceChatHandler is used to register a class which has extended (inherited from) ServiceChatHandler class so as to receive incoming messages intended for ServiceChat
 @param handler A class which has extended(inherited from) ServiceChatHandler
 */
+ (void)setServiceChatHandler:(ServiceChatHandler *)handler;
/**
 The method setPresenceGroupHandler is used to register a class which has extended (inherited from) PresenceGroupHandler class so as to receive incoming messages intended for PresenceGroup
 @param handler A class which has extended(inherited from) PresenceGroupHandler
 */
+ (void)setPresenceGroupHandler:(PresenceGroupHandler *)handler;
/**
 The method setCustomChatHandler is used to register a class which has extended (inherited from) CustomChatHandler class so as to receive incoming messages intended for CustomChat
 @param handler A class which has extended(inherited from) CustomChatHandler
 */
+ (void)setCustomChatHandler:(CustomChatHandler *)handler;
//@end

@end
/**
 The class UserStatus holds status code and status message.
 */
@interface UserStatus : NSObject
/**
 The method setScode is used to set the status code.
 */
- (void)setScode:(NSString *)scode;
/**
 The method setSmsg is used to set the status message.
 */
- (void)setSmsg:(NSString *)smsg;
/**
 The method getScode returns the status code.
 * @return Returns Status code.
 */
- (NSString *)getScode;
/**
 The method getScode returns the status code.
 * @return Returns Status code.
 */
- (NSString *)getSmsg;

@end

/**
 PEXResponse is a class that constructs the response object using the response given in the param.
 */

@interface PEXResponse : NSObject
{
    int readystate;
    NSObject *response;
    NSMutableString *responseText;
    NSObject *responseObject;
    BOOL progressive;
}
@property(readonly) int readystate;
/**
 Returns the current response.
 */
@property(readonly) NSObject *response;
/**
 Returns the response object as a string.
 */
@property(readonly, strong) NSMutableString *responseText;
/**
 Returns the total response.
 */
@property(readonly) NSObject *responseObject;
/**
 Indicates whether the response is progressive or not.
 */
@property(readonly) BOOL progressive;
@end



/**
 PEXEvent is a base class which is used to send message to the wms server.
 */
@interface PEXEvent : NSObject
{
    id <PEXEventHandler> handler;
    
}
/**
 handler should implement PEXEventHandler Protocol so as to get updates about the status of the pex event.
 */
@property id <PEXEventHandler> handler;
/**
 The method is used to set cookie values to the PEXEvent message
 */
- (void)setCookie:(NSString *)cookie;
/**
 The method is used to add header values to the request
 @param key Key present in the header
 @param value value to be added for the key.
 @warning Throws PEXException if the key doesn't have the prefix @"X-"
 */
- (void)addHeader:(NSString *)key andValue:(NSString *)value;
/**
 The method is used to add configuration details to the Request
 @param key The key to denote the configuration 
 @param value Value is passed as LibProperty object 
 @warning Throws PEXException if the key begins with @"_" or invalid LibProperty value is supplied
 */
- (void)addData:(NSString *)key andValue:(LibProperty *)value;
@end

/**
 PEXRequest is extended from PEXEvent and it is used to send requests to the WMS Server
 */
@interface PEXRequest : PEXEvent
{
    NSString *method;
}

/**
 Specifies the method 
 For example @"POST".@"GET" etc.
 */
@property NSString *method;
/**
 This method creates a pex request for the given product with the relative url and request data.
 @param prd The Specific Zoho Product
 @param theURL url relative from the product home directory. For example to access chat.zoho.com/mpchat.do the value of theURL should be mpchat.do
 @param thedata The form data , that is to be sent with the request
 */
- (id)initRequestWithType:(WmsService *)theprd andURL:(NSString *)theURL anddata:(id)thedata;
/**
 This method creates a pex request for the given product with the relative url and request data abd indicate that it is a progressive request.
 @param prd The Specific Zoho Product
 @param theURL url relative from the product home directory. For example to access chat.zoho.com/mpchat.do the value of theURL should be mpchat.do
 @param thedata The form data , that is to be sent with the request
 */
- (id)initProgRequestWithType:(WmsService *)theprd andURL:(NSString *)theURL anddata:(id)thedata;
/**
 This method is used to add Cookie key-value pairs to the request.
 */
- (void)addCookie:(NSString *)key andValue:(NSString *)value;

@end

@interface PEXTaskTypes : NSObject
{
    PEXTaskTypes *CHAT_MSG;
    PEXTaskTypes *ANNON_CHAT_MSG;
    PEXTaskTypes *CREATE_CHAT;
    PEXTaskTypes *ADD_MEMBER;
    PEXTaskTypes *JOIN_CHAT;
    PEXTaskTypes *DELETE_MEMBER;
    PEXTaskTypes *QUIT_CHAT;
    PEXTaskTypes *CHAT_INFO_MSG;
    PEXTaskTypes *INFO_MSG;
    PEXTaskTypes *GET_TRANSCRIPTS;
    PEXTaskTypes *CREATE_GROUP_CHAT;
    PEXTaskTypes *SET_HISTORY;
    PEXTaskTypes *GET_INSID;
    PEXTaskTypes *REGISTER_UNS;
    PEXTaskTypes *ATTACHANDJOIN;
    PEXTaskTypes *CLEAR_UNREAD_CHATS;
    PEXTaskTypes *SENDATTMSG;
    PEXTaskTypes *SETUSERSTATUS;
    PEXTaskTypes *SETPNSLEEP;
    PEXTaskTypes *UNREGISTER_UNS;
    PEXTaskTypes *GETCONTACTINFO;
    PEXTaskTypes *BLOCKCHATNOTIFICATIONS;
    PEXTaskTypes *SYNC_CONTACTS;
    PEXTaskTypes *SET_LOCATION;
    PEXTaskTypes *GET_BADGE;
}
@property(readonly)PEXTaskTypes *GET_BADGE;
@property(readonly)PEXTaskTypes *SET_LOCATION;
@property(readonly)PEXTaskTypes *SYNC_CONTACTS;
@property(readonly)PEXTaskTypes *BLOCKCHATNOTIFICATIONS;
@property(readonly)PEXTaskTypes *UNREGISTER_UNS;
@property(readonly)PEXTaskTypes *CLEAR_UNREAD_CHATS;
@property(readonly)PEXTaskTypes *SENDATTMSG;
@property(readonly)PEXTaskTypes *SETUSERSTATUS;
@property(readonly)PEXTaskTypes *SETPNSLEEP;
@property(readonly)PEXTaskTypes *ATTACHANDJOIN;
@property(readonly)PEXTaskTypes *REGISTER_UNS;
@property(readonly)PEXTaskTypes *GET_INSID;
@property(readonly)PEXTaskTypes *GET_TRANSCRIPTS;
@property(readonly)PEXTaskTypes *CHAT_MSG;
@property(readonly)PEXTaskTypes *ANNON_CHAT_MSG;
@property(readonly)PEXTaskTypes *CREATE_CHAT;
@property(readonly)PEXTaskTypes *ADD_MEMBER;
@property(readonly)PEXTaskTypes *JOIN_CHAT;
@property(readonly)PEXTaskTypes *DELETE_MEMBER;
@property(readonly)PEXTaskTypes *QUIT_CHAT;
@property(readonly)PEXTaskTypes *CHAT_INFO_MSG;
@property(readonly)PEXTaskTypes *INFO_MSG;
@property(readonly)PEXTaskTypes *CREATE_GROUP_CHAT;
@property(readonly)PEXTaskTypes *SET_HISTORY;
@property(readonly)PEXTaskTypes *GETCONTACTINFO;

+ (PEXTaskTypes *)getSharedInstance;

@end

/**
 The class PEXErrorCodes provides a way of categorizing the errors, such that each error code denotes a particular type of error.
 */
@interface PEXErrorCodes : NSObject
/**
 Indicates No connection is Available
 @return Corresponding Error Code
 */
+ (int)NO_CONNECTION;
/**
 Indicates that the operation is not supported
 @return Corresponding Error Code
 */
+ (int)NOT_SUPPORTED;
/**
 Indicates that there is an error in the remote server
 @return Corresponding Error Code
 */
+ (int)REMOTE_SERVER_ERROR;
/**
 Indicates that invalid data is passed as an argument 
 @return Corresponding Error Code
 */
+ (int)INVALID_DATA;
/**
 Indicates that there is decryption error generated in the server side when processing the request
 @return Corresponding Error Code
 */
+ (int)DECRYPTION_ERROR;
/**
 Indicates that the receiver (PEX) is in a invalid state to process the request
 @return Corresponding Error Code
 */
+ (int)INVALID_STATE;
/**
 Indicates that the receiver (PEX) is supplied with invalid credential
 @return Corresponding Error Code
 */
+ (int)INVALID_CREDENTIAL;
/**
  Indicates that the receiver(PEX) has received invalid data for PEX event.
 @return Corresponding Error Code
 */
+ (int)INVALID_PEX_EVENT_DATA;
/**
 Returns the message associated with the particular error code
 @param code The error code
 @return The message corresponding to 'code'
 */
+ (NSString *)getMessage:(int)code;

@end

/**
 PEXError is a class that wraps around a particular PEXErrorCode and it's corresponding error message
 */
@interface PEXError : NSObject
{
    NSNumber *code;
    NSString *msg;
    NSDictionary *error;
}
/**
 PEXErrorCode in NSNumber format
 */
@property NSNumber *code;
/**
 Stores the error message
 */
@property NSString *msg;
/**
 Stores the remote error message
 */
@property NSDictionary *error;
@end

/**
 PEXCredentials class is used for authenticating a request to the WMS server.
 */
@interface PEXCredentials : NSObject
{
   
    NSString *username;
    NSString *displayName;
    NSString *zuid;
    NSString *osCode;
    
}
@property NSString *zuid;
@property NSString *osCode;
/**
 Stores the username
 */
@property NSString *username;
/**
 stores the display name
 */
@property NSString *displayName;
/**
 Assigns a NSDictionary of key value pairs to information related to this credential
 @param theinfo A hash map of key value pairs
 */
- (void)setInfo:(NSDictionary *)theinfo;
/**
 Sets the user Agent for the credential.
 @discussion Examples of User-Agent are @"IOS".
 @param userAgent User-Agent Value.
 */
- (void)setUserAgent:(NSString *)userAgent;
/**
 Stores the user's IP Address.
 @param ip The IP address of the current user.
 */
- (void)setIp:(NSString *)ip;
/**
 The method setInsid is used to inform WMS Server that this device has a INSID associated with it. This method should be called before calling "connect" method
 @param insid The insid to be provided to WMS Server.
 */
- (void)setInsid:(NSString *)insid;
/**
 The method addInfo adds a key value pair to the credentials information.
 @discussion Not to be confused with setInfo, which sets the entire HashMap as the Credentials. Information
 */
- (void)addInfo:(NSString *)thekey andValue:(NSString *)value;
/**
 The method getAddInfo is used to retrieve a Credential Information associated with that particular key.
 */
- (id)getAddInfo:(NSString *)key;
- (void)setUserZuid:(NSString *)wmsid;
- (void)setUserOscode:(NSString *)oscode;
- (void)setPnsKey:(NSString *)pKey;

@end

/**
 The class IAMTicket is extended from PEXCredentials.
 */
@interface IAMTicket : PEXCredentials
/**
 The method initWithTicket initializes the PEXCredentials with IAMTicket.
 @param theTicket IAMTicket.
 */
- (id)initWithTicket:(NSString *)theTicket;
@end

/**
 The class IAMAuthToken is extended from PEXCredentials.
 */
@interface IAMAuthToken : PEXCredentials
/**
 The method initWithToken initializes the PEXCredentials with IAM Authentication token.
 @param theToken IAM authentication token.
 */
- (id)initWithToken:(NSString *)theToken;
/**
 The method setISCScope is used to set ISC scope.
 @param iscscope ISCscope.
 */
- (void)setISCScope:(NSString *)iscscope;
@end


/**
 The class WMSAnnonUser is extended from PEXCredentials.
 */
@interface WMSAnnonUser : PEXCredentials
/**
 The method initWithUserName andDname initializes the PEXCredentials with a valid username and dname
 @param username name of the user.
 @param dispname dname of the user.
 */
- (id)initWithUserName:(NSString *)username andDname:(NSString *)dispname;
@end


/**
 The class IAMSSTicket is extended from PEXCredentials.
 */
@interface IAMSSTicket : PEXCredentials
/**
 The method initWithSSTicket initializes the PEXCredentials with SSTicket.
 @param ticket SSTicket.
 */
- (id)initWithSSTicket:(NSString *)ticket;
/**
 The method setDomain is used to set the domain
 @param domain domain name.
 */
- (void)setDomain:(NSString *)domain;
@end


/**
 The class PEXAuthToken is extended from PEXCredentials.
 */
@interface PEXAuthToken : PEXCredentials
/**
 The method initWithToken initializes the PEXCredentials with PEX Access key.
 @param accessKey PEX Access Key.
 */
- (id)initWithToken:(NSString *)accessKey;
/**
 The method setBundleId is used to set the bundle identifier
 @param bundleid Bundle Identifier.
 */
- (void)setBundleId:(NSString *)bundleid;

@end

