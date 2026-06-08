# ZohoDeskPortal SDK (XCFramework Distribution)

This repository contains prebuilt ZohoDeskPortal SDK modules as `.xcframework` binaries.

Use this guide to integrate the correct module + subdependency set in Xcode.

## Official Documentation

For complete Zoho Desk ASAP iOS SDK developer documentation, refer to:

https://help.zoho.com/portal/en/kb/desk/developer-space/asap/ios-sdk

## Package Layout

The SDKs are available under `native/` with the following structure:

```text
native/
├── ZohoDeskPortalAPIKit/                         [Foundation - Required Module]
│   ├── ZohoDeskPortalAPIKit.xcframework
│   ├── ZohoPortalAuthKit.xcframework
│   └── ZIAMCryptKit.xcframework
├── ZohoDeskPortalConfiguration/                  [Foundation - Required Module]
│   ├── ZohoDeskPortalConfiguration.xcframework
│   ├── ZohoDeskPlatformUIKit.xcframework
│   ├── ZohoDeskPlatformDataBridge.xcframework
│   ├── ZDMediaPickerSDK.xcframework
│   └── ZDHelperKit.xcframework
├── ZohoDeskPortalKB/                             [Feature Module]
│   └── ZohoDeskPortalKB.xcframework
├── ZohoDeskPortalCommunity/                      [Feature Module]
│   └── ZohoDeskPortalCommunity.xcframework
├── ZohoDeskPortalTicket/                         [Feature Module]
│   ├── ZohoDeskPortalTicket.xcframework
│   ├── ZDAttachmentUploader.xcframework
│   └── ZDLayoutKit.xcframework
├── ZohoDeskPortalCore/                           [Core ASAP Module]
│   └── ZohoDeskPortalCore.xcframework
├── ZohoDeskPortalChatKit/                        [Optional Module]
│   ├── ZohoDeskPortalChatKit.xcframework
│   ├── ZDChat.xcframework
│   ├── ZDOneChatSDK.xcframework
│   └── ZohoPubSubSDK.xcframework
└── ZohoDeskPortalSalesIQ/                        [Optional Module]
    ├── ZohoDeskPortalSalesIQ.xcframework
    ├── Mobilisten.xcframework
    ├── MobilistenCore.xcframework
    ├── MobilistenCallsCore.xcframework
    └── AVCallKitBridge.xcframework
```

## Important

For modular SDKs, **do not add only the main framework**. You must add the required subdependencies listed below in the same target.

Also follow these dependency rules:

- `ZohoDeskPortalAPIKit` and `ZohoDeskPortalConfiguration` are required core dependencies for `KB`, `Community`, and `Ticket` modules.
- `ZohoDeskPortalCore` is a combined Desk SDK and should be integrated along with `KB`, `Community`, and `Ticket`.
- `ChatKit` and `SalesIQ` are treated as optional Desk dependencies and can be integrated with `Core` when those features are required.

## Integration Decision Guide

Use this table to decide what to integrate based on your app feature needs.

| If you need | Integrate |
| --- | --- |
| KB | API Kit (base) + Configuration (base) + ZohoDeskPortalKB |
| Community | API Kit (base) + Configuration (base) + ZohoDeskPortalCommunity |
| Ticket | API Kit (base) + Configuration (base) + ZohoDeskPortalTicket + ZDAttachmentUploader + ZDLayoutKit |
| Desk Core | ZohoDeskPortalCore + KB + Community + Ticket |
| Core + Chat | Desk Core + ZohoDeskPortalChatKit + ZDChat + ZDOneChatSDK + ZohoPubSubSDK |
| Core + SalesIQ | Desk Core + ZohoDeskPortalSalesIQ + Mobilisten + MobilistenCore + MobilistenCallsCore + AVCallKitBridge |
| Core + Chat + SalesIQ | Desk Core + Chat Kit + SalesIQ |

## Xcode Integration Steps (Manual)

1. Open your app target in Xcode.
2. Go to **General** -> **Frameworks, Libraries, and Embedded Content**.
3. Add the required `.xcframework` files for the module you are integrating.
4. Ensure each added framework is set to **Embed & Sign** (or project-specific equivalent if already linked by another binary target).
5. Clean build folder and rebuild.

## Required Subdependencies

### 1) API Kit

Path: `native/ZohoDeskPortalAPIKit/`

Required frameworks:

- `ZohoDeskPortalAPIKit.xcframework`
- `ZohoPortalAuthKit.xcframework`
- `ZIAMCryptKit.xcframework`

### 2) Configuration

Path: `native/ZohoDeskPortalConfiguration/`

Required frameworks:

- `ZohoDeskPortalConfiguration.xcframework`
- `ZohoDeskPlatformUIKit.xcframework`
- `ZohoDeskPlatformDataBridge.xcframework`
- `ZDMediaPickerSDK.xcframework`
- `ZDHelperKit.xcframework`

### 3) KB

Path: `native/ZohoDeskPortalKB/`

Required frameworks:

- `ZohoDeskPortalKB.xcframework`

### 4) Community

Path: `native/ZohoDeskPortalCommunity/`

- `ZohoDeskPortalCommunity.xcframework`

### 5) Ticket

Path: `native/ZohoDeskPortalTicket/`

Required frameworks:

- `ZohoDeskPortalTicket.xcframework`
- `ZDAttachmentUploader.xcframework`
- `ZDLayoutKit.xcframework`

### 6) Desk Core

Path: `native/ZohoDeskPortalCore/`

Required frameworks:

- `ZohoDeskPortalCore.xcframework`

### 7) Chat Kit

Path: `native/ZohoDeskPortalChatKit/`

Frameworks required only if Chat Kit is integrated:

- `ZohoDeskPortalChatKit.xcframework`
- `ZDChat.xcframework`
- `ZDOneChatSDK.xcframework`
- `ZohoPubSubSDK.xcframework`

### 8) SalesIQ

Path: `native/ZohoDeskPortalSalesIQ/`

Frameworks required only if SalesIQ is integrated:

- `ZohoDeskPortalSalesIQ.xcframework`
- `Mobilisten.xcframework`
- `MobilistenCore.xcframework`
- `MobilistenCallsCore.xcframework`
- `AVCallKitBridge.xcframework`