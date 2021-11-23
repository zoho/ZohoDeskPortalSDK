//
//  LDWmsService.h
//  LDZohoMessenger
//
//  Created by Balaji Sankar on 05/02/14.
//  Copyright (c) 2014 Balaji Sankar. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 The LDWmsService class stores the list of product codes associated with each Zoho Product
 */
@interface LDWmsService : NSObject
/**
 The method initWithPrd is used to initialize a LDWmsService instance
 Usage :
 LDWmsService *wmsService=[[LDWmsService alloc] initWithPrd:@"BA"];
 @param productCode Product code of the service.
 @warning Use this method only for csez set up and the product code must be a valid entry present in the WmsServer
 */
- (id)initWithPrd:(NSString *)productCode;

- (NSString *)getPrd;

/**
 * LiveDesk
 */
+ (LDWmsService *)LIVEDESK;

@end


